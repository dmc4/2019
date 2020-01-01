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

using namespace std;

int main(int argc, const char * argv[]) {
    string fname;
    ifstream f;
    int temp;
    vector<int> array;
    
    cout << "Give the file:";
    cin >> fname;
    
    f.open(fname);
    f>>temp;
    
    while (!f.eof())
    {
        array.push_back(temp);
        f>>temp;
    }
    
    cout<<array.size()<<endl;

    
    
    return 0;
}

