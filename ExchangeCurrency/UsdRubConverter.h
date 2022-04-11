#pragma once

#include "CurrencyConverter.h"
#include "UsdRubProvider.h"

class UsdRubConverter : public CurrencyConverter
{

protected:
	CurrencyProvider* createProvider() const override {
		return new UsdRubProvider;
	}
};

