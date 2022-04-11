#pragma once


class CurrencyProvider
{
public:
	virtual double update() const = 0;
	virtual ~CurrencyProvider() {}
};

