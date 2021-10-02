# Constructors in C++

What is constructor? 
A constructor is a special type of member function of a class which initializes objects of a class. In C++, Constructor is automatically called when object(instance of class) create. It is special member function of the class because it does not have any return type.
How constructors are different from a normal member function?

A constructor is different from normal functions in following ways: 

- Constructor has same name as the class itself
- Constructors don’t have return type
- A constructor is automatically called when an object is created.
- It must be placed in public section of class.
- If we do not specify a constructor, C++ compiler generates a default constructor for object (expects no parameters and has an empty body).

Let us understand the types of constructors in C++ by taking a real-world example. Suppose you went to a shop to buy a marker. When you want to buy a marker, what are the options? The first one you go to a shop and say give me a marker. So just saying give me a marker mean that you did not set which brand name and which color, you didn’t mention anything just say you want a marker. So when we said just I want a marker so whatever the frequently sold marker is there in the market or in his shop he will simply hand over that. And this is what a default constructor is! The second method you go to a shop and say I want a marker a red in color and XYZ brand. So you are mentioning this and he will give you that marker. So in this case you have given the parameters. And this is what a parameterized constructor is! Then the third one you go to a shop and say I want a marker like this(a physical marker on your hand). So the shopkeeper will see that marker. Okay, and he will give a new marker for you. So copy of that marker. And that’s what copy constructor is!
Types of Constructors

## 1. Default Constructors: 
Default constructor is the constructor which doesn’t take any argument. It has no parameters.

```
// Cpp program to illustrate the
// concept of Constructors
#include <iostream>
using namespace std;
 
class construct
{
public:
    int a, b;
 
    // Default Constructor
    construct()
    {
        a = 10;
        b = 20;
    }
};
 
int main()
{
    // Default constructor called automatically
    // when the object is created
    construct c;
    cout << "a: " << c.a << endl
         << "b: " << c.b;
    return 1;
}
```

Output: 

a: 10
b: 20

Note: Even if we do not define 
any constructor explicitly, the 
compiler will automatically 
provide a default constructor 
implicitly.

## 2. Parameterized Constructors:

 It is possible to pass arguments to constructors. Typically, these arguments help initialize an object when it is created. To create a parameterized constructor, simply add parameters to it the way you would to any other function. When you define the constructor’s body, use the parameters to initialize the object. 

```
#include <iostream>
using namespace std;
 
class Point
{
private:
    int x, y;
 
public:
    // Parameterized Constructor
    Point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
 
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};
 
int main()
{
    // Constructor called
    Point p1(10, 15);
 
    // Access values assigned by constructor
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
 
    return 0;
}
```

Output: 

p1.x = 10, p1.y = 15
When an object is declared in a parameterized constructor, the initial values have to be passed as arguments to the constructor function. The normal way of object declaration may not work. The constructors can be called explicitly or implicitly.

 Example e = Example(0, 50); // Explicit call

 Example e(0, 50);           // Implicit call

Uses of Parameterized constructor: 
- It is used to initialize the various data elements of different objects with different values when they are created.
- It is used to overload constructors.

Can we have more than one constructor in a class?
       Yes, It is called Constructor Overloading.


## Copy Constructor:
A copy constructor is a member function that initializes an object using another object of the same class. A copy constructor has the following general function prototype: 

    ClassName (const ClassName &old_obj); 
Following is a simple example of copy constructor. 

```
#include<iostream>
using namespace std;
 
class Point
{
private:
    int x, y;
public:
    Point(int x1, int y1) { x = x1; y = y1; }
 
    // Copy constructor
    Point(const Point &p1) {x = p1.x; y = p1.y; }
 
    int getX()            {  return x; }
    int getY()            {  return y; }
};
 
int main()
{
    Point p1(10, 15); // Normal constructor is called here
    Point p2 = p1; // Copy constructor is called here
 
    // Let us access values assigned by constructors
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
    cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();
 
    return 0;
```


Output: 

p1.x = 10, p1.y = 15
p2.x = 10, p2.y = 15 

### When is  copy constructor called? 

