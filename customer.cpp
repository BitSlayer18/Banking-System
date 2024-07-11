#pragma once
#include <iostream>
#include <stdio.h>
//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <unordered_set>
#include "Accounts.cpp"
using namespace std;
//int count = 1;
class Customer{
public:
    string firstName;
    string lastName;
    string email;
    string phone_number;
    string address;
    int customerId;
    int age;
    Date birth_date;
    vector<CurrentAccount> Current_Accounts;
    vector<SavingsAccount> Savings_Accounts;
    vector<LoanAccount> Loan_Accounts;
    vector<Transaction> transaction_history;
    Customer(string f,string l,string e,string p,string a,Date d1,int age1){
        firstName = f;
        lastName = l;
        email = e;
        phone_number = p;
        address = a;
        birth_date = d1;
        age = age1;
        customerId = getid(f);
        if(!isValid(birth_date)){
            cout << "Entered birth date is invalid" << endl;
            cout << "You will be assigned a default birth date" << endl;
            birth_date.day = 1 ;birth_date.month = 1;birth_date.year = 2000;
        }
        if(!is_phone_valid(phone_number)){
            cout << "Your entered phone number is incorrect or does not match the desired format" << endl;
        }
        if(!is_Valid_Email(email)){
            cout << "Your email is incorrect" << endl;
            string email_new = firstName + "_" + lastName;
            //email_new += count -'0';
            //count++;
            cout << "Try " << email_new << " as your new email" << endl;
            email = email_new;
        }
    }
};