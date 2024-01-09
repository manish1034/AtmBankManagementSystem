#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;

class bank{
    private:
        int pin;
        float balance;
        string id,pass,name,fname,address,phone;
    public:
        void menu();
        void bank_management();
        void atm_management();
        void new_user();
        void already_user();
        void deposit();
        void withdraw();
        void transfer();
        void payment();
        void search();
};

    void bank::menu(){
        p:
        system("cls");
        int choice;
        char ch;
        string pin,pass,email;
        cout<<"\n\n\t\t\tControl Panel";
        cout<<"\n\n 1. Bank Manangement";
        cout<<"\n 2. ATM Manangement";
        cout<<"\n 3. Exit";
        cout<<"\n\n Enter your choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"\n\n\t\t\tLogin Account";
            cout<<"\n\n Email : ";
            cin>>email;
            cout<<"\n\n Pin Code : ";
            for(int i=0; i<=5; i++){
                ch = getch();
                pin += ch;
                cout<<"*";
            }
            cout<<"\n\n Password : ";
            for(int i=0; i<=5; i++){
                ch = getch();
                pass += ch;
                cout<<"*";
            }
            if(email == "manishchandra1034@gmail.com" && pin == "137952" && pass == "137952"){
                bank_management();
            }
            else{
                cout<<"\n\n Your Email, Pin & Password is wrong!!";
            }
            break;
        case 2:
            atm_management();
            break;
        case 3:
            exit(0);
        default:
            cout<<"\n\n Invalid value... Please try again!!";
        }
        getch();
        goto p;
    }

    void bank::bank_management(){
        p:
        system("cls");
        int choice;
        cout<<"\n\n\t\t\tBank Management System";
        cout<<"\n\n 1. New User";
        cout<<"\n 2. Already User";
        cout<<"\n 3. Deposit Option";
        cout<<"\n 4. Withdraw Option";
        cout<<"\n 5. Transfer Option";
        cout<<"\n 6. Payment Option";
        cout<<"\n 7. Search User Record";
        cout<<"\n 8. Edit User Record";
        cout<<"\n 9. Delete User Record";
        cout<<"\n 10. Show All Records";
        cout<<"\n 11. Payment All Records";
        cout<<"\n 12. Go Back";
        cout<<"\n\n Enter Your Choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            new_user();
            break;
        case 2:
            already_user();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            transfer();
            break;
        case 6:
            payment();
            break;
        case 7:
            search();
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            menu();
        default:
            cout<<"\n\n Invalid value... Please try again!!";
        }
        getch();
        goto p;
    }

    void bank::atm_management(){
        p:
        system("cls");
        int choice;
        cout<<"\n\n\t\t\tATM Management System";
        cout<<"\n\n 1. User Login & Check Balance";
        cout<<"\n 2. Withdraw Amount";
        cout<<"\n 3. Account Details";
        cout<<"\n 4. Go Back";
        cout<<"\n\n Enter Your Choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            menu();
        default:
            cout<<"\n\n Invalid value... Please try again!!";
        }
        getch();
        goto p;
    }

    void bank::new_user(){
        p:
        system("cls");
        fstream file;
        int p;
        float b;
        string n,f,pa,a,ph,i;
        cout<<"\n\n\t\t\tAdd New User";
        cout<<"\n\n User ID : ";
        cin>>id;
        cout<<"\n\n\t\tName : ";
        cin>>name;
        cout<<"\n\n Father Name : ";
        cin>>fname;
        cout<<"\n\n\t\tAddress : ";
        cin>>address;
        cout<<"\n\n Pin code (5 digit) : ";
        cin>>pin;
        cout<<"\n\n\t\tPassword : ";
        cin>>pass;
        cout<<"\n\n Phone No. : ";
        cin>>phone;
        cout<<"\n\n\t\tCurrent Balance : ";
        cin>>balance;
        file.open("bank.txt",ios::in);
        if(!file){
            file.open("bank.txt",ios::app|ios::out);
            file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            file.close();
        }else{
            file>>i>>n>>f>>a>>p>>pa>>ph>>b;
            while(!file.eof()){
                if(i == id){
                    cout<<"\n\n User ID Already Exist!!!";
                    getch();
                    goto p;
                }
                file>>i>>n>>f>>a>>p>>pa>>ph>>b;
            }
            file.close();
            file.open("bank.txt",ios::app|ios::out);
            file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            file.close();
        }
        cout<<"\n\n New User Added Successfully!!!";
    }

    void bank::already_user(){
        system("cls");
        fstream file;
        int found=0;
        string t_id;
        cout<<"\n\n\t\t\tAlready User Account";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\n File Opening Error!!!";
        }else{
            cout<<"\n\n User ID : ";
            cin>>t_id;
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(t_id == id){
                    system("cls");
                    cout<<"\n\n\t\t\tAlready User Account";
                    cout<<"\n\n User ID : "<<id<<"  Pin Code : "<<pin<<"  Password : "<<pass;
                    found++;
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            }
            file.close();
            if(found == 0){
                cout<<"\n\n User ID Can't Found...";
            } 
        }
    }

    void bank::deposit(){
        fstream file,file1;
        system("cls");
        int found=0;
        float dep;
        string t_id;
        cout<<"\n\n\t\t\tDeposite Amount Option";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\n File Opening Error...";
        }else{
            cout<<"\n\n User ID : ";
            cin>>t_id;
            file1.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(t_id == id){
                    cout<<"\n\n Amount For Deposit : ";
                    cin>>dep;
                    balance += dep;
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    found++;
                    cout<<"\n\n\t\t\tYour Amount "<<dep<<" Has Been Successfully Deposited!!!";
                }else{
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
            if(found == 0){
                cout<<"\n\n User ID Can't Found...";
            } 
        }
    }

    void bank::withdraw(){
        fstream file,file1;
        system("cls");
        int found=0;
        float with;
        string t_id;
        cout<<"\n\n\t\t\tDeposite Amount Option";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\n File Opening Error...";
        }else{
            cout<<"\n\n User ID : ";
            cin>>t_id;
            file1.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(t_id == id){
                    cout<<"\n\n Amount For Withdraw : ";
                    cin>>with;
                    if(with <= balance){
                        balance -= with;
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                        cout<<"\n\n\t\t\tYour Amount "<<with<<" Has Been Successfully Withdrawed!!!";
                    }else{
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                        cout<<"\n\n\t\t\tYour Current Balance "<<balance<<" is Less...";
                    }
                    found++;
                }else{
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
            if(found == 0){
                cout<<"\n\n User ID Can't Found...";
            } 
        }
    }

    void bank::transfer(){
        fstream file,file1;
        system("cls");
        int found=0;
        float amount;
        string s_id,r_id;
        cout<<"\n\n\t\t\tPayment Transfer Option";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\n File Opening Error...";
        }else{
            cout<<"\n\n Sender User ID for Transactiobn : ";
            cin>>s_id;
            cout<<"\n\n Receiver User ID for Transaction : ";
            cin>>r_id;
            cout<<"\n\n Enter Transaction Amount : ";
            cin>>amount;
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(s_id == id && amount <= balance){
                    found++;
                }
                else if(r_id == id){
                    found++;
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            }
            file.close();
            if(found == 2){
                file.open("bank.txt",ios::in);
                file1.open("bank1.txt",ios::app|ios::out);
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
                while(!file.eof()){
                    if(s_id == id && amount >= balance){
                        balance -= amount;
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    }
                    else if(r_id == id){
                        balance += amount;
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    }
                    else{
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    }
                    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
                }
                file.close();
                file1.close();
                remove("bank.txt");
                rename("bank1.txt","bank.txt");

            }else{
                cout<<"\n\n\t\t\tBoth Transaction User ID's & Balance Invalid!!!";
            }
        }
    }

    void bank::payment(){
        system("cls");
        fstream file,file1;
        int found=0;
        float amount;
        string b_name,t_id;
        SYSTEMTIME x;
        cout<<"\n\n\t\t\tBills Payment Option";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\n File Opening Error...";
        }else{
            cout<<"\n\n User ID : ";
            cin>>t_id;
            cout<<"\n\n Bill Name : ";
            cin>>b_name;
            cout<<"\n\n Bill Amount : ";
            cin>>amount;
            file1.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while (!file.eof()){
                if(t_id == id && amount <= balance){
                    balance -= amount;
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    found++;
                }else{
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            } 
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
            if(found == 1){
                GetSystemTime(&x);
                file.open("bill.txt",ios::app|ios::out);
                file<<t_id<<" "<<b_name<<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<"\n";
                file.close();
                cout<<"\n\n\t\t\t"<<b_name<<" Bill Paid Sucessfully...";
            }else{
                cout<<"\n\n\t\t\tUser ID or Amount Invalid...";
            }
        }
    }

    void bank::search(){
        system("cls");
        fstream file;
        int found=0;
        string t_id;
        cout<<"\n\n\t\t\tSearch User Record";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\n File Opening Error...";
        }else{
            cout<<"\n\n User ID : ";
            cin>>t_id;
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(t_id == id){
                    system("cls");
                    cout<<"\n\n\t\t\tSearch User Record";
                    cout<<"\n\n\n User ID : "<<id<<"    Name : "<<name<<"\n Father's Name : "<<fname;
                    cout<<"    Address : "<<address<<"\n Pin : "<<pin<<"    Password : "<<pass;
                    cout<<"\n Phone : "<<phone<<"    Current Balance : "<<balance;
                    found++;
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            }
            file.close();
            if(found == 0){
                cout<<"\n\n User ID Can't Found!!!";
            }
        }
    }

main(){
    bank obj;
    obj.menu();
}