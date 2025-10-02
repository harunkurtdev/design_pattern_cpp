cmake_minimum_required(VERSION 3.10.0)
project(design_pattern_cpp VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main executable (optional demo)
add_executable(design_pattern_cpp main.cpp)

# ============================================================================
# Creational Patterns
# ============================================================================

# Singleton Pattern - Basic implementation
add_executable(Singleton SingletonPattern/Singleton.cpp)

# Singleton Pattern - Thread-safe implementation
add_executable(SingletonThreadSafe SingletonPatternThreadSafe/SingletonThreadSafe.cpp)

# Factory Method Pattern
add_executable(FactoryMethod FactoryMethod/FactoryMethod.cpp)

# Abstract Factory Pattern
add_executable(AbstractFactory AbstractFactory/AbstractFactory.cpp)

# ============================================================================
# Structural Patterns
# ============================================================================

# Composite Pattern
add_executable(CompositePattern CompositePattern/Composite.cpp)

# ============================================================================
# Behavioral Patterns
# ============================================================================

# Observer Pattern - Basic implementation
add_executable(Observer ObserverPattern/Observer.cpp)

# Observer Pattern - Real-world example
add_executable(ObserverExample ObserverPattern/Example/ObserverExample.cpp)

# Visitor Pattern
add_executable(VisitorPattern VisitorPattern/Visitor.cpp)

# ============================================================================
# CPack Configuration
# ============================================================================

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
