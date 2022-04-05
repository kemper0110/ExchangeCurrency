#pragma once


#include <nana/gui/widgets/form.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui.hpp>

#include "Fawazahmed0CurrencyConverter.h"

// View class for Fawazahmed0CurrencyConverter
// uses nana::textbox to view converted amount
class Fawazahmed0CurrencyConverterView 
	: public BasicCurrencyConverterView
{
public:
	Fawazahmed0CurrencyConverterView(nana::window parent, Fawazahmed0CurrencyConverter* converter) 
		: output(parent), converter(converter)
	{
		output.editable(false);
	}
	void display(double amount) override {
		output.caption(std::to_string(amount));
	}
	nana::textbox& getOutputBox() noexcept {
		return output;
	}
private:
	Fawazahmed0CurrencyConverter* converter;
	nana::textbox output;
};

