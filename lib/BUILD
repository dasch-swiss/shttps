package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "jwt",
    srcs = [
        "jwt/jwt.c",
    ],
    hdrs = [
        "jwt/jwt.h"
    ],
    deps = [
        "//ext:openssl"
    ]
)

cc_library(
    name = "sole",
    hdrs = [
        "sole/sole.hpp"
    ],
)