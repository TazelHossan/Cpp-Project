#ifndef MEDICINETYPE_H
#define MEDICINETYPE_H
#include<iostream>
#include "pay.h"
using namespace std;
class Pharmacy_Management 	///base class
{
protected:
    string PharmacyName;
public:
    virtual void Pharmacy_Name()=0; ///pure virual function
    virtual void Show_Pharmacy_Name()=0; ///pure virual function
};
class medicineType:public Pharmacy_Management
{

private:
    //int serial_no;

public:
    void takingOrder(); ///to  take_order
    void delete_order(); ///to delete the order
    void modify(); ///to modify the order
    void order_list(); ///to display the order_list
    void daily_summary(); ///to display daily_summary
    void exit();  ///function to exit system
    medicineType(); ///constuctor
    void Pharmacy_Name()
    {
        cout<< "\n\t\t\t\t Write The Pharmacy name::";
        cin>>PharmacyName;
    }
    void Show_Pharmacy_Name()
    {
        cout<<PharmacyName;
    }

};

#endif // MEDICINETYPE_H
