# Singleton Pattern

> **Category**: Creational
> 
> **Difficulty**: Beginner

## Intent

Ensures a class has only one instance and provides a global point of access to it.

## Motivation

Sometimes we need exactly one instance of a class. For example:
- A single database connection pool
- A configuration manager
- A logging service
- A window manager in a GUI system

The Singleton pattern ensures that only one instance exists and provides controlled access to it.

## Structure

```
┌─────────────────────┐
│    Singleton        │
├─────────────────────┤
│ - instance: static  │
│ - Singleton()       │  (private constructor)
├─────────────────────┤
│ + getInstance()     │  (static method)
│ + showMessage()     │
└─────────────────────┘
```

### Participants

- **Singleton**: The class that controls its instantiation
  - Private constructor prevents external instantiation
  - Static instance variable holds the single instance
  - Static getInstance() method provides access

## When to Use

Use the Singleton pattern when:
- There must be exactly one instance of a class
- The instance must be accessible from a well-known access point
- The single instance should be extensible by subclassing
- You need to control access to a shared resource

## Implementation

### Key Components

1. **Private Constructor**: Prevents direct instantiation
2. **Static Instance**: Holds the single instance
3. **Public Static Access Method**: Provides global access point

### Code Example

```cpp
class Singleton {
private:
    static Singleton* instance;
    Singleton() { /* private constructor */ }
    
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};
```

## Pros and Cons

### Advantages ✅
- Controlled access to sole instance
- Reduced memory footprint (only one instance)
- Can be extended by subclassing
- Permits a variable number of instances (can be modified)
- More flexible than class operations (static methods)

### Disadvantages ❌
- Difficult to test (global state)
- Violates Single Responsibility Principle
- Can be problematic in multi-threaded environments
- Can hide dependencies
- Makes code tightly coupled

## Thread Safety

The basic implementation in `Singleton.cpp` is **not thread-safe**. For multi-threaded applications, use the thread-safe version in `SingletonPatternThreadSafe/SingletonThreadSafe.cpp`.

### Thread-Safe Implementation Approaches

1. **Eager initialization**: Create instance at startup
2. **Double-checked locking**: Use mutex only when needed
3. **Static local variable** (C++11): Thread-safe by standard

## Related Patterns

- **Abstract Factory**: Often implemented as Singletons
- **Builder**: Often implemented as a Singleton
- **Prototype**: Often implemented as a Singleton

## Real-World Examples

1. **Logger**: Single logging instance across application
2. **Configuration Manager**: One configuration object
3. **Thread Pool**: Single pool managing all threads
4. **Device Drivers**: Single interface to hardware

## Implementation Files

- `Singleton.cpp` - Basic implementation (not thread-safe)
- `../SingletonPatternThreadSafe/SingletonThreadSafe.cpp` - Thread-safe version

## Usage

```bash
# Build
cmake --build build --target Singleton

# Run
./build/Singleton
```

## Output

```
Singleton Instance Created
Hello from Singleton!
Hello from Singleton!
Both instances are the same.
```

## Additional Resources

- [Wikipedia: Singleton Pattern](https://en.wikipedia.org/wiki/Singleton_pattern)
- [Refactoring.Guru: Singleton](https://refactoring.guru/design-patterns/singleton)
