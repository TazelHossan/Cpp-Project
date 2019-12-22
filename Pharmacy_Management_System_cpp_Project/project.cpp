#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iomanip>
#include<vector>
#include "pay.h"
#include "medicineType.h"
enum Size {max1 = 80,max2 = 80};
using namespace std;


medicineType::medicineType ()
{
///constructor
}
struct node ///constract node
{
    int reciept_number;
    string customerName;
    string date;
    int quantity[10];
    int x; ///number of the medicine
    int same[10];
    double amount[10];
    vector<string> medicineName{"Vitamin A(500mg)","Vitamin C(500mg)","Vitamin B(500mg)","NAPA Extra(500mg)","Paracetamol","Pain Killer(700mg)",
        "Amino Zinc Tablet(500mg)","Burnex(500mg)","Fabuloss 5(500mg)","Acetic Acid(50mg)"
    };
    vector<double>Medicine{5,6,7,5,7,9,7,4,8,9}; ///medicine price
    double total;
    node *prev;
    node *next;
    node *link;

}*q, *temp;				///pointer declaration
node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;
template<class T>
int search_medicine(vector<string>arr,T* medicine)
{
    int i;
    for( i =0; i<arr.size(); i++)
    {
        if(arr[i]==medicine)
        {
            return 1;
            break;
        }
    }
    if(i==10)
    {
        return -1;
    }
}

