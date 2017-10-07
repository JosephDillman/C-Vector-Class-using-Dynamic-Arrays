#include <iostream>
#include "VectorDouble.h"
using namespace std;

VectorDouble::VectorDouble()
{
    max_count = 50;
    doubles = new double[max_count];
    count = 0;  //no elements yet
}

VectorDouble::VectorDouble(int i)
{
    max_count = i;
    doubles = new double[max_count];
    count = 0;  //no elements yet
}

VectorDouble::VectorDouble(const VectorDouble& v)
{
    max_count = v.max_count;}

VectorDouble::~VectorDouble()
{
    delete[] doubles;
}

void VectorDouble::push_back(double i)
{
    if (count + 1 > max_count)
    {
        NewMemory();
    }
    
    doubles[count] = i;
    count++;
}

double VectorDouble::value_at(int i)
{
    if ( i < 0 || i > count)
    {
        cerr << "ERROR: undefined vector cell, will return 0 ";
        return 0;
    }
    return doubles[i];
}

VectorDouble& VectorDouble::operator=(const VectorDouble& v)
{
    max_count = v.max_count;
    count = v.count;
    delete[] doubles;
    doubles = new double[max_count];
    for( int i =0; i < v.count; i++)
    {
        doubles[i] = v.doubles[i];
    }
    return *this;
}

bool operator ==(const VectorDouble& v1, const VectorDouble& v2)
{
    int  x = v1.count;
    for(int i = 0; i < x; i++)
    {
        if(v1.doubles[i] != v2.doubles[i])
        {
            return false;
        }
    }
    return true;
}

void VectorDouble::change_value_at(double d, int i)
{
    if ( i < 0 || i > count)
    {
        cerr << "ERROR: undefined vector cell, will return 0";
    }
    doubles[i] = d;
}

int VectorDouble::size()
{
    return count;
}

int VectorDouble::capacity()
{
    return max_count;
}

void VectorDouble::reserve(int i)
{
    if( i > max_count)
    {
        double* tmp = new double[i];
        max_count = i;
        for(int j = 0; j < i; j++ )
        {
            tmp[j] = doubles[j];
        }
        delete[] doubles;
        doubles = tmp;
    }
}

void VectorDouble::resize(int i)
{
    double* tmp = new double[i];
    if (i < count)
    {
        for(int j =0; j < i; j++ )
        {
            tmp[j] = doubles[j];
        }
    }
    
    else if( i > count)
    {
        for(int j =0; j < i; j++ )
        {
            if(j < count)
            {
                tmp[j] = doubles[j];
            }
            else
            {
                tmp[j] = 0;
            }
        }
    }
    
    else
    {
        delete[] tmp;
        return;
    }
    
    count = i;
    max_count = i;
    delete[] doubles;
    doubles = tmp;
}

void VectorDouble::resize(int i, double d)
{
    double* tmp = new double[i];
    if (i < count)
    {
        for(int j =0; j < i; j++ )
        {
            tmp[j] = doubles[j];
        }
    }
    
    else if( i > count)
    {
        for(int j =0; j < i; j++ )
        {
            if(j < count)
            {
                tmp[j] = doubles[j];
            }
            else
            {
                tmp[j] = d;
            }
        }
    }
    
    else
    {
        delete[] tmp;
        return;
    }
    
    count = i;
    max_count = i;
    delete[] doubles;
    doubles = tmp;
}

void VectorDouble::NewMemory()
{
    max_count = count*2;
    double* tmp = new double[max_count];
    for( int i =0; i < count; i++)
    {
        tmp[i] = doubles[i];
    }
    
    delete[] doubles;
    doubles = tmp;
}