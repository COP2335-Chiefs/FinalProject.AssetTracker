#include "Inventory.h"
#include <iostream>
#include "Customer.h"
#include "Date.h"
#include "Tablet.h"
#include <fstream>

Inventory::Inventory(int num)
{
    //ctor
    numTabs=num;
    loanTabs=0;
    brokenTabs=0;
    allTabs();
}

Inventory::~Inventory()
{
    //dtor
}
void Inventory::allTabs()
{
    fstream file("id.txt");
    fstream file2("available.txt");
    fstream file3("loan.txt");
    fstream file4("broken.txt");
        if(!file.is_open())
        {
            cout<<"FILES NOT FOUND!";
            system("PAUSE");
            exit(0);
        }
    for(int i=0; i<numTabs; i++)
    {

        string ID;
        getline(file,ID);
        tabs[i]=new Tablet(false);

        tabs[i]->SetID(ID);
        bool b=tabs[i]->checkBroken();
        if(b)
        {
            file4<<tabs[i]->GetID()<<endl;
            tabs[i]->SetonLoan(false);

        }
        else if(tabs[i]->GetonLoan())
        {
            file3<<tabs[i]->GetID()<<endl;

        }
        else file2<<tabs[i]->GetID()<<endl;
    }
    file.clear();
    file2.clear();
    file3.clear();
    file4.clear();
    file.close();
    file2.close();
    file3.close();
    file4.close();
}
void Inventory::loadAllTabs()
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
