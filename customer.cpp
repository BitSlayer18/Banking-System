#pragma once
#include <iostream>
#include <stdio.h>
//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <unordered_set>
#include "Accounts.cpp"
using namespace std;
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
    }
};