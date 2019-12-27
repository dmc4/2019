//1
//  main.cpp
//  alg_q1
//
//  Created by Toby on 19/12/19.
//  Copyright © 2019 Toby. All rights reserved.
//
//ref: https://drawar.github.io/karatsuba-cpp/
#include <iostream>
#include <cstring>
#include <sstream>  //todo
#include <algorithm>

using namespace std;

string add(string i1, string i2)
{
    string result;
    int length = max(i1.size(), i2.size());
    while (i1.size() < length)
      i1.insert(0,"0");
            
    while (i2.size() < length)
      i2.insert(0,"0");
    
    
    int carry = 0;
    int sum;  // sum of two digits in the same column
    for (int i = length-1; i >= 0; i--)
    {
        int aInt = 0, bInt = 0;
        aInt = stoi(i1.substr(i, 1));
        bInt = stoi(i2.substr(i, 1));
        sum = aInt + bInt + carry;
        carry = sum/10;
        result.insert(0,to_string(sum % 10));
    }
    
    if (carry)
      result.insert(0,to_string(carry));
    
    // remove leading zeros
    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
    
}

//assume i1 > i2
string subs(string i1, string i2)
{
    string result;
    int length = max(i1.size(), i2.size());

    while (i1.size() < length)
      i1.insert(0,"0");

    while (i2.size() < length)
      i2.insert(0,"0");

    int diff;
    for (int i = length-1; i >= 0; i--)
    {
        int aInt = 0, bInt = 0;
        aInt = stoi(i1.substr(i, 1));
        bInt = stoi(i2.substr(i, 1));
        diff = aInt - bInt;
        if (diff >= 0)
        {
            result.insert(0, to_string(diff));
        }
        else
        {
            // borrow from the previous column
            int j = i - 1;
            while (j >= 0)
            {
                
                i1[j] = ((i1[j]-'0') - 1) % 10 + '0';
                if (i1[j] == '/')
                {
                    i1[j] = '9';
                    j--;
                }
                else
                    break;
            }
            result.insert(0, to_string(diff+10));
        }

    }

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}


string km(string i1, string i2)
{
    //stuff smaller number with 0
    int length = max(i1.size(), i2.size());

    while (i1.size() < length)
      i1.insert(0,"0");

    while (i2.size() < length)
      i2.insert(0,"0");

    //base case
    //if (length == 1)
    //    return to_string((a[0]-'0')*(b[0]-'0'));
    if (length == 1)
    {
        int aInt = 0, bInt = 0;
        aInt = stoi(i1);
        bInt = stoi(i2);
        return to_string(aInt * bInt);
    }
    
    //split the number
    string a = i1.substr(0,length/2);
    string b = i1.substr(length/2,length-length/2);
    string c = i2.substr(0,length/2);
    string d = i2.substr(length/2,length-length/2);
    
    string ac = km(a, c);
    string bd = km(b, d);
    string aPbTcPd = km(add(a,b),add(c,d));
    string P321 = subs(aPbTcPd,add(ac,bd)); //aPbTcPd must > ac + bd
    
    for (int i = 0; i < 2*(length-length/2); i++)
        ac.append("0");
    for (int i = 0; i < length-length/2; i++)
        P321.append("0");
    
    string result = add(add(ac,bd),P321);

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}


int main(int argc, const char * argv[]) {

    string firstNum, secondNum;

    std::cout << "the first number: ";
    cin>>firstNum;
    
    cout<< "the second number: ";
    cin>>secondNum;
    
    //'' "" difference cout<<'a';
    
    cout<<km(firstNum, secondNum);
    
    return 0;
}
