#pragma once
#include "BasicCurrencyConverter.h"

#include <nlohmann/json.hpp>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <fmt/format.h>

#include "BasicCurrencyConverterView.h"


// Currency converter based on Fawazahmed0 API
// https://github.com/fawazahmed0/currency-api#readme
// Can be used with/without ..View and ..Controller classes
class Fawazahmed0CurrencyConverter :
	public BasicCurrencyConverter
{
public:
	// currency updates on converter creation
	Fawazahmed0CurrencyConverter()
	{
		// trying to update currency
		try {
			updateCurrency();
		}
		// if updating causes error then program terminating with message;
		// there is no sense to continue without connection to source currency service
		catch (const std::exception& ex) {
			std::cout << "update currency exception: " << ex.what()
				<< '\n' << "exit\n";
			std::terminate();
		}
	}
	// manually update
	void updateCurrency() override {
		this->currency = requestCurrency("latest");
	}
	// date = "YYYY-MM-DD" or "latest"
	double requestCurrency(const std::string& date) {
		constexpr auto url = "https://cdn.jsdelivr.net/gh/fawazahmed0/currency-api@1/{}/currencies/usd/rub.json";

		// make request with api url
		curlpp::Easy request;
		request.setOpt(new curlpp::options::Url(fmt::format(url, date)));

		// perform request and store data in stringstream 
		std::stringstream ss;
		ss << request;

		// parse json from request
		const auto data = nlohmann::json::parse(ss);
		// and retrieve rub member
		return data["rub"].get<double>();
	}
	// overrode method with notifying view observer
	double convert(const double amount) const noexcept override {
		const auto converted = amount * currency;
		if (view != nullptr)
			view->display(converted);
		return converted;
	}
	void setView(BasicCurrencyConverterView* view) {
		this->view = view;
	}
	BasicCurrencyConverterView* getView() {
		return view;
	}
private:
	BasicCurrencyConverterView* view = nullptr;
};

