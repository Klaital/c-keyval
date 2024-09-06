#include <gtest/gtest.h>
#include "keyval.h"

TEST(ParsingTest, Entry)
{
    char buf[256] = "loop=true";
    Entry e;
    e.set(buf);
    EXPECT_STREQ("loop", e.key());
    EXPECT_STREQ("true", e.val());
}

TEST(ParsingTest, KeyValSet)
{
    char buf[512] = "playlists_available=are_you_being_served.m3u,father_ted.m3u,futurama.m3u,night_all.m3u,the_simpsons.m3u\nselected_playlist=the_simpsons.m3u\nshuffle=true\nloop=true\n";
    KeyValSet kv;
    size_t token_len = kv.parse_line(buf);
    EXPECT_EQ(103, token_len);
    EXPECT_EQ(1, kv.length());
    EXPECT_STREQ("are_you_being_served.m3u,father_ted.m3u,futurama.m3u,night_all.m3u,the_simpsons.m3u", kv.get("playlists_available"));
}

TEST(KeyValTest, ToString) 
{
    char buf[128];
    buf[0] = '\0';
    Entry e;
    e.set("playlist", "futurama.m3u", ':');
    EXPECT_STREQ("playlist", e.key());
    EXPECT_STREQ("futurama.m3u", e.val());
    e.cat(buf);
    EXPECT_STREQ("playlist:futurama.m3u", buf);
}

TEST(KeyValSet, HighLevel)
{
    char buf[512] = "playlists_available=are_you_being_served.m3u,father_ted.m3u,futurama.m3u,night_all.m3u,the_simpsons.m3u\nselected_playlist=the_simpsons.m3u\nshuffle=true\nloop=true\n";
    KeyValSet kv;
    kv.parse(buf);
    EXPECT_STREQ("true", kv.get("loop"));
}
