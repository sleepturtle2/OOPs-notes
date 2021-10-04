#include<iostream>
#include<fstream>
using namespace std; 

int main()
{
    //writing to the file 
    ofstream myFile; 
    myFile.open("example.txt"); 
    myFile<<"Writing to this file\n"; 
    myFile.close(); 

    //reading from the file 
    string line; 
    ifstream readMyFile("example.txt"); 
    if(readMyFile.is_open())
    {
        while(getline(readMyFile, line))
        {
            cout<<line<<"\n";
        }
        myFile.close(); 
    }
    else 
    cout<<"Unable to open the file\n"; 
    return 0; 
}