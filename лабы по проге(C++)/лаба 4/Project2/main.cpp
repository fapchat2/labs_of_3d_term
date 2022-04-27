
//���������� ������� GOF �������� � ����� �����(������� ������ � ������� �������)
//�� ��������� �������.�������� ��������� IFormattable � ������� std::string
//format() ��� �������������� �������, ������������ ������ ���������, � �����
//������� void prettyPrint(const IFormattable& object), ������� ������� ��
//����� ������ - �������� � ����������������� ����.�������� ���, ����� � ���
//������� ����� ���� ���������� ������ �� ���� ������ ����, ������������� �
//������� 1. �������� �������������� ���������� ������������ ����.


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

