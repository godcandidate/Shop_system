#include "ShopClass.h"
#include <iostream>
using namespace std;



int main() {

    Users user1, user2;
    user1.setUser(1, "Shaukat Bint", "Administrator", "Admin", "pas123", "02567490");
    user2.setUser(2, "Denzel Nii", "Cashier", "Denz", "w23frac", "024567191");

    Products product1, product2;
    product1.addProduct(1, "Indomie",10.00,50);
    product2.addProduct(2, "Egg",2.00,10);

  return 0;
}

