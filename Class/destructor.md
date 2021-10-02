# Destructors in C++

### What is a destructor? 
Destructor is an instance member function which is invoked automatically whenever an object is going to be destroyed. Meaning, a destructor is the last function that is going to be called before an object is destroyed.

The thing is to be noted here, if the object is created by using new or the constructor uses new to allocate memory which resides in the heap memory or the free store, the destructor should use delete to free the memory.   

Syntax:

~constructor-name();


Properties of Destructor:

Destructor function is automatically invoked when the objects are destroyed.
It cannot be declared static or const.
The destructor does not have arguments.
It has no return type not even void.
An object of a class with a Destructor cannot become a member of the union.
A destructor should be declared in the public section of the class.
The programmer cannot access the address of destructor.
When is destructor called? 
A destructor function is called automatically when the object goes out of scope: 
(1) the function ends 
(2) the program ends 
(3) a block containing local variables ends 
(4) a delete operator is called  



How are destructors different from a normal member function? 
Destructors have same name as the class preceded by a tilde (~) 
Destructors don’t take any argument and don’t return anything

```
class String {
private:
	char* s;
	int size;

public:
	String(char*); // constructor
	~String(); // destructor
};

String::String(char* c)
{
	size = strlen(c);
	s = new char[size + 1];
	strcpy(s, c);
}
String::~String() { delete[] s; }

```
Can there be more than one destructor in a class? 
No, there can only one destructor in a class with classname preceded by ~, no parameters and no return type.

When do we need to write a user-defined destructor? 
If we do not write our own destructor in class, compiler creates a default destructor for us. The default destructor works fine unless we have dynamically allocated memory or pointer in class. When a class contains a pointer to memory allocated in class, we should write a destructor to release memory before the class instance is destroyed. This must be done to avoid memory leak.

Can a destructor be virtual? 
Yes, In fact, it is always a good idea to make destructors virtual in base class when we have a virtual function.

## Private Destructor

Predict the output of following programs. 
```
// CPP program to illustrate
// Private Destructor
#include <iostream>
using namespace std;

class Test {
private:
	~Test() {}
};
int main()
{
}
```
The above program compiles and runs fine. Hence, we can say that : It is not compiler error to create private destructors. 
Now, What do you say about below program. 


```
// CPP program to illustrate
// Private Destructor
#include <iostream>
using namespace std;

class Test {
private:
	~Test() {}
};
int main()
{
	Test t;
}

```

The above program fails in compilation. The compiler notices that the local variable ‘t’ cannot be destructed because the destructor is private. 
Now, What about the below program? 

```
// CPP program to illustrate
// Private Destructor
#include <iostream>
using namespace std;

class Test {
private:
	~Test() {}
};
int main()
{
	Test* t;
}

```
The above program works fine. There is no object being constructed, the program just creates a pointer of type “Test *”, so nothing is destructed.
Next, What about the below program? 

```
// CPP program to illustrate
// Private Destructor

#include <iostream>
using namespace std;

class Test {
private:
	~Test() {}
};
int main()
{
	Test* t = new Test;
}

```

The above program also works fine. When something is created using dynamic memory allocation, it is programmer’s responsibility to delete it. So compiler doesn’t bother. 
In the case where the destructor is declared private, an instance of the class can also be created using malloc() function. Same is implemented in below program.

```
// CPP program to illustrate
// Private Destructor

#include <bits/stdc++.h>
using namespace std;

class Test {
public:
	Test() // Constructor
	{
		cout << "Constructor called\n";
	}

private:
	~Test() // Private Destructor
	{
		cout << "Destructor called\n";
	}
};

int main()
{
	Test* t = (Test*)malloc(sizeof(Test));
	return 0;
}
```

Output: 

  
However, The below program fails in compilation. When we call delete, destructor is called.
 


```
// CPP program to illustrate
// Private Destructor
#include <iostream>
using namespace std;

class Test {
private:
	~Test() {}
};
int main()
{
	Test* t = new Test;
	delete t;
}

```

We noticed in the above programs, when a class has private destructor, only dynamic objects of that class can be created. Following is a way to create classes with private destructors and have a function as friend of the class. The function can only delete the objects. 

```
// CPP program to illustrate
// Private Destructor
#include <iostream>

// A class with private destructor
class Test {
private:
	~Test() {}
public:
	friend void destructTest(Test*);
};

// Only this function can destruct objects of Test
void destructTest(Test* ptr)
{
	delete ptr;
}

int main()
{
	// create an object
	Test* ptr = new Test;

	// destruct the object
	destructTest(ptr);

	return 0;
}

```

What is the use of private destructor?

Whenever we want to control destruction of objects of a class, we make the destructor private. For dynamically created objects, it may happen that you pass a pointer to the object to a function and the function deletes the object. If the object is referred after the function call, the reference will become dangling. 

