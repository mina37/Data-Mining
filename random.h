#pragma once

#include <ctime>
#include <fstream>
using namespace std;

int random()
{
	srand(time(NULL));
	fstream f;
	f.open("randinputs.txt");
	for (int year = 2009;year <= 2016;year++)
	{
		//f << year << endl;
		for (int customers = 0; customers <= (rand() % 10 + 10) ;customers++)
		{
			f << rand() % 2 + 10 << " ";
			f << rand() % 4 + 20 << " ";
			for (int products = 0; products <= (rand() % 10 + 5);products++)
				f << rand() % 7 + (rand() % 3 + 1) * 100 << " ";
			f << "-1" << endl;
		}
	}
	f.close();
	return 0;
}