
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <nlohmann/json.hpp>


#include <nana/gui/widgets/form.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui.hpp>

#include "UsdRubConverter.h"

int main()
{
	// create form 
	nana::form fm(nana::API::make_center(300, 200));


	UsdRubConverter converter;

	nana::textbox output(fm, "");
	output.editable(false);

	nana::textbox input(fm, "");

	nana::button but(fm, "Convert");
	but.events().click([&input, &converter, &output, &fm]
		{
			// try parse double from textbox
			double value;
			try {
				value = input.to_double();
			}
			// if conversion causes error then show error message box,
			// clear inputbox and continue without converting
			catch (...) {
				nana::msgbox msg(fm, "Error", nana::msgbox::button_t::ok);
				msg.icon(nana::msgbox::icon_error);
				msg << "Conversion to double error";
				msg();
				input.caption("");
				output.caption("");
				return;
			}
			double converted;
			try {
				converted = converter.convert(value);
			}
			catch (...) {
				nana::msgbox msg(fm, "Error", nana::msgbox::button_t::ok);
				msg.icon(nana::msgbox::icon_error);
				msg << "Currency update error";
				msg();
				input.caption("");
				output.caption("");
				return;
			}
			output.caption(std::to_string(converted));
		}
	);

	// layout for window
	fm.div(
		"<"
		"< vert <usdlabel weight = 10%> <inputbox> >"
		"< vert <rublabel weight = 10%> <outputbox> >"
		">"
		"vert < convert_button weight = 30%>"
	);

	fm["inputbox"] << input;
	fm["outputbox"] << output;

	nana::label usd_label(fm, "USD"), rub_label(fm, "RUB");
	fm["usdlabel"] << usd_label;
	fm["rublabel"] << rub_label;
	fm["convert_button"] << but;

	fm.collocate();
	fm.show();
	nana::exec();
}