In C++, a Copy Constructor may be called in the following cases: 
1. When an object of the class is returned by value. 
2. When an object of the class is passed (to a function) by value as an argument. 
3. When an object is constructed based on another object of the same class. 
4. When the compiler generates a temporary object.
It is, however, not guaranteed that a copy constructor will be called in all these cases, because the C++ Standard allows the compiler to optimize the copy away in certain cases, one example is the return value optimization (sometimes referred to as RVO). 

### When is a user-defined copy constructor needed? 
If we don’t define our own copy constructor, the C++ compiler creates a default copy constructor for each class which does a member-wise copy between objects. The compiler created copy constructor works fine in general. We need to define our own copy constructor only if an object has pointers or any runtime allocation of the resource like filehandle, a network connection..etc.
The default constructor does only shallow copy. 

Deep copy is possible only with user defined copy constructor. In user defined copy constructor, we make sure that pointers (or references) of copied object point to new memory locations.  

Copy constructor vs Assignment Operator 
Which of the following two statements call copy constructor and which one calls assignment operator? 

```

MyClass t1, t2;
MyClass t3 = t1;  // ----> (1)
t2 = t1;          // -----> (2)
```


Copy constructor is called when a new object is created from an existing object, as a copy of the existing object. Assignment operator is called when an already initialized object is assigned a new value from another existing object. In the above example (1) calls copy constructor and (2) calls assignment operator. See this for more details.

Write an example class where copy constructor is needed? 
Following is a complete C++ program to demonstrate use of Copy constructor. In the following String class, we must write copy constructor. 

```
#include<iostream>
#include<cstring>
using namespace std;
 
class String
{
private:
    char *s;
    int size;
public:
    String(const char *str = NULL); // constructor
    ~String() { delete [] s;  }// destructor
    String(const String&); // copy constructor
    void print() { cout << s << endl; } // Function to print string
    void change(const char *);  // Function to change
};
 
String::String(const char *str)
{
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}
 
void String::change(const char *str)
{
    delete [] s;
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}
 
String::String(const String& old_str)
{
    size = old_str.size;
    s = new char[size+1];
    strcpy(s, old_str.s);
}
 
int main()
{
    String str1("GeeksQuiz");
    String str2 = str1;
 
    str1.print(); // what is printed ?
    str2.print();
 
    str2.change("GeeksforGeeks");
 
    str1.print(); // what is printed now ?
    str2.print();
    return 0;
}
```

Output: 

GeeksQuiz
GeeksQuiz
GeeksQuiz
GeeksforGeeks
What would be the problem if we remove copy constructor from above code? 
If we remove copy constructor from the above program, we don’t get the expected output. The changes made to str2 reflect in str1 as well which is never expected. 

```
#include<iostream>
#include<cstring>
using namespace std;
 
class String
{
private:
    char *s;
    int size;
public:
    String(const char *str = NULL); // constructor
    ~String() { delete [] s;  }// destructor
    void print() { cout << s << endl; }
    void change(const char *);  // Function to change
};
 
String::String(const char *str)
{
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}
 
void String::change(const char *str)
{
    delete [] s;
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}
 
int main()
{
    String str1("GeeksQuiz");
    String str2 = str1;
 
    str1.print(); // what is printed ?
    str2.print();
 
    str2.change("GeeksforGeeks");
 
    str1.print(); // what is printed now ?
    str2.print();
    return 0;
}
```


Output: 

GeeksQuiz
GeeksQuiz
GeeksforGeeks
GeeksforGeeks

Can we make copy constructor private? 
Yes, a copy constructor can be made private. When we make a copy constructor private in a class, objects of that class become non-copyable. This is particularly useful when our class has pointers or dynamically allocated resources. In such situations, we can either write our own copy constructor like above String example or make a private copy constructor so that users get compiler errors rather than surprises at runtime. 
Why argument to a copy constructor must be passed as a reference? 
A copy constructor is called when an object is passed by value. Copy constructor itself is a function. So if we pass an argument by value in a copy constructor, a call to copy constructor would be made to call copy constructor which becomes a non-terminating chain of calls. Therefore compiler doesn’t allow parameters to be passed by value.

Why argument to a copy constructor should be const? 

When we create our own copy constructor, we pass an object by reference and we generally pass it as a const reference.
One reason for passing const reference is, we should use const in C++ wherever possible so that objects are not accidentally modified. This is one good reason for passing reference as const, but there is more to it. For example, predict the output of following C++ program. Assume that copy elision is not done by compiler.


