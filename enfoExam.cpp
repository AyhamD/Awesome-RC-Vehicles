// enfoExam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "radio.h"
#include <iostream>


int main()
{
    size_t rows , columns;
    cout << "ange storlek p� bana" << "\n";
    cin >> rows;
    columns = rows;
    radioCar cars(rows, columns);
    string inmatningKommando = "";
    std::cout << "V�nligen skriva in sp�r" << std::endl << "F g� fram�t" << "\n" << "R rotera mot h�ger" << "\n" << "B g� bak�t" << "\n" << "L rotera mot v�nster"<< "\n";
    std::cin >> inmatningKommando;
    cars.movePath(cars.changeToUpperCase(inmatningKommando));
    if (!cars.isItSolved) {
        cars.print();
    }
    else {
        cout << "Det g�r inte att g� via den bana" << endl;
    }
    return 0;
}
