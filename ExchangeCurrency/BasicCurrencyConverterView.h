#pragma once


class BasicCurrencyConverterView {
public:
	virtual void display(double) = 0;
	virtual ~BasicCurrencyConverterView(){}
};