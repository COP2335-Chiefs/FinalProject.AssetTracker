#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <iostream>
#include <Tablet.h>
using namespace std;
const int maxTabs=50;
class Inventory
{

    public:

        Inventory(int num, int loan, int broke);
        ~Inventory();
        int GetnumTabs() { return numTabs; }
        void SetnumTabs(int val) { numTabs = val; }
        int GetloanTabs() { return loanTabs; }
        void SetloanTabs(int val) { loanTabs = val; }
        int GetbrokeTabs() { return brokenTabs; }
        void SetbrokeTabs(int val) { brokenTabs = val; }
        void availableTabs();
        void loadAvailableTabs();

    protected:
    private:
        //Tabs in inventory
        int numTabs;
        //Tabs on loan
        int loanTabs;
        //Busted tabs
        int brokenTabs;
        //Inventory list of non rented tabs
        Tablet* tabs[maxTabs];
};

#endif // INVENTORY_H
