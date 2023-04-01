#ifndef SHOPCLASS_H
#define SHOPCLASS_H

#include <string>
#include <iostream>
#include <fstream>
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
        void openfile(string);
        void textseparator(string, int);


    protected:
        ofstream myfile; //stores an open file
        bool is_fileEmpty;
        string searchfile(string, string); // search results found
        string* fields = nullptr; // points to the data values in a search results
        void editfile(string, string, string, string);

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
        void editLogins(string, string, string);
        void searchUser(string);

        void display();
};

class Products:ShopClass
{
    private:
        short int Product_ID;
        string Product_name;
        float Product_cost;
        short int Product_quantity;
        void saveProduct();


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

class Transactions:Users
{
    private:
        string date;
        string cashier_name;
        string customer_name;
        string customer_number;
        string product_name;
        short int product_quantity;
        float product_price;
        float totalCost;
        float amountPayed;
        float balance;

    public:

};

#endif // SHOPCLASS_H
