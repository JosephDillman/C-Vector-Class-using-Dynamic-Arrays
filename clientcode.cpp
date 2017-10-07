// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____Joseph Dillman____ _____September 30, 2017______________
//
// ____ 301317623______
//
// (if this is group project, please list all the team members at the following space:
//
// _____Cyrus WaChong____ _____September 30, 2017______________
//
// ____301306459______
/**
* @file hw1.cpp
* @author Cyrus WaChong, Joseph Dillman
* @date October 2,2017
* @version 1
*
* @brief <ENSC 251, Lab 1>
*
* @section DESCRIPTION
*
* <DESCRIPTION FOR THIS CODE>
* In this code the class VectorDouble is used to shown to mimick the 'Vector'  
* class in C++. The VectorDouble class is based on dynamically allocated arrays 
* in order to provide the same functions as a vector. Constructor, destructors,
* overloaded operators, and numerous member functions will make the use of this
* class seamless and easy.
*/

#include <iostream>
using namespace std;
#include "VectorDouble.h"

// main function 
int main()
{
    
    VectorDouble inputtedVal;
    double value;
    int memory;
    int value3;
    int elementValue;
    int newValue;
    
    cout << "The following text output will showcase the functionality\n";
    cout << "of the VectorDouble class. See int main() source code for\n";
    cout << "details. After the text is outputted, you the user may enter\n";
    cout << "their own data to create the VectorDouble class\n\n";

    cout << "First, to showcase the constructors\n";

    VectorDouble v1;

    cout << "VectorDouble v1 has been initialized with the first constructor\n";
    cout << "taking no parametetrs. It has been automatically been initialized\n";
    cout << "to count zero and max_count 50\n";
    cout << v1.size() << " " << v1.capacity() << endl << endl;

    VectorDouble v2(30);

    cout << "VectorDouble v2 has been initialized with the second constructor\n";
    cout << "taking parametetr int 30. It has been automatically been initialized\n";
    cout << "to a count of zero and max_count 30\n";

    cout << v2.size() << " " << v2.capacity() << endl << endl;

    VectorDouble v3;

    for(int i =0; i < 20; i++)
    {
        v3.push_back(i);
    }

    cout << "VectorDouble v3 will be copied to v4 via the copy constructor\n";
    cout << "v3 is 20 counts long holding values that start at 1 and increment\n";
    cout << "by one. v3 looks like: " << endl;

    for(int j = 0; j < 20; j++)
    {
        cout << v3.value_at(j) << " ";
    }

    cout << "v3 size and capacity is: " << v3.size() << " " << v3.capacity() << endl << endl;

    VectorDouble v4(v3);

    cout << "VectorDouble v4 was initialied via copy constructor, it is identical to\n";
    cout << "v3. It's size and capacity is: " << v4.size() << " " << v4.capacity() << endl;
    cout << "and it looks like: \n\n";

    for(int j = 0; j < 20; j++)
    {
        cout << v3.value_at(j) << " ";
    }

    cout << endl << endl;
    cout << "At this point, functions value_at() and push_back() have been used\n";
    cout << "in initializing and displaying v3. But for the sake of this output\n";
    cout << "We can add a 12.52 to the end of v4 and then retrieve the 20th element\n";

    double l = 12.52;
    v4.push_back(l);

    cout << "The 20th element is: " << v4.value_at(20) << endl << endl;

    cout <<"We can then resize v4 back to 20 elements (before it was 21) using\n";
    cout << "the resize() function. Then show it is equal to v3 with the overlaoded\n";
    cout << " == operator\n";
    v4.resize(20);
    cout << "The logical exression (v4 == v3) returns: " << (v4==v3);

    cout << "\n However, (v1 == v4) will return: " << (v4==v1);

    cout << "\n\n We can also use the resize to increase the max number of elements\n";
    cout << "For example, we can now allocate v4 to 60 cells\n";
    v4.resize(60);
    cout << "v4 size and capacity is: " << v4.size() << " " << v4.capacity();

    cout << "\n\n We can also use resize(100,12.5) to make all new elements past\n";
    cout << "the original count equal to 12.5\n";
    v4.resize(100, 12.5);
    cout << "v4 now looks like\n\n";
    for(int i =0; i<100; i++)
    {
        cout << v4.value_at(i) << " ";
    }

    cout << endl << endl << "We can also use the change_value_at() function to\n";
    cout << "make edits to specidic cells. Let's change element 5 and 30 to 0.111\n";
    v4.change_value_at(0.111, 5);
    v4.change_value_at(0.111, 30);
    cout << "v4 now looks like\n\n";
    for(int i =0; i<100; i++)
    {
        cout << v4.value_at(i) << " ";
    }

    cout << endl << endl  << "We can also use the overlaoded = operator to copy an array \n";
    cout << "v5 will be copied from v4, it looks like : \n";
    VectorDouble v5;
    v5 = v4;
    for(int i =0; i<100; i++)
    {
        cout << v5.value_at(i) << " ";
    }

    cout << "\n\nRight now v5 has a capacity of " << v5.capacity();
    cout << "\nIf we write over the capcaity, it will automatically double its allocated\n";
    cout << "memory to ensure no lost data";
    v5.push_back(2);
    cout << "Since we've added an element to go over 100, its capacity is now " << v5.capacity();

    cout << "\n\nAnd thats all for this showcase, now enter your own data if you want to see this work!\n";
    cout << "We promise this script has not been hardcoded!\n\n\n";



    
    cout<< "\nThere has been a default 50 element array created\n";
    while (true)
    {
        cout << "Please enter (a) number(s) into the array, separate \n";
        cout << "numbers with either a space or an enter key. To finish \n";
        cout << "enterring numbers, enter a '-1' : " << endl << endl;
        
        while(true)
        {
            cin>>value;
            if(value == -1)
            {
                break;
            }
            inputtedVal.push_back(value);
        }
      
        cout << "Your Capacity is: " << inputtedVal.capacity()<< endl;
        cout << "Your Size is: " << inputtedVal.size() << endl;
        cout << "Your current array is: ";
        
        for(int i=0; i<inputtedVal.size(); i++)
        {
            cout << inputtedVal.value_at(i) << ", ";
        }
        cout << endl;
        
        cout<< "How many spots would you like to allocate to memory? ";
        cin >> memory;
        
        inputtedVal.reserve(memory);
        
        cout << endl <<"The capacity of you array is: " << inputtedVal.capacity() << endl;
        cout << "What size would you like to resize your vector to?\n";
        
        cin >> value3;
        inputtedVal.resize(value3);
        
        cout << "The size of your vector is: " << inputtedVal.size() << endl;
        
        
        cout << "What is the ith element you would like to swap? ";
        cin >> elementValue;
        cout << "With what value would you like to swap the element with? ";
        
        cin >> newValue;
        inputtedVal.change_value_at(newValue,elementValue-1);
        cout << "Your array is: ";
        
        for(int i=0; i<inputtedVal.size(); i++)
        {
            cout << inputtedVal.value_at(i) << ", ";
        }
            
    }
    return (0);
}

