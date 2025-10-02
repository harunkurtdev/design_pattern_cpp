# Design Patterns in C++

A comprehensive collection of classic Gang of Four (GoF) design patterns implemented in C++. This repository serves as a learning resource and reference for software developers studying design patterns.

## 📚 Table of Contents

- [Overview](#overview)
- [Implemented Patterns](#implemented-patterns)
- [Getting Started](#getting-started)
- [Building the Project](#building-the-project)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)

## Overview

This repository demonstrates the implementation of various design patterns in C++. Each pattern is implemented in its own directory with clear examples and can be compiled and executed independently.

Design patterns are reusable solutions to common problems in software design. They represent best practices and can speed up the development process by providing tested, proven development paradigms.

## Implemented Patterns

### Creational Patterns
Design patterns that deal with object creation mechanisms.

- ✅ **[Singleton](SingletonPattern/)** - Ensures a class has only one instance and provides a global point of access
  - Basic implementation: `SingletonPattern/Singleton.cpp`
  - Thread-safe version: `SingletonPatternThreadSafe/SingletonThreadSafe.cpp`
- ✅ **[Factory Method](FactoryMethod/)** - Defines an interface for creating objects, letting subclasses decide which class to instantiate
- ✅ **[Abstract Factory](AbstractFactory/)** - Provides an interface for creating families of related objects without specifying concrete classes

### Structural Patterns
Design patterns that deal with object composition and relationships.

- ✅ **[Composite](CompositePattern/)** - Composes objects into tree structures to represent part-whole hierarchies
- ⏳ **Decorator** - Attaches additional responsibilities to objects dynamically
- ⏳ **Adapter** - Converts the interface of a class into another interface clients expect

### Behavioral Patterns
Design patterns that deal with object collaboration and responsibility.

- ✅ **[Observer](ObserverPattern/)** - Defines a one-to-many dependency between objects
  - Basic implementation: `ObserverPattern/Observer.cpp`
  - Real-world example: `ObserverPattern/Example/ObserverExample.cpp`
- ✅ **[Visitor](VisitorPattern/)** - Represents an operation to be performed on elements of an object structure
- ⏳ **Strategy** - Defines a family of algorithms and makes them interchangeable
- ⏳ **Command** - Encapsulates a request as an object

**Legend**: ✅ = Implemented, ⏳ = Planned

## Getting Started

### Prerequisites

- CMake 3.10.0 or higher
- C++ compiler with C++11 support or later (GCC, Clang, MSVC)
- Git (for cloning the repository)

### Clone the Repository

```bash
git clone https://github.com/harunkurtdev/design_pattern_cpp.git
cd design_pattern_cpp
```

## Building the Project

### Using CMake (Recommended)

```bash
# Create build directory
mkdir -p build
cd build

# Configure the project
cmake ..

# Build all patterns
cmake --build .

# Or build specific pattern
cmake --build . --target Singleton
```

### Manual Compilation

You can also compile individual patterns directly:

```bash
g++ -o singleton SingletonPattern/Singleton.cpp
./singleton
```

## Usage

After building, executables will be in the `build` directory:

```bash
cd build

# Run a specific pattern
./Singleton
./Observer
./ObserverExample
./FactoryMethod
./AbstractFactory
./VisitorPattern
./CompositePattern
```

Each executable demonstrates the pattern with example output to the console.

## Project Structure

```
design_pattern_cpp/
├── README.md                          # This file
├── CONTRIBUTING.md                    # Contribution guidelines
├── CMakeLists.txt                     # CMake build configuration
├── main.cpp                           # Main entry point
│
├── SingletonPattern/                  # Singleton pattern implementation
│   └── Singleton.cpp
├── SingletonPatternThreadSafe/        # Thread-safe Singleton
│   └── SingletonThreadSafe.cpp
│
├── FactoryMethod/                     # Factory Method pattern
│   └── FactoryMethod.cpp
├── AbstractFactory/                   # Abstract Factory pattern
│   └── AbstractFactory.cpp
│
├── ObserverPattern/                   # Observer pattern
│   ├── Observer.cpp                   # Basic implementation
│   └── Example/
│       └── ObserverExample.cpp        # Real-world example
│
├── CompositePattern/                  # Composite pattern
│   └── Composite.cpp
│
└── VisitorPattern/                    # Visitor pattern
    └── Visitor.cpp
```

## Contributing

Contributions are welcome! If you'd like to add a new pattern or improve existing implementations:

1. Read the [CONTRIBUTING.md](CONTRIBUTING.md) guide
2. Fork the repository
3. Create a feature branch (`git checkout -b feature/new-pattern`)
4. Follow the coding style and structure conventions
5. Commit your changes (`git commit -am 'Add new pattern'`)
6. Push to the branch (`git push origin feature/new-pattern`)
7. Open a Pull Request

See [CONTRIBUTING.md](CONTRIBUTING.md) for detailed guidelines on:
- Repository organization
- Naming conventions
- Code style guidelines
- Adding new patterns

## Pattern Resources

For more information about design patterns:
- [Design Patterns: Elements of Reusable Object-Oriented Software](https://en.wikipedia.org/wiki/Design_Patterns) (Gang of Four book)
- [Refactoring.Guru - Design Patterns](https://refactoring.guru/design-patterns)
- [SourceMaking - Design Patterns](https://sourcemaking.com/design_patterns)

## License

This project is open source and available for educational purposes.

## Author

[Harun Kurt](https://github.com/harunkurtdev)

---

**Note**: This is an educational project. The implementations focus on clarity and demonstrating pattern concepts rather than production-ready code.
