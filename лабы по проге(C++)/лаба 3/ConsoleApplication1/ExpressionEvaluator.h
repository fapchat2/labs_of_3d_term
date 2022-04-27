
#pragma once
#include "ILoggable.h"
using namespace std;

class ExpressionEvaluator :public ILoggable 
{
public:
	ExpressionEvaluator();
	ExpressionEvaluator(int n);
	virtual double calculate() = 0;
	void setOperand(size_t n, double value);
	void setOperands(double* ops, size_t n);
	virtual ~ExpressionEvaluator();
protected:
	int numberOfOperands_;
	double* arrayOfOperands_;
};


