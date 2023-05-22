#ifndef MYHEADER_H
#define MYHEADER_H

#define L 60


//Position the cursor
// x horizontal scaling
// y vertical scaling
void Coordinate(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
//for printing the underLine
void printunderLine()
{
    for(int i=0;i<L;i++)
    {
        printf("-");
    }
}
//for printing the equalLine for headings
void printEqualLine()
{
    for(int i=0;i<L;i++)
    {
        printf("=");
    }
}

#endif
