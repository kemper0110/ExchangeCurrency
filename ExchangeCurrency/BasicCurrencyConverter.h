#pragma once

// Basic class for currency converter;
// If you want to use new currency source
// inherit this class and overload updateCurrency() method;
class BasicCurrencyConverter
{
public:
	virtual ~BasicCurrencyConverter() noexcept {}
	// must be overrode with concrete update method
	virtual void updateCurrency() = 0;
	double getCurrency() const noexcept {
		return currency;
	}
	// can be overrode if required another actions during converting
	virtual double convert(const double amount) const noexcept  {
		return amount * currency;
	}
protected:
	double currency = 0.;
};

