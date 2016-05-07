#include <iostream>
#include <string>
#include <fstream>
#include<vector>
//implemented :
#include "dsList.h"
#include "Enums.h"
#include "string"
#include"Customer.h"
using namespace std;
void main() {
	ifstream f("randinputs.txt");
	int i = 0;
	vector<Customer>c;//vector of Customers 
	while (!f.eof())
	{
		int x, gender, place;
		dsList<Product> products;
		f >> gender;
		f >> place;
		while (true)
		{
			f >> x;
			if (x == -1)
				break;
			products.insertoTail(static_cast<Product>(x));
		}
		c.push_back(Customer(gender, place, products));
	}

	f.close();


	//for testing purpose :

	/*c[0].printProductsList();
	cout << "Gender: " << c[0].getGender()<<endl;
	cout << "place : " << c[0].getPlace()<<endl;*/
	
	
} 
