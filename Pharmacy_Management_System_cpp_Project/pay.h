#ifndef PAY_H
#define PAY_H
#include "pay.h"
#include<iostream>
#include "medicineType.h"
using namespace std;
class pay
{
private:
    int taka;
public:

    pay()
    {
        ///costructor
    }
    pay(int n1):taka(n1)
    {

    }

    void payTaka()
    {
        string ch ;
        int credit_no;

        cout << "\n\t\t\t\t How To Payment The Bill(via credit/cash)?:: ";
        cin>>ch;
        if(ch=="credit")
        {
            cout << "\n\t\t\t\t Enter The Credit Nomber:: ";
            cin>>credit_no;
            cout << "\n\t\t\t\t Enter The Total Amount to pay:: ";
            cin >> taka;
            cout<<"\n\t\t\t\t Payment is Done";
            cout<<"\n\t\t\t\t Thank You\n";
        }
        if(ch=="cash")
        {
            cout << "\n\t\t\t\t Enter The Total Amount to pay:: ";
            cin >> taka;
            cout<<"\n\t\t\t\t Payment is Done";
            cout<<"\n\t\t\t\t Thank You\n";
        }
    }
    void getTaka()
    {

        cin>>taka;
    }
    void showBonus()
    {
        cout<< "\n\t\t\t\t      You Got "<<taka<< "TK Bonus !!!"<<endl;
    }

    pay operator + (pay t)
    {
        int b = taka + t.taka;
        if(b>=500 && b<1000)
        {
            return b = 50;
        }
        if(b>=1000)
        {return b =100;
        }

    }
};

#endif // PAY_H
