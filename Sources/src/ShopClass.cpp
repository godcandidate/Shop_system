#include "ShopClass.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

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

void Users::setUser(int id, string fname, string rol,
                    string usname,string pass, string num)
{

	user_ID = id;
	fullname = fname;
	user_role = rol;
	username = usname;
	password = pass;
	user_number = num;
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
