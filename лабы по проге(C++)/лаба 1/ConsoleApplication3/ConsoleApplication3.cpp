/*Написать свой аналог стандартной функции обработки строк из файла cstring, в
соответствии с вариантом.В функции main на тестовых данных продемонстрировать
результат работы как стандартной функции, так и собственной версии.Ввод - вывод
данных организовать средствами cstdio. */

//Функция strncat.
//Формат char* strncat(char* dest, const char* src, size_t maxlen).
//Функция приписывает maxlen символов строки src к строке dest


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>


using namespace std;

char* myStrncat(char* dest, const char* src, size_t masxlen)
{
    string srcStr = string(src);
    string destStr = string(dest);
    string masxlenStr = srcStr.substr(0, masxlen);
    destStr += masxlenStr;
    std::strcpy(dest, destStr.c_str());

    return dest;
}  

int main()
{

    char dest[99] = "ffffff      ";
    char src[] = "aaaaaaaa";
    myStrncat(dest, src, 5);
    printf("%s\n", dest);

    char s[99] = "ffffff      ";
    strncat(s, src, 5);
    printf("%s\n", s);

}