#include <bits/stdc++.h>
using namespace std;

class User {
    public:
    string name;
    string email;
    long long int number;
    int date[3];
    int id=rand();
    int age;
    User(string e, string n, int m, int d, int mon, int y){
        email=e;
        name=n;
        number=m;
        date[0]=d;
        date[1]=mon;
        date[2]=y;
        time_t now=time(0);
        tm *ltm = localtime(&now);
        int year=1900 + ltm->tm_year;
        int month= 1 + ltm->tm_mon;
        int day= ltm->tm_mday;
        int age_temp=year-y;
        if(month==mon){
            if(day<d){
                age_temp--;
            }
        } else if(month<mon){
            age_temp--;
        }
        age=age_temp;
    }
};
vector<User> v;

class Account {
    public:
    string user_email;
    string account_type;
    int account_number=rand();
    int amount;
    string created_at;
    //Use a constructor instead of this function
    void Account:: setAccount(string em, string ty, int am, string cr){
    this->user_email=em;
    this->account_type=ty;
    this->amount=am;
    this->created_at=cr;
}
};

class SavingAccount: public Account {
    public:
    int card_number=rand();
    int cvv=123;
    SavingAccount(string e, string t, int a, string c){
        setAccount(e,t,a,c);
    }
};
vector<SavingAccount> sa;

class CurrentAccount: public Account {
    public:
    CurrentAccount(string e, string t, int a, string c){
        setAccount(e,t,a,c);
    }
};
vector<CurrentAccount> ca;

class LoanAccount: public Account {
    public:
    string loan_type;
    int interest_rate;
    LoanAccount(string e, string t, int a, string l, string c){
        setAccount(e,t,a,c);
        loan_type=l;
        if(l=="H"){
            interest_rate=7;
        } else if(l=="C"){
            interest_rate=8;
        } else if(l=="P"){
            interest_rate=12;
        } else if(l=="B"){
            interest_rate=15;
        }
    }
};
vector<LoanAccount> la;

// class Transaction: public SavingAccount, CurrentAccount, LoanAccount{
//     public:
//     int account_number;
//     string transaction_type;
//     string user_email;
//     int amount_trans;
//     void addTransaction();
// }

// void Transaction:: addTransaction(int ac, string ty, string em, int am){
    
// }

class Transaction {
    public:
    string transaction_type;
    int account_number;
    // int account_number_from;
    // int account_number_to;
    string user_email;
    int amount;
    string account_type;
    Transaction(string t, int a, string e, int am){
        transaction_type=t;
        account_number=a;
        user_email=e;
        amount=am;
    }
};

vector<Transaction> t;

