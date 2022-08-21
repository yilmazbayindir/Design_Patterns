## When and why should the Adapter Pattern be used?

- You want to use an existing class, and its interface does not match the one you need any more.
- You want to create a reusable class that cooperates with classes that don't necessarily have compatible interfaces.
- You need to use several existing subclasses, however it is not practical or efficient solution to adapt their interface by subclassing every one. Only an object adapter can adapt the interface of its parent class(i.e the interface of Target class)
