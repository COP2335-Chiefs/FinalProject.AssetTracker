#ifndef TABLET_H
#define TABLET_H

#include <string>
#include <iostream>
#include <Customer.h>
#include <Date.h>
using namespace std;
class Tablet
{
    public:
        Tablet(bool b);
        Tablet(bool b, Customer *c, Date* ret);
        ~Tablet();
        bool GetonLoan() { return onLoan; }
        void SetonLoan(bool val) { onLoan = val; }
        Customer GetloanedTo() { return *loanedTo; }
        void SetloanedTo(Customer val) { *loanedTo=val; }
        string GetID() { return ID; }
        void SetID(string val) { ID = val; }
        Date GetreturnDate() { return *returnDate; }
        void SetreturnDate(string val) { returnDate->setDate(val); }

        //utility
        bool checkBroken()
        {
            string answer;
            cout<<"Is it broken?"<<endl;
            cin>>answer;
            if(answer.find("yes")!=std::string::npos)
                return true;
            else return false;
        }
    protected:
    private:
        bool onLoan;
        Customer *loanedTo;
        string ID;
        Date *returnDate;
};

#endif // TABLET_H
