genrule(
    name = "jansson_genrule",
    srcs = glob(["src/**.c", "src/**.h"]),
    outs = ["jansson.a", "jansson.h", "jansson_config.h"],
    cmd = "cmake . && make",
)

cc_library(
    name = "jansson-lib",
    srcs = ["jansson.a"],
    hdrs = ["jansson.h", "jansson_config.h"],
    visibility = ["//visibility:public"],
)