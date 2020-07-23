//
//  main.cpp
//  quick
//
//  Created by Toby on 3/2/20.
//  Copyright © 2020 Toby. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;

enum OPT {q1 = 1, q2 = 2, q3 = 3};

/*
void quickSort(list<int> inputArr)
{
    if (inputArr.size() <= 1)
        return;
    
    
    
}
*/
//do not consider equal
int findMid(pair<int, int> a, pair<int, int> b,pair<int, int> c)
{
    if ((a.second < b.second && b.second < c.second) || (c.second < b.second && b.second < a.second))
        return b.first;
    else if ((b.second < a.second && a.second < c.second) || (c.second < a.second && a.second < b.second))
        return a.first;
    else
        return c.first;
}



unsigned long quickSort(vector<int> &inArr, int start, int end, OPT q)
{
    unsigned long totalNum;
    unsigned long a, b, c; //to comp in this funtion and first and second half
    if (end - start <= 1)
        return 0;
    
//    if (q == q2)
//    {
//        cout<<"end: "<<end<<" start: "<<start<<endl;
//        for (int k = 0; k < inArr.size(); k++)
//            cout<<inArr[k]<<" ";
//    }
//    cout<<endl;
    
    int pivot;
    switch (q) {
        case q1:
            pivot = inArr[start];
            break;
        case q2:
            pivot = inArr[end - 1];
            swap(inArr[end - 1], inArr[start]);
            break;
       case q3:
            int pivotIndex;
            int mid, size;
            size = end - start;
            if (size % 2 == 0)
                mid = (size / 2) - 1 + start;
            else
                mid = (size / 2) + start;
            
            pivotIndex = findMid(pair<int, int>(start, inArr[start]), pair<int, int>(mid, inArr[mid]), pair<int, int>(end - 1, inArr[end - 1]));
            pivot = inArr[pivotIndex];
            //cout<<pivotIndex<<endl;
            swap(inArr[pivotIndex], inArr[start]);
            break;
    }
    
    
    
    
    int i = start + 1;
    int j;
    
    a = end - start - 1;
    
    for(j = i; j < end; j++)
    {
        if (inArr[j] < pivot)
        {
            swap(inArr[j], inArr[i]);
            i++;
        }
    }
    swap(inArr[start], inArr[i - 1]);
    
    b = quickSort(inArr, start, i - 1, q);
    c = quickSort(inArr, i, j, q);
    
    totalNum = a + b + c;
    return totalNum;
}



int main(int argc, const char * argv[]) {
    
    ifstream f("/Users/toby/Desktop/alg/quick/1.txt");
    //list<int> inputArr;
    int pivot, temp;
    unsigned long totalNum;

    vector<int> inArr;
    
    f>>temp;
    while (!f.eof())
    {
        inArr.push_back(temp);
        f>>temp;
    }
    
    vector<int> test = {1, 2, 3, 4, 5, 6, 7};
    
    //q1: 162085    q2:164123
    totalNum = quickSort(inArr, 0, inArr.size(), q3);
    cout<<totalNum<<endl;
//    for (int i = 0; i < test.size(); i++)
//    {
//        cout<<test[i]<<" ";
//
//    }
//    cout<<endl;
    
    //cout<<inArr.size();
    
//using list
//    totalNum = 0;
//    f>>pivot;
//    inputArr.push_back(pivot);
//
//    int i = 0;
//
//    f>>temp;
//    while (!f.eof())
//    {
//        if (temp >= pivot)
//            inputArr.push_back(temp);
//        else
//        {
//            inputArr.push_front(temp);
//            i++;
//        }
//        f>>temp;
//    }
    
    //cout<<i<<endl;
    //cout<<pivot<<endl;
    
    //https://thispointer.com/c-how-to-get-element-by-index-in-list/
    //advance
    //list<int>::iterator it=inputArr.begin();
    //advance(it, i);
    //cout<<*it;
    
    
    //totalNum = inputArr.size() - 1;


    return 0;
}

