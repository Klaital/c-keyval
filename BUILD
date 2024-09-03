cc_library(
	name = "keyval",
	hdrs=glob(["**/*.h"]),
    srcs=glob(["**/*.cpp"]),
)
cc_test(
	name = "keyval_test",
	size = "small",
	srcs = [
		"keyval.cpp",
		"keyval_test.cc",
	],
	deps = [
		"@googletest//:gtest",
		"@googletest//:gtest_main",
		"//:keyval",
	],
)
