#pragma once
#include <iostream>
#include <string>
#include<vector>
//implemented headers :
#include "dsList.h"
#include "Enums.h"
#include "string"

class Customer {

private:
	Gender gen;
	Place pl;
	dsList<Product>prodList; //list of customer products

public:
	//constructor :
	Customer(int gInt, int pInt, dsList <Product> prList) {
		gen = static_cast<Gender>(gInt);
		pl = static_cast<Place>(pInt);
		prodList = prList;
	}
	////////////////////////////
	//some getters :
	Gender getGender()
	{
		return gen;
	}
	Place getPlace()
	{
		return pl;
	}
	dsList<Product>prodListReturn() {

		return prodList;
	}

	//print all products in a list form : 
	void printProductsList() {
		prodList.printList();
	}

	//endOfclass.

};
