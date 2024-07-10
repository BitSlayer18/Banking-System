#pragma once
#include <iostream>
#include <stdio.h>
//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <unordered_set>
#include "utilities.cpp"
using namespace std;
/* Here there are three types of the transactions
0 -> withdrwal 
1 -> deposit 
2 -> repayment of a loan installment
*/
class Transaction{
    public:
    int type_of_transaction;
    int account_type;
    string email;
    int amount;
    string account_number;
    Date d1;
    Transaction(string emai,int amoun,string account_numbe,int account_typ,int type_of_transactio,Date d){
        email = emai;
        amoun = amount;
        account_number = account_numbe;
        account_type = account_typ;
        type_of_transaction = type_of_transactio;
        d1 = d;
    }
};