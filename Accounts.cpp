#pragma once
#include <iostream>
#include <stdio.h>
//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <unordered_set>
#include "Transaction.cpp"
/*
0 -> Current Account
1 -> Savings Account
2 -> Loan Account
*/
using namespace std;
//Base class for the account of a customer
//Here account_type denotes the account type 
/*
0 -> Current Account
1 -> Savings Account
2 -> Loan Account
*/
class Account{
public:
    string email;
    Date creation_time;
    string account_number = cardnumber();
    int amount;
    int account_type;
    Account(string e,int ty,int a ,Date d){
        email = e;
        creation_time = d;
        amount = a;
        account_type = ty;
    }
};
//Derived Class for all the current accounts
class CurrentAccount:public Account{
    public:
    CurrentAccount(string e,int ty,int a,Date t) :Account(e,ty,a,t){
    }
};
//Derived Class for all the Savings Account
class SavingsAccount:public Account{
    public:
    string cvv = CVV();
    string Cardnumber = cardnumber();
    Date expiry_date;
    SavingsAccount(string e,int ty,int a ,Date t) :Account(e,ty,a,t){
        expiry_date = t;
        expiry_date.year += 16;
    }
};
//Derived Class for all the LoanAccounts
/*
The four number 0 , 1 ,2 and 3 defines the 4 loan types i.e 
0 -> Home Loan
1 -> Car Loan
2 -> Personal Loan
3 -> Business Loan
*/
class LoanAccount:public Account{
    public:
    int ltype;
    int interest;
    int loan_duration;
    int amount_due;
    LoanAccount(string e,int ty,int a , Date t,int ltype,int duration):Account(e,ty,a,t){
        if(ltype == 0) interest = 7;
        else if(ltype == 1) interest = 8;
        else if(ltype == 2) interest = 12;
        else if (ltype == 3) interest = 15;
        loan_duration = duration;
        amount_due = amount;
    } 
};
// Transaction class to store each type of the transactions
/* Here there are three types of the transactions
0 -> withdrwal 
1 -> deposit 
2 -> repayment of a loan installment
*/