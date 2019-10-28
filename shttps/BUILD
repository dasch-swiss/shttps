package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_binary(
    name = "shttps",
    srcs = ["shttps.cpp"],
    deps = [
        ":shttps-lib",
        "//lib:jwt",
        "//lib:sole",
        "//ext:jansson",
        "@lua//:lua",
        "//ext:openssl",
    ],
)

cc_library(
    name = "shttps-lib",
    srcs = [
        "ChunkReader.cpp",
        "Connection.cpp",
        "Error.cpp",
        "Hash.cpp",
        "LuaServer.cpp",
        "LuaSqlite.cpp",
        "Parsing.cpp",
        "Server.cpp",
        "SockStream.cpp",
    ],
    hdrs = [
        "ChunkReader.h",
        "Connection.h",
        "Error.h",
        "Global.h",
        "Hash.h",
        "LuaServer.h",
        "LuaSqlite.h",
        "makeunique.h",
        "Parsing.h",
        "Server.h",
        "SockStream.h",

    ],
)


