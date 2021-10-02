# Operators that cannot be overloaded in C++
In C++ we can overload some operators like +, -, [], -> etc. But we cannot overload any operators in it. Some of the operators cannot be overloaded. These operators are like below

- ? “.” Member access or dot operator
- ? “? : ” Ternary or conditional operator
- ? “::” Scope resolution operator
- ? “.*” Pointer to member operator
- ? “sizeof” The object size operator
- ? “typeid” Object type operator
These operators cannot be overloaded because if we overload them it will make serious programming issues.

For an example the sizeof operator returns the size of the object or datatype as an operand. This is evaluated by the compiler. It cannot be evaluated during runtime. So we cannot overload it.