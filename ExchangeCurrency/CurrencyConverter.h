#pragma once

#include "CurrencyProvider.h"

class CurrencyConverter
{
public:
	double convert(const double amount) const noexcept {
		if(provider == nullptr)
			provider = createProvider();
		return amount * provider->update();
	}
	virtual ~CurrencyConverter(){}
protected:
	virtual CurrencyProvider* createProvider() const = 0;
private:
	mutable CurrencyProvider* provider;
};
