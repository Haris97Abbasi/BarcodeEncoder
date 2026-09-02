# BarcodeEncoder

This is a small console application that encodes a text message into a Code-128 Barcode (Subset B).

# Project Structure
The CMakeLists.txt file specifies the project structure and creates two executeables: 

ascii_cli.exe for running the console application

ascii_tests.exe for running the unit tests of this project that have been created using google tests.

The "include" folder contains the header files Encoder.h for the core functions Encoder.cpp and the Constants.cpp defining the constants like Startcode, Stopcode, mimimum ascii character, maximum ascii character and Checksum Modulus etc.

The "src" folder contains the file Encoder.cpp that defines the methods for encoding and validating the input text message from the user. It also inlcudes the file main.cpp that defines the main() method which calls the encode() method of the Encoder.cpp.

The "tests" folder contains the unit tests that have been created to check the encode and checksum calculate methods used in Encode.cpp.

## Build

After navigating to the root folder containing the CMakeLists.txt, run
```powershell
cmake -S . -B build
cmake --build build --config Debug
```
Remember to adjust the paths [ target_include_directories ] in CMake according to your own environment, as they have been hardcoded to avoid errors.

## Run the CLI

To run the console application, navigate to "out\build\x64-Debug" and execute
```powershell
.\asciix_cli.exe --encode "HELLO123"
# Expected Output: 104 40 69 76 76 79 17 18 19 44 106
```

## Run Tests

To run the unit tests, navigate to "out\build\x64-Debug" and execute
```powershell
.\asciix_tests.exe
```
