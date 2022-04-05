#pragma once


#include <nana/gui/widgets/form.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui.hpp>

#include "Fawazahmed0CurrencyConverter.h"

// Controller class for Fawazahmed0CurrencyConverter
// uses nana::textbox for users input
class Fawazahmed0CurrencyConverterController
{
public:
	Fawazahmed0CurrencyConverterController(nana::window parent, Fawazahmed0CurrencyConverter* converter)
		: input(parent), converter(converter)
	{
		// set lambda handler for text changing
		input.events().text_changed(
			[converter, this, parent] {
				// try parse double from textbox
				double value;
				try {
					value = input.to_double();
				}
				// if conversion causes error then show error message box,
				// clear inputbox and continue without converting
				catch (...) {
					nana::msgbox msg(parent, "Error", nana::msgbox::button_t::ok);
					msg.icon(nana::msgbox::icon_error);
					msg << "Conversion to double error";
					msg();
					// clear inputbox 
					input.caption("");
					return;
				}
				const auto converted_v = converter->convert(value);
			}
		);
	}
	nana::textbox& getInputBox() noexcept {
		return input;
	}
private:
	nana::textbox input;
	Fawazahmed0CurrencyConverter* converter;
};