int main()	/// Main function
{
    cout<< "\n\n";
    cout<< "\t\t\t\t    ----------------------------------------------------------\n";
    cout<< "\t\t\t\t    ==========================================================\n";
    cout<< "\t\t\t\t            ||            A Program Of          ||\n";
    cout<< "\t\t\t\t            ||  \"Pharmacy Management System\"    ||\n";
    cout<< "\t\t\t\t    ==========================================================\n";
    cout<< "\t\t\t\t    ----------------------------------------------------------\n\n\n";
    cout<< "\t\t\t\t ===================================================================\n";
    cout<< "\t\t\t\t                    The Features Of Our Management\n";
    cout<< "\t\t\t\t ===================================================================\n";
    cout<< "\t\t\t\t     ||    \"1\" Take new Medicine order                        ||\n";
    cout<< "\t\t\t\t     ||    \"2\" Print The Medicine Order Reciept               ||\n";
    cout<< "\t\t\t\t     ||    \"3\" Modify Order List                              ||\n";
    cout<< "\t\t\t\t     ||    \"4\" Delete A Medicine Order                        ||\n";
    cout<< "\t\t\t\t     ||    \"5\" Print The Daily Summery                        ||\n";
    cout<< "\t\t\t\t     ||    \"6\" Pay The Due Bill Of The Order                  ||\n";
    cout<< "\t\t\t\t     ||    \"7\" Search A Medicine By Name Or Its Id            ||\n";
    cout<< "\t\t\t\t     ||    \"8\" More Spent More Bonus !                        ||\n";
    cout<< "\t\t\t\t     ||    \"9\" For Exiting From The Present Actions           ||\n";
    cout<< "\t\t\t\t ===================================================================\n";
    cout<< "\t\t\t\t ===================================================================\n";
    cout<<"\n\t\t\t\t\t\t Enter Your Choice:: ";
    medicineType medicine;
    pay p1,p2,bonus;
    int choice;
    vector<string> medicineName{"Vitamin A(500mg)","Vitamin C(500mg)","Vitamin B(500mg)","NAPA Extra(500mg)","Paracetamol","Pain Killer(700mg)",
                                "Amino Zinc Tablet(500mg)","Burnex(500mg)","Fabuloss 5(500mg)","Acetic Acid(50mg)"
                               };
    vector<string>medicineId{"1","2","3","4","5","6",
                             "7","8","9","10"
                            };
    char medi1[max1],medi2[max2];
    int index;
    char ch;
    fstream file;
    file.open("tazz.dat",ios::in | ios:: out | ios::app | ios:: binary);
    do
    {
        //system("cls");
        cin>>choice;
        while(true)
        {
            if(cin.good())
            {
                cin.ignore(10,'\n');
                break;
            }
            cin.clear();
            cout<< "\t\t\t\t    ----------------------------------------------------------\n";
            cout<< "\t\t\t\t            |  You Enter An Invalid Choice !   |\n";
            cout<< "\t\t\t\t            |  Please ,Re-Enter Again...       |\n";
            cout<< "\t\t\t\t    ----------------------------------------------------------\n\n";
            cin.ignore(10,'\n');
            break;
        }
        if(choice==1)
        {
            medicine.Pharmacy_Name();
            medicine.takingOrder();
            file.write(reinterpret_cast<char*>(&medicine),sizeof(medicine));	///function add
        }
        if(choice==2)
        {
            file.seekg(0);
            file.read(reinterpret_cast<char*>(&medicine),sizeof(medicine));
            medicine.order_list();	///function order
            system("PAUSE");
        }
        if(choice==3)
        {
            medicine.modify();	///function modify
            file.write(reinterpret_cast<char*>(&medicine),sizeof(medicine));
            system("PAUSE");
        }
        if(choice==4)
        {
            medicine.delete_order();	///function delete
            system("PAUSE");

        }
        if(choice==5)
        {
            medicine.daily_summary();	///function daily_summary
            file.seekg(0);
            file.read(reinterpret_cast<char*>(&medicine),sizeof(medicine));
            system("PAUSE");
        }
        if(choice==6)
        {
            p1.payTaka();
        }
        if(choice==7)
        {
            cout<< "\t\t\t\t    ----------------------------------------------------------\n";
            cout<< "\t\t\t\t          |  Enter Your Preference To Search a Medicine|\n";
            cout<< "\t\t\t\t          |  Press \"a\" For Searching By Name           |\n";
            cout<< "\t\t\t\t          |  Press \"b\" For Searching By Id             |\n";
            cout<< "\t\t\t\t    ----------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t Enter Your Preference:: ";
            ch = getchar();
            if(ch=='a')
            {
                getchar();
                cout<< "\n\t\t\t\t\t Write The Medicine Name To Be Search::";
                cin.get(medi1,max1);
                index =search_medicine(medicineName,medi1);
                if(index==1)
                {
                    cout<< "\n\t\t\t\t\t Yes,Medicine Is in Stock";
                }
                else
                {
                    cout<< "\n\t\t\t\t\t Sorry ,Medicine is not in stock";
                }
            }
            if(ch=='b')
            {
                getchar();
                cout<< "\n\t\t\t\t\t Write The Medicine Id To Be Search::";
                cin.get(medi2,max2);
                index =search_medicine(medicineId,medi2);
                if(index==1)
                {
                    cout<< "\n\t\t\t\t\t Yes,Medicine Is in Stock.";
                }
                else
                {
                    cout<< "\n\t\t\t\t\t Sorry ,Medicine is not in stock !";
                }
            }
        }
        if(choice==8)
        {
            cout<< "\n\t\t\t\t    -------------------------------------------------------------------------";
            cout<< "\n\t\t\t\t      | If You Spend 1Tk To 500TK or more Then, You'll Get 50TK Bonus!     |";
            cout<< "\n\t\t\t\t      | If You Spend 500TK To 1000TK or more Then, You'll Get 100TK Bonus!|";
            cout<< "\n\t\t\t\t    -------------------------------------------------------------------------\n\n";
            cout<< "\n\t\t\t\t      Enter Your Initial Cost(Taka)::";
            p1.getTaka();
            cout<< "\n\t\t\t\t      Enter Your Maximum Cost(Taka)::";
            p2.getTaka();
            bonus = p1 + p2;
            bonus.showBonus();
            cout<<endl;
        }
        if(choice==9)
        {
            medicine.exit();	///function exit
            goto a;
        }
        cout<<"\n\t\t\t\t\t\t Enter Your Choice:: ";
    }
    while(choice!=9); ///end do
a: ///goto
    cout<< "\t\t\t\t    ----------------------------------------------------------\n";
    cout<< "\t\t\t\t            |  Thank You So Much For Staying With Us |\n";
    cout<< "\t\t\t\t            |        Take Care Of Yourself           |\n";
    cout<< "\t\t\t\t    ----------------------------------------------------------\n\n";
    system ("PAUSE");
    return 0;
}///end  main function