## Virtual Destructor

Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. To correct this situation, the base class should be defined with a virtual destructor. For example, following program results in undefined behavior.

```
// CPP program without virtual destructor
// causing undefined behavior
#include<iostream>

using namespace std;

class base {
public:
	base()	
	{ cout<<"Constructing base \n"; }
	~base()
	{ cout<<"Destructing base \n"; }	
};

class derived: public base {
public:
	derived()	
	{ cout<<"Constructing derived \n"; }
	~derived()
	{ cout<<"Destructing derived \n"; }
};

int main(void)
{
derived *d = new derived();
base *b = d;
delete b;
getchar();
return 0;
}

```

Although the output of following program may be different on different compilers, when compiled using Dev-CPP, it prints following:

Constructing base
Constructing derived
Destructing base

Making base class destructor virtual guarantees that the object of derived class is destructed properly, i.e., both base class and derived class destructors are called. For example,

```
// A program with virtual destructor
#include<iostream>

using namespace std;

class base {
public:
	base()	
	{ cout<<"Constructing base \n"; }
	virtual ~base()
	{ cout<<"Destructing base \n"; }	
};

class derived: public base {
public:
	derived()	
	{ cout<<"Constructing derived \n"; }
	~derived()
	{ cout<<"Destructing derived \n"; }
};

int main(void)
{
derived *d = new derived();
base *b = d;
delete b;
getchar();
return 0;
}

```
Output:

Constructing base
Constructing derived
Destructing derived
Destructing base

## Pure virtual destructor in C++

Can a destructor be pure virtual in C++?
Yes, it is possible to have pure virtual destructor. Pure virtual destructors are legal in standard C++ and one of the most important things to remember is that if a class contains a pure virtual destructor, it must provide a function body for the pure virtual destructor. You may be wondering why a pure virtual function requires a function body. The reason is because destructors (unlike other functions) are not actually ‘overridden’, rather they are always called in the reverse order of the class derivation. This means that a derived class’ destructor will be invoked first, then base class destructor will be called. If the definition of the pure virtual destructor is not provided, then what function body will be called during object destruction? Therefore the compiler and linker enforce the existence of a function body for pure virtual destructors.
Consider the following program:

```
#include <iostream>
class Base
{
public:
	virtual ~Base()=0; // Pure virtual destructor
};

class Derived : public Base
{
public:
	~Derived()
	{
		std::cout << "~Derived() is executed";
	}
};

int main()
{
	Base *b=new Derived();
	delete b;
	return 0;
}

```

The linker will produce following error in the above program.

test.cpp:(.text$_ZN7DerivedD1Ev[__ZN7DerivedD1Ev]+0x4c): 
undefined reference to `Base::~Base()' 
Now if the definition for the pure virtual destructor is provided, then the program compiles & runs fine.

```
#include <iostream>
class Base
{
public:
	virtual ~Base()=0; // Pure virtual destructor
};
Base::~Base()
{
	std::cout << "Pure virtual destructor is called";
}

class Derived : public Base
{
public:
	~Derived()
	{
		std::cout << "~Derived() is executed\n";
	}
};

int main()
{
	Base *b = new Derived();
	delete b;
	return 0;
}
```

Output:

~Derived() is executed
Pure virtual destructor is called
It is important to note that a class becomes abstract class when it contains a pure virtual destructor. For example, try to compile the following program.

```
#include <iostream>
class Test
{
public:
	virtual ~Test()=0; // Test now becomes abstract class
};
Test::~Test() { }

int main()
{
	Test p;
	Test* t1 = new Test;
	return 0;
}

