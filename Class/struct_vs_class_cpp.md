# Structure vs class in C++

In C++, a structure is the same as a class except for a few differences. The most important of them is security. A Structure is not secure and cannot hide its implementation details from the end-user while a class is secure and can hide its programming and designing details. Following are the points that expound on this difference: 
1) Members of a class are private by default and members of a structure are public by default. 
For example program 1 fails in compilation and program 2 works fine.
 


# Program 1
```
#include <stdio.h>
 
class Test {
    int x; // x is private
};
int main()
{
  Test t;
  t.x = 20; // compiler error because x is private
  getchar();
  return 0;
}
```
# Program 2
```
#include <stdio.h>
 
struct Test {
    int x; // x is public
};
int main()
{
  Test t;
  t.x = 20; // works fine because x is public
  getchar();
  return 0;
}
```
2) When deriving a struct from a class/struct, the default access-specifier for a base class/struct is public. And when deriving a class, the default access specifier is private. 
For example program 3 fails in compilation and program 4 works fine. 



# Program 3
```
#include <stdio.h>
 
class Base {
public:
    int x;
};
 
class Derived : Base { }; // is equivalent to class Derived : private Base {}
 
int main()
{
  Derived d;
  d.x = 20; // compiler error because inheritance is private
  getchar();
  return 0;
}
```
# Program 4
```
#include <stdio.h>
 
class Base {
public:
    int x;
};
 
struct Derived : Base { }; // is equivalent to struct Derived : public Base {}
 
int main()
{
  Derived d;
  d.x = 20; // works fine because inheritance is public
  getchar();
  return 0;
}
```