//In guaud
#ifndef ADMINLOGGED_H
#define ADMINLOGGED_H
//user defined headers
#include "myheader.h"
#include "main.cpp"
#include "adminpage.h"
//Std headers
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>

int main();
void add_admin();
void admin_login();
void student_activity();

void add_marks();
void view_student();

void admin_loggedin_page()
{
    int choice;
    Coordinate(0,1);
    printEqualLine();
    Coordinate(15,2);//Now cursor goes to left to right in 10th position
    cout<<"Admin Logged in PAGE";
    Coordinate(0,3);
    printEqualLine();

    Coordinate(0,4);
    cout<<"Select the Choice";
    Coordinate(3,6);
    cout<<"<Enter 1>... Add Admin";
    Coordinate(3,8);
    cout<<"<Enter 2>... Student Activity";
    Coordinate(3,10);
    cout<<"<Enter 3>... Switch User";
    Coordinate(3,12);
    cout<<"<Enter 0>... Exit ";
    Coordinate(0,14);
    cout<<"Enter Your Choice: ";
    Coordinate(0,16);
    printEqualLine();

    Coordinate(18,14);
    cin>>choice;

    switch(choice)
    {
    case 0:
        exit(0);
        break;
    case 1:
        system("CLS");
        add_admin();
        break;
    case 2:
        system("CLS");
        student_activity();
        break;
    case 3:
        //switch_user
        system("CLS");
        main();
        break;
    default:
        system("CLS");
        cout<<"Oops Try to enter correct choice";
        admin_loggedin_page();
    }
}

void add_admin()
{
    string ad_user_id,ad_user_name,ad_password,ad_con_password;

    Coordinate(0,2);
    printEqualLine();
    Coordinate(10,3);
    cout<<"Please Enter the Following details: ";
    Coordinate(0,4);
    printEqualLine();

    Coordinate(0,5);
    cout<<"User Name";
    Coordinate(18,5);
    cout<<":";
    Coordinate(0,6);
    printunderLine();

    Coordinate(0,7);
    cout<<"Mail Id";
    Coordinate(18,7);
    cout<<":";
    Coordinate(0,8);
    printunderLine();

    Coordinate(0,9);
    cout<<"Password";
    Coordinate(18,9);
    cout<<":";
    Coordinate(0,10);
    printunderLine();

    Coordinate(0,11);
    cout<<"Confirm Password";
    Coordinate(18,11);
    cout<<":";
    Coordinate(0,12);
    printunderLine();

    Coordinate(19,5);
    cin>>ad_user_name;

    Coordinate(19,7);
    cin>>ad_user_id;

    Coordinate(19,9);
    cin>>ad_password;

    Coordinate(19,11);
    cin>>ad_con_password;

    if(ad_password == ad_con_password)
    {
        ofstream adfile("adminfile.txt",ios::app);
        adfile<<ad_user_name<<' '<<ad_user_id<<' '<<ad_password;
        adfile.close();
        system("CLS");
        Coordinate(0,1);
        cout<<"Registration Successful";
        admin_login();
    }
    else
    {
        system("CLS");
        cout<<"Password Doesn't match";
        add_admin();
    }
}

void student_activity()
{
    int ch;
    Coordinate(0,2);
    printEqualLine();
    Coordinate(15,3);//Now cursor goes to left to right in 10th position
    cout<<"Student Activity";
    Coordinate(0,4);
    printEqualLine();

    Coordinate(0,5);
    cout<<"Select the Choice";
    Coordinate(3,7);
    cout<<"<Enter 1>... Add Marks";
    Coordinate(3,9);
    cout<<"<Enter 2>... View Student activity";
    Coordinate(3,11);
    cout<<"<Enter 3>... Back";
    Coordinate(3,13);
    cout<<"<Enter 0>... Exit ";
    Coordinate(0,15);
    cout<<"Enter Your Choice: ";
    Coordinate(0,17);
    printEqualLine();

    Coordinate(18,15);
    cin>>ch;

    switch(ch)
    {
    case 0:
        exit(0);
        break;
    case 1:
        system("CLS");
        add_marks();
        break;
    case 2:
        system("CLS");
        //cout<<"Makrs pafge";
        view_student();
        break;
    case 3:
        system("CLS");
        cout<<"view page";
        admin_loggedin_page();
        break;
    default:
        system("CLS");
        cout<<"Oops Try to enter correct choice";
        student_activity();
    }
}

