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
        Tablet(bool b, bool r, Customer *c, Date* ret);
        ~Tablet();
        bool GetonLoan() { return onLoan; }
        void SetonLoan(bool val) { onLoan = val; }
        bool GetonReserve() { return onReserve; }
        void SetonReserve(bool val) {
            onReserve = val;
        }
        Customer GetloanedTo() { return *loanedTo; }
        void SetloanedTo(Customer val) { *loanedTo=val; }
        Date GetreserveStartDate(){return *reserveStartDate;}
        void SetreserveStartDate(string val);
        Date GetreserveEndDate(){return *reserveEndDate;}
        void SetreserveEndDate(string val);
        string GetID() { return ID; }
        void SetID(string val) { ID = val; }
        Date GetreturnDate() { return *returnDate; }
        void SetreturnDate(string val) { returnDate->setDate(val); }
        void setBroken(bool val){broken=val;}
        bool getBroken(){return broken;}
        //utility

        bool checkBroken();
    protected:
    private:
        bool onLoan;
        Customer *loanedTo;
        string ID;
        Date *returnDate;
        bool onReserve;
        Date *reserveStartDate;
        Date *reserveEndDate;
        bool broken;
};

#endif // TABLET_H
