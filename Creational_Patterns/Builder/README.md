# Builder

## Intent:
- Builder is a creational design pattern that lets you construct a complex object step by step under director's control; so it is different than any creational pattern that constructs an object in one shot.
- It allows you to create different representations of an object via the same construction codes.
- It gives you more control over the construction process of an object. The object is accessed from builder only when the whole construction process is completed.
- This pattern can be applied to objects only.

## When should "the Builder Pattern" be used?
- Use this pattern when your algorithm for creating a complex object should be independent of the parts that form the object.
- Use this pattern when you want the same construction codes to create different representations of an object.
- Use this pattern when you want to get rid of a “telescoping constructor”, i.e., when you don’t want to add dozens of parameters into your constructor.
