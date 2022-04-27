#include"CustomExpressionEvaluator.h"
#include <fstream>
#include <iostream>

void CustomExpressionEvaluator::shuffle()
{	
        double temp;
        for (size_t i = 0; i < numberOfOperands_; i++) {
            for (int k = i + 1; k < numberOfOperands_; k++) {
                if (arrayOfOperands_[i] < arrayOfOperands_[k]) {
                    temp = arrayOfOperands_[i];
                    arrayOfOperands_[i] = arrayOfOperands_[k];
                    arrayOfOperands_[k] = temp;
                }
            }
        }
}
void CustomExpressionEvaluator::shuffle(size_t i, size_t j)
{
    double temp;
    for (; i < j; i++) {
        for (size_t k = i + 1; k < j; k++) {
            if (arrayOfOperands_[i] < arrayOfOperands_[k]) {
                temp = arrayOfOperands_[i];
                arrayOfOperands_[i] = arrayOfOperands_[k];
                arrayOfOperands_[k] = temp;
            }
        }
    }

}
double CustomExpressionEvaluator::calculate()
{
    double sum = 0;
    for (int i = 0; i < numberOfOperands_; i++)
    {
        sum += arrayOfOperands_[i] * (i + 1);
    }
    return sum;
}

void CustomExpressionEvaluator::logToScreen()
{
    cout << numberOfOperands_ << " operands:" << endl;
    for (int i = 0; i < numberOfOperands_ - 1; i++) 
    {
		if (arrayOfOperands_[i] >= 0) 
        {
            cout << arrayOfOperands_[i] << " * " << i + 1 << " + ";
        }
        else
        {
            cout << "(" << arrayOfOperands_[i] << ")" << " * " << i + 1 << " + ";
        }
    }
    cout << arrayOfOperands_[numberOfOperands_ - 1] << " * " << numberOfOperands_ << endl << " -> " << calculate() << endl << endl;
}

void CustomExpressionEvaluator::logToFile(const string& filename)
{
    ofstream fout;
    fout.open("C:/Users/User/source/repos/2 курс/лабы по проге/лаба 3/ConsoleApplication1" + filename + ".txt", fstream::app);
    cout << " CustomExpressionEvaluator::logToFile: " << filename << endl;
    for (int i = 0; i < numberOfOperands_ - 1; i++) 
    {
        if (arrayOfOperands_[i] >= 0)
        {
            fout << arrayOfOperands_[i] << " * " << i + 1 << " + ";
        }
        else
        {
            fout << "(" << arrayOfOperands_[i] << ")" << " * " << i + 1 << " + ";
        }
    }
    fout << arrayOfOperands_[numberOfOperands_ - 1] << " * " << numberOfOperands_ << endl << " -> " << calculate() << endl << endl;

}
