#include "Tablet.h"
#include <iostream>
#include "Customer.h"
#include "Date.h"
#include "Inventory.h"
#include <fstream>
#include <cstdlib>

Tablet::Tablet(bool b)
{
    onLoan=false;
    loanedTo=nullptr;


    returnDate=nullptr;
}

Tablet::Tablet(bool b, Customer *c, Date* ret)
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
}
