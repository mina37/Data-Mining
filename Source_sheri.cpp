
#include "dsList.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Enums.h"
#include"Customer.h"
#include <vector>

using namespace std;

const int total_products = 17;

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

void product_v_n_costumer()
{
	vector<Customer> v;
	v = parse_in();
	ofstream f("productvscostumers.txt");
	//int num_of_products[17] = { 0 };
	int *num_of_products = new int[total_products];
	for (int i = 0; i < total_products; i++)
	{
		num_of_products[i] = 0;
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (unsigned int j = 0; j < v.at(i).prodListReturn().get_size(); j++)
		{
			switch (v.at(i).prodListReturn().get(j))
			{
			case 101:
				num_of_products[0]++;
				break;
			case 102:
				num_of_products[1]++;
				break;
			case 103:
				num_of_products[2]++;
				break;
			case 104:
				num_of_products[3]++;
				break;
			case 105:
				num_of_products[4]++;
				break;
			case 106:
				num_of_products[5]++;
				break;
			case 201:
				num_of_products[6]++;
				break;
			case 202:
				num_of_products[7]++;
				break;
			case 203:
				num_of_products[8]++;
				break;
			case 204:
				num_of_products[9]++;
				break;
			case 205:
				num_of_products[10]++;
				break;
			case 206:
				num_of_products[11]++;
				break;
			case 301:
				num_of_products[12]++;
				break;
			case 302:
				num_of_products[13]++;
				break;
			case 303:
				num_of_products[14]++;
				break;
			case 304:
				num_of_products[15]++;
				break;
			case 305:
				num_of_products[16]++;
				break;
			}
		}
	}
	for (int i = 0; i < total_products; i++)
	{
		f << num_of_products[i] << " ";
		cout << num_of_products[i] << " ";
	}
	f << endl;
	cout << endl;
	
	delete[] num_of_products;
	int num_of_product[2] = { 0 };
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v.at(i).getGender() == 10)
		{
			num_of_product[0] += v.at(i).prodListReturn().get_size();
		}
		else
		{
			num_of_product[1] += v.at(i).prodListReturn().get_size();
		}
	}

	for (int i = 0; i < 2; i++)
	{
		f << num_of_product[i] << " ";
		cout << num_of_product[i] << " ";
	}
	f << endl;
	cout << endl;

	f.close();
}



int main()
{

	//cout << "hello" << endl;

	//dsList<int> d(new Node<int>(10)),d2(new Node<int>(100));
	//
	//d.insertoTail(1);
	//d.insertoTail(2);
	//d.insertoTail(3);
	//d.printList();
	////cout << d.get_size() << endl;
	//d.insertoHead(0);
	//d.printList();
	//////cout << d.get_size() << endl;
	//d.deleteHead();
	//d.printList();
	////cout << d.get_size() << endl;
	//d.deleteTail();
	//d.printList();
	//cout << d.get(0)<<endl;
	//cout << d.get(1) << endl;
	//cout << d.get(2) << endl;

	//d.set(1, 50);
	//d.printList();
	//d.printList();
	//d2.printList();

	//ifstream f("randinputs.txt");
	//string s;
	//getline(f, s);
	//cout << s << endl;
	//f.close();

	product_v_n_costumer();
	
	//d3.printList();
	//cout << d.get_size() << endl;
	//cout << d.get_Head()->get_data() << endl;
	//cout << d.get_Tail()->get_data() << endl;
}