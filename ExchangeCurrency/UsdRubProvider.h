#pragma once

#include <format>

#include <nlohmann/json.hpp>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include "CurrencyProvider.h"


// Currency converter based on Fawazahmed0 API
// https://github.com/fawazahmed0/currency-api#readme
// Can be used with/without ..View and ..Controller classes
class UsdRubProvider : public CurrencyProvider
{
public:
	// currency updates on converter creation
	UsdRubProvider(){}

	double update() const override {
		return updateOnDate("latest");
	};
	//************************************
	// Method:    updateOnDate
	// FullName:  UsdRubProvider::updateOnDate
	// Access:    public 
	// Returns:   double
	// Qualifier: const
	// Parameter: const std::string & date in format "yyyy-mm-dd"
	//************************************
	double updateOnDate(const std::string& date) const {
		constexpr auto url = "https://cdn.jsdelivr.net/gh/fawazahmed0/currency-api@1/{}/currencies/usd/rub.json";

		// make request with api url
		curlpp::Easy request;
		
		request.setOpt(new curlpp::options::Url(std::format(url, date)));

		// perform request and store response in stringstream 
		std::stringstream ss;
		ss << request;

		// parse json from request
		const auto data = nlohmann::json::parse(ss);
		// and retrieve rub member
		return data["rub"].get<double>();
	}
};

