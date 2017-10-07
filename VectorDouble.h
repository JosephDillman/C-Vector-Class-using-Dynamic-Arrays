#ifndef VectorDouble_H
#define VectorDouble_H

#include <iostream>
using namespace std;

// class to mimic the type "vector" using arrays 
class VectorDouble
{
    public:
        VectorDouble();                    
        // constructor to assign length 50  
        
        VectorDouble(int);                
        // constructor to assign length int
        
        VectorDouble(const VectorDouble&); 
        // copy constructor to make new VectorDouble from array 
        
        ~VectorDouble();                   
        // destructor
        
        void push_back(double);            
        // Add element to last open cell
        
        double value_at(int i);            
        // return ith element
        
        VectorDouble& operator=(const VectorDouble&);
        // overloaded assignment operator 
        
        friend bool operator ==(const VectorDouble& v1, const VectorDouble& v2);
        // overloaded logical equals operator 
        
        void change_value_at(double d, int i);   
        // replaces ith element with double d 
        
        int size();                        
        // return number of elements in Vector Double
        
        int capacity();
        // returns allocated space in vector
        
        void reserve(int i);
        // increases allocated space in VectorDouble, if int i is less than 
        // current number of elements then nothing is done. If i is greater, 
        // then excess elements are initialized to 0
        
        void resize(int i);
        // if i is smaller than current count, all data after the ith element 
        // is erased. If i is greater than current count or max_count, all 
        // excess cells are initialized to 0
        
        void resize(int i, double d);
        // similar to resize(int i) except if i is greater than count or 
        // max_count, all excess cells are initialized to d 
       
        
    private:
        int max_count;                     
        // Current number of cells allocated in memeory
        
        int count;                         
        // Number of elements in vector
        
        void NewMemory();                  
        // allocates twice the current amount of memory
        
        double* doubles;                   
        // Array pointer to represent vector 
};

#endif