```

The above program fails in compilation & shows following error messages.
[Error] cannot declare variable ‘p’ to be of abstract type ‘Test’
[Note] because the following virtual functions are pure within ‘Test’:
[Note] virtual Test::~Test()
[Error] cannot allocate an object of abstract type ‘Test’
[Note] since type ‘Test’ has pure virtual functions

## Difference between destructors and functions 

Destructors in C++ are members functions in a class that delete an object. They are called when the class object goes out of scope such as when the function ends, the program ends, a delete variable is called etc.

Destructors are different from normal member functions as they don’t take any argument and don’t return anything. Also, destructors have the same name as their class and their name is preceded by a tilde(~).

A program that demonstrates destructors in C++ is given as follows.

Example

```
#include<iostream>
using namespace std;
class Demo {
   private:
   int num1, num2;
   public:
   Demo(int n1, int n2) {
      cout<<"Inside Constructor"<<endl;
      num1 = n1;
      num2 = n2;
   }
   void display() {
      cout<<"num1 = "<< num1 <<endl;
      cout<<"num2 = "<< num2 <<endl;
   }
   ~Demo() {
      cout<<"Inside Destructor";
   }
};
int main() {
   Demo obj1(10, 20);
   obj1.display();
   return 0;
}
```

Output
```
Inside Constructor
num1 = 10
num2 = 20
Inside Destructor
```
In the above program, the class Demo contains a parameterized constructor that initializes num1 and num2 with the values provided by n1 and n2. It also contains a function display() that prints the value of num1 and num2. There is also a destructor in Demo that is called when the scope of the class object is ended. The code snippet for this is given as follows.

```
class Demo {
   private:
   int num1, num2;
   public:
   Demo(int n1, int n2) {
      cout<<"Inside Constructor"<<endl;
      num1 = n1;
      num2 = n2;
   }
   void display() {
      cout<<"num1 = "<< num1 <<endl;
      cout<<"num2 = "<< num2 <<endl;
   }
   ~Demo() {
      cout<<"Inside Destructor";
   }
};
```
The function main() contains the object definition for an object of class type Demo. Then the function display() is called. This is shown below.
```
Demo obj1(10, 20);
obj1.display();
```

## A class has multiple constructors but why it has only one destructor?

13

A destructor doesn't have parameters, so there can be only one. However you can have more than 1 constructor since you can overload the constructor which is not possible with Destructors. Also to add that destructor is used to terminate the instance of the class and release all resources which it is using. There is nothing optional when you are destroying the object. The instance will not exist when destructor will be called.

Although a very wierd example to explain it but its like if you have 1 Apple and 1 Guava then you will use the 1 knife to cut it. ;)

Destructors are usually used to deallocate memory and do other cleanup for a class object and its class members when the object is destroyed. A destructor is called for a class object when that object passes out of scope or is explicitly deleted.

before abc a(5); gets called destructor will get called

No it will not be called as Destructors are called implicitly.

On a side note:-

However if you plan to call the Destructor explicitly(which most of the programmers will not suggest) then it would be completely your responsibility to manage the resources. The compiler will not take care of it and it may result in serious memory issues.

## Why do we need to define user-defined destructors? 

35

The rule of Three and The Rule of Zero
The good ol' way of handling resources was with the Rule of Three (now Rule of Five due to move semantic), but recently another rule is taking over: the Rule of Zero.

The idea, but you should really read the article, is that resource management should be left to other specific classes.

On this regard the standard library provides a nice set of tools like: std::vector, std::string, std::unique_ptr and std::shared_ptr, effectively removing the need for custom destructors, move/copy constructors, move/copy assignment and default constructors.

How to apply it to your code
In your code you have a lot of different resources, and this makes for a great example.

The string
If you notice brandname is effectively a "dynamic string", the standard library not only saves you from C-style string, but automatically manages the memory of the string with std::string.

The dynamically allocated B
The second resource appears to be a dynamically allocated B. If you are dynamically allocating for other reasons other than "I want an optional member" you should definitely use std::unique_ptr that will take care of the resource (deallocating when appropriate) automatically. On the other hand, if you want it to be an optional member you can use std::optional instead.

The collection of Bs
The last resource is just an array of Bs. That is easily managed with an std::vector. The standard library allows you to choose from a variety of different containers for your different needs; Just to mention some of them: std::deque, std::list and std::array.

Conclusion
To add all the suggestions up, you would end up with:

```
class A {
private:
    std::string brandname;
    std::unique_ptr<B> b;
    std::vector<B> vec;
public:
    virtual void something(){} = 0;
};
```
Which is both safe and readable.


## Can a destructor be virtual? 
Which is both safe and readable.

```
class Base 
{
    // some virtual methods
};

class Derived : public Base
{
    ~Derived()
    {
        // Do some important cleanup
    }
};
```
Here, you'll notice that I didn't declare Base's destructor to be virtual. Now, let's have a look at the following snippet:

```
Base *b = new Derived();
// use b
delete b; // Here's the problem!
```

Virtual destructors are useful when you might potentially delete an instance of a derived class through a pointer to base class:

class Base 
{
    // some virtual methods
};

class Derived : public Base
{
    ~Derived()
    {
        // Do some important cleanup
    }
};
Here, you'll notice that I didn't declare Base's destructor to be virtual. Now, let's have a look at the following snippet:

Base *b = new Derived();
// use b
delete b; // Here's the problem!
Since Base's destructor is not virtual and b is a Base* pointing to a Derived object, delete b has undefined behaviour:

[In delete b], if the static type of the object to be deleted is different from its dynamic type, the static type shall be a base class of the dynamic type of the object to be deleted and the static type shall have a virtual destructor or the behavior is undefined.

In most implementations, the call to the destructor will be resolved like any non-virtual code, meaning that the destructor of the base class will be called but not the one of the derived class, resulting in a resources leak.

To sum up, always make base classes' destructors virtual when they're meant to be manipulated polymorphically.

If you want to prevent the deletion of an instance through a base class pointer, you can make the base class destructor protected and nonvirtual; by doing so, the compiler won't let you call delete on a base class pointer.

