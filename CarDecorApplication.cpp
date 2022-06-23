#CARDECOR MODELING
#include<iostream>
using namespace std;

class Car
{
public:
    string cname;
    string color;
    string cType;

    Car() {}
    Car(string cname,string color,string cType):cname(cname),color(color),cType(cType)
    {
    }
    void carDisplay()
    {
        cout<<"Car Name:"<<cname<<endl;
        cout<<"Car color:"<<color<<endl;
        cout<<"Car Type:"<<cType<<endl;
    }
};
class PaintType
{
public:
    string *color;
    // for particular color their will be more number of matfinish graidents//
    string matfinish1;
    string matfinish2;
    string matfinish3;
    string matfinish4;
    PaintType(){}
    PaintType(string *c,string m1,string m2,string m3,string m4):color(c),matfinish1(m1),matfinish2(m2),matfinish3(m3),matfinish4(m4)
    {
    }
};

class Person
{
public:
    string name;
    string address;
    long long phoneno;

    Person() {}
    Person(string name,string address,long long phoneno)
    {
        this->name=name;
        this->address=address;
        this->phoneno=phoneno;
    }
    void setData(string n1,string a1,long long p)
    {
        name=n1;
        address=a1;
        phoneno=p;
    }
    virtual void printDetails()
    {
    }
    virtual float generateBill(PaintType p)
    {
        return 0;
    }
};

class Customer:public Person
{
public:
    int cId;
    string pstatus="UNPAID";
    string selectColor,matf;
    Car c;
    Customer(){}
    Customer(int cId,string name,string address,long long phoneno,string selectColor,string mf,Car c1):Person(name,address,phoneno)
    {
        this->cId=cId;
        this->c=c1;
        this->selectColor=selectColor;
        this->matf=mf;
    }
    void printDetails()
    {
        cout<<endl<<"---------------------------------------------"<<endl;
        cout<<"Name of the Customer:"<<name<<endl;
        cout<<"Address:"<<address<<endl;
        cout<<"Phone number:"<<phoneno<<endl;
        c.carDisplay();
        cout<<"Color selected by Customer is:"<<selectColor<<","<<matf<<endl;

    }
    float printBill(float p)
    {
        cout<<"Price:"<<p<<endl;
        return p;
    }
};

class Workers:public Person
{
public:
    int _workersId;
    int assignedTo;
    Car *c;
    bool status;
    Workers(int wid,string name,string address,long long phoneno,bool s):Person(name,address,phoneno)
    {
        _workersId=wid;
        status=s;
    }
    void printDetails()
    {
        cout<<endl<<"---------------------------------------"<<endl;
        cout<<"Worker ID:"<<_workersId<<endl;
        cout<<"Name of the worker:"<<name<<endl;
        cout<<"Address:"<<address<<endl;
        cout<<"Phone number:"<<phoneno<<endl;
    }
};

class Manager:public Person
{
    static Manager *_instance;
    Manager():Person()
    {
    }
public:


    Customer *custId;
    Workers *workerId;
    static Manager* getInstance()
    {
        if(_instance==0)
        {
            _instance=new Manager();
        }

        return _instance;
    }
    void setdata(string name,string address,long long phoneno,Customer *cid,Workers *wid)
    {
        custId=cid;
        workerId=wid;
        Person::setData(name,address,phoneno);
    }
    int searchh(string wname1)
    {
        for(int i=0; i<2; i++)
        {
            if(workerId[i].name==wname1 && workerId[i].status==false){
                return i;
            }
            if(workerId[i].name==wname1 && workerId[i].status==true)
            {
                return -1;
            }
        }
        return 0;
    }
    void assignn(string wname,Customer b)
    {
        int wfree=searchh(wname);
        if(wfree!=-1)
        {

            workerId[wfree].assignedTo=b.cId;
            workerId[wfree].status=true;
            workerId[wfree].printDetails();
            cout<<workerId[wfree].name <<" is assigned to customer " <<b.name<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"Not Avaiable Now"<<endl;
        }

    }
    void printDetails()
    {
        int select;
        cout<<endl;
        cout<<"Name of the manager:"<<name<<endl;
        cout<<"Address:"<<address<<endl;
        cout<<"Phone number:"<<phoneno<<endl<<endl;
       for(int k=0;k<3;k++)
        {
            cout<<endl<<"\n1.Customers details\n2.Workers Details\n3.Exit\nEnter option:";
            cin>>select;
            switch(select)
            {
                case 1:
                    cout<<"----------------------------------"<<endl;
                    cout<<"CUSTOMER DETAILS"<<endl;
                    for(int i=0; i<3; i++)
                    {
                        custId[i].printDetails();
                    }
                    break;

                case 2:
                    cout<<"--------------------"<<endl;
                    cout<<"EMPLOYEE DETAILS"<<endl;
                    for(int j=0; j<3; j++)
                    {
                        workerId[j].printDetails();
                    }
                    break;

               case 3:break;

                default:cout<<"Invalid option"<<endl;
                        break;
            }
        }
    }
    float generateBill(string n,PaintType p1)
    {
        float price=0;
        bool found = false;
        for(int i=0;i<2;i++)
        {
            if(custId[i].name==n)
            {
                found = true;
                for(int j=0;j<=0;j++)
                {
                    if(custId[i].matf=="semiglass")
                        price+=-1000;
                    else if(custId[i].matf=="Metallicwave")
                        price+=600;
                    else if(custId[i].matf=="vinylwrap")
                        price+=500;
                    else if(custId[i].matf=="satinfinish")
                        price+=800;
                    if(custId[i].selectColor=="Red")
                    {
                        price-=2500.00;
                        custId[i].printDetails();
                        custId[i].printBill(price);
                        paymentStatus(n);
                    }
                    else if(custId[i].selectColor=="Blue")
                    {
                        price+=3000.00;
                        custId[i].printDetails();
                        custId[i].printBill(price);
                        paymentStatus(n);
                    }
                    else if(custId[i].selectColor=="White")
                    {
                        price+=4000.00;
                        custId[i].printDetails();
                        custId[i].printBill(price);
                        paymentStatus(n);
                    }
                    else if(custId[i].selectColor=="Black")
                    {
                        price+=2000.00;
                        custId[i].printDetails();
                        custId[i].printBill(price);
                        paymentStatus(n);
                    }
                }
            }
        }
        if(!found)
        {
            cout<<"Customer not found"<<endl;
        }
        return 0;
    }
     void paymentStatus(string n)
     {
         for(int i=0;i<2;i++)
         {
             if(custId[i].name==n)
             {
                 if(custId[i].pstatus=="UNPAID")
                 {
                     cout<<"Customer payment status is pending"<<endl;
                     cout<<"------Processing-----"<<endl;
                     custId[i].pstatus="PAID";
                     cout<<"Customer payment status is:"<<custId[i].pstatus<<endl;
                 }
                 else{
                    custId[i].pstatus="PAID";
                    cout<<"Customer Payment is:"<<custId[i].pstatus<<endl;

                 }
             }
         }
    }
};
Manager *Manager::_instance=0;
int main()
{
    int ch;
    //class PaintType objects
    string colors[]= {"Red","White","Blue","Black"};
    PaintType pt1(colors,"satinfinish","vinylWrap","semiglass","Metallicwave");


    //class Car objects
    Car car1("Nano","Blue","Sedan");
    Car car2("Benz","Red","Supercar");
    Car car3("Ferrari","Yellow","super");
    Car carArr[]= {car1,car2,car3};


    //class Customer objects
    Customer c1(1,"Sandeep","Hubli",6246838285,"White","satinfinish",car1);
    Customer c2(2,"Swaroop","Dharwad",7378292992,"Red","semiglass",car2);
    Customer c3(3,"Bharat","Vidyanagar",6488292992,"Blue","vinylwrap",car3);
    Customer cArr[]= {c1,c2,c3};

    //class Worker objects
    Workers e1(1,"Pratik","Unkal",2877372888,false);
    Workers e2(2,"Prasad","Dharwad",2553724888,false);
    Workers e3(3,"Ajay","NTTF",8463848287,false);
    Workers wArr[]= {e1,e2,e3};

    Manager *m1;
    m1=m1->getInstance();
    m1->setdata("Vishal","Hubli",6758749288,cArr,wArr);

    cout<<" *****    *    *****     *****  *****  *****   *****  *****  "<<endl;
    cout<<"*        * *   *    *    *    * *     *       *     * *    * "<<endl;
    cout<<"*       *****  *****     *    * ***   *       *     * *****  "<<endl;
    cout<<" ***** *     * *    *    *****  *****  *****   *****  *    * "<<endl;
    cout<<endl<<"*********************************************************************************"<<endl;
    for(int j=0;j<10;j++)
    {
        cout<<endl<<"\n1.Manager Details\n2.Customers\n3.Workers\n4.Assigned Workers"
        <<"\n5.Generate Bill\n6.Exit\n\nEnter option:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                m1->printDetails();
                break;

            case 2:
                for(int i=0;i<3;i++)
                {
                    cArr[i].printDetails();
                }
                break;

            case 3:
                for(int i=0;i<3;i++)
                {
                    wArr[i].printDetails();
                }
                break;

            case 4:
                m1->assignn("Pratik",c2);
                m1->assignn("Prasad",c1);
                m1->assignn("Prasad",c3);
                break;

            case 5:
                m1->generateBill("Sandeep",pt1);
                m1->generateBill("Swaroop",pt1);
                m1->generateBill("Sandeep",pt1);
                break;

            case 6:
                exit(0);

            default:cout<<"Invalid option"<<endl<<endl;;
        }
    }
}

