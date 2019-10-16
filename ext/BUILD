load("@rules_foreign_cc//tools/build_defs:configure.bzl", "configure_make")
load("@rules_foreign_cc//tools/build_defs:make.bzl", "make")
load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")


# build zlib
configure_make(
    name = "zlib",
    configure_options = [
        "--static",
    ],
    lib_source = "@zlib//:all",
    out_lib_dir = "lib",
    configure_env_vars = {
            "AR": "",
    },
    visibility = ["//visibility:public"],
)

# build openssl
configure_make(
    name = "openssl",
    configure_options = [
        "zlib",
        "no-shared",
    ],
    lib_source = "@sqlite//:all",
    deps = [
        ":zlib",
    ],
    out_lib_dir = "lib",
    configure_env_vars = {
            "AR": "",
    },
    visibility = ["//visibility:public"],
)


# build lua
make(
    name = "lua",
    lib_source = "@lua//:all",
    out_lib_dir = "lib",
    visibility = ["//visibility:public"],
)


# build jansson
cmake_external(
   name = "jansson",
   lib_source = "@jansson//:all",
   static_libraries = ["libjansson.a"],
)

# build sqlite
configure_make(
    name = "sqlite",
    configure_options = [
        "--enable-fts5",
        "--enable-shared",
         "--enable-static",
    ],
    lib_source = "@sqlite//:all",
    out_lib_dir = "lib",
    configure_env_vars = {
            "AR": "",
    },
    visibility = ["//visibility:public"],
)