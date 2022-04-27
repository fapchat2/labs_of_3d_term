#include "ExpressionEvaluator.h"

class Multiplier : public ExpressionEvaluator
{
public:
	inline virtual double calculate() override;
	inline void logToScreen() override;
	inline void logToFile(const std::string& filename) override;


};