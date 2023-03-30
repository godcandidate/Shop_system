#include "ShopClass.h"

using namespace std;

int main()
{
	ShopClass shop;
  	cout << "-------------------------------------------------------------\n" << endl;
  	cout << "Info of System\n" << endl;
  	shop.display();

	cout << "\n";
	cout << "-------------------------------------------------------------\n" << endl;
	cout << "Info of User 1\n" << endl;

	// User
	Users user1;

	user1.setUser(12, "Shaukat", "Admin", "LiveOn" ,"pass123", "023167281");
	user1.display();
	cout << "-------------------------------------------------------------\n" << endl;
	cout << "After changing login info\n" << endl;
	user1.editLogin("Shin", "pass");
	user1.display();

	//Product
	cout << "-------------------------------------------------------------\n" << endl;
	cout << "Info of Product 1\n" << endl;
	Products product1;

	product1.addProduct(1, "Indomie", 6.00, 10);


	return 0;
}
