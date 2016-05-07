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
	Beds = 101, Desk = 102, Cupboards = 103, TV = 104, chairs = 105,tables=106,
	Samsung = 201, iphone = 202, HTC = 203,Nexus=204,sony=205,LG=206,
	Bag = 301, Shoes = 302, Dresses = 303, chemises=304 , pulls=305
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
	case 104: return "TV";
	case 105: return "chairs";
	case 106: return "tables";

	case 201: return "Samsung";
	case 202: return "iphone";
	case 203: return "HTC";
	case 204: return "Nexus";
	case 205: return "Sony";
	case 206: return "LG";

	case 301: return "Bags";
	case 302: return "Shoes";
	case 303: return "Dresses";
	case 304: return "chemises";
	case 305: return "pulls";
	}
	return "";
};

