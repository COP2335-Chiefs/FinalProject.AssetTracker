#include "Inventory.h"
#include <iostream>
#include "Customer.h"
#include "Date.h"
#include "Tablet.h"
#include <fstream>

Inventory::Inventory(int num, int loan, int broke)
{
    //ctor
    numTabs=num;
    loanTabs=loan;
    brokenTabs=broke;
    availableTabs();
}

Inventory::~Inventory()
{
    //dtor
}
void Inventory::availableTabs()
{
    fstream file("id.txt");
        if(!file.is_open())
        {
            cout<<"FILES NOT FOUND!";
            system("PAUSE");
            exit(0);
        }
    for(int i=0; i<maxTabs; i++)
    {

        string ID;
        getline(file,ID);
        tabs[i]=new Tablet(false);
        tabs[i]->SetID(ID);
    }
}
void Inventory::loadAvailableTabs()
{
    for(int i=0; i<numTabs; i++)
    {
        cout<<"Tablet ID: "<<tabs[i]->GetID()<<endl;
        cout<<"On Loan: "<<tabs[i]->GetonLoan()<<endl;
        if(tabs[i]->GetonLoan())
        {
            cout<<"Customer: "<<endl;
            tabs[i]->GetloanedTo().printInfo();
            cout<<"Return Date: "<<tabs[i]->GetreturnDate().getDate()<<endl;
        }
    }
}
