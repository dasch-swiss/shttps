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
    configure_env_vars = {
            "AR": "",
    },
    static_libraries = ["libz.a"],
    visibility = ["//visibility:public"],
)

# build openssl
configure_make(
    name = "openssl",
    configure_command = "config",
    configure_options = [
        "zlib",
        "no-shared",
    ],
    lib_source = "@openssl//:all",
    deps = [
        ":zlib",
    ],
    configure_env_vars = {
            "AR": "",
    },
    static_libraries = [
        "libcrypto.a",
        "libssl.a",
    ],
    visibility = ["//visibility:public"],
)

# TODO: calculate platform for lua
# lua_platform = "macosx" if Label("@local_config_platform//:host") == "osx" else "linux"

# build lua
make(
    name = "lua",
    # needs to be specified
    prefix = "$(BAZEL_GEN_ROOT)",
    # need to pass platform: macosx or linux
    make_commands = ["macosx"],
    lib_source = "@lua//:all",
    static_libraries = ["liblua.a"],
    visibility = ["//visibility:public"],
)


# build jansson
cmake_external(
   name = "jansson",
   lib_source = "@jansson//:all",
   static_libraries = ["libjansson.a"],
   visibility = ["//visibility:public"],
)

# build sqlite
configure_make(
    name = "sqlite3",
    install_prefix = "$(BAZEL_GEN_ROOT)",
    configure_options = [
        "--enable-fts5",
        "--enable-shared",
        "--enable-static",
    ],
    lib_source = "@sqlite3//:all",
    configure_env_vars = {
            "AR": "",
    },
    out_lib_dir = "lib",
    static_libraries = ["libsqlite3.a"],
    visibility = ["//visibility:public"],
)