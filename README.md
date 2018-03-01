# DexDump

Tiny and lightweight DBC dump tool for all embedded methods in .dex files.

# Requirements

 + C++ compiler (g++, clang++, etc.)
 + CMake > 3.5.1

# Installation

In order to compile the project, you have to run this set of commands:

```bash
mkdir build
cd build
cmake ..
make
```

If no error occured during the compilation process, you should find a binary file called "dexdiff" on your current directory.

# Usage

You can process one or n .dex files to the program by passing the paths as arguments:

```bash
./dexdump /tmp/classes.dex ... /tmp/classes31337.dex
```

# License

DexDump is licensed under the GNU GPL license. Have a look at the [LICENSE](https://github.com/bla5r/DexDump/blob/master/LICENSE) for more information.

# Contact

If you have any question about the project, feel free to contact me on Twitter: [@bla5r](https://twitter.com/bla5r)
