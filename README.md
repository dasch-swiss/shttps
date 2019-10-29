# shttps
Simple HTTP server

## Developers Quickstart


On macOS, you'll need to install several dependencies. This can be accomplished via [Homebrew](https://brew.sh/):
```
brew install coreutils wget cmake libtool go bazel automake ninja clang-format autoconf aspell
```
_notes_: `coreutils` is used for `realpath`, `gmd5sum` and `gsha256sum`

XCode is also required to build on macOS.
Envoy compiles and passes tests with the version of clang installed by XCode 9.3.0:
Apple LLVM version 9.1.0 (clang-902.0.30).

In order for bazel to be aware of the tools installed by brew, the PATH
variable must be set for bazel builds. This can be accomplished by setting
this in your `$HOME/.bazelrc` file:

```
build --action_env=PATH="/usr/local/bin:/opt/local/bin:/usr/bin:/bin"
```

Alternatively, you can pass `--action_env` on the command line when running
`bazel build`/`bazel test`.

Having the binutils keg installed in Brew is known to cause issues due to putting an incompatible
version of `ar` on the PATH, so if you run into issues building third party code like luajit
consider uninstalling binutils.
