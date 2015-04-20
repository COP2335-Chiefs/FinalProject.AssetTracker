#include <iostream>
#include "Customer.h"
#include "Date.h"
#include "Inventory.h"
#include "Tablet.h"

Date::Date(int m, int d, int y)
{
    day=d;
    month=m;
    year=y;
}
Date::Date(string s)
{
    string delimiter;
    if(s.find("/")>=0)
    {
        delimiter="/";
    }
    else delimiter="-";
    int arr[2];
    size_t pos = 0;
    string token;
    int i=0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        arr[i]=atoi(token.c_str());
        s.erase(0, pos + delimiter.length());
        i++;
    }
    year=atoi(s.c_str());
    day=arr[1];
    month=arr[0];

}

Date::~Date()
{
    cout<<"Date Deleted"<<endl;
}
void Date::setDate(string s)
{
    string delimiter;
    if(s.find("/")>=0)
    {
        delimiter="/";
    }
    else delimiter="-";
    int arr[2];
    size_t pos = 0;
    string token;
    int i=0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        arr[i]=atoi(token.c_str());
        s.erase(0, pos + delimiter.length());
        i++;
    }
    year=atoi(s.c_str());
    day=arr[1];
    month=arr[0];
}


string Date::getDate()
{
    string b="";
    ostringstream ss;
     ss << month;
     ss<<"/";
     ss<<day;
     ss<<"/";
     ss<<year;
    return ss.str();
}
