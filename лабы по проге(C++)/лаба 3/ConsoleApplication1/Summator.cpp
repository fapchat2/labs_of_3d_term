#include "Summator.h"
#include <fstream>
#include <iostream>


double Summator::calculate()
{
	double sum = 0;
	for (size_t i = 0; i < numberOfOperands_; i++)
	{
		sum += arrayOfOperands_[i];
	}
	return sum;
}

void Summator::logToScreen()
{
	cout << numberOfOperands_ << " operands:" << endl;

	for (int i = 0; i < numberOfOperands_ - 1; i++) {
		if (arrayOfOperands_[i] >= 0) 
		{
			cout << arrayOfOperands_[i] << " + ";
		} 
		else
		{
			cout << "(" << arrayOfOperands_[i] << ")" << " + ";
		}

	}
	cout << arrayOfOperands_[numberOfOperands_ - 1] << endl << " -> " << calculate() << endl << endl;

}

void Summator::logToFile(const string& filename)
{
	ofstream fout;
	fout.open("C:/Users/User/source/repos/2 курс/лабы по проге/лаба 3/ConsoleApplication1" + filename + ".txt", fstream::app);
	cout << " Multiplier::logToFile: " << filename << endl;
	for (int i = 0; i < numberOfOperands_ - 1; i++) {

		if (arrayOfOperands_[i] >= 0)
		{
			fout << arrayOfOperands_[i] << " + ";
		}
		else
		{
			fout << "(" << arrayOfOperands_[i] << ")" << " + ";
		}
	}
	fout << arrayOfOperands_[numberOfOperands_ - 1] << endl << " -> " << calculate() << endl << endl;

}
