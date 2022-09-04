# Prototype

## Intent:
- Prototype is a creational design pattern that lets you create new objects by copying existing prototype objects without making your client code dependent on their classes.
- This pattern can be applied to objects only.

## When should "the Prototype Pattern" be used?
- Use this pattern when you want your client code to be independent of the concrete classes of existing prototype objects that you want to copy.
- Use this pattern when the classes to instantiate are specified at run-time.
- Use this pattern when instances of a class can have one of several different configurations of state. As you know, it will be more convenient way to copy the existing prototype objects rather than instantiating the class of prototype objects manually. Besides, instantiating the class of prototype objects manually with the same states can be impossible since some states can be private or unvisible.
