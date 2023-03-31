#ifndef SHOPCLASS_H
#define SHOPCLASS_H

#include <string>
#include <iostream>
using namespace std;

class ShopClass
{
    private:
        string name;
        string location;

    public:
        ShopClass();
        void display();
        void saveHeader(ofstream&);
    protected:


};

class Users:ShopClass
{
    private:
        int user_ID;
        string fullname;
        string user_role;
        string user_number;
        void saveLogins();
        void saveUser();


    protected:
        string username;
        string password;



    public:
        void setUser(int, string, string, string, string, string);
        void editLogin(string, string);

        void display();
};

class Products:Users
{
    private:
        short int Product_ID;
        string Product_name;
        float Product_cost;
        short int Product_quantity;


    public:
        void addProduct(short int, string, float, short int);
        void display();

};

class Customers:Users
{
    private:
        string name;
        string number;

    public:
        void setCustomer(string, string);
        void displayCustomer();

};

class Payments:Users
{
    private:
        string date;
        float amountToPay;
        float amountPayed;

};

#endif // SHOPCLASS_H
