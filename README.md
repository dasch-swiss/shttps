# shttps
Simple HTTP server

## Style Guide

The code follows the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) and the
exceptions which are documented in this section.

## Prerequisites

On macOS, you'll need to install several dependencies. This can be accomplished via [Homebrew](https://brew.sh/):

In order for bazel to be aware of the tools installed by brew, the PATH
variable must be set for bazel builds. This can be accomplished by setting
this in your `$HOME/.bazelrc` file:

```
build --action_env=PATH="/usr/local/bin:/opt/local/bin:/usr/bin:/bin"
```

Alternatively, you can pass `--action_env` on the command line when running
`bazel build`/`bazel test`.

- on macOS, this might be necessary:
  ```bash
  export DEVELOPER_DIR=/Applications/Xcode.app/Contents/Developer
  export SDKROOT=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
  ```

- Apple Command Line Tools:
  ```bash
  $ xcode-select --install
  ```

- Java 11:
  ```
  $ brew tap AdoptOpenJDK/openjdk
  $ brew cask install AdoptOpenJDK/openjdk/adoptopenjdk11
  ```

  To pin the version of Java, please add this environment variable to your starup script:
  ```
  export JAVA_HOME=`/usr/libexec/java_home -v 11`
  ```

- Node:
  ```
  $ brew install node
  $ brew install n // optional
  $ n lts // optional
  ```

- Bazel:
  ```
  $ npm install -g @bazel/bazelisk
  $ npm install -g @bazel/buildozer
  ```

- CMake:
  ```
  $ brew install cmake
  ```

## Linux Container

To test if the build and tests run under Linux, you can start a Linux Docker container,
which matches your current CPU platform:
```bash
$ make start-linux-amd64-container
$ make start-linux-arm64-container
$ make start-linux-armv7-container
```

Then inside the container, change into the `src` directory, and run
the `test-linux` make target:
```bash
$ cd src
$ make test-linux
```

## Experimental Apple Silicon Support

To run the tests on a Apple Silicon machine, run the following:
```bash
$ USE_BAZEL_VERSION=last_green bazel test -c opt --cpu=darwin_arm64 //...
```
