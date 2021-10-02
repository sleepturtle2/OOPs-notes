# Difference between C structures and C++ structures

In C++, struct and class are exactly the same things, except for that struct defaults to public visibility and class defaults to private visibility. 
Some important differences between the C and C++ structures: 

Member functions inside structure: Structures in C cannot have member functions inside structure but Structures in C++ can have member functions along with data members.

### C Program to Implement Member functions inside structure

```
#include <stdio.h>
struct marks {
    int num;
    void
    Set(int temp)   // Member function inside Structure to
                    // take input and store it in "num"
    {
        num = temp;
    }
    void display()  //  function used to display the values
    {
        printf("%d", num);
    }
};
// Driver Program
int main()
{
    struct marks m1;
    m1.Set(9); // calling function inside Struct to
               // initialize value to num
    m1.display(); // calling function inside struct to
                  // display value of Num
}
 
/* Error Occured
prog.c:18:4: error: ‘struct marks’ has no member named ‘Set’
  m1.Set(9);  // calling function inside Struct to
initialize value to num
    ^
prog.c:19:4: error: ‘struct marks’ has no member named
‘display’ m1.display(); // calling function inside struct to
display value of Num
 */
```
This will generate an error in C but no error in C++. 


### C++ Program to Implement Member functions inside structure
 ```
#include <iostream>
using namespace std;
struct marks {
    int num;
    void
    Set(int temp) // Member function inside Structure to
                  // take input and store it in "num"
    {
        num = temp;
    }
    void display() //  function used to display the values
    {
        cout << "num=" << num;
    }
};
// Driver Program
int main()
{
    marks m1;
    m1.Set(9); // calling function inside Struct to
               // initialize value to num
    m1.display(); // calling function inside struct to
                  // display value of Num
}
 ```

Output
num=9

## Direct Initialization:
 We cannot directly initialize structure data members in C but we can do it in C++. 
 
 ```

// C program to demonstrate that direct
// member initialization is not possible in C
#include <stdio.h>
 
struct Record {
    int x = 7;
};
 
// Driver Program
int main()
{
    struct Record s;
    printf("%d", s.x);
    return 0;
}
/* Output :  Compiler Error
   6:8: error: expected ':', ', ', ';', '}' or
  '__attribute__' before '=' token
  int x = 7;
        ^
  In function 'main': */
  ```


```
// CPP program to initialize data member in c++
#include <iostream>
using namespace std;
 
struct Record {
    int x = 7;
};
 
// Driver Program
int main()
{
    Record s;
    cout << s.x << endl;
    return 0;
}
```

Output: 7

### Using struct keyword:
 In C, we need to use struct to declare a struct variable. In C++, struct is not necessary. For example, let there be a structure for Record. In C, we must use “struct Record” for Record variables. In C++, we need not use struct and using ‘Record‘ only would work.
Static Members: C structures cannot have static members but is allowed in C++. 

```

// C program with structure static member
struct Record {
    static int x;
};
 
// Driver program
int main()
{
    return 0;
}
/* 6:5: error: expected specifier-qualifier-list
   before 'static'
     static int x;
     ^*/
```

```
// C++ program with structure static member
 
struct Record {
    static int x;
};
 
// Driver program
int main()
{
    return 0;
}
```
This will generate an error in C but no error in C++. 



### Constructor creation in structure: Structures in C cannot have constructor inside structure but Structures in C++ can have Constructor creation.

```

// C program to demonstrate that Constructor is not allowed
#include <stdio.h>
 
struct Student {
    int roll;
    Student(int x)
    {
        roll = x;
    }
};
 
// Driver Program
int main()
{
    struct Student s(2);
    printf("%d", s.x);
    return 0;
}
/* Output :  Compiler Error
   [Error] expected specifier-qualifier-list
    before 'Student'
   [Error] expected declaration specifiers or
   '...' before numeric constant
   [Error] 's' undeclared (first use
   5555555555in this function)
   In function 'main': */
   ```

   ```
// CPP program to initialize data member in c++
#include <iostream>
using namespace std;
 
struct Student {
    int roll;
    Student(int x)
    {
        roll = x;
    }
};
 
// Driver Program
int main()
{
    struct Student s(2);
    cout << s.roll;
    return 0;
}
```

Output: 2


### sizeof operator:
 This operator will generate 0 for an empty structure in C whereas 1 for an empty structure in C++. 
 

```
// C program to illustrate empty structure
#include <stdio.h>
 
// empty structure
struct Record {
};
 
// Driver program
int main()
{
    struct Record s;
    printf("%lu\n", sizeof(s));
    return 0;
}
```
Output in C: 0

```

// C++ program to illustrate empty structure
#include <iostream>
using namespace std;
 
// empty structure
struct Record{   
};
 
// Driver program
int main() {
    struct Record s;
    cout<<sizeof(s);
    return 0;
}
```

Output in C++: 1


Note:   The default type of  sizeof  is long unsigned int , that’s why  “%lu” is used instead of “%d” in printf function.

### Data Hiding:
 C structures do not allow concept of Data hiding but is permitted in C++ as C++ is an object oriented language whereas C is not. 
 
### Access Modifiers:
 C structures do not have access modifiers as these modifiers are not supported by the language. C++ structures can have this concept as it is inbuilt in the language. 
 