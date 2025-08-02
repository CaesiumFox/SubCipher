# SubCipher

Simple substitution cipher CLI tool

# How to build

You will need:
- A C++ compiler like G++ or Clang++
- Meson build system (can be installed through `pip`)
- An Internet connection to download the "cxxopts" dependency

Steps:
1. Clone the repository:
   ```
   git clone https://github.com/CaesiumFox/SubCipher.git
   ```
2. Change current directory to the project directory:
   ```
   cd SubCipher
   ```
3. Setup Meson build directory:
   ```
   meson setup build
   ```
4. Compile the project:
   ```
   meson compile -C build
   ```
   > [!WARNING]
   > Meson will download the "cxxopts"
   > dependency from the Internet
5. Done.
   The executable is located at `./build/subc`
