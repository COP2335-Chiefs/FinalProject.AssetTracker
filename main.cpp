#include <iostream>
#include "Customer.h"
#include "Date.h"
#include "Inventory.h"
#include "Tablet.h"
#include <fstream>
using namespace std;


void makeReservation(Tablet *t);
void moveBroken(Tablet *t);
void fixBroken(string);
void clearData();
int main()
{

    Inventory *in=new Inventory(16);
    in->loadAllTabs();
    in->tabs[0]->setBroken(true);
    makeReservation(in->tabs[1]);
    moveBroken(in->tabs[0]);
    fixBroken(in->tabs[0]->GetID());
    return 0;
}

void makeReservation(Tablet *t)
{
    t->SetonReserve(true);
    string id;
    int x=0;
    ifstream file("available.txt");
    ofstream temp("temp.txt");
    string tname=t->GetID();
    while(file>>id)
    {
        if(tname!=id)
            temp<<id<<endl;
        if(tname==id)
            x=1;
    }
    file.clear();
    file.seekg(0, ios::beg);
    file.close();
    temp.close();
    remove("available.txt");
    rename("temp.txt", "available.txt");
    if(x==0)
    {
        cout << "There is no table with that id." << endl;
    }
    else
    {
        fstream file2("loan.txt");
        file2<<tname<<endl;
    }

}
void moveBroken(Tablet *t)
{
    if(t->getBroken())
    {
        fstream file("broken.txt");
        file<<t->GetID()<<endl;
        t->SetonLoan(false);
    }
    string id;
    int x=0;
    ifstream file("available.txt");
    ofstream temp("temp.txt");
    string tname=t->GetID();
    while(file>>id)
    {
        if(tname!=id)
            temp<<id<<endl;
        if(tname==id)
            x=1;
    }
    file.clear();
    file.seekg(0, ios::beg);
    file.close();
    temp.close();
    remove("available.txt");
    rename("temp.txt", "available.txt");
    if(x==0)
    {
        cout << "There is no table with that id." << endl;
    }
    else
    {
        fstream file2("broken.txt");
        file2<<tname<<endl;
    }
}
void fixBroken(string tname)
{
    string id;
    int x=0;
    ifstream file("broken.txt");
    ofstream temp("temp.txt");

    while(file>>id)
    {
        if(tname!=id)
            temp<<id<<endl;
        if(tname==id)
            x=1;
    }
    file.clear();
    file.seekg(0, ios::beg);
    file.close();
    temp.close();
    remove("student.txt");
    rename("temp.txt", "students.txt");
    if(x==0)
    {
        cout << "There is no table with that id." << endl;
    }
    else
    {
        fstream file2("available.txt");
        file2<<tname<<endl;
    }
}
void clearData()
{
    fstream file;
    file.open("broken.txt",std::ofstream::out|std::ofstream::trunc);
    fstream file2;
    file2.open("loan.txt",std::ofstream::out|std::ofstream::trunc);
    fstream file3;
    file3.open("available.txt",std::ofstream::out|std::ofstream::trunc);
    file.close();
    file2.close();
    file3.close();



}


