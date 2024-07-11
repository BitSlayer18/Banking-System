#pragma once
#include <iostream>
#include <stdio.h>
//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
struct Date{
    int day,month,year;
};
unordered_set <string> cardnumbers; 
int getid (string name){
    int ans = 0;
    int base = 1;
    //some prime number  larger will be good
    int val = 7;
    vector<int>letter(26);
    letter[0] = 1;
    for(int i = 1;i < 26;i++){
        letter[i] = letter[i - 1]*2 + i + 1;
    }
    for(char c:name){
        ans += (letter[c - 'a'] *base);
        base *= val;
    }
    return ans;
}
//Function to generate a 3 digit cvv
string CVV(){
    string val="";
    for(int i = 0;i < 3;i++){
        val += to_string(rand() % 10);
    }
    return val;
}
//Function to generate a 16 digit card number
string cardnumber(){
    string val  = "";
    do {
        for (int i = 0; i < 16; ++i) {
            val += to_string(rand() % 10);
        }
    } while (cardnumbers.find(val) != cardnumbers.end()); // Ensure uniqueness

    cardnumbers.insert(val);
    return val;
}