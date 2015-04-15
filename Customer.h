#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
using namespace std;
class Customer
{
    public:
        Customer(string name, string organization, string organHead,
                 string loc, string address, string phone);
        ~Customer();
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getorgan() { return organization; }
        void Setorgan(string val) { organization = val; }
        string GetorganHead() { return organHead; }
        void SetorganHead(string val) { organHead = val; }
        string Getloc() { return loc; }
        void Setloc(string val) { loc = val; }
        string Getaddress() { return address; }
        void Setaddress(string val) { address = val; }
        string Getphone() { return phone; }
        void Setphone(string val) { phone = val; }
        void printInfo();
    protected:
    private:
        //loanee name
        string name;
        //organization rented to
        string organization;
        //head of organization
        string organHead;
        //location to be used
        string loc;
        //customer address
        string address;
        //customer phone number
        string phone;
};

#endif // CUSTOMER_H
