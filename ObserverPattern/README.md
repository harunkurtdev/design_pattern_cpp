# Observer Pattern

> **Category**: Behavioral
> 
> **Difficulty**: Intermediate

## Intent

Defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

## Motivation

When building systems, we often need to maintain consistency between related objects without making them tightly coupled. The Observer pattern allows an object (Subject) to notify other objects (Observers) about changes without knowing who or what those observers are.

## Structure

```
┌─────────────┐         observes        ┌─────────────┐
│  Subject    │◆────────────────────────│  Observer   │
├─────────────┤                         ├─────────────┤
│ +Attach()   │                         │ +update()   │
│ +Detach()   │                         │ +getState() │
│ +Notify()   │                         └─────────────┘
└─────────────┘                               △
      △                                       │
      │                                       │
┌─────────────────┐                   ┌───────────────────┐
│ ConcreteSubject │                   │ ConcreteObserver  │
├─────────────────┤                   ├───────────────────┤
│ -state          │                   │ -observerState    │
│ +GetState()     │                   │ +update()         │
│ +SetState()     │                   │ +getState()       │
└─────────────────┘                   └───────────────────┘
```

### Participants

- **Subject**: Maintains list of observers and provides methods to attach/detach them
- **Observer**: Defines an updating interface for objects that should be notified
- **ConcreteSubject**: Stores state and notifies observers when state changes
- **ConcreteObserver**: Maintains reference to subject and implements update interface

## When to Use

Use the Observer pattern when:
- A change to one object requires changing others, and you don't know how many objects need to be changed
- An object should be able to notify other objects without knowing who they are
- You need a publish-subscribe mechanism
- You want loose coupling between interacting objects

## Implementation

### Key Components

1. **Subject**: The object being observed
2. **Observer**: The interface for objects that should be notified
3. **Attach/Detach**: Methods to register/unregister observers
4. **Notify**: Method to update all observers
5. **Update**: Method called on observers when subject changes

### Code Example

```cpp
class Subject {
protected:
    vector<Observer*> observerList;
public:
    void Attach(Observer* o) { observerList.push_back(o); }
    void Notify() {
        for (auto observer : observerList) {
            observer->update(state);
        }
    }
};

class Observer {
public:
    virtual void update(int value) = 0;
};
```

## Pros and Cons

### Advantages ✅
- Loose coupling between subject and observers
- Support for broadcast communication
- Dynamic relationships (can add/remove observers at runtime)
- Follows Open/Closed Principle (can add observers without modifying subject)

### Disadvantages ❌
- Observers are notified in random order
- Can cause memory leaks if observers aren't properly detached
- Unexpected updates can occur
- Performance issues with many observers

## Related Patterns

- **Mediator**: Both promote loose coupling, but Mediator uses centralized control
- **Singleton**: Subjects are often implemented as Singletons
- **Model-View-Controller (MVC)**: Observer is fundamental to MVC architecture

## Real-World Examples

1. **GUI Event Handling**: Button clicks notify multiple listeners
2. **Newsletter Subscriptions**: Subscribers receive updates when new content is published
3. **Stock Market**: Traders observe stock price changes
4. **Sensor Systems**: Multiple displays update when sensor values change (see Example/)

## Implementation Files

- `Observer.cpp` - Basic implementation demonstrating the pattern
- `Example/ObserverExample.cpp` - Real-world sensor/room monitoring system

### Example Description

The `ObserverExample.cpp` demonstrates a room monitoring system where:
- **Subject (Room)**: Monitors temperature and moisture
- **Observers (Sensors)**: Thermometers and moisture meters that update when room conditions change
- **Selective Updates**: Sensors register for specific metrics (temperature OR moisture)

## Usage

```bash
# Build basic implementation
cmake --build build --target Observer

# Build real-world example
cmake --build build --target ObserverExample

# Run
./build/Observer
./build/ObserverExample
```

## Output (Example)

```
Observer 1 updated with state 10
Observer 2 updated with state 10
Observer 3 updated with state 10
subject state: 10
1 state: 10
2 state: 10
3 state: 10
```

## Additional Resources

- [Wikipedia: Observer Pattern](https://en.wikipedia.org/wiki/Observer_pattern)
- [Refactoring.Guru: Observer](https://refactoring.guru/design-patterns/observer)
- [SourceMaking: Observer](https://sourcemaking.com/design_patterns/observer)
