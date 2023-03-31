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

void ShopClass::openfile(string filename)
{
    //Adding Headers
    ifstream file(filename);
    is_fileEmpty = isfileEmpty(file);

    //writing to file
    // // create an ofstream object to write a file
    myfile.open(filename, ios::app); //open the file in append mode

    if (myfile.is_open())
        return;
    else
        cout << "\n\t\t -------------- Unable to open file ----------------------------\n";

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

    saveUser();
    saveLogins();
    cout << "\n\t\t User's details saved successfully ...... \n";
}

void Users::saveLogins()
{
    string filename = "loginInfo.txt";
    ShopClass::openfile(filename);

    if (is_fileEmpty)
        {
            ShopClass::saveHeader(myfile);
            myfile << "\t\t\t Login info" << endl;
            myfile << "ROLE,USERNAME,PASSWORD" << endl;
        }
        is_fileEmpty = "";
        myfile << user_role << "," << username << "," << password << endl;
        myfile.close();
}

void Users::saveUser()
{
    string filename = "usersData.txt";
    ShopClass::openfile(filename);

    if (is_fileEmpty)
        {
            ShopClass::saveHeader(myfile);
            myfile << "\t\t\t User info" << endl;
            myfile << "ID,FULLNAME,ROLE,NUMBER" << endl;
        }
        myfile << user_ID << "," << fullname << "," << user_role << "," << user_number <<  endl;
        myfile.close();
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
    saveProduct();
}

void Products::saveProduct()
{
    string filename = "productsData.txt";
    ShopClass::openfile(filename);

    if (is_fileEmpty)
        {
            ShopClass::saveHeader(myfile);
            myfile << "\t\t\t Product info" << endl;
            myfile << "ID,NAME,COST,QUANTITY" << endl;
        }
        myfile << Product_ID << "," << Product_name << "," << Product_cost << "," << Product_quantity <<  endl;
        myfile.close();
        cout << "\n\t\t Product's details saved successfully ...... \n";
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
