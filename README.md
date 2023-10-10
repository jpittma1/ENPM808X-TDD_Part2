# cpp-boilerplate-v2

# C++ Boilerplate v2 Badges
![CICD Workflow status](https://github.com/Rashmikapu/ENPM808X-Test-Driven-Development-/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/Rashmikapu/ENPM808X-Test-Driven-Development-/branch/main/graph/badge.svg)](https://codecov.io/gh/Rashmikapu/ENPM808X-Test-Driven-Development-) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)



Authors :

-- RASHMI KAPU (119461754)
-- NEHA MADHEKAR (119374436)


## Part 2 Authors
Driver: Jerry Pittman, Jr. (jpittma1)<br>
Navigator: Vyshnav Achuthan (Achuthankrishna)

### TODO: 
1. UML to repository
2. validate PID gain values or make a iterative feedback loop (1 of 2 tests fail "this_should_pass")

Instructions to build and run :

# Configure the project and generate a native build system:
  
  cmake -S ./ -B build/

# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose

# Run program:
  ./build/app/shell-app

# Run tests:
  cd build/; ctest; cd -
  # or if you have newer cmake
  ctest --test-dir build/

# Build docs:
  cmake --build build/ --target docs
  # open a web browser to browse the doc
  open docs/html/index.html

# Clean
  cmake --build build/ --target clean

# Clean and start over:
  rm -rf build/
```

ref: https://cmake.org/cmake/help/latest/manual/cmake.1.html



## Building for code coverage (for assignments beginning in Week 4)

```bash
# if you don't have gcovr or lcov installed, do:
  sudo apt-get install gcovr lcov
# Set the build type to Debug and WANT_COVERAGE=ON
  cmake -D WANT_COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug -S ./ -B build/
# Now, do a clean compile, run unit test, and generate the covereage report
  cmake --build build/ --clean-first --target all test_coverage
# open a web browser to browse the test coverage report
  open build/test_coverage/index.html

This generates a index.html page in the build/test_coverage sub-directory that can be viewed locally in a web browser.
```

You can also get code coverage report for the *shell-app* target, instead of unit test. Repeat the previous 2 steps but with the *app_coverage* target:

``` bash
# Now, do another clean compile, run shell-app, and generate its covereage report
  cmake --build build/ --clean-first --target all app_coverage
# open a web browser to browse the test coverage report
  open build/app_coverage/index.html

This generates a index.html page in the build/app_coverage sub-directory that can be viewed locally in a web browser.

### Visual studio code C++ IDE setup

Download vscode from https://code.visualstudio.com/docs/?dv=linux64_deb.

To install and it on your Ubuntu, do

``` bash
cd ~/Downloads
sudo dpkg -i code_1.81.1-1691620686_amd64.deb
code
```

Now, you must configure it to use clangd. Follow the instructions at https://clangd.llvm.org/installation.html#editor-plugins and look for "Visual Studio Code" under the `Editor plugins` section.

See https://github.com/clangd/vscode-clangd for more info.

### Emacs C++ IDE setup

If you use Emacs as your C++ IDE, then install eglot and supporting packages:
``` lisp
(package-initialize)
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/"))
(package-refresh-contents)
(setq package-selected-packages '(eglot yasnippet company markdown-mode yasnippet-snippets cpp-auto-include))
(package-install-selected-packages)

```

Add to ~/.emacs:

``` lisp
(require 'eglot)
(add-to-list 'eglot-server-programs '((c++-mode c-mode) "clangd"))
```

See https://joaotavora.github.io/eglot/ for more info.



## Verify C++ IDE and LSP are working

clangd will automatically run (in the background) when invoked by the IDE. To verify that it's running correctly, you just need to check if the IDE can perform features such as code completion, finding declarations, references, definitions, and symbols, etc.

However, for clangd to work properly, it must ab able to find a file called `compile_commands.json` somewhere in your source code tree.  There are many ways to generate this compilation database file.  CMake can generate it for you already (this is done by using `CMAKE_EXPORT_COMPILE_COMMANDS` option).   Everytime you invoke the configuration command `cmake -S ./ -B build/`, cpp-boilerplate-v2 creates a symbolic link to the `compile_commands.json` file.

``` bash
  # generate compile_commands.json
  cmake -S ./ -B build/
  # verify compile_commands.json has been generated
  ls -l compile_commands.json
  cat compile_commands.json
```

Alternatively, a program called `bear` can also be used to create `compile_commands.json`, regardless of the C++ build system you are using. It does this by intercepting subsequent command-line commands and collecting all C++ compilation flags passed to the compiler.  To use this approach, prepend `bear --` at the beginning of the build command.   For CMake, you can do:

``` bash
# build compile_commands.json from scratch
  bear -- cmake --build build/ --clean-first
# or, update the existing compile_commands.json
  bear --append -- cmake --build build/
```

Either way, this should produce the `compile_commands.json` file.  Now, you can use it with the IDE.

### Visual studio code
1. Open `cpp-boilerplate-v2/app/main.cpp`

1. Move the cursor to the `dummy()` function call and press the F12 key (or right-click->Go to Definition).  Visual studio code should automatically open `cpp-boilerplate-v2/include/lib.hpp` and place the curse at line 5, where the `dummy` function is defined.

1. Close the editor, delete the `compile_commands.json` file and repeat.  Verify that *step 2 does not work anymore*.

### Emacs

1. Open `cpp-boilerplate-v2/app/main.cpp` and start `eglot` if it's not already running.

1. Move the cursor to the `dummy()` function call and press the `<M-.>` key (or xref-find-definitions).  Emacs should automatically open `cpp-boilerplate-v2/include/lib.hpp` and place the curse at line 5, where the `dummy` function is defined.

1. Close the editor, delete the `compile_commands.json` file and repeat.  Verify that *step 2 does not work anymore*.
