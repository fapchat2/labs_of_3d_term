#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class CustomExpressionEvaluator : public IShuffle, public ExpressionEvaluator
{
	public:
		inline void shuffle() override;
		inline void shuffle(size_t i, size_t j) override;
		inline virtual double calculate() override;
		inline void logToScreen() override;
		inline void logToFile(const std::string& filename) override;
};