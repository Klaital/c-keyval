#include <gtest/gtest.h>
#include "keyval.h"

TEST(KeyValTest, ToString) 
{
    char buf[128];
    buf[0] = '\0';
    Entry e;
    e.set("playlist", "futurama.m3u", ":");
    EXPECT_STREQ("playlist", e.key());
    EXPECT_STREQ("futurama.m3u", e.val());
    e.cat(buf);
    EXPECT_STREQ("playlist:futurama.m3u", buf);
}