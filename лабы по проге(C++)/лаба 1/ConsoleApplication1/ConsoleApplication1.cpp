
//Написать программу обработки одномерного массива с n элементами, в соответствии с
//вариантом(приложение А).Необходимые действия должны производиться в
//функции processArray(), возвращающей определенное значение и формирующей
//еще один(выходной) массив данных(см.свой вариант).Память под массивы
//выделять статически(объявлять массивы локально в функции main) и для доступа к
//элементам использовать индексы.Ввод - вывод данных организовать средствами cstdio.

//Объявить массив из n = 20 целых чисел, проинициализировать нулями.Функция
//process_array() должна заполнить массив случайными числами от 1 до 10, вычислить
//и вернуть наиболее часто встречающееся значение в массиве(если таких несколько,
//	вернуть наименьшее) и сформировать выходной массив из всех элементов, которые
//	встречаются как минимум 2 раза во входном массиве.Вывести на экран массивы.

#include <iomanip>
#include <cstdio>







int process_array(int Array[], int countOfNumbers[], int ar[], int lastArray[])
{

	srand(time(NULL));

	for (int i = 0; i < 20; i++) {
		int randomNumber = rand() % 10 + 1;
		Array[i] = randomNumber;
		switch (randomNumber)
		{
		case 1:
			++countOfNumbers[0];
			break;
		case 2:
			++countOfNumbers[1];
			break;
		case 3:
			++countOfNumbers[2];
			break;
		case 4:
			++countOfNumbers[3];
			break;
		case 5:
			++countOfNumbers[4];
			break;
		case 6:
			++countOfNumbers[5];
			break;
		case 7:
			++countOfNumbers[6];
			break;
		case 8:
			++countOfNumbers[7];
			break;
		case 9:
			++countOfNumbers[8];
			break;
		case 10:
			++countOfNumbers[9];
			break;
		}
	}
	

	int max = countOfNumbers[0];

	for (int i = 0; i < 10; ++i) {
		if (countOfNumbers[i] > max) {
			max = countOfNumbers[i];
		}
	}


	for (int i = 0; i < 10; i++)
	{
		if (countOfNumbers[i] == max) {
			ar[i] = i + 1; //  любой элемент массива - то число, которое больше всего встречалось в исходном массиве Array  //
		}

	}

	int min = ar[0];

	for (int i = 0; i < 10; ++i)
	{
		if (ar[i] < min)
		{
			min = ar[i];
		}
	}



	int j = 0;

	for (int i = 0; i < 10; i++)
		{
			if (countOfNumbers[i] >= 2)
			{
				lastArray[j] = i + 1;
				j++;
			}
		}




	printf("\n Array of double numbers(lastArray): ");
	for (int i = 0; i < 10; i++)
	{
		if (lastArray[i] > 0 && lastArray[i] < 11)
		{
			printf("%i ", lastArray[i]);
		}
	}
	printf("\n");




	return min;

}

int main()
{ 
    int array[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
	int countOfNumbers[10] = {0, 0, 0, 0, 0, 0, 0, 0 ,0, 0};
	int ar[10] = { 11, 11, 11, 11, 11, 11, 11, 11, 11, 11 };
	int lastArray[10];
    int arrSize = sizeof(array) / sizeof(array[0]); //20 

	printf("\n MostFrequentElement: %i \n ", process_array(array, countOfNumbers, ar, lastArray));

	printf("\n The first array:");
	for (size_t i = 0; i < arrSize; i++)
	{
		printf("%i ", array[i]);
	}
	printf("\n");
}


