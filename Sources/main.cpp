#include "ShopClass.h"
#include <iostream>

using namespace std;
//structs

struct ProductItem
{
    int id;
    string name;
    float price;
    short int quantity;
};

struct UserInfo
{
    int id;
    string name;
    string usname;
    string pass;
    string role;
    string number;
};

void header(string heading)
{
    cout << "\n\t\t\t "<< heading <<endl;
    cout << "\t         *************************************\n"<<endl;
}

void manage()
{
    cout << "\n\t        Enter what to do?\n" << endl;
    cout << "\t\t 1. View all"<<endl;
    cout << "\t\t 2. Add"<<endl;
    cout << "\t\t 3. Delete "<<endl;
    cout << "\t\t 4. Edit"<<endl;
    cout << "\n\n\t         *************************************\n"<<endl;
    cout << "\t\t Please select: ";
}

char deleteItem()
{
    char opt;
    cout << "\n\n\t\t Are you sure you want to delete this (y/n): " ;
    cin >> opt;
    return opt;
}
//Global
UserInfo editItem;
void edit()
{
    cout << "\n\n\t\t Enter old value: ";
    cin >> editItem.usname;
    cout << "\n\t\t Enter new value  : ";
    cin >> editItem.pass;
}

int main()
{
    int choice;
    char opt;

    //STRUCTS
    ProductItem productitem;
    UserInfo userinfo;

    //CLASSES
    Products product1;
    Users user1;
    Transactions transact1;

    cout << "\n\n\t        Which category do you fall under?\n" << endl;
    cout << "\t\t 1. Administrator"<<endl;
    cout << "\t\t 2. Cashier \n\n"<<endl;
    cout << "\t         *************************************\n"<<endl;
    cout << "\t\t Please select: ";
    cin >> choice;

	system("cls");
    if (choice == 1)
    {
        cout << "\n\t         *************************************\n"<<endl;
        cout << "\n\t        What activity do you want to undertake?\n" << endl;
        cout << "\t\t 1. Manage Cashiers"<<endl;
        cout << "\t\t 2. Manage Products "<<endl;
        cout << "\t\t 3. Display all Transactions"<<endl;
        cout << "\n\n\t         *************************************\n"<<endl;
        cout << "\t\t Please select: ";
        cin >> choice;

        system("cls");

        // MANAGE CASHIERS
        if (choice == 1)
        {
            header("MANAGE CASHIERS");
            manage();
            cin >> choice;

            system("cls");
            switch (choice)
            {
                // View all cashiers
                case 1:
                    header("ALL USERS");
                    user1.displayUser();
                break;

                //Add New USER
                case 2:
                    header("ADD NEW USER");
                    cout << "\n\t\t ID       : ";
                    cin >> userinfo.id;
                    cin.ignore();
                    cout << "\n\t\t Fullname : ";
                    getline(cin, userinfo.name);
                    cout << "\n\t\t Role     : ";
                    cin >> userinfo.role;
                    cout << "\n\t\t Username : ";
                    cin >> userinfo.usname;
                    cout << "\n\t\t Password : ";
                    cin >> userinfo.pass;
                    cout << "\n\t\t Mobile   : ";
                    cin >> userinfo.number;

                    cout << "\n\t Do you want save it (y/n): ";
                    cin >> opt;
                    if (opt == 'y')
                    {
                        user1.setUser(userinfo.id, userinfo.name, userinfo.role, userinfo.usname,
                                      userinfo.pass, userinfo.number);
                    }
                    break;

                //Delete
                case 3:
                    header("DELETE USER");
                    cout << "\n\t\t Enter User ID : ";
                    cin >> userinfo.name;
                    user1.searchUser(userinfo.name);
                    opt = deleteItem();
                    if (opt == 'y')
                        user1.deleteUser(userinfo.name);
                    break;

                //Edit user
                case 4:
                    header("EDIT USER");
                    cout << "\n\t\t Enter userID : ";
                    cin >> userinfo.name;
                    cout << "\n\t\t ---------- RESULTS -------------\n";
                    user1.searchUser(userinfo.name);
                    cout << "\n\t\t ----------         -------------\n";
                    edit();
                    user1.editUser(userinfo.name,  editItem.usname, editItem.pass);
                    break;

            }
        }
        //MANAGE PRODUCTS
        else if (choice == 2)
        {
            header("MANAGE PRODUCTS");
            manage();
            cin >> choice;

            system("cls");
            switch (choice)
            {
                //Display all products
                case 1:
                    header("ALL PRODUCTS");
                    product1.displayProducts();
                    break;

                //Add Product
                case 2:
                    header("ADD PRODUCT");
                    cout << "\n\t\t ID       : ";
                    cin >> productitem.id;
                    cin.ignore();
                    cout << "\n\t\t NAME     : ";
                    getline(cin, productitem.name);
                    cout << "\n\t\t PRICE    : GHc";
                    cin >> productitem.price;
                    cout << "\n\t\t QUANTITY : ";
                    cin >> productitem.quantity;

                    cout << "\n\t Do you want save it (y/n): ";
                    cin >> opt;
                    if (opt == 'y')
                    {
                        product1.addProduct(productitem.id, productitem.name, productitem.price,
                                            productitem.quantity);
                    }
                    break;

                //Delete
                case 3:
                    header("DELETE PRODUCT");
                    cout << "\n\t\t Enter ProductID : ";
                    cin >> productitem.name;
                    product1.searchProduct(productitem.name);
                    opt = deleteItem();

                    if (opt == 'y')
                        product1.deleteProduct(productitem.name);
                    break;

                //Edit user
                case 4:
                    header("EDIT PRODUCT");
                    cout << "\n\t\t Enter ProductID : ";
                    cin >> productitem.name;
                    cout << "\n\t\t ---------- RESULTS -------------\n";
                    product1.searchProduct(productitem.name);
                    cout << "\n\t\t ----------         -------------\n";
                    edit();
                    product1.editProduct(productitem.name, editItem.usname, editItem.pass);
                    break;
            }
        }
        else if (choice == 3)
        {
            header("Transactions");
            transact1.displayTransact();
        }
   }

    else if (choice == 2)
    {
        cout << "\n\t         *************************************\n"<<endl;
        cout << "\n\t        What activity do you want to undertake?\n" << endl;
        cout << "\t\t 1. Customer Service"<<endl;
        cout << "\t\t 2. Manage Product "<<endl;
        cout << "\t\t 3. View Product"<<endl;
        cout << "\n\n\t         *************************************\n"<<endl;
        cout << "\t\t Please select: ";
         cin >> choice;

		system("cls");
          if (choice == 1)
          {
              cout << "\n\t         *************************************\n"<<endl;
              cout << "\n\t        What again do you want to do?\n" << endl;
              cout << "\t\t 1. Register Customer"<<endl;
              cout << "\t\t 2. Select items purchased "<<endl;
              cout << "\t\t 3. Add process to database"<<endl;
              cout << "\t\t 3. Print PaySlip"<<endl;
              cout << "\n\n\t         *************************************\n"<<endl;
              cout << "\t\t Please select: ";
              cin >> choice;
          }

    }
    return 0;
}

