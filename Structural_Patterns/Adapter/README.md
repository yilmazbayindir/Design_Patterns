# Adapter

## Intent:
Adapter is a structural design pattern that transforms the interface of an existing class into the one clients know. This pattern can be applied to both classes and objects. 

## When/Why should "the Adapter Pattern" be used?
- Use this pattern when you want to use some existing class, however its interface is not compatible with your current code.
- Use this pattern when you want to have a special class which has a relationship with your current classes that do not share the same interface with target class any more. 
- Use this pattern when you need to use several existing subclasses, however it is not practical or efficient solution to adapt their interface by subclassing every one. Only an object adapter can match the interface of its parent class(i.e the interface of Target class)
