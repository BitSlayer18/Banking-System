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
bool is_phone_valid(string phone){
    if(phone.length() != 10) return false;
    for(char c:phone){
        if(c - '0' < 0 || c - '0' > 9){
            return false;
        }
    }
    return true;
}
bool is_Valid_Email(string email) {
    if (email.find(' ') != string::npos) return false;
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);
    return atPos != string::npos && dotPos != string::npos &&
           atPos > 0 && dotPos > atPos + 1 &&
           dotPos < email.length() - 1 &&
           email[atPos - 1] != '.' && email[atPos + 1] != '.';
}

bool isLeapYear(int year) {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0)
                return true;
            else
                return false;
        }else
            return true;
    }else
        return false;
}

bool isValid(Date date) {
    if(date.year < 1) return false;
    if(date.month < 1 || date.month > 12) return false;
    int days;
    switch (date.month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
            days = isLeapYear(date.year) ? 29 : 28;
            break;
        default:
            return false;
    }
    if(date.day < 1 || date.day > days) return false;
    return true;
}
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