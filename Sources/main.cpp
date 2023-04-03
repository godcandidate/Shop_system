
#include "ShopClass.h"
#include <iostream>
using namespace std;



int main() {
/*

    Users user1, user2;
    user1.setUser(1, "Shaukat Bint", "Administrator", "Admin", "pas123", "02567490");
    user2.setUser(2, "Denzel Nii", "Cashier", "Denz", "w23frac", "024567191");


    Products product1, product2;
    product1.addProduct(1, "Indomie",10.00,50);
    product2.addProduct(2, "Egg",2.00,10);


    Users user1;
    user1.searchUser("Shaukat");
    user1.editLogins("1", "ADmin", "administrate");

*/
    Transactions transact;
    bool proceed = transact.setTransact("12/02/23", "Shaukat", "Cephas", "0565322", "Indomie", 9);

    char opt;
    if (proceed)
        cout << "\n Do you want to proceed to payment (y/n): ";
        cin >> opt;
        switch (opt)
        {
            case 'y':
                cout << "proceeding ..... ";
                transact.setAmountPayed(100.00);
                break;
        }
  return 0;
}
