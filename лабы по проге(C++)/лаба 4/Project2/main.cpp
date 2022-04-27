
//Реализуйте паттерн GOF «Адаптер» в обоих видах(адаптер класса и адаптер объекта)
//на следующем примере.Напишите интерфейс IFormattable с методом std::string
//format() для форматирования объекта, реализующего данный интерфейс, а также
//функцию void prettyPrint(const IFormattable& object), которая выводит на
//экран объект - параметр в отформатированном виде.Сделайте так, чтобы в эту
//функцию можно было передавать ссылку на Вашу колоду карт, разработанную в
//задании 1. Алгоритм форматирования придумайте произвольный сами.


#include "Formator.h"
#include "ClassFormator.h"

void prettyPrint(const IFormattable& object)
{
	std::cout << object.format() << std::endl;
}

int main()
{
	Formator f;
	std::cout << f.format() << std::endl;

	ClassFormator form;
	std::cout << form.format() << std::endl;

	prettyPrint(form);
	prettyPrint(f);

}

