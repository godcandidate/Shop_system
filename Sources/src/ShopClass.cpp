#include "ShopClass.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

bool isfileEmpty(ifstream&);

ShopClass::ShopClass()
{
    name = "Arhin's ShopRite";
    location = "Kotei";
}

void ShopClass::display()
{
    cout << "Shop Name     : " << name << endl;
    cout << "Shop Location : " << location << endl;
}

void ShopClass::saveHeader(ofstream& file)
{
    file << "\t\t" << name << "  @" << location << endl;
    file << "\t---------------------------------------------\n";
}
void Users::setUser(int id, string fname, string rol,
                    string usname,string pass, string num)
{

    user_ID = id;
    fullname = fname;
    user_role = rol;
    username = usname;
    password = pass;
    user_number = num;

    saveLogins();
}

void Users::saveLogins()
{
    bool isEmpty;

    //Adding Headers
    ifstream file("loginInfo.txt");
    isEmpty = isfileEmpty(file);

    ofstream myfile; // create an ofstream object to write a file
    myfile.open("loginInfo.txt", ios::app); //open the file in append mode

    if (myfile.is_open())
    {
        if (isEmpty)
        {
            ShopClass::saveHeader(myfile);
            myfile << "\t\t\t Login info" << endl;
            myfile << "ROLE,USERNAME,PASSWORD" << endl;
        }
        myfile << user_role << "," << username << "," << password << endl; // write the params to the file separated by comma
        myfile.close();
        cout << "\n\t\t Logins saved successfully ...... \n";
    }
    else
        cout << "\n\t\t -------------- Unable to open file ----------------------------\n";

}


bool isfileEmpty(ifstream& myfile)
{
    if (!myfile.is_open())
    {
        cout << "\n\t\t -------------- Unable to open file ----------------------------\n";
        return 0;
    }
    else
    {
       //check if the file is empty
        if (myfile.peek() == ifstream::traits_type::eof())
        {
            myfile.close();
            return true;
        }

        else
        {
            myfile.close();
            return false;
        }
    }

}

void Users::editLogin(string usname,string pass)
{
    username = usname;
    password = pass;
}

void Users::display()
{
    ShopClass::display();
    cout << "UserID   : " << user_ID << endl;
    cout << "FullName : " << fullname << endl;
    cout << "Role     : " << user_role << endl;
    cout << "UserName : " << username << endl;
    cout << "Password : " << password << endl;
    cout << "Number   : " << user_number << endl;
}

void Products::addProduct(short int id, string name, float price, short int quantity)
{
    Product_ID = id;
    Product_name = name;
    Product_cost = price;
    Product_quantity = quantity;
}

void Products::display()
{
    cout << "Product ID   : " << Product_ID << endl;
    cout << "Product Name : " <<Product_name << endl;
    cout << "Cost    : " << Product_cost << endl;
    cout << "Quantity : " << Product_quantity << endl;
}

void Customers::setCustomer(string fname, string mobile)
{
    name = fname;
    number = mobile;
}

void Customers::displayCustomer()
{
    cout << "Name: " << name << endl;
    cout << "Number: " << number << endl;

}

