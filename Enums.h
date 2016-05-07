#pragma once
#include "string"

enum  Product_Categories
{
	Domestic = 1, Electronics = 2, Fashion = 3
};
enum Gender {
	Male = 10, Female = 11
};

enum Place {
	North = 20, East = 21, West = 22, South = 23
};
enum Product {
	Beds = 101, Desk = 102, Cupboards = 103,
	Samsung = 201, iphone = 202, laptops = 203,
	Bag = 301, Shoes = 302, Dresses = 303
};

template < typename T>
std::string Get_Enum(T item)
{
	switch (item)
	{
	case 1: return  "Domestic";
	case 2: return "Electronics";
	case 3: return "Fashion";
	case 10: return "Male";
	case 11: return "Female";
	case 20: return "North";
	case 21: return "East";
	case 22: return "West";
	case 23: return "South";

	case 101: return "Beds";
	case 102: return "Desk";
	case 103: return "Cupboards";
	case 201: return "Samsung";
	case 202: return "iphone";
	case 203: return "laptops";
	case 301: return "Bags";
	case 302: return "Shoes";
	case 303: return "Dresses";
	}
	return "";
};

//getEnum:

template < typename T>
std::string GetEnum(T item)
{
	switch (item)
	{
	case 1: return  "Domestic";
	case 2: return "Electronics";
	case 3: return "Fashion";
	case 10: return "Male";
	case 11: return "Female";
	case 20: return "North";
	case 21: return "East";
	case 22: return "West";
	case 23: return "South";

	case 101: return "Beds";
	case 102: return "Desk";
	case 103: return "Cupboards";
	case 201: return "Samsung";
	case 202: return "iphone";
	case 203: return "laptops";
	case 301: return "Bags";
	case 302: return "Shoes";
	case 303: return "Dresses";
	}
	return "";
};

