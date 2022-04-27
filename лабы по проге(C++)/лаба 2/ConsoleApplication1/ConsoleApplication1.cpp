//Написать классы Vector и Matrix для хранения и обработки одномерных и
//двумерных массивов, соответственно.Реализовать задание 2 лабораторной работы №1
//с помощью созданных классов.Все функции оформить в виде методов классов.
//В коде отразить следующее :
// Выделение и освобождение динамической памяти производить в конструкторах и
//деструкторах классов, соответственно.
// В классе Vector перегрузить оператор индексации[].В классе Matrix добавить
//методы T at(int i, int j) const и setAt(int i, int j, T val), которые
//позволяют получить и установить значение элемента массива с индексом[i][j], T –
//это тип элементов массива по варианту(int или double).
// Перегрузить операторы инкремента и декремента(как префиксного, так и
//    постфиксного).Смысл инкремента / декремента всего массива заключается в
//    инкременте / декременте каждого элемента массива.
//

#include <iostream>
#include <iomanip>
#include <cstdio>
 
;
class Vector
{
public:
	double* firstArray;
	double Elements;
	Vector(int elements)
	{
		Elements = elements;
		firstArray = new double [elements];

	}
	~Vector()
	{
		delete[] firstArray;
	}

	double* initialization() {

		for (int i = 0; i < Elements; ++i) {
			firstArray[i] = i;
		}
		return firstArray;
	}


	void output() {


		for (size_t i = 0; i < Elements; i++)
		{
			std::cout << std::setw(14) << *(firstArray + i);
			if ((i + 1) % 3 == 0) {
				std::cout << std::endl;
			}
		}

	}


	Vector& operator++() // префиксный инкремент
	{
		for (size_t i = 0; i < Elements; i++)
		{
			this->firstArray[i]++;
		}
	return *this;
	}

	 Vector& operator++(int) // постфиксный инкремент
	{
		for (size_t i = 0; i < Elements; i++)
		{
			this->firstArray[i]++;
		}
		return *this;
	}

    Vector& operator--() // префиксный декремент
	{
		for (size_t i = 0; i < Elements; i++)
		{
			this->firstArray[i]--;
		}
		return *this;
	}

	Vector& operator--(int) 
	{
		for (size_t i = 0; i < Elements; i++)
		{
			this->firstArray[i]--;
		}
		return *this;
	}

	//double* operator [] (int i) { return firstArray; }
	double& operator[] (const int index) { return firstArray[index]; }
}; 





class Matrix
{
public:

	double** firstArray;
	size_t Rows, Cols;

	
	Matrix(size_t rows, size_t cols)
	{
		Rows = rows;
		Cols = cols;
		firstArray = new double* [rows];
		for (size_t i = 0; i < rows; ++i) {
			*(firstArray + i) = new double[cols];
		}

	}

	~Matrix()
	{
		for (size_t i = 0; i < Rows; i++)
		{
			delete[] firstArray[i];
		}
		delete[] firstArray;
	}

	void output() {
		for (size_t i = 0; i < Rows; i++)
		{
			for (size_t j = 0; j < Cols; j++)
			{
				std::cout << std::setw(14) << firstArray[i][j];
				if (j == Cols - 1) {
					std::cout << std::endl;
				}
			}
		}
	}

	double** initialization() {

		for (int i = 0; i < Rows; ++i) {
			for (int j = 0; j < Cols; ++j)
				(*(firstArray + i))[j] = sin(i - j) + cos(i + j);
		}
		return firstArray;
	}

	double* transform() {

		double* lastArray = new double[15];
		int k = 0;

		for (int i = 0; i < Rows; ++i)
		{
			for (int j = 0; j < Cols; ++j)
			{
				*(lastArray + k) = (*(firstArray + i))[j];
				++k;
			}
		}
		return lastArray;
	}

	const double at(int i, int j) {
		return firstArray[i][j];
	}

	 void setAt(int i, int j, double value) {
		firstArray[i][j] = value;
	}



	Matrix& operator++() // префиксный инкремент
	{
		for (size_t i = 0; i < Rows; ++i) {
			for (size_t j = 0; j < Cols; ++j)
				this->firstArray[i][j]++;
		}
		return *this;
	}

	 Matrix &operator++(int) // постфиксный инкремент
	{
		for (size_t i = 0; i < Rows; ++i) {
			for (size_t j = 0; j < Cols; ++j)
				this->firstArray[i][j]++;
		}
		return *this;

	}  

	Matrix& operator--() // префиксный инкремент
	{
		for (size_t i = 0; i < Rows; ++i) {

			for (size_t j = 0; j < Cols; ++j)
				(*(this->firstArray + i))[j]--;
		}
 
		return *this;
	}

	Matrix& operator--(int)
	{
		for (size_t i = 0; i < Rows; ++i) {

			for (size_t j = 0; j < Cols; ++j)
				(*(this->firstArray + i))[j]--;
		}

		return *this;
	}

};



int main()
{
	setlocale(LC_ALL, "Russian");
	Matrix matrix(5, 3);
	matrix.initialization();
	printf("Первый элемент массива matrix %f\n", matrix.at(1, 1));
	matrix.setAt(1, 1, 322);
	--matrix;
	--matrix;
	++matrix;

	matrix++;	
	matrix--;	

	printf("Первый элемент массива matrix %f\n\n", matrix.at(1, 1)); 
	printf("Вывод массива matrix после использования matrix.transform()\n");
	for (size_t i = 0; i < 15; i++)
	{
		std::cout << std::setw(14) << *(matrix.transform() + i);
		if ((i + 1) % 3 == 0) {
			std::cout << std::endl;
		}
	} 

	printf("\n\n\n\n");


	Vector vect(6);
	vect[1] = 10;
	printf("Первый элемент массива vect %f\n", vect[1]);

	vect++;	
	printf("Первый элемент массива vect %f\n", vect[1]);

	vect--;	
	printf("Первый элемент массива vect %f\n", vect[1]);



	++vect;
	printf("Первый элемент массива vect %f\n", vect[1]);

	--vect;
	printf("Первый элемент массива vect %f\n", vect[1]);



}

