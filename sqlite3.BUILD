genrule(
    name = "sqlite3_genrule",
    srcs = glob(["**.c", "**.h"]),
    outs = ["sqlite3.a", "sqlite3.h", "sqlite3ext.h"],
    cmd = "make",
)

cc_library(
    name = "sqlite3-lib",
    srcs = ["sqlite3.a"],
    hdrs = ["sqlite3.h", "sqlite3ext.h"],
    visibility = ["//visibility:public"],
)