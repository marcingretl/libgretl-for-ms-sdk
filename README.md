# libgretl for Microsoft Windows SDK

Precompiled **libgretl** import libraries and headers for developing C and C++ applications on **Microsoft Windows (x64 and ARM64)** using native Windows toolchains.

This GitHub repository is a mirror of the [official SourceForge SVN repository](https://sourceforge.net/p/libgretl-for-ms-sdk/code/). Development and releases are maintained on SourceForge.

## Requirements

To link your C/C++ application against `libgretl`:

1. Download and unpack [`mscompile.zip`](https://sourceforge.net/projects/gretl/files/mscompile/) from SourceForge.
2. Install **Microsoft Visual Studio** (Visual Studio 2022 has been used for development) or the necessary Microsoft Windows SDK and build tools.
3. Install the native Windows **Clang/LLVM** toolchain. Support for the Microsoft C/C++ compiler (`cl.exe`) is available but needs further testing.

## Examples and environment

Simple examples are available in the [`c/`](c/) and [`c++/`](c++/) directories.

To run the resulting executables, configure the required environment variables and library paths. See [`setenv.bat`](setenv.bat) (Command Prompt) or [`setenv.ps1`](setenv.ps1) (PowerShell) for details.

For information on generating MSVC-compatible import libraries, see [`howto.txt`](howto.txt). Version changes are recorded in [`changelog.txt`](changelog.txt).

## Mixing C runtimes: MSVCRT and UCRT

**Take care when mixing code linked against different C runtimes**, in particular **MSVCRT** and **UCRT**.

Memory allocated by one C runtime must be released by a compatible deallocation function from that same runtime. For example, memory allocated with `malloc()` in MSVCRT must not be released with `free()` from UCRT, or vice versa. Crossing runtime boundaries in this way can corrupt the heap and cause crashes or other undefined behavior.

To avoid this problem, use the corresponding **libgretl** API function to release memory allocated by libgretl whenever one is provided. For example, use `gretl_list_free()` to release a list allocated by libgretl. Do not assume that every pointer returned by the library can be safely passed to your application's `free()`.

## Development status

- **Clang/LLVM:** supported native Windows toolchain.
- **MSVC (`cl.exe`):** basic support is available; additional testing is needed.

## Links

- [SourceForge project](https://sourceforge.net/projects/libgretl-for-ms-sdk/)
- [SourceForge SVN repository](https://sourceforge.net/p/libgretl-for-ms-sdk/code/)
- [gretl project](https://gretl.sourceforge.net/)
- [libgretl API documentation](https://gretl.sourceforge.net/API/new/gretl/)