void medicineType::takingOrder()		///function to take an order
{
    system("cls");
    int choice, quantity, price,None, i;
    cout <<"\n\t\t\t\t Add Order Details \n";
    node *temp;
    temp=new node;
    cout<< "\t\t\t\t=========================================================================\n";
    cout<<"\t\t\t\t  MEDICINE ID "<<"   \t\tMEDICINE NAME"<<"           MEDICINE PRICE(TK)"<<endl;
    cout<< "\t\t\t\t=========================================================================\n";
    cout<<"\t\t\t\t |  0001  |"<<"\t\t"<<"   | Vitamin A(500mg)  |"<<"        |  TK 5.00  |"<<endl;
    cout<<"\t\t\t\t |  0002  |"<<"\t\t"<<"   | Vitamin C(500mg)  |"<<"        |  TK 6.00  |"<<endl;
    cout<<"\t\t\t\t |  0003  |"<<"\t\t"<<"   | Vitamin B(500mg)  |"<<"        |  TK 7.00  |"<<endl;
    cout<<"\t\t\t\t |  0004  |"<<"\t\t"<<"   | NAPA Extra(500mg) |"<<"        |  TK 5.00  |"<<endl;
    cout<<"\t\t\t\t |  0005  |"<<"\t\t"<<"   | Paracetamol(500mg)|"<<"        |  TK 7.00  |"<<endl;
    cout<<"\t\t\t\t |  0006  |"<<"\t\t"<<"   | Pain Killer(700mg)|"<<"        |  TK 9.00  |"<<endl;
    cout<<"\t\t\t\t |  0007  |"<<"\t\t"<<"   | Amino Zinc Tablet |"<<"        |  TK 7.00  |"<<endl;
    cout<<"\t\t\t\t |  0008  |"<<"\t\t"<<"   | Burnex(500mg)     |"<<"        |  TK 4.00  |"<<endl;
    cout<<"\t\t\t\t |  0009  |"<<"\t\t"<<"   | Fabuloss 5 (500mg)|"<<"        |  TK 8.00  |"<<endl;
    cout<<"\t\t\t\t |  0010  |"<<"\t\t"<<"   | Acetic Acid(50mg) |"<<"        |  TK 9.00  |"<<endl;
    cout<< "\t\t\t\t=========================================================================\n";
    cout<< "\t\t\t\t=========================================================================\n";
    temp = new node;
    cout<<"\n\t\t\t\t Enter The Date :: ";
    cin>>temp->date;
    cout<< "\n\t\t\t\t Enter The Customer Name:: ";
    cin>> temp->customerName;
    cout << "\n\t\t\t\t Enter The Reciept Id Of The Order :: ";
    cin >> temp->reciept_number;
    cout << "\n\t\t\t\t How Many Medicine Do You Want?(Maximum is 10)::";
    cin >> temp->x;
    if (temp->x >10)
    {
        cout << "\n\t\t\t\t The Medicine Is Out Of Stock !";
        system("pause");
    }
    else
    {
        for (i=0; i<temp->x; i++)
        {
            cout << "\n\t\t\t\t Please Enter The Id Of The Medicines :: ";
            cin>> temp->same[i];
            cout<< "\n\t\t\t\t Medicine Name:: " <<temp->medicineName[temp->same[i]-1]<<endl;

            cout << "\n\t\t\t\t How many medicine do you want?:: ";
            cin >> temp->quantity[i];
            temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->same[i]-1];
            cout << "\n\t\t\t\t Your Bill is:: " << temp->amount[i]<<" TK"<<endl;
            system("PAUSE");
        }
        cout<< "\n\t\t\t\t    ----------------------------------------------------------";
        cout<< "\n\t\t\t\t            |  Medicine Order Is Taken Successfully  |";
        cout<< "\n\t\t\t\t            |  Go to The Recieption And Pay The Bill |";
        cout<< "\n\t\t\t\t    ----------------------------------------------------------\n";
        system ("PAUSE");
        temp->next=NULL;
        if(start_ptr!=NULL)
        {
            temp->next=start_ptr;
        }
        start_ptr=temp;
        system("cls");
    }
}///End function take_order


