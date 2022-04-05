
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <nlohmann/json.hpp>


#include <nana/gui/widgets/form.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui.hpp>


#include "Fawazahmed0CurrencyConverter.h"
#include "Fawazahmed0CurrencyConverterController.h"
#include "Fawazahmed0CurrencyConverterView.h"

int main()
{
	// create form 
	nana::form fm(nana::API::make_center(400, 200));

	Fawazahmed0CurrencyConverter converter;
	// responsible for input from user
	Fawazahmed0CurrencyConverterController controller(fm, &converter);
	// responsible for output
	Fawazahmed0CurrencyConverterView view(fm, &converter);
	converter.setView(&view);

	// layout for window
	fm.div(
		"<"
		"< vert <usdlabel weight = 10%> <inputbox> >"
		"< vert <rublabel weight = 10%> <outputbox> >"
		">"
	);

	fm["inputbox"] << controller.getInputBox();
	fm["outputbox"] << view.getOutputBox();

	nana::label usd_label(fm, "USD"), rub_label(fm, "RUB");
	fm["usdlabel"] << usd_label;
	fm["rublabel"] << rub_label;

	fm.collocate();
	fm.show();
	nana::exec();
}
