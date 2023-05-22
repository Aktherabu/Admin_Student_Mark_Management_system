#ifndef STUDENTPAGE_H
#define STUDENTPAGE_H

#include "myheader.h"
#include "main.cpp"
#include "studentlogged.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<thread>
#include<chrono>
#include<sstream>


using namespace std;

int main();
void student_login();
void student_register();
void forget_password();
void student_logged();


void student_page()
{
    int choice;
    //system("CLS");
    Coordinate(0,1);
    printEqualLine();
    Coordinate(15,2);//Now cursor goes to left to right in 10th position
    cout<<"STUDENT PAGE";
    Coordinate(0,3);
    printEqualLine();

    Coordinate(0,4);
    cout<<"Select the Choice";
    Coordinate(3,6);
    cout<<"<Enter 1>... Login ";
    Coordinate(3,8);
    cout<<"<Enter 2>... Register ";
    Coordinate(3,10);
    cout<<"<Enter 3>... Switch User ";
    Coordinate(3,12);
    cout<<"<Enter 0>... Exit ";

    Coordinate(0,14);
    cout<<"Enter Your Choice: ";
    //endline should be marked before getting input
    Coordinate(0,16);
    printEqualLine();
    //positioning input cursor should be at exact point after the text/char ends ie : -> here
    Coordinate(18,14);
    cin>>choice;

    switch(choice)
    {
    case 0:
        exit(0);
        break;
    case 1:
        system("CLS");
        student_login();
        break;
    case 2:
        system("CLS");
        student_register();
        break;
    case 3:
        //switch_user
        system("CLS");
        main();
        break;
    default:
        system("CLS");
        cout<<"Oops Try to enter correct choice";
        student_page();
    }
}
void student_register()
{
    string r_user_id,r_user_name,r_password,r_confirm_password,r_email_id;
    string r_phone_no;
    string age,r_dob;

    //system("CLS");
    Coordinate(0,1);
    printEqualLine();
    Coordinate(10,2);
    cout<<"Please Enter the Following details: ";
    Coordinate(0,3);
    printEqualLine();

    Coordinate(0,4);
    cout<<"User Name";
    Coordinate(18,4);
    cout<<":";
    Coordinate(0,5);
    printunderLine();
    Coordinate(0,6);
    cout<<"Mail Id";
    Coordinate(18,6);
    cout<<":";
    Coordinate(0,7);
    printunderLine();
    Coordinate(0,8);
    cout<<"DOB";
    Coordinate(18,8);
    cout<<":";
    Coordinate(0,9);
    printunderLine();
    Coordinate(0,10);
    cout<<"Age";
    Coordinate(18,10);
    cout<<":";
    Coordinate(0,11);
    printunderLine();
    Coordinate(0,12);
    cout<<"Phone";
    Coordinate(18,12);
    cout<<":";
    Coordinate(0,13);
    printunderLine();
    Coordinate(0,14);
    cout<<"Password";
    Coordinate(18,14);
    cout<<":";
    Coordinate(0,15);
    printunderLine();
    Coordinate(0,16);
    cout<<"Confirm Password";
    Coordinate(18,16);
    cout<<":";
    Coordinate(0,17);
    printunderLine();


    //inputing
    Coordinate(19,4);
    cin>>r_user_name;

    Coordinate(19,6);
    cin>>r_email_id;

    Coordinate(19,8);
    cin>>r_dob;

    Coordinate(19,10);
    cin>>age;

    Coordinate(19,12);
    cin>>r_phone_no;

    Coordinate(19,14);
    cin>>r_password;

    Coordinate(19,16);
    cin>>r_confirm_password;

    if(r_password == r_confirm_password)
    {
        ofstream rfile("studentDetails.txt",ios::app);
        rfile<<r_user_name<<' '<<r_email_id<<' '<<r_dob<<' '<<age<<' '<<r_phone_no<<' '<<r_password<<' '<<endl;
        rfile.close();
        system("CLS");
        cout<<"Registration Successful";
        student_page();
    }
    else
    {
        system("CLS");
        cout<<"Password Doesn't match";
        student_register();
    }
}
void student_login()
{
    Coordinate(0,1);
    printEqualLine();
    Coordinate(10,2);
    cout<<"Enter User name/User id and Password to Login";
    Coordinate(0,3);
    printEqualLine();

    string l_user,l_password;
  //  string username, id, password;

    Coordinate(0,4);
    cout<<"User name/id ";
    Coordinate(15,4);
    cout<<":";
    Coordinate(0,5);
    printunderLine();

    Coordinate(0,6);
    cout<<"PassWord ";
    Coordinate(15,6);
    cout<<":";
    Coordinate(0,7);
    printunderLine();


    Coordinate(16,4);
    cin>>l_user;

    Coordinate(16,6);
    cin>>l_password;

    int flag = 0;
    //int option;

    ifstream lfile("studentDetails.txt");

    if(!lfile.is_open())
    {
        Coordinate(0,8);
        cout<<"Failed to open Fail";
        //return 1;
    }

    string line;
    while(getline(lfile,line))
    {
        //tokenzing the line
        stringstream ss(line);
        string username,id,dob,age,ph,password;
        ss>>username>>id>>dob>>age>>ph>>password;

        if((username==l_user || id ==l_user) && password == l_password)
        {
            flag = 1;

        }
    }

    lfile.close();
    static int attempts = 3;
    if(flag == 1)
    {
        system("CLS");
        //Coordinate(0,9);
        student_logged();
        //cout<<"Login Successful";
        //break;
    }
    else //if (flag==0 && option =="N")
    {
        Coordinate(0,8);
        cout<<"Login Failed";
        while(attempts!=0)
        {
            string option;
            Coordinate(0,9);
            cout<<"Forget Password (Y/N): ";
            Coordinate(23,9);
            cin>>option;

            if(option=="Y")
            {
                system("CLS");
                cout<<"Forget Password";
                forget_password();
                break;
            }
            else
            {
                system("CLS");
                --attempts;
                cout<<"Login Failed Attempts Left"<<attempts;
                student_login();
            }
        }
    }
}
void forget_password()
{
    Coordinate(0,1);
    printEqualLine();
    Coordinate(10,2);
    cout<<"Forget Password Don't Worry";
    Coordinate(0,3);
    printEqualLine();

    string f_user,f_id,f_dob;

    Coordinate(0,4);
    cout<<"User name";
    Coordinate(15,4);
    cout<<":";
    Coordinate(0,5);
    printunderLine();

    Coordinate(0,6);
    cout<<"User id";
    Coordinate(15,6);
    cout<<":";
    Coordinate(0,7);
    printunderLine();

    Coordinate(0,8);
    cout<<"Date of Birth";
    Coordinate(15,8);
    cout<<":";
    Coordinate(0,9);
    printunderLine();

    //inputing
    Coordinate(16,4);
    cin>>f_user;
    Coordinate(16,6);
    cin>>f_id;
    Coordinate(16,8);
    cin>>f_dob;

    int flag =0;

    ifstream ffile("studentDetails.txt");

    if(!ffile.is_open())
    {
        Coordinate(0,8);
        cout<<"Failed to open Fail";
        //return 1;
    }
    else
    {
        string f_line;
        while(getline(ffile,f_line))
        {
            stringstream ss(f_line);
            string username,id,dob,age,ph,password;
            ss>>username>>id>>dob>>age>>ph>>password;

            if(username==f_user && id ==f_id && dob == f_dob)
            {
                flag = 1;
                Coordinate(0,10);
                cout<<"Your Password is: "<<password;
                this_thread::sleep_for(chrono::seconds(2));
                Coordinate(0,11);
                printunderLine();
                system("CLs");
                student_login();

            }
        }
        ffile.close();
        int atmp = 3;
        if(flag==0)
        {
            while(atmp!=0)
            {
                --atmp;
                Coordinate(0,10);
                cout<<"Account Doesn't Exits and attempts left"<<atmp;
                Coordinate(0,11);
                printunderLine();
                this_thread::sleep_for(chrono::seconds(1));
                system("CLS");
                forget_password();
            }
        }
    }
}

#endif
