workspace(name = "shttps")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

new_git_repository(
    name = "openssl",
    build_file = "openssl.BUILD",
    remote = " https://github.com/openssl/openssl",
)

new_http_archive(
    name = "curl",
    build_file = "curl.BUILD",
    urls = ["https://curl.haxx.se/download/curl-7.66.0.tar.gz"],
)

new_http_archive(
    name = "lua",
    build_file = "lua.BUILD",
    urls = ["http://www.lua.org/ftp/lua-5.3.5.tar.gz"],
)

new_git_repository(
    name = "jansson",
    build_file = "jansson.BUILD",
    remote = "https://github.com/akheron/jansson.git",
)

new_http_archive(
    name = "sqlite3",
    build_file = "sqlite3.BUILD",
    urls = ["https://www.sqlite.org/2019/sqlite-autoconf-3300100.tar.gz"],
)
