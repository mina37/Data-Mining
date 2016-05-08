
#include "dsList.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Enums.h"
#include"Customer.h"
#include <vector>
#include "random.h"

using namespace std;

const int total_products = 17;
ifstream f("randinputs.txt");

vector<Customer> parse_in(int &year)
{
	int i = 0;
	vector<Customer>c;//vector of Customers 
	int x;
	f >> year;
	cout << year << endl;
	while(!f.eof())
	{
		int gender, place;
		dsList<Product> products;
		f >> gender;
		if (gender == year)
			break;
		cout << gender << endl;
		f >> place;
		cout << place << endl;
		while (true)
		{
			f >> x;
			if (x == -1||x==year+1)
				break;
			products.insertoTail(static_cast<Product>(x));
		}
		c.push_back(Customer(gender, place, products));
		cout << x << " ";
	}
	cout << endl;
	return c;
}

void product_v_n_costumer()
{
	if (!f.is_open())
		f.open("randinputs.txt",ifstream::in);
	ofstream fx("productvscostumers.txt");
	vector<Customer> v;

	int *num_of_products = new int[total_products];
	for (int k = 0; k < 8;k++)
	{
		int year;
		v = parse_in(year);
		fx << year << endl;

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
			fx << num_of_products[i] << endl;
			cout << num_of_products[i] << endl;
		}
		v.clear();
	}
	delete[] num_of_products;
	fx.close();
	f.close();
}

void gender_v_products()
{
	if(!f.is_open())
		f.open("randinputs.txt",ifstream::in);
	ofstream fx("gendervproducts.txt");
	int num_of_product[2] = { 0 };
	vector<Customer> v;
	for (int k = 0; k < 8; k++)
	{
		int year;
		v = parse_in(year);
		fx << year << endl;

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
			fx << num_of_product[i] << endl;
			cout << num_of_product[i] << endl;
		}
		v.clear();
	}

	fx.close();
	f.close();
}



int main()
{
	//random();

	product_v_n_costumer();

	gender_v_products();
	
	
}