void add_marks()
{
    double mark1,mark2,mark3,mark4,mark5,total;
    Coordinate(0,2);
    printEqualLine();
    Coordinate(10,3);
    cout<<"Students Marks";
    Coordinate(0,4);
    printEqualLine();

    Coordinate(0,5);
    cout<<"Students Name";
    Coordinate(20,5);
    cout<<"| Sub1 | Sub2 | Sub3 | Sub4 | Sub5 | Total";
    Coordinate(0,6);
    printEqualLine();

    ifstream atfile("studentDetails.txt");
    if(!atfile.is_open())
    {
        Coordinate(0,16);
        cout<<"Failed to Open";
    }
    string atline;
    int i = 7;
    while(getline(atfile,atline))
        {
            stringstream s(atline);
            string username,id,dob,age,ph,password;
            s>>username>>id>>dob>>age>>ph>>password;

            Coordinate(0,i);
            cout<<username;
            Coordinate(20,i);
            cout<<"|      |      |      |      |      |     ";

            Coordinate(0,i+1);
            printunderLine();

            i=i+2;
        }
    atfile.close();
    ifstream inputfile("studentDetails.txt");
    ofstream outfile("studentmarks.txt",ios::app);

    if(!outfile.is_open()|| !inputfile.is_open())
    {
        Coordinate(0,16);
        cout<<"Failed to Open";
    }

    string markline;
    int j = 7;
    while(getline(inputfile,markline))
    {
        stringstream as(markline);
        string username,id,dob,age,ph,password;
        as>>username>>id>>dob>>age>>ph>>password;
        Coordinate(22,j);
        cin>>mark1;
        Coordinate(29,j);
        cin>>mark2;
        Coordinate(36,j);
        cin>>mark3;
        Coordinate(43,j);
        cin>>mark4;
        Coordinate(50,j);
        cin>>mark5;
        Coordinate(57,j);
        total = mark1+mark2+mark3+mark4+mark5;
        cout<<total;

        outfile << username << ' '<< to_string(mark1)<< ' ' << to_string(mark2) << ' ' <<to_string(mark3) << ' ' << to_string(mark4) << ' ' << to_string(mark5)<< ' ' << to_string(total) << endl;
        j = j + 2;
    }
    outfile.close();
}

void view_student()
{
    int goback;
    Coordinate(0,1);
    printEqualLine();
    Coordinate(10,2);
    cout<<"Students Marks are: ";
    Coordinate(0,3);
    printEqualLine();


    ifstream infile("studentmarks.txt");
    if(!infile.is_open())
    {
        Coordinate(0,1);
        cout<<"Failed to Open";
    }
    string Line;
    int i=4;
    while(getline(infile,Line))
    {
        string username,mark1,mark2,mark3,mark4,mark5,total;
        stringstream fs(Line);
        fs>>username>>mark1>>mark2>>mark3>>mark4>>mark5>>total;

        Coordinate(0,i);
        cout<<username;
        Coordinate(20,i);
        cout<<"|  "<<mark1<<"  |  "<<mark2<<"  |  "<<mark3<<"  |  "<<mark4<<"  |  "<<mark5<<"  |  "<<total<<"  |";
       // cout<<"|     |      |      |      |      |     ";
        Coordinate(0,i+1);
        printunderLine();
        i=i+2;
    }
    Coordinate(0,i);
    cout<<"<Enter 0> Exit";
    Coordinate(0,i+2);
    cout<<"<Enter 1> Goback";
    Coordinate(0,i+3);
    cout<<"Enter your Choice: ";
    cin>>goback;
    Coordinate(0,i+4);
    printEqualLine();

    switch(goback)
    {
    case 0:
        exit(0);
        break;
    case 1:
        system("CLS");
        admin_loggedin_page();
        break;
    default:
        cout<<"Worng Choice Enter again";
        break;
    }
}

#endif // ADMINLOGGED_H

