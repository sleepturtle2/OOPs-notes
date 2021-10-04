#include<iostream>
using namespace std; 

int main(int argc, char *argv[])
{
    cout<<"You have entered "<<argc-1<<" argument(s)\n"; 

    for(int i=1; i<argc; i++)
    cout<<argv[i]<<"\n"; 
    return 0; 
}