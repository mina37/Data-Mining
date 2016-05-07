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

vector<Customer> parse_in()
{
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
	return c;
}

void placeNoOfCustomers(vector<Customer>cin,int& n, int &s,int &w,int &e) {
	for (unsigned int i = 0;i<cin.size();i++) {
	
		if (cin[i].getPlace() == North) {
			n++;
		}
		if (cin[i].getPlace() == West) {
			w++;
		}

		if (cin[i].getPlace() == East) {
			e++;
		}

		if (cin[i].getPlace() == South) {
			s++;
		}
		
	}

}
///////

void placeNoOfProducts(vector<Customer>cin, int& n, int &s, int &w, int &e) {
	for (unsigned int i = 0;i<cin.size();i++) {
		if (cin[i].getPlace() == North) {
			n+=cin[i].getProductListSize();
		}

		if (cin[i].getPlace() == West) {
			w += cin[i].getProductListSize();
		}

		if (cin[i].getPlace() == South) {
			s += cin[i].getProductListSize();
		}

		if (cin[i].getPlace() == East) {
			e += cin[i].getProductListSize();
		}
	}

}


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
	//place no Of Customers : 
	int northNoOfCustomers=0;
	int southNoOfCustomers=0;
	int westNoOfCustomers=0;
	int eastNoOfCustomers=0;
	placeNoOfCustomers(c, northNoOfCustomers, southNoOfCustomers, westNoOfCustomers, eastNoOfCustomers);
	//writing on output File :
	ofstream fout("outputStat.txt");
	fout << northNoOfCustomers << endl;
	fout << southNoOfCustomers << endl;
	fout << westNoOfCustomers << endl;
	fout << eastNoOfCustomers << endl;
	///////////////////////////////////////////////////////

	//place No Of Products :

	int northNoOfProducts = 0;
	int southNoOfProducts = 0;
	int westNoOfProducts = 0;
	int eastNoOfProducts = 0;
	placeNoOfProducts(c, northNoOfProducts, southNoOfProducts, westNoOfProducts, eastNoOfProducts);
	
	fout << northNoOfProducts << endl;
	fout << southNoOfProducts << endl;
	fout << westNoOfProducts << endl;
	fout << eastNoOfProducts << endl;
	fout.close();
	

	///---------------------------------------///
	//for testing purpose :

	/*cout << "north  : " << northNoOfProducts << endl;
	cout << "south  : " << southNoOfProducts << endl;
	cout << "west  : " << westNoOfProducts << endl;
	cout << "east  : " << eastNoOfProducts << endl;*/

	/*c[0].printProductsList();
	cout<<"sizeCheck : "<<c[0].getProductListSize();*/
	//cout << "Gender: " << c[0].getGender() << endl;
	//cout << "place : " << c[0].getPlace() << endl;

	////////

	/*cout << "north 20 : "<< northNoOfCustomers << endl;
	cout << "east 21 : " << eastNoOfCustomers << endl;
	cout << "west 22 : " << westNoOfCustomers << endl;
	cout << "south 23 : " << southNoOfCustomers << endl;*/


}