int main(){
    string email_in;
    cout << "Enter email: ";
    cin >> email_in;
    bool exist=false;
    for( auto &usr: v){
        if(usr.email==email_in){
            cout << "welcome " << usr.name;
            exist=true;
            break;
        }
    }
    if(!exist){
        cout << "user does not exist";
        cout << "\n create user \n";
        string name;
        long long int number;
        int day, month, year;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\n Enter mobile number: ";
        cin >> number;
        cout << "\n Enter year of birth: ";
        cin >> year;
        cout << "\n Enter month of birth: ";
        cin >> month;
        cout << "\n Enter day of birth: ";
        cin >> day;
        User u(email_in, name, number, day, month, year);
        v.push_back(u);
        cout << "\n welcome " << u.email << endl; 
    }
    int a=1;
    while(a==1){
        cout << "Type 1 to create a new account \n";
        cout << "Type 2 to view personal details \n";
        cout << "Type 3 to view account details \n";
        cout << "Type 4 to make transaction into an account \n";
        cout << "Type 5 to view all transactions \n";
        int b;
        cin >> b;
        switch(b){
            case 1:
            {
                string t;
                int amount;
                int age;
                for(auto &usr:v){
                    if(usr.email==email_in){
                        age=usr.age;
                    }
                }
                time_t now = time(0);
                string dt = ctime(&now);
                cout << "Enter the type of account (S/C/L): ";
                cin >> t;
                if(t=="S"){
                    cout << "Enter amount: ";
                    cin >> amount;
                    if(amount<10000){
                        cout << "Minimum amount is 10,000";
                    } else {
                        SavingAccount ac(email_in, t, amount, dt);
                        sa.push_back(ac);
                        cout << "Saving account number " << ac.account_number << " created. \n";
                    }
                } else if(t=="C"){
                    if(age<18){
                        cout << "Minimum age is 18 \n";
                    } else {
                        cout << "Enter amount: ";
                        cin >> amount;
                        if(amount<50000){
                            cout << "Minimum amount is 50,000 \n";
                            break;
                        } else {
                            CurrentAccount ac(email_in, t, amount, dt);
                            ca.push_back(ac);
                            cout << "Current account number " << ac.account_number << " created. \n";
                        }
                    }
                } else if(t=="L"){
                    if(age<25){
                        cout << "Minimum age is 25 \n";
                    } else {
                        int total=0;
                        bool exists=false;
                        for(auto &acc: sa){
                            if(acc.user_email==email_in){
                                exists=true;
                                total+=acc.amount;
                            }
                        }
                        for(auto &acc: ca){
                            if(acc.user_email==email_in){
                                exists=true;
                                total+=acc.amount;
                            }
                        }
                        if(!exists){
                            cout << "You need either a savings account or a current account to create a loan account \n";
                        }else {
                        cout << "Enter amount: ";
                        cin >> amount;
                        if(amount<500000){
                            cout << "Minimum amount is 5,00,000 \n";
                        }
                        else {
                            if(amount<=0.4*total){
                                string l;
                                cout << "\nEnter loan type (H/C/P/B): ";
                                cin >> l;
                                LoanAccount ac(email_in, t, amount, l, dt);
                                la.push_back(ac);
                                cout << "\n Loan account number " << ac.account_number << " created. \n";
                            } else {
                                cout << "Maximum amount you can avail is 40% of your total deposit \n";
                            }
                        }
                        }
                    }
                }
                break;
            }
            case 2:
            {
                for(auto &usr: v){
                    if(usr.email==email_in) { 
                        cout << "\n User ID: " << usr.id;
                        cout << "\n Name: " << usr.name;
                        cout << "\n Email: " << usr.email;
                        cout << "\n Mobile number: " << usr.number;
                        cout << "\n Date of birth: " << usr.date[0] << "/" << usr.date[1] << "/" << usr.date[2];
                        cout << "\n Age: " << usr.age << endl;
                }
                break;
                }
            }
            case 3:
            {
                for(auto &acc: sa){
                    if(acc.user_email==email_in){
                        cout << acc.user_email << " " << acc.account_number << " " << acc.account_type << " " << acc.created_at << " " << acc.amount << "\n";
                    }
                }
                for(auto &acc: ca){
                    if(acc.user_email==email_in){
                        cout << acc.user_email << " " << acc.account_number << " " << acc.account_type << " " << acc.amount << "\n";
                    }
                }
                for(auto &acc: la){
                    if(acc.user_email==email_in){
                        cout << acc.user_email << " " << acc.account_number << " " << acc.account_type << " " << acc.amount << "\n";
                    }
                }
                break;
            }
            case 4:
            {
                int num;
                int amounta;
                string type;
                int total=0;
                cout << "Enter amount: ";
                cin>>num;
                for(auto &trans: t){
                    if(trans.account_number==num && trans.transaction_type=="W"){
                        total+=trans.amount;
                    }
                }
                cout << "Enter the type of transaction: ";
                cin >> type;
                // if(total+num>=50000 && type=="W"){
                //     cout << "Maximum 50,000 can be withdrawn in a day";
                // }
                cout << "Enter amount: ";
                cin >> amounta;
                for(auto &acc: sa){
                    if(acc.account_number==num){
                        if(type=="D"){
                            acc.amount+=amounta;
                            Transaction tr(type, num, email_in, amounta);
                            t.push_back(tr);
                        } else if(type=="W"){
                            if(acc.amount>amounta){
                                acc.amount-=amounta;
                                Transaction tr(type, num, email_in, amounta);
                            t.push_back(tr);
                            } else {
                                cout << "Insufficient balance \n";
                            }
                        }
                        break;
                    }
                }
                for(auto &acc: ca){
                    if(acc.account_number==num){
                        if(type=="D"){
                            acc.amount+=amounta;
                             Transaction tr(type, num, email_in, amounta);
                            t.push_back(tr);
                        } else if(type=="W"){
                            if(acc.amount>amounta){
                                acc.amount-=amounta;
                                 Transaction tr(type, num, email_in, amounta);
                            t.push_back(tr);
                            } else {
                                cout << "Insufficient balance \n";
                            }
                        }
                        break;
                    }
                }
                for(auto &acc: la){
                    if(acc.account_number==num){
                        if(type=="D"){
                            if(acc.amount>amounta && (amounta<=(0.1*acc.amount))){
                                acc.amount-=amounta;
                                Transaction tr(type, num, email_in, amounta);
                            t.push_back(tr);
                            } else if(acc.amount>amounta){
                                cout << "Loan amount is only " << acc.amount << endl;
                            } else if(amounta>0.1*acc.amount){
                                cout << "Max amount to deposit at once is " << 0.1*acc.amount << endl;
                            }
                        } else if(type=="W"){
                            cout << "Can't withdraw from loan account \n";
                        }
                        break;
                    }
                }
                break;
            }
            case 5:
            {
                for(auto &trans: t){
                    cout << trans.user_email << " " << trans.account_number << " " << trans.transaction_type << " " << trans.amount << endl;
                }
                break;
            }
        }
    }
}