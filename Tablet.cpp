#include "Tablet.h"
#include <iostream>
#include "Customer.h"
#include "Date.h"
#include "Inventory.h"
#include <fstream>
#include <cstdlib>
#include <cstddef>

Tablet::Tablet(bool b)
{
    onLoan=false;
    loanedTo=NULL;


    returnDate=NULL;
}

Tablet::Tablet(bool b, bool r, Customer *c, Date* ret)
{
    if(b)
    {
        onLoan=b;
        loanedTo=c;
        fstream file("id.txt");
    if(!file.is_open())
    {
        cout<<"FILES NOT FOUND!";
        system("PAUSE");
        exit(0);
    }
    getline(file,ID);
        returnDate=ret;
    }
    else
        Tablet(false);
}

Tablet::~Tablet()
{
    delete returnDate;
    delete loanedTo;
    delete reserveEndDate;
    delete reserveStartDate;
}
bool Tablet::checkBroken()
{

    string answer;
    cout<<"For tab: "<<ID<<endl;
    cout<<"Is it broken?"<<endl;
    cin>>answer;
    if(answer.find("yes")!=std::string::npos)
    {
        broken=true;
        return true;
    }

    else return false;
}
void Tablet::SetreserveEndDate(string val)
{
    reserveEndDate->setDate(val);
}
void Tablet::SetreserveStartDate(string val)
{
    reserveStartDate->setDate(val);
}
