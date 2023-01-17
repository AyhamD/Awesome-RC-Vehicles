// enfoExam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "radio.h"
#include <iostream>


int main()
{
    size_t rows , columns;
    cout << "ange storlek på bana" << "\n";
    cin >> rows;
    columns = rows;
    radioCar cars(rows, columns);
    string inmatningKommando = "";
    std::cout << "Vänligen skriva in spår" << std::endl << "F gå framåt" << "\n" << "R rotera mot höger" << "\n" << "B gå bakåt" << "\n" << "L rotera mot vänster"<< "\n";
    std::cin >> inmatningKommando;
    cars.movePath(cars.changeToUpperCase(inmatningKommando));
    if (!cars.isItSolved) {
        cars.print();
    }
    else {
        cout << "Det går inte att gå via den bana" << endl;
    }
    return 0;
}
