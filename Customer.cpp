#include <iostream>
#include "Customer.h"
#include "Date.h"
#include "Inventory.h"
#include "Tablet.h"
Customer::Customer(string name, string organization, string organHead,
                 string loc, string address, string phone)
{
    this->name=name;
    this->organization=organization;
    this->organHead=organHead;
    this->loc=loc;
    this->address=address;
    this->phone=phone;

}

Customer::~Customer()
{
    //dtor
}

void Customer::printInfo()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Organization: "<<organization<<endl;
    cout<<"Head: "<<organHead<<endl;
    cout<<"Location: "<<loc<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Phone: "<<phone<<endl;
}
