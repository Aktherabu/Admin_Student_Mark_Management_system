#ifndef STUDENTLOGGED_H
#define STUDENTLOGGED_H

#include "myheader.h"
#include "main.cpp"
#include "studentpage.h"


#include<conio.h>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main();
void student_page();


void view_stud_marks();

void student_logged()
{
    int choice;
    Coordinate(0,1);
    printEqualLine();
    Coordinate(15,2);
    cout<<"STUDENT Logged PAGE";
    Coordinate(0,3);
    printEqualLine();

    Coordinate(0,4);
    cout<<"Select the Choice";
    Coordinate(3,6);
    cout<<"<Enter 1>... View Marks ";
    Coordinate(3,8);
    cout<<"<Enter 2>... Back";
    Coordinate(3,10);
    cout<<"<Enter 3>... Switch User ";
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
        view_stud_marks();
      // cout<<"student marks";
        break;
    case 2:
        system("CLS");
        student_page();
        break;
    case 3:
        system("CLS");
        main();
    default:
        system("CLS");
        cout<<"Oops Try to enter correct choice";
        student_logged();
    }
}

void view_stud_marks()
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
        student_logged();
        break;
    default:
        cout<<"Worng Choice Enter again";
        break;
    }
}

#endif
