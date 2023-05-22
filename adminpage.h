//In guaur
#ifndef ADMINPAGE_H
#define ADMINPAGE_H
//user defined function
#include "myheader.h"
#include "adminlogged.h"
#include "main.cpp"

//stdfunctions
#include<conio.h>
#include<iostream>
#include<fstream>

using namespace std;
//calling other functions
int main();
void admin_login();
//void add_admin();
void admin_loggedin_page();


void admin_page()
{
    int choice;
    Coordinate(0,1);
    printEqualLine();
    Coordinate(15,2);//Now cursor goes to left to right in 10th position
    cout<<"Admin PAGE";
    Coordinate(0,3);
    printEqualLine();

    Coordinate(0,4);
    cout<<"Select the Choice";
    Coordinate(3,6);
    cout<<"<Enter 1>... Login ";
    Coordinate(3,8);
    cout<<"<Enter 2>... Switch";
    //Coordinate(3,10);
    //cout<<"<Enter 3>... Switch User ";
    Coordinate(3,10);
    cout<<"<Enter 0>... Exit ";
    Coordinate(0,12);
    cout<<"Enter Your Choice: ";
    Coordinate(0,16);
    printEqualLine();

    Coordinate(18,12);
    cin>>choice;

    switch(choice)
    {
    case 0:
        exit(0);
        break;
    case 1:
        system("CLS");
        admin_login();
        break;
    case 2:
        //switch_user
        system("CLS");
        main();
        break;
    default:
        system("CLS");
        cout<<"Oops Try to enter correct choice";
        admin_page();
    }
}
void admin_login()
{
    string a_user, a_password;
    Coordinate(0,2);
    printEqualLine();
    Coordinate(0,3);
    cout<<"Enter Admin User name/id and Password to login";
    Coordinate(0,4);
    printEqualLine();

    Coordinate(0,5);
    cout<<"User name/id ";
    Coordinate(15,5);
    cout<<":";
    Coordinate(0,6);
    printunderLine();

    Coordinate(0,7);
    cout<<"Password ";
    Coordinate(15,7);
    cout<<":";
    Coordinate(0,8);
    printunderLine();

    Coordinate(16,5);
    cin>>a_user;

    Coordinate(16,7);
    cin>>a_password;

    int flag = 0;

    ifstream alfile("adminfile.txt");

    if(!alfile.is_open())
    {
        Coordinate(0,8);
        cout<<"Failed to open Fail";
    }
    string line;
    while(getline(alfile,line))
    {
        stringstream ss(line);
        //tokenzing the line
        string username,id,password;
        ss>>username>>id>>password;

        if((username==a_user || id == a_user) && password == a_password)
        {
            flag =1;
        }
    }
    alfile.close();

    static int attempt = 3;
    if(flag ==1)
    {
        system("CLS");
        cout<<"Logged in";
        admin_loggedin_page();
    }
    else
    {
        while(attempt!=0)
        {
            --attempt;
            system("CLS");
            Coordinate(0,1);
            cout<<"Login in Failed Attempts Left is: "<<attempt;
            admin_login();
        }
    }
}

#endif
