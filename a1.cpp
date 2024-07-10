#include <iostream>
#include <stdio.h>
//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <unordered_set>
#include "utilities.cpp"
#include "customer.cpp""
using namespace std;
//All cards are valid till(last date of the year) 5 years from the date of being issued
//CVVs are being generated as random number
//Struct that stores the details of a transaction
//Function to generate at 3 digit cvv
// The set storing all the users present in the system
//Base class for the account of a customer
//Here account_type denotes the account type 
// Transaction class to store each type of the transaction

vector<Customer> Users;
int main(){
    cout << "Welcome" << endl;
    cout << "Enter email or username associated with your account" << endl;
    string email_entered;cin >> email_entered;
    bool isuser = false;
    Date dummy = {0,0,0};
    Customer current_customer("","","","","",dummy,0);
    for(auto &x:Users){
        if(x.email == email_entered){
            isuser = true;
            current_customer = x;
            cout << "Logging in" << x.firstName << " " << x.lastName << "....";
            break;
        }
    }
    if(isuser == false){
        cout << "No Data associated with the current customer" << endl;
        cout << "Creating new user" << endl;
        string firstname,lastname;
        string email,phone_number,address;
        int birth_day, birth_month, birth_year;
        cout << "Enter firstname and lastname (seprated by a space)" << endl;
        cin >> firstname >> lastname;
        int age;
        cout << "Enter your age" << endl; cin >> age;
        cout << "Enter your date of birth (dd mm yy )" << endl;
        cin >> birth_day >> birth_month >> birth_year;
        cout << "Enter your email" << endl; cin >> email;
        cout << "Enter your phone_number" << endl; cin >> phone_number;
        cout << "Enter your address" << endl; cin >> address;
        Date d1={birth_day,birth_month,birth_year};
        Customer new_customer(firstname,lastname,email,phone_number,address,d1,age);
        current_customer = new_customer;
        Users.push_back(current_customer);
        cout << "User created successfully" << endl;
    }
    while(1){
        //The user can perform manily 6 different types of operation depending on its need.
        cout << "Enter 0 for creating new account " << endl;
        cout << "Enter 1 for showing personal detail " << endl;
        cout << "Enter 2 to view account details " << endl;
        cout << "Enter 3 deposit into your accounts " << endl;
        cout << "Enter 4 to withdraw from your account " << endl;
        cout << "Enter 5 to repay a loan installment" << endl;
        int initial_input; cin >> initial_input;
        int t_day,t_month,t_year;
        cout << "Enter today's date (dd mm yy format)" << endl;
        cin >> t_day >> t_month >> t_year;
        Date today = {t_day,t_month,t_year};
        if(initial_input == 0){
            cout << "Creating new account please fill in the required details:" << endl;
            int account_type;
            /*
            0 -> Current Account
            1 -> Savings Account
            2 -> Loan Account
            */
            cout << "What type of account do you want to create ?" << endl;
            cin >> account_type;
            if(account_type == 0){
                int opening_amount;
                cout << "Enter the amount you want to open account with" << endl;
                cin >> opening_amount;
                cout << "Creating new current account..." << endl;
                if(current_customer.age < 18) cout << "Minimum age required is 18" << endl;
                else if(opening_amount < 50000) cout << "Minimum amount for opening a current account is 50000" << endl;
                else{
                    CurrentAccount newaccount(current_customer.email,account_type,opening_amount,today);
                    current_customer.Current_Accounts.push_back(newaccount);
                }
                cout << "Created a current account successfully..." << endl;
            }
            else if(account_type == 1){
                int opening_amount;
                cout << "Enter opening amount.." << endl;
                cin >> opening_amount;
                if(opening_amount < 10000) cout << "Minimum amount required to open the account is 10000" << endl;
                else{
                    SavingsAccount newaccount(current_customer.email,account_type,opening_amount,today);
                    current_customer.Savings_Accounts.push_back(newaccount);
                    cout << "Savings account created successfully" << endl;
                }
            }
            else if(account_type == 2){
                int total_money = 0;
                int loan_amount,loan_duration;
                cout << "Enter loan amount and duration of the loan(in yrs)" << endl;
                cin >> loan_amount >> loan_duration;
                if(current_customer.age < 25) cout << "Minimm age to open an account is 25" << endl;
                else if(loan_duration < 2) cout << "Minimum loan duration must be 2 years" << endl;
                else{
                    for(auto &a : current_customer.Current_Accounts) total_money += a.amount;
                    for(auto &a : current_customer.Savings_Accounts) total_money += a.amount;
                    if(loan_amount >0.4*total_money || loan_amount < 500000)
                    cout << "Either loan amount is too high or too low  or you don't have a savings or current account in the bank" << endl;
                    else{
                        int loan_type;
                        cout << "Enter which type of loan you want to take" << endl;
                        LoanAccount newaccount(current_customer.email,account_type,loan_amount,today,loan_type,loan_duration);
                        current_customer.Loan_Accounts.push_back(newaccount);
                        cout << "Loan account created successfully and required amount has been issued as loan" << endl;
                    }
                }
            }
            else {
                cout << "Invalid user input" << endl;
            }
        }
        else if(initial_input == 1){
            cout << "Customer Name: " << current_customer.firstName << " " << current_customer.lastName << endl;
            cout << "Customer email : " << current_customer.email << endl;
            cout << "Age :" << current_customer.age << endl;
            cout << "Phone number: " << current_customer.phone_number << endl;
            cout << "Adress: " << current_customer.address << endl;
        }
        else if(initial_input == 2){
            if(current_customer.Current_Accounts.size() != 0){
                cout << "Your Current Account are" << endl;
                for(auto &x : current_customer.Current_Accounts){
                    cout << "Account Number:" <<  x.account_number << endl << "Email:" << x.email << endl << "Account Balance:"<< x.amount << endl;
                }
            }
            else cout << "You do not have any Current Account" << endl;
            if(current_customer.Savings_Accounts.size() != 0){
                cout << "Your Savings Account are" << endl;
                for(auto &x : current_customer.Savings_Accounts){
                    cout << "Account Number:" <<  x.account_number << endl << "Email:" << x.email << endl << "Account Balance:"<< x.amount << endl;
                }
            }
            else cout << "You do not have any Savings Account" << endl;
            if(current_customer.Loan_Accounts.size() != 0){
                for(auto &x : current_customer.Loan_Accounts){
                    cout << "Your Loan Accounts are" << endl;
                    cout <<"Account Number :"<< x.account_number << endl<<"Email :" << x.email << endl << "Loan amount :" << x.amount << endl 
                    << "Loan duration :" << x.loan_duration << endl << "Loan Amount Due" << x.amount_due << endl;
                }
            }
            else cout << "You do not have any Loan Account" << endl;
        }
        else if(initial_input == 3){
            string ac_number;int amount_w;
            cout << "Enter account number of the bank" << endl;
            cin >> ac_number;
            cout << "Enter the amount you wish to withdraw" << endl;
            cin >> amount_w;
            for(auto &a :current_customer.Current_Accounts){
                if(a.account_number == ac_number && a.amount >= amount_w){
                    a.amount -= amount_w;
                    a.amount -= max(double(500),0.005*amount_w);
                    int penalty_months = 0;
                    for(auto &tr:current_customer.transaction_history){
                        if(tr.account_number== ac_number && tr.account_type == 0){
                            penalty_months += today.month - tr.d1.month;
                        }
                    }
                    a.amount -= penalty_months*500;
                    if(penalty_months)
                    cout << "You have deduted a penalty of 500 per month for past" << penalty_months << "months" << endl;
                    Transaction t(current_customer.email,amount_w,a.account_number,0,0,today);
                    current_customer.transaction_history.push_back(t);
                }
                else cout << "Insufficient account balance" << endl;
            }
            for(auto &a :current_customer.Savings_Accounts){
                if(a.account_number == ac_number && a.amount >= amount_w){
                    a.amount -= amount_w;
                    Transaction t(current_customer.email,amount_w,a.account_number,1,0,today);
                    current_customer.transaction_history.push_back(t);
                }
                else cout << "Insufficient account balance" << endl;
            }
        }
        else if(initial_input == 4){
            string ac_number;int amount_d;
            cout << "Enter account number of the bank" << endl;
            cin >> ac_number;
            cout << "Enter the amount you wish to deposit" << endl;
            cin >> amount_d;
            for(auto &a :current_customer.Current_Accounts){
                if(a.account_number == ac_number){
                    a.amount += amount_d;
                    Transaction t(current_customer.email,amount_d,a.account_number,0,1,today);
                    current_customer.transaction_history.push_back(t);
                }
            }
            for(auto &a :current_customer.Savings_Accounts){
                if(a.account_number == ac_number){
                    a.amount += amount_d;
                    Transaction t(current_customer.email,amount_d,a.account_number,1,1,today);
                    for(auto &tr:current_customer.transaction_history){
                        if(tr.account_number== ac_number && tr.account_type == 1){
                            if(t.d1.year != tr.d1.year){
                                a.amount += 0.06*a.amount;
                            }
                            break;
                        }
                    }
                    current_customer.transaction_history.push_back(t);
                }
            }
        }
        else if(initial_input == 5){
            string ac_number;int loan_installment;
            cout << "Enter the account number associated with your loan installment" << endl;
            cin >> ac_number;
            cout << "Enter the amount of installment you wish to pay(must be less than 10%)" << endl;
            cin >> loan_installment;
            for(auto &a:current_customer.Loan_Accounts){
                if(a.account_number == ac_number){
                    if(loan_installment > 0.1*a.amount) cout << "You can't pay more than 10% of the loan amount at once" << endl;
                    else{
                        a.amount_due -= min(loan_installment,a.amount_due);
                        Transaction t(current_customer.email,loan_installment,a.account_number,2,2,today);
                        current_customer.transaction_history.push_back(t);
                    }
                    if(a.amount_due == 0) cout << "Your loan is paid successfully";
                }
            }

        }
    }
}


