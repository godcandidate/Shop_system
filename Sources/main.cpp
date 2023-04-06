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
//global

struct TransactInfo
{
    string date;
    string customer_name;
    string customer_mobile;
    string* product_name;
    float* product_price = nullptr;
    int* product_quantity = nullptr;
    int nproducts;
    float* cost = nullptr;
    float totalcost;
    float amountPayed;
    float balance;
};
TransactInfo transactinfo;

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

UserInfo currentUser;
bool login()
{
    Users user1;
    cout << "\n\t\t Enter username : ";
    cin >> currentUser.usname;
    cout << "\n\t\t Enter password : ";
    cin >> currentUser.pass;
    currentUser.name = user1.searchLogin(currentUser.usname, currentUser.pass);
    if (currentUser.name != "")
        return true;
    else
        return false;

}

void slip_table(string name, float price, int quantity, float cost)
{
    cout << "\t " << setw(20) << left << name
            << setw(15) << left << price
            << setw(15) << left << quantity
            << setw(15) << left << cost << endl;
    cout << "\t ------------------------------------------------------------\n";

}

int main()
{
    int choice;
    char opt;
    bool success;

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
        header("LOGIN");
        bool success = login();

        system("cls");
        if (success)
        {
            header("CASHIER");
            cout << "\n\t       Welcome " << currentUser.name <<", select your option?\n" << endl;
            cout << "\t\t 1. Purchase Item"<<endl;
            cout << "\t\t 2. View your Transactions "<<endl;
            cout << "\t\t 3. Change credentials"<<endl;
            cout << "\n\n\t         *************************************\n"<<endl;
            cout << "\t\t Please select: ";
            cin >> choice;

            system("cls");
            switch (choice)
            {
                case 1:
                    header("Purchase Item");
                    cout << "n\t\t Enter customer details"<<endl;
                    cin.ignore();
                    cout << "\n\t\t Fullname : ";
                    getline(cin, transactinfo.customer_name);
                    cout << "\n\t\t Mobile   : ";
                    cin >> transactinfo.customer_mobile;
                    cout << "\n\t\t Number of products to purchase: ";
                    cin >> transactinfo.nproducts;

                    transactinfo.product_name = new string[transactinfo.nproducts];
                    transactinfo.product_price = new float[transactinfo.nproducts];
                    transactinfo.product_quantity = new int[transactinfo.nproducts];
                    transactinfo.cost = new float[transactinfo.nproducts];

                    for (int i = 0; i < transactinfo.nproducts; i++)
                    {
                        system("cls");
                        header("PURCHASING ITEM ");
                        cout << "\n\t\t Product "<< i + 1 << endl;
                        cin.ignore();
                        cout << "\n\t\t Name     : ";
                        getline(cin, transactinfo.product_name[i]);
                        cout << "\n\t\t Quantity : ";
                        cin >> transactinfo.product_quantity[i];
                        success = transact1.isproceed(transactinfo.product_name[i], transactinfo.product_quantity[i]);

                        //transact;
                        if (success)
                        {
                            transactinfo.cost[i] = transact1.getCost();
                            transactinfo.product_price[i] = transact1.getPrice();
                            cout << "\n\t Press any key to continue: ";
                            cin >> opt;
                        }
                        else
                        {
                            cout << "\n\t Press any key to continue: ";
                            cin >> opt;
                        }

                    }
                    for (int i = 0; i < transactinfo.nproducts; i++)
                    {
                        transactinfo.totalcost += transactinfo.cost[i];
                    }
                    system("cls");
                    header("PAYMENT");
                    cout << "\n\t Total Amount : GHc" << transactinfo.totalcost;
                    cout << "\n\t Amount Payed : GHc";
                    cin >> transactinfo.amountPayed;

                    //
                    if (transactinfo.amountPayed >= transactinfo.totalcost)
                    {
                        transactinfo.balance = transactinfo.amountPayed - transactinfo.totalcost;
                        system("cls");
                        header("PAYSLIP");
                        cout << "\n\t\t Cashier name     : " << currentUser.name;
                        cout << "\n\t\t Customer name    : " << transactinfo.customer_name;
                        //loop

                        cout << "\n\n\t " << setw(20) << left << "Product Name"
                        << setw(15) << left << "Price"
                        << setw(15) << left << "Quantity"
                        << setw(15) << left << "COST" << endl;
                        cout << "\t ------------------------------------------------------------\n";
                        for (int i = 0; i < transactinfo.nproducts; i++)
                        {
                            //save each transaction
                            transact1.setTransact("12/03/23", currentUser.name, transactinfo.customer_name,
                                                  transactinfo.customer_mobile);
                            slip_table(transactinfo.product_name[i], transactinfo.product_price[i],
                                        transactinfo.product_quantity[i], transactinfo.cost[i]);
                        }
                        cout << "\t__________________________________\n";
                        cout << "\t " << setw(15) << left << "Total Cost   : GHc" << transactinfo.totalcost << endl;
                        cout << "\t " << setw(15) << left << "Amount Payed : GHc" << transactinfo.amountPayed << endl;
                        cout << "\t " << setw(15) << left << "Balance      : GHc" << transactinfo.balance << endl;
                        cout << "\t___________________________________\n";
                    }
                    else
                        cout << "\n\t\t Transaction failed, insufficient balance";





                    break;

                case 2:
                    header("Transactions");
                    transact1.searchTransact(currentUser.name);
                    break;
            }
        }

    }
    return 0;
}
