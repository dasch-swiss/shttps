
genrule(
    name = "openssl_genrule",
    srcs = glob(["**.c", "**.h"]),
    outs = ["openssl.a", "openssl.h"],
    cmd = "make",
)

cc_library(
    name = "openssl-lib",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"],
)