```
#include<iostream>
using namespace std;

class Test
{
/* Class data members */
public:
Test(Test &t) { /* Copy data members from t*/}
Test()	 { /* Initialize data members */ }
};

Test fun()
{
	cout << "fun() Called\n";
	Test t;
	return t;
}

int main()
{
	Test t1;
	Test t2 = fun();
	return 0;
}

```

Output:

 Compiler Error in line "Test t2 = fun();" 
The program looks fine at first look, but it has compiler error. If we add const in copy constructor, the program works fine, i.e., we change copy constructor to following.


```
Test(const Test &t) { cout << "Copy Constructor Called\n"; }

```

Or if we change the line “Test t2 = fun();” to following two lines, then also the program works fine.

```
Test t2;
t2 = fun();

```

The function fun() returns by value. So the compiler creates a temporary object which is copied to t2 using copy constructor in the original program (The temporary object is passed as an argument to copy constructor). The reason for compiler error is, compiler created temporary objects cannot be bound to non-const references and the original program tries to do that. It doesn’t make sense to modify compiler created temporary objects as they can die any moment.

## Virtual Constructor in C++

The virtual mechanism works only when we have a base class pointer to a derived class object.

In C++, the constructor cannot be virtual, because when a constructor of a class is executed there is no virtual table in the memory, means no virtual pointer defined yet. So, the constructor should always be non-virtual.

But virtual destructor is possible.
Example Code

```
#include<iostream>
using namespace std;
class b {
   public:
      b() {
         cout<<"Constructing base \n";
      }
      virtual ~b() {
         cout<<"Destructing base \n";
      }
};
class d: public b {
   public:
      d() {
         cout<<"Constructing derived \n";
      }
      ~d() {
         cout<<"Destructing derived \n";
      }
};
int main(void) {
   d *derived = new d();
   b *bptr = derived;
   delete bptr;
   return 0;
}

```

Output

Constructing base

Constructing derived

Destructing derived

Destructing base


## Virtual Copy Constructor in C++

Before digging deep into the topics lets brush up all the related terms.

A copy constructor is a special type of constructor that is used to create an object that is an exact copy of the object that is passed.

A virtual function is a member function that is declared in the parent class and is redefined ( overridden) in a child class that inherits the parent class.

With the use of a virtual copy constructor, the programmer will be able to create an object without knowing the exact data type of the object.

In C++ programming language, copy Constructor is used to creating an object copied from another. but if you want the program to decide at the runtime about the type of object created i.e. that object type is defined at runtime, not at compile-time and is based on some input provided by the user for a certain condition. in this situation, We need a copy constructor with some special powers to do this thing. So so to do this virtual copy constructor is declared that offers the cloning of objects in real-time.

Let's take an example, Suppose we have a figure who is the area is to be found out using the program. but the type up of an object is defined as real-time that it can be a square rectangle or a circle. So we will use a virtual copy constructor that will copy the objects based on the type that the user inputted.

For virtual constructors to work properly there are two methods that are defined over the base class. they are −

```
clone()
create()
```

Copy constructor uses the virtual clone method whereas the virtual create method is used by the default constructors for creating a virtual constructor.

