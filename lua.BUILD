genrule(
    name = "lua_genrule",
    srcs = glob(["src/**.c", "src/**.h"]),
    outs = ["lua.a", "lua.hpp"],
    cmd = "make",
)

cc_library(
    name = "lua-lib",
    srcs = ["lua.a"],
    hdrs = ["lua.hpp"],
    visibility = ["//visibility:public"],
)