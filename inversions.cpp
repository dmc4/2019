//
//  main.cpp
//  inversions
//
//  Created by Toby on 31/12/19.
//  Copyright © 2019 Toby. All rights reserved.
//

#include <iostream>
#include <fstream>      //复习 fstream 输出 输入位置
#include <vector>       //复习vector
#include <algorithm>

using namespace std;

//see pass reference
//todo istreambuf_iterator
void countfileLine(ifstream &f, string name)
{
    //f.seekg(f.beg);
    cout<<count(std::istreambuf_iterator<char>(f),
    std::istreambuf_iterator<char>(), '\n');
}


long int CountSplitInv(int *array, int size, int start)
{
    int * tempArr;
    tempArr = new int [size];
    
    int k = start, j = start + size/2;
    long int count = 0;
    
    int firstHalfSize, secondHalfSize;
    int firstLeft, secondLeft;
    int firstEnd, secondEnd;
    
    firstHalfSize = size /2 ;
    secondHalfSize = size - size/2;
    firstEnd = k + firstHalfSize;
    secondEnd = j + secondHalfSize;
    
    firstLeft = firstHalfSize;
    secondLeft = secondHalfSize;
    
    
    for (int i = 0; i < size; i++)
    {
        if (k >= start + size/2)
        {
            tempArr[i] = array[j];
            j++;
            continue;
        }
        
        if (j >= start + size && k < start + size/2)
        {
            tempArr[i] = array[k];
            k++;
            continue;
        }
        
        //first half bigger
        if (array[k] > array[j])
        {
            tempArr[i] = array[j];  //put second half
            j++;
            
            count = count + firstLeft;
            
            secondLeft--;
        }
        //second half bigger
        else if (array[k] < array[j])
        {
            tempArr[i] = array[k];
            k++;
            firstLeft--;
        }
        else if (array[k] == array[j])
        {
            tempArr[i] = array[k];
            k++;
            firstLeft--;
        }
        
    }
    
//    for (int i = 0; i < size; i++)
//    {
//        array[i + start];
//        cout<<array[i];
//    }

    //cout<<endl;
    for (int i = 0; i < size; i++)
    {
        array[i + start] = tempArr[i];
        //cout<<tempArr[i];
    }
    //cout<<endl;
    delete [] tempArr;
    
    return count;
}

long int SortAndCount(int *array, int size, int start)
{
    long int x = 0 , y = 0, z = 0;
    
    if (size == 1)
        return 0;
    
    x = SortAndCount(array, size/2, start); //quzheng
    y = SortAndCount(array, size - size/2, start + size/2);
    z = CountSplitInv(array, size, start);
    return x+y+z;
}




int main(int argc, const char * argv[]) {
    string fname = "/Users/toby/Desktop/alg/inversions/aaa.txt";
    ifstream f;
    int temp;
    vector<int> array;
    int *arrayAddress;
    
    //cout << "Give the file:";
    //cin >> fname;
    
    f.seekg(f.beg);
    f.open(fname);
    f>>temp;
    
    while (!f.eof())
    {
        array.push_back(temp);
        f>>temp;
    }
    
    
    cout<<array.size()<<endl;
    arrayAddress = new int [array.size()];
    copy(array.begin(), array.end(), arrayAddress);

//    for(int i = 0; i < array.size(); i++)
//    {
//        cout<<arrayAddress[i];
//
//    }

    long int res = SortAndCount(arrayAddress, array.size(), 0);
    cout<<endl<<res<<endl;

//    for(int i = 0; i < array.size(); i++)
//    {
//        cout<<arrayAddress[i];
//
//    }

    return 0;
}