void medicineType::order_list()		///Function to display receipt
{
    system("cls");
    medicineType m1;
    int i, num, currrent_reciept;
    bool found;

    node *temp;

    temp=start_ptr;
    found = false;
    m1.Show_Pharmacy_Name();
    cout<<"\n\t\t\t\t Enter The Reciept Number::";
    cin>>currrent_reciept;
    cout<< "\t\t\t\t  ----------------------------------------------------------\n";
    cout<< "\t\t\t\t              |  Medicine Order List Is   |\n";
    cout<< "\t\t\t\t  ----------------------------------------------------------\n\n";


    if(temp == NULL) ///Invalid receipt code
    {
        cout << "\n\t\t\t\t The List Is Empty.";
    }

    while(temp !=NULL && !found)
    {
        if (temp->reciept_number==currrent_reciept)
        {
            found = true;
        }
        else
        {
            temp = temp -> next;
        }

        if (found)	///print the receipt
        {
            cout<< "\n\t\t\t\t Pharmacy Name::"<<PharmacyName;
            cout<<"\n\t\t\t\t Date         :: "<<temp->date;
            cout <<"\n\t\t\t\t Reciept Id   :: "<<temp->reciept_number;
            cout<<"\n\t\t\t\t Customer Name:: "<<temp->customerName<<endl;
            cout<< "\n\t\t\t\t ===================================================================\n";
            cout << "\n\t\t\t\t |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
            cout<< "\n\t\t\t\t ===================================================================\n";
            for (i=0; i<temp->x; i++)
            {
                cout<<"\n\t\t\t\t    "<<temp->medicineName[temp->same[i]-1]<<"\t\t\t";
                cout<<temp->quantity[i] <<"\t\t\t";
                cout<< temp->amount[i]<<" TK"<<endl;
                cout<< "\n\t\t\t\t ===================================================================\n";
            }

            temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
                          +temp->amount[8]+temp->amount[9];

            cout<<"\n\t\t\t\t Total Bill is :: "<<temp->total;
            cout<< "\n\t\t\t\t    ----------------------------------------------------------\n";
            cout<< "\n\t\t\t\t            |  Go to The Accountance And Pay The Bill |\n";
            cout<< "\n\t\t\t\t    ----------------------------------------------------------\n\n";
        }
    }
}	///End function order_list


void medicineType::delete_order()	///function to delete_order
{
    system("cls");
    int i, reciept_id, count;
    cout<<"\n\t\t\t\t Enter The Receipt Id::";
    cin>>reciept_id;
    node *q;
    node *temp;
    bool found;

    if(start_ptr == NULL)
        cerr<<"\n\t\t\t\t Sorry, Can Not Delete From An Empty List!\n";
    else
    {
        if(start_ptr->reciept_number == reciept_id)
        {
            q = start_ptr;
            start_ptr = start_ptr->next;
            count--;
            if(start_ptr == NULL)
                last = NULL;
            delete q;
            cout<<"\n\t\t\t\t The Reciept is Deleted Successfully \n";
        }
        else
        {
            found = false;
            temp = start_ptr;
            q = start_ptr->next;

            while((!found) && (q != NULL))
            {
                if(q->reciept_number != reciept_id)
                {
                    temp = q;
                    q = q-> next;
                }
                else
                    found = true;
            }

            if(found)
            {
                temp->next = q->next;
                count--;

                if(last == q)
                    last = temp;
                delete q;
                cout<<"\n\t\t\t\t The Reciept Id Is Deleted Successfully\n";
            }
            else
                cout<<"\n\t\t\t\t The Order Which Is To Be Deleted Is Not In The Database!\n";
        }
    }
}	///End function delete_order