Example 
```
#include <iostream>
using namespace std;
class figure{
   public:
   figure() { }
   virtual
   ~figure() { }
   virtual void ChangeAttributes() = 0;
   static figure *Create(int id);
   virtual figure *Clone() = 0;
};
class square : public figure{
   public:
   square(){
      cout << "square created" << endl;
   }
   square(const square& rhs) { }
   ~square() { }
   void ChangeAttributes(){
      int a;
      cout<<"The side of square";
      cin>>a;
      cout<<"Area of square is "<<a*a;
   }
   figure *Clone(){
      return new square(*this);
   }
};
class circle : public figure{
   public:
   circle(){
      cout << "circle created" << endl;
   }
   circle(const circle& rhs) { }
   ~circle() { }
   void ChangeAttributes(){
      int r;
      cout << "enter the radius of the circle ";
      cin>>r;
      cout<<"the area of circle is "<<((3.14)*r*r);
   }
   figure *Clone(){
      return new circle(*this);
   }
};
class rectangle : public figure{
   public:
   rectangle(){
      cout << "rectangle created" << endl;
   }
   rectangle(const rectangle& rhs) { }
   ~rectangle() { }
   void ChangeAttributes(){
      int a ,b;
      cout<<"The dimensions of rectangle ";
      cin>>a>>b;
      cout<<"Area of rectangle is "<<a*b;
   }
   figure*Clone(){
      return new rectangle(*this);
   }
};
figure *figure::Create(int id){
   if( id == 1 ){
      return new square;
   }
   else if( id == 2 ){
      return new circle;
   }
   else{
      return new rectangle;
   }
}
class User{
   public:
   User() : figures(0){
      int input;
      cout << "Enter ID (1, 2 or 3): ";
      cin >> input;
      while( (input != 1) && (input != 2) && (input != 3) ){
         cout << "Enter ID (1, 2 or 3 only): ";
         cin >> input;
      }
      figures = figure::Create(input);
   }
   ~User(){
      if( figures ){
         delete figures;
         figures = 0;
      }
   }
   void Action(){
      figure *newfigure = figures->Clone();
      newfigure->ChangeAttributes();
      delete newfigure;
   }
   private:
   figure *figures;
};
int main(){
   User *user = new User();
   user->Action();
   delete user;
}
```

Output
Enter ID (1, 2 or 3): 2
circle created
enter the radius of the circle R 3
the area of circle is 28.26

## How constructors are different from a normal member function?
A constructor is different from normal functions in following ways:

Constructor has same name as the class itself
Constructors don’t have return type
A constructor is automatically called when an object is created.
If we do not specify a constructor, C++ compiler generates a default constructor for us (expects no parameters and has an empty body).


## Constructor Overloading 

To put it simply, you use multiple constructors for convenience (1st example) or to allow completely different initialization methods or different source types (2nd example.

You might need multiple constructors to implement your class to simply allow omitting some of the parameters that are already setup:

```
//The functionality of the class is not important, just keep in mind parameters influence it.
class AirConditioner{
   enum ConditionerMode{
      Automatic, //Default
      On,
      Off
   }
   public ConditionerMode Mode; //will be on automatic by default.
   public int MinTemperature = 18;
   public int MaxTemperature = 20;

   public AirConditioner(){ //Default constructor to use default settings or initialize manually.
      //Nothing here or set Mode to Automatic. 
   }

   //Mode
   public AirConditioner(ConditionerMode mode){ //Setup mode, but leave the rest at default
      Mode = mode;
   }
   //setup everything.
   public AirConditioner(ConditionerMode mode, int MinTemp, int MaxTemp){
      Mode = mode;
      MinTemperature = MinTemp;
      MaxTemperature = MaxTemp;
   }
}

```

To put it simply, you use multiple constructors for convenience (1st example) or to allow completely different initialization methods or different source types (2nd example.

You might need multiple constructors to implement your class to simply allow omitting some of the parameters that are already setup:
```
//The functionality of the class is not important, just keep in mind parameters influence it.
class AirConditioner{
   enum ConditionerMode{
      Automatic, //Default
      On,
      Off
   }
   public ConditionerMode Mode; //will be on automatic by default.
   public int MinTemperature = 18;
   public int MaxTemperature = 20;

   public AirConditioner(){ //Default constructor to use default settings or initialize manually.
      //Nothing here or set Mode to Automatic. 
   }

   //Mode
   public AirConditioner(ConditionerMode mode){ //Setup mode, but leave the rest at default
      Mode = mode;
   }
   //setup everything.
   public AirConditioner(ConditionerMode mode, int MinTemp, int MaxTemp){
      Mode = mode;
      MinTemperature = MinTemp;
      MaxTemperature = MaxTemp;
   }
}
```


Another example is when different constructors follow different procedures to initialize the variables. For instance you could have a data table that simply displays a table of text. The constructor could get the data from either database OR a file:



```
class DataTable{
   public DataTable(){} //Again default one, in case you want to initialize manually

   public DataTable(SQLConnection con, SQLCommand command){
      //Code to connect to database get the data and fill the table
   }

   public DataTable(File file){
      //Code to read data from a file and fill the table
   }
}
```