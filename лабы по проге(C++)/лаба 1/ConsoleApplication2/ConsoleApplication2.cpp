//Написать программу, которая преобразует одномерный массив (1D) в двумерный (2D)
//(или наоборот), в соответствии с вариантом.Необходимо оформить в отдельных
//функциях код следующих действий : 1) инициализация массива; 2) вывод массива; 3)
//преобразование массива(создание нового массива с другой структурой).Память под
//массивы выделять динамически и для доступа к элементам использовать указатели.
//Ввод - вывод данных организовать средствами iostream и iomanip

//Преобразование: 2D → 1D.Двумерный массив 5х3 вещественных чисел необходимо
//выложить в один ряд по элементам слева направо и снизу вверх.
//Инициализация : заполнить массив числами x[i][j] = sin(i–j) + cos(i + j).
//Вывод на экран : на каждый элемент массива отвести 14 позиций.

#include <iostream>
#include <iomanip>




double** initialization(int rows, int cols) {

	double** firstArray = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		*(firstArray + i) = new double[cols];
		for (int j = 0; j < cols; ++j)
			(*(firstArray + i))[j] = sin(i - j) + cos(i + j);
	}
	return firstArray;
}


void output(double *array) {


	for (size_t i = 0; i < 15; i++)
	{
		std::cout << std::setw(14) << *(array + i);
		if ((i + 1) % 3 == 0) {
			std::cout << std::endl;
		}
	}

}

double* transform(double (**array)) {

	double* lastArray = new double[15];
	int k = 0;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			*(lastArray + k) = (*(array + i))[j];
			++k;
		}
	}
	return lastArray;
}

int main()
{
	double** firstArray = initialization(5, 3);
	double* lastArray = transform(firstArray);

	for (size_t i = 0; i < 5; i++)
	{
		delete[] firstArray[i];
	}
	delete[] firstArray;

	output(lastArray);

	delete[] lastArray;

}


