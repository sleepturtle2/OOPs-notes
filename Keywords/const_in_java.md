# Why const keyword is not used in Java? 

Can you see reasons for closing the request, does Sun provides any explanations?

Yes. Sun provided 3 reasons for why they won't act on the request in the request itself. I quote:

"There are no current plans to add this feature to Java. In addition to creeping featurism, we see the following problems with this feature:

- Adding const is too late now. Had this been added from 1.0, the situation could have been different.

- Const pollution: the C++ approach requires all const methods to be marked with a const keyword. This means that most methods will have to be marked const explicitly. This tend to clutter all methods in C++.

- Compatibility is a very important feature of the JDK. Arguably, the collection classes should be modified to indicate that the elements are const. That would require all existing implementations to be updated in the same way, effectively breaking all existing non-JDK implementations of the collection interfaces. Similarly, hashCode would have to be const, breaking the current implementation of String."

