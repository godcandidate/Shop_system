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
         if (line.substr(0, keyword.length()) == keyword) {
            return line;
        }
    }
}

void ShopClass::editfile(string filename, string searchword, string oldword, string newword )
{
    bool success;
     // Open the CSV file in read mode and create a temporary file in write mode
    ifstream infile(filename);
    ofstream outfile("temp.csv");

    // Loop through each line of the CSV file
    string line;
     //skipping the first three lines

    while (getline(infile, line)) {
        // Use a stringstream to retrieve the line of the search result
        stringstream ss(line);

        // Check if the searchword is present in the line
        if (line.substr(0, searchword.length()) == searchword)
        {
            // Accumulate the modified line with the new values
            stringstream modified_line;
            string value;
            while (getline(ss, value, ','))
            {
                if (value == oldword)
                {
                    success = true;
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

    if (success)
        cout << "\n Edited successfully..........\n";
    else
        cout << "\n Edit was unsuccessfully, check spellings of old word..........\n";


}

void ShopClass::deletefile(string filename, string keyword)
{
    int st = 0;
    string temp_filename = "temp.txt";
    bool success = false;
    ifstream input_file(filename);
    ofstream output_file(temp_filename);

    string line;
    // initialize to false
    while (getline(input_file, line)) {
        if (line.substr(0, keyword.length()) == keyword) {
            success = true;
        }
        else
           output_file << line << endl;
    }

    input_file.close();
    output_file.close();
    if (success) {
        remove(filename.c_str());
        rename(temp_filename.c_str(), filename.c_str());
        cout << "\n\t\t Deletion successful." << endl;
    }
    else {
        remove(temp_filename.c_str());
        cout << "\n\t\t Deletion failed: word not found." << endl;
    }



}

string ShopClass::searchWord(string filename, string keyword)
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
            myfile << "ID,FULLNAME,USERNAME,PASSWORD" << endl;
        }
        myfile << user_ID << ","<< fullname << "," << username << "," << password << endl;
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
        ShopClass::textseparator(query,4);

        //displaying results
        cout << "\n\t\t ID       : " << fields[0];
        cout << "\n\t\t Fullname : " << fields[1];
        cout << "\n\t\t Role     : " << fields[2];
        cout << "\n\t\t Number   : " << fields[3];
        /*
        //convert id to float
        float di = stof(fields[0]);
        cout << "-- " << di + 1;*/
    }
    else
        cout << "Item not found " << endl;

}

void Users::editLogins(string id, string oldword, string newword)
{
    string filename = "loginInfo.txt";
    ShopClass::editfile(filename, id, oldword, newword);
}

void Users::editUser(string id, string oldword, string newword)
{
    string filename = "usersData.txt";
    ShopClass::editfile(filename, id, oldword, newword);
}

void Users::deleteUser(string keyword)
{
    string filename = "usersData.txt";
    ShopClass::deletefile(filename, keyword);
}

string Users::searchLogin(string username, string password)
{
    string name;
     // Open the CSV file in read mode and create a temporary file in write mode
    ifstream infile("loginInfo.txt");

    // Loop through each line of the CSV file
    string line;
    while (std::getline(infile, line)) {
        if (line.find(username) != std::string::npos && line.find(password) != std::string::npos) {
            textseparator(line,4);
            name = fields[1];
            break;
        }
        else
            name = "";
    }

    // Close both files and replace the original file with the temporary file
    infile.close();
    return name;

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
        cout << "\t " << setw(10) << left << fields[0]
            << setw(15) << left << fields[1]
            << setw(15) << left << fields[2]
            << setw(15) << left << fields[3] << endl;
        cout << "--------------------------------------------------------------\n";
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

void Products::searchProduct(string keyword)
{
    string query = ShopClass::searchfile("productsData.txt", keyword);
    if (query.size() != 0)
    {
        ShopClass::textseparator(query,4);

        //displaying results
        cout << "\n\t\t ID        : " << fields[0];
        cout << "\n\t\t Name      : " << fields[1];
        cout << "\n\t\t Price(GHc): " << fields[2];
        cout << "\n\t\t Quantity  : " << fields[3];
    }
    else
        cout << "\n\t\t Item not found............" << endl;
}

void Products::editProduct(string id, string oldword, string newword)
{
    string filename = "productsData.txt";
    ShopClass::editfile(filename, id, oldword, newword);
}

void Products::deleteProduct(string keyword)
{
    string filename = "productsData.txt";
    ShopClass::deletefile(filename, keyword);

}
void Products::displayProducts()
{
    mfile = ShopClass::display("productsData.txt");
    while (getline(mfile, line))
    {
        ShopClass::textseparator(line, 4);
        //display
        cout << "\t  " << setw(10) << left << fields[0]
            << setw(15) << left << fields[1]
            << setw(10) << left << fields[2]
            << setw(5) << left << fields[3] << endl;
        cout << "\t-----------------------------------------------\n";
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
    string results = ShopClass::searchWord("productsData.txt", name);
    if (results.size() != 0)
    {
        ShopClass::textseparator(results, 4);
        return stof(fields[2]);
    }
    else
        return 0;
}

float Transactions::getCost()
{
    return totalCost;
}
float Transactions::getPrice()
{
    return product_price;
}
bool Transactions::isproceed(string productName, int quantity)
{
    // Retrieve product price from product file
    product_name = productName;
    product_quantity = quantity;

    product_price = retrieveProduct(productName, quantity);
    totalCost = product_price * quantity;

    if (product_quantity >= stof(fields[3]))
    {
        cout << "\n\t\t only " << fields[3] << " stocks of " << product_name << " is available............";
        return false;
    }
    else
    {
        cout << "\n\t\t -------------------------------------------\n";
        cout << "\n\t\t  Product price: GHc" << product_price << endl;
        cout << "\n\t\t  Cost         : GHc" << totalCost << endl;
         return true;
    }
}

void Transactions::setTransact(string tdate, string cashier, string customerName,
                               string customerNumber)
{
    date = tdate;
    cashier_name = cashier;
    customer_name = customerName;
    customer_number = customerNumber;
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
            myfile << "DATE,CASHIER-NAME,CUSTOMER-NAME,MOBILE,PRODUCT,QUANTITY,TOTAL-COST" << endl;
        }

        // inserting transaction into a file
        myfile << date << "," << cashier_name << "," << customer_name << "," << customer_number << ","<< product_name
         << "," << product_quantity << "," << totalCost << endl;
        myfile.close();
}

void Transactions::displayTransact()
{
    mfile = ShopClass::display("transactsData.txt");
    while (getline(mfile, line))
    {
        ShopClass::textseparator(line, 7);
        //display
        cout << "\t " << setw(15) << left << fields[0]
            << setw(18) << left << fields[1]
            << setw(18) << left << fields[2]
            << setw(15) << left << fields[3]
            << setw(15) << left << fields[4]
            << setw(10) << left << fields[5]
            << setw(15) << left << fields[6] << endl;
        cout << "-------------------------------------------------------------------------------------------------------------\n";
    }
    myfile.close();
}

void Transactions::searchTransact(string keyword)
{
    ifstream file("transactsData.txt");
    string line;
    int count = 0;

     //display
        cout << "\t " << setw(10) << left << "DATE"
            << setw(15) << left << "CASHIER NAME"
            << setw(15) << left << "CUSTOMER NAME"
            << setw(15) << left << "MOBILE"
            << setw(15) << left << "PRODUCT NAME"
            << setw(10) << left << "QUANTITY"
            << setw(15) << left << "TOTAL COST"<< endl;
        cout << "--------------------------------------------------------------------------------------------------------------\n";

    //skipping the first four lines
    for (int i=0; i < 4; i++)
        getline(file, line);

    while (getline(file, line))
    {
        size_t pos = line.find(keyword);

        if (pos != string::npos)
        {
           ShopClass::textseparator(line, 9);
            //display
            cout << "\t " << setw(10) << left << fields[0]
                << setw(15) << left << fields[1]
                << setw(15) << left << fields[2]
                << setw(15) << left << fields[3]
                << setw(10) << left << fields[4]
                << setw(15) << left << fields[5]
                << setw(15) << left << fields[6]
                << setw(15) << left << fields[7] << endl;
            cout << "----------------------------------------------------------------------------------------------------------\n";
            count++;
        }
    }
    if (count == 0)
        cout << "\t\t No transaction made ........"<<endl;
}
