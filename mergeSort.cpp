//
//  main.cpp
//  mergeSort
//
//  Created by Toby on 26/12/19.
//  Copyright © 2019 Toby. All rights reserved.
//

#include <iostream>

using namespace std;


template<typename T>
void mergeSort(const T arr[], int len)      //reference
{
    
    
}


//some review here
void f1(int *a)
{
    cout<<*a<<endl;
    
}

void f2(int &a)
{
    cout<<a<<endl;
    
}

int main(int argc, const char * argv[]) {
    
    int arraySize, *array;
    cout<<"Firstly, give the size of array: ";
    cin>>arraySize;
    
    array = new int [arraySize];
    if (array == nullptr)
        return 1;
    

    
    return 0;
}

