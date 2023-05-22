#include<iostream>
#include<Windows.h>
#include<bits/stdc++.h>
#include<conio.h>
//#include<chrono>
//#include<thread>

//in gaurd function
#ifndef MAIN_CPP
#define MAIN_CPP

//user define functions
#include "studentpage.h"
#include "myheader.h"
#include "adminpage.h"


using namespace std;

void admin_page();
void student_page();

int main()
{
    int choice;
    //Main Page heading
    Coordinate(0,1);
    printEqualLine();
    Coordinate(10,2);//Now cursor goes to left to right in 10th position
    cout<<"WELCOME TO MANAGEMENT SYSTEM";
    Coordinate(0,3);//Now cursor goes to 0th position
    printEqualLine();

    Coordinate(0,4);
    cout<<"Select the User Type";
    Coordinate(3,6);
    cout<<"<Enter 1>... Admin ";
    Coordinate(3,8);
    cout<<"<Enter 2>... Student ";
    Coordinate(3,10);
    cout<<"<Enter 0>... Exit ";

    Coordinate(0,12);
    cout<<"Enter Your Choice: ";
    //endline should be marked before getting input
    Coordinate(0,14);
    printEqualLine();

    //positioning input cursor should be at exact point after the text/char ends ie : -> here
    Coordinate(18,12);
    cin>>choice;
   // this_thread::sleep_for(chrono::seconds(2));

    switch(choice)
    {

    case 0:
        exit(0);
        break;
    case 1:
        system("CLS");
        admin_page();
        break;
    case 2:
        system("CLS");
        student_page();
        break;
    default:
        system("CLS");
        cout<<"Oops Try to enter correct choice"<<endl;
        main();
    }
}
#endif
