#pragma once

#include <ctime>
#include <fstream>
using namespace std;

int random()
{
    const int base = 10;
    const int div  = 10;
	srand(time(NULL));
	fstream f;
	f.open("randinputs.txt");
	for (int year = 2009;year <= 2016;year++)
	{
		f << year << endl;
		for (int customers = 0; customers <= (rand() % div + base) ;customers++)
		{
			f << rand() % 2 + 10 << " ";
			f << rand() % 4 + 20 << " ";
			for (int products = 0; products <= (rand() % div + base);products++)
				f << rand() % 7 + (rand() % 3 + 1) * 100 << " ";
			f << "-1" << endl;
		}
        f << year;
        if (year!=2016)
            f << endl;
	}
	f.close();
	return 0;
}