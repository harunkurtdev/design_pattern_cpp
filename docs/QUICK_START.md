# Quick Start Guide

Get started with Design Patterns in C++ in just a few minutes!

## Prerequisites

Before you begin, ensure you have:
- C++ compiler (GCC 7+, Clang 5+, or MSVC 2017+)
- CMake 3.10 or higher
- Git

### Check Your Tools

```bash
# Check C++ compiler
g++ --version
# or
clang++ --version

# Check CMake
cmake --version

# Check Git
git --version
```

## Installation

### 1. Clone the Repository

```bash
git clone https://github.com/harunkurtdev/design_pattern_cpp.git
cd design_pattern_cpp
```

### 2. Build All Patterns

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

This will compile all design pattern examples.

## Running Examples

### Run All Patterns

```bash
# From the build directory
./Singleton
./Observer
./FactoryMethod
./AbstractFactory
./CompositePattern
./VisitorPattern
./ObserverExample
```

### Run a Specific Pattern

```bash
# Just run the one you're interested in
./Observer
```

Expected output:
```
Observer 1 updated with state 10
Observer 2 updated with state 10
Observer 3 updated with state 10
subject state: 10
1 state: 10
2 state: 10
3 state: 10
...
```

## Building Individual Patterns

If you only want to build a specific pattern:

```bash
# From the build directory
cmake --build . --target Singleton
./Singleton
```

Available targets:
- `Singleton` - Basic Singleton pattern
- `SingletonThreadSafe` - Thread-safe Singleton
- `Observer` - Observer pattern
- `ObserverExample` - Real-world Observer example
- `FactoryMethod` - Factory Method pattern
- `AbstractFactory` - Abstract Factory pattern
- `CompositePattern` - Composite pattern
- `VisitorPattern` - Visitor pattern

## Directory Navigation

```bash
# View available patterns
ls -la
# Output shows directories like:
# SingletonPattern/
# ObserverPattern/
# FactoryMethod/
# etc.

# Navigate to a specific pattern
cd SingletonPattern

# View the implementation
cat Singleton.cpp

# Check for documentation
cat README.md  # if available
```

## Learning Path

### Beginner (Start Here)

1. **Singleton** - Simplest pattern, single instance
   ```bash
   ./Singleton
   ```

2. **Factory Method** - Creating objects
   ```bash
   ./FactoryMethod
   ```

### Intermediate

3. **Observer** - Object communication
   ```bash
   ./Observer
   ./ObserverExample  # Real-world example
   ```

4. **Abstract Factory** - Creating families of objects
   ```bash
   ./AbstractFactory
   ```

### Advanced

5. **Composite** - Tree structures
   ```bash
   ./CompositePattern
   ```

6. **Visitor** - Adding operations without modifying classes
   ```bash
   ./VisitorPattern
   ```

## Modifying Examples

### Quick Edit Workflow

1. Edit a pattern file:
   ```bash
   vim SingletonPattern/Singleton.cpp
   # or use your preferred editor
   ```

2. Rebuild just that pattern:
   ```bash
   cd build
   cmake --build . --target Singleton
   ```

3. Run to see changes:
   ```bash
   ./Singleton
   ```

### Clean Build

If you need to start fresh:
```bash
cd ..
rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
```

## Manual Compilation

Don't want to use CMake? You can compile directly:

```bash
# Compile a single pattern
g++ -std=c++11 -o singleton SingletonPattern/Singleton.cpp

# Run it
./singleton
```

## Common Issues

### CMake Not Found
```bash
# Ubuntu/Debian
sudo apt-get install cmake

# macOS
brew install cmake

# Windows
# Download from https://cmake.org/download/
```

### Compiler Not Found
```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# macOS
xcode-select --install

# Windows
# Install Visual Studio or MinGW
```

### Build Errors

Try a clean build:
```bash
rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
```

## Next Steps

1. **Read the Code**: Start with `SingletonPattern/Singleton.cpp`
2. **Check Documentation**: Read pattern-specific README files
3. **Experiment**: Modify examples and rebuild
4. **Learn More**: Check [CONTRIBUTING.md](../CONTRIBUTING.md) for detailed guidelines
5. **Add Patterns**: Implement missing patterns (Strategy, Command, etc.)

## Getting Help

- Read the [main README](../README.md) for overview
- Check [CONTRIBUTING.md](../CONTRIBUTING.md) for detailed guidelines
- Review pattern-specific README files in each directory
- Open an issue on GitHub for questions

## Resources

- [Design Patterns Book (GoF)](https://en.wikipedia.org/wiki/Design_Patterns)
- [Refactoring.Guru](https://refactoring.guru/design-patterns)
- [SourceMaking](https://sourcemaking.com/design_patterns)

---

Happy coding! 🚀