void medicineType::modify()		///function to modify order
{
    system("cls");
    int i, ch, id;
    bool found;
    found = false;
    temp = start_ptr;
    cout<<"\n\t\t\t\t Enter Receipt Id:: ";
    cin>>id;
    if (temp==NULL && id==0)
    {
        cout<<"\n\t\t\t\t There Is No Record To Modify! \n";
    }
    else
    {
        while(temp !=NULL && !found)
        {
            if (temp->reciept_number==id)
            {
                found = true;
            }
            else
            {
                temp = temp -> next;
            }
            if (found)
            {
                cout << "\n\t\t\t\t Please , Re-Write The Reciept Id ::";
                cin >> temp->reciept_number;
                cout<<"\n\t\t\t\t Please , Re-Write The Order Date :: ";
                cin>>temp->date;
                cout<< "\n\t\t\t\t Please , Re-Write The Customer Name:: ";
                cin>> temp->customerName;

                cout<<"\n\t\t\t\t RECORD MODIFIED....!\n";
            }
            else
            {
                if(temp != NULL && temp->reciept_number != id)
                {
                    cout<<"\n\t\t\t\t Invalid Reciept Id!\n";
                }
            }
        }
    }
}		///End modify function



void medicineType::daily_summary()		///Function to display Daily Summary
{
    system("cls");
    int i,num;
    node *temp ;
    temp=start_ptr;
    if(temp == NULL) ///Invalid receipt code
    {
        cout << "\n\t\t\t\t Sorry ,The List is Empty !\n";
    }
    else
    {
        cout<<"\n";
        cout<<"\n\t\t\t\t ===========================================================================";
        cout <<"\n\t\t\t\t                   Daily Summary of All Orders \n";
        cout<<"\n\t\t\t\t ===========================================================================";
        while(temp!=NULL)
        {
            cout<< "\n\t\t\t\t Pharmacy Name::"<<PharmacyName;
            cout<<"\n\t\t\t\t Order Date   :: "<<temp->date;
            cout <<"\n\t\t\t\t Reciept Id   :: "<<temp->reciept_number;
            cout<<"\n\t\t\t\t Customer Name:: "<<temp->customerName;
            cout<<"\n\t\t\t\t ___________________________________________________________________________";
            cout <<"\n\t\t\t\t |   Medicine Name    |    Quantity     |    Total Price |";
            cout <<"\n\t\t\t\t ==========================================================================\n";
            for (i=0; i<temp->x; i++)
            {
                cout<<"\n\t\t\t\t    "<<temp->medicineName[temp->same[i]-1]<<"\t\t\t";
                cout<<temp->quantity[i] <<"\t\t";
                cout<<temp->amount[i]<<"TK"<<endl;
                cout<<"\n\t\t\t\t _____________________________________________________________________________";
            }
            temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
                          +temp->amount[8]+temp->amount[9];
            cout<<"\n\t\t\t\t Total Bill is :: "<<temp->total;
            cout <<"\n\t\t\t\t _______________________________________________________________________________\n";
            temp=temp->next;
        }
    }
}///End daily summary

void medicineType::exit() ///Function to exit
{
    cout<<"\n\t\t\t\t\t\t You Choose To Exit.\n"<<endl;
}	///end function exit
