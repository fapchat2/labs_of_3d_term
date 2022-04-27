#pragma once

#include "ExpressionEvaluator.h"


ExpressionEvaluator::ExpressionEvaluator()
	{
		arrayOfOperands_ = new double[20];
		for (size_t i = 0; i < 20; i++)
		{
			arrayOfOperands_[i] = 0;
		}
	}
ExpressionEvaluator::ExpressionEvaluator(int n)
	{
		arrayOfOperands_ = new double[n];
		for (size_t i = 0; i < n; i++)
		{
			arrayOfOperands_[i] = 0;
		}
	}
ExpressionEvaluator:: ~ExpressionEvaluator()
	{
		delete[] arrayOfOperands_;
	}

	void ExpressionEvaluator::setOperand(size_t pos, double value)
	{
        arrayOfOperands_[pos] = value;
		if (pos > numberOfOperands_) {
			numberOfOperands_ = pos;
		}
	}

	void ExpressionEvaluator::setOperands(double* ops, size_t n)
	{
		for (int i = 0; i < n; i++) {
			arrayOfOperands_[i] = ops[i];
		}
		if (n > numberOfOperands_) {
			numberOfOperands_ = n;
		}

	}

