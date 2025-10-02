# Contributing to Design Patterns in C++

Thank you for your interest in contributing to this design patterns repository!

## Repository Organization Guidelines

### Directory Structure

The repository follows a consistent structure for organizing design patterns:

```
design_pattern_cpp/
├── README.md                          # Main documentation
├── CONTRIBUTING.md                    # This file
├── CMakeLists.txt                     # Build configuration
├── main.cpp                           # Main entry point (optional demo)
├── <PatternName>/                     # Pattern implementation directory
│   ├── <PatternName>.cpp             # Main pattern implementation
│   ├── README.md                      # Pattern-specific documentation (optional)
│   └── Example/                       # Examples subdirectory (optional)
│       └── <PatternName>Example.cpp  # Example usage
└── docs/                              # Additional documentation (future)
```

### Naming Conventions

1. **Directory Names**: Use PascalCase with "Pattern" suffix
   - Examples: `SingletonPattern`, `ObserverPattern`, `FactoryMethod`
   - Exception: Well-known patterns can omit "Pattern" if commonly recognized

2. **File Names**: Match the directory name
   - Main implementation: `<PatternName>.cpp`
   - Examples: `<PatternName>Example.cpp`

3. **Class Names**: Use descriptive names following the pattern's standard terminology
   - Examples: `Singleton`, `Observer`, `Subject`, `ConcreteFactory`

### Code Style Guidelines

1. **Indentation**: Use 4 spaces (no tabs)
2. **Braces**: Opening brace on the same line for functions and classes
3. **Naming**:
   - Classes: PascalCase (e.g., `ConcreteObserver`)
   - Functions/Methods: camelCase (e.g., `getInstance()`, `Attach()`)
   - Variables: camelCase (e.g., `observerList`, `concreteState`)
   - Constants: UPPER_SNAKE_CASE (e.g., `MAX_SIZE`)

4. **Memory Management**:
   - Use `new`/`delete` consistently
   - Always delete dynamically allocated objects
   - Consider smart pointers for modern C++ (C++11+)

5. **Header Guards**: Use `#pragma once` or traditional include guards

### Adding a New Pattern

To add a new design pattern to the repository:

1. **Create Directory Structure**:
   ```bash
   mkdir <PatternName>
   ```

2. **Implement the Pattern**:
   - Create `<PatternName>/<PatternName>.cpp`
   - Include a working `main()` function
   - Add comprehensive comments explaining the pattern

3. **Add Optional Example**:
   - Create `<PatternName>/Example/` directory if needed
   - Add real-world example implementation

4. **Update CMakeLists.txt**:
   ```cmake
   add_executable(<PatternName> <PatternName>/<PatternName>.cpp)
   ```

5. **Update README.md**:
   - Add pattern name to the list
   - Add brief description and link to implementation

6. **Document the Pattern** (Optional but recommended):
   - Create `<PatternName>/README.md`
   - Include:
     - Pattern intent and purpose
     - UML diagram (if applicable)
     - When to use
     - Pros and cons
     - Related patterns

### Pattern Implementation Checklist

Each pattern implementation should include:

- [ ] Clear class hierarchy with interface/abstract classes
- [ ] Concrete implementations demonstrating the pattern
- [ ] Working `main()` function with example usage
- [ ] Proper memory cleanup (delete allocated objects)
- [ ] Comments explaining key concepts
- [ ] Console output demonstrating pattern behavior
- [ ] Entry in CMakeLists.txt for compilation
- [ ] Entry in main README.md

### Build and Test

Before submitting changes:

1. **Build the project**:
   ```bash
   mkdir -p build && cd build
   cmake ..
   cmake --build .
   ```

2. **Test your pattern**:
   ```bash
   ./<PatternName>
   ```

3. **Verify output**: Ensure the program runs without errors and demonstrates the pattern correctly

### Common Patterns to Implement

The README lists patterns that should be implemented:
- ✅ Singleton
- ✅ Observer
- ✅ Factory Method
- ✅ Abstract Factory
- ✅ Composite
- ✅ Visitor
- ⏳ Strategy
- ⏳ Command
- ⏳ Decorator
- ⏳ Adapter

### Code Review Process

When contributing:
1. Ensure code follows style guidelines
2. Test compilation and execution
3. Add meaningful commit messages
4. Update documentation as needed
5. One pattern per pull request (preferred)

### Questions or Suggestions?

Feel free to open an issue for:
- Questions about implementation
- Suggestions for improvement
- Reporting bugs
- Requesting new patterns

Thank you for contributing to help others learn design patterns in C++!
