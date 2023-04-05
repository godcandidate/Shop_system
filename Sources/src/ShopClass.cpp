#include "ShopClass.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <typeinfo>

using namespace std;

bool isfileEmpty(ifstream&);


ShopClass::ShopClass()
{
    name = "Arhin's ShopRite";
    location = "Kotei";
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
        cout << "\n\t\t -------------- Unable to open file, creating file.... ----------------------------\n";

}
void ShopClass::saveHeader(ofstream& file)
{
    file << "\t\t" << name << "  @" << location << endl;
    file << "\t---------------------------------------------\n";
}

void ShopClass::textseparator(string text, int nsize)
{
    string value;
    fields = new string[nsize];

    stringstream ss(text);
    int i=0;
    while (getline(ss, value, ','))
    {
            fields[i] = value;
            i++;
    }
}

string ShopClass::searchfile(string filename, string keyword)
{
    ifstream file(filename);
    string line;

    //skipping the first four lines
    for (int i=0; i < 4; i++)
        getline(file, line);

    while (getline(file, line))
    {
        size_t pos = line.find(keyword);
        if (pos != string::npos)
        {
            return line;
        }
    }
}

void ShopClass::editfile(string filename, string searchword, string oldword, string newword )
{
     // Open the CSV file in read mode and create a temporary file in write mode
    ifstream infile(filename);
    ofstream outfile("temp.csv");

    // Loop through each line of the CSV file
    string line;
    while (getline(infile, line)) {
        // Use a stringstream to retrieve the line of the search result
        stringstream ss(line);

        // Check if the searchword is present in the line
        if (line.find(searchword) != string::npos)
        {
            // Accumulate the modified line with the new values
            cout << "\n Replacing word ..........\n";
            stringstream modified_line;
            string value;
            while (getline(ss, value, ','))
            {
                if (value == oldword)
                {
                    modified_line << newword;
                } else {
                    modified_line << value;
                }
                modified_line << ",";
            }
            modified_line.seekp(-1, ios_base::end); // Remove the last comma

            // Write the modified line to the temporary file
            outfile << modified_line.str() << endl;
        } else {
            // Write the original line to the temporary file
            outfile << line << endl;
        }
    }

    // Close both files and replace the original file with the temporary file
    infile.close();
    outfile.close();
    remove(filename.c_str());
    rename("temp.csv", filename.c_str());

}

ifstream ShopClass::display(string filename)
{
    ifstream mfile(filename);
    string line;

    //skipping the first three lines
    for (int i=0; i < 3; i++)
        getline(mfile, line);

    return mfile;

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
            myfile << "ID,USERNAME,PASSWORD" << endl;
        }
        myfile << user_ID << "," << username << "," << password << endl;
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

void Users::searchUser(string keyword)
{
    string query = ShopClass::searchfile("usersData.txt", keyword);
    if (query.size() != 0)
    {
        cout << "Item found : " << query;
        ShopClass::textseparator(query,5);
        cout << "\n--------VALUES----------\n";

        for (int i = 0; i < 5; i++) {
        cout <<  fields[i] << endl;
        }
        //convert id to float
        float di = stof(fields[0]);
        cout << "-- " << di + 1;
    }
    else
        cout << "Item not found " << endl;

}

void Users::editLogins(string id, string oldword, string newword)
{
    string filename = "loginInfo.txt";
    ShopClass::editfile(filename, id, oldword, newword);
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

void Users::displayUser()
{
    mfile = ShopClass::display("usersData.txt");
    while (getline(mfile, line))
    {
        ShopClass::textseparator(line, 4);
        //display
        cout << setw(5) << left << fields[0]
            << setw(15) << left << fields[1]
            << setw(15) << left << fields[2]
            << setw(15) << left << fields[3] << endl;
        cout << "-----------------------------------------------\n";
    }
    myfile.close();

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
void Products::displayProducts()
{
    mfile = ShopClass::display("productsData.txt");
    while (getline(mfile, line))
    {
        ShopClass::textseparator(line, 4);
        //display
        cout << setw(5) << left << fields[0]
            << setw(15) << left << fields[1]
            << setw(10) << left << fields[2]
            << setw(5) << left << fields[3] << endl;
        cout << "-----------------------------------------------\n";
    }
    myfile.close();
}

void Customers::setCustomer(string fname, string mobile)
{
    name = fname;
    number = mobile;
}

int Transactions::retrieveProduct(string name, int qty)
{
    string results = ShopClass::searchfile("productsData.txt", name);
    if (results.size() != 0)
    {
        cout << results ;
        ShopClass::textseparator(results, 4);
        return stoi(fields[2]);
    }
    else
        cout << "Error!... product " << name << " not found";
}

bool Transactions::setTransact(string tdate, string cashier, string customerName,
                               string customerNumber, string productName,
                               int qty)
{
    date = tdate;
    cashier_name = cashier;
    customer_name = customerName;
    customer_number = customerNumber;
    product_name = productName;
    product_quantity = qty;

    // Retrieve product price from product file
    product_price = retrieveProduct(product_name, product_quantity);
    totalCost = product_price * product_quantity;

    if (product_quantity >= stof(fields[3]))
    {
        cout << "\n only " << fields[3] << " stocks of " << product_name << " is available....";
        return false;
    }
    else
    {
        cout << "\n-------------------------------------------\n";
        cout << "\n Product price: GHc" << product_price << endl;
        cout << "\n Total Amount : GHc" << totalCost << endl;
         return true;
    }
}

void Transactions::setAmountPayed(float amount)
{
    amountPayed = amount;
    balance = amountPayed - totalCost;
    saveTransact();
}

void Transactions::saveTransact()
{
    string filename = "transactsData.txt";
    ShopClass::openfile(filename);

    if (is_fileEmpty)
        {
            ShopClass::saveHeader(myfile);
            myfile << "\t\t\t Transaction info" << endl;
            myfile << "DATE,CASHIER NAME,CUSTOMER NAME,PRODUCT NAME,PRODUCT QUANTITY,TOTAL COST, AMOUNT PAYED, BALANCE" << endl;
        }

        // inserting transaction into a file
        myfile << date << "," << cashier_name << "," << customer_name << "," << product_name
         << "," << product_quantity << "," << totalCost << "," << amountPayed << "," << balance << endl;
        myfile.close();
        cout << "\n\t\t Transaction saved successfully ...... \n";
        //printPaySlip();
}

void Transactions::displayTransact()
{
    mfile = ShopClass::display("transactsData.txt");
    while (getline(mfile, line))
    {
        ShopClass::textseparator(line, 9);
        //display
        cout << setw(10) << left << fields[0]
            << setw(15) << left << fields[1]
            << setw(15) << left << fields[2]
            << setw(15) << left << fields[3]
            << setw(10) << left << fields[4]
            << setw(15) << left << fields[6]
            << setw(15) << left << fields[7]
            << setw(15) << left << fields[8] << endl;
        cout << "----------------------------------------------------------------------------------------------------\n";
    }
    myfile.close();
}
