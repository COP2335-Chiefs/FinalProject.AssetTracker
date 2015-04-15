#ifndef DATE_H
#define DATE_H
#include <sstream>


#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
class Date
{
    public:
        Date(int d, int m, int y);
        Date(string tot);
        ~Date();
        int Getday() { return day; }
        void Setday(int val) { day = val; }
        int Getmonth() { return month; }
        void Setmonth(int val) { month = val; }
        int Getyear() { return year; }
        void Setyear(int val) { year = val; }
        string getDate();
        void setDate(string s);
    protected:
    private:
        int day;
        int month;
        int year;
};

#endif // DATE_H
