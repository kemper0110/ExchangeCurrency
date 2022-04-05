
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include "../ExchangeCurrency/Fawazahmed0CurrencyConverter.h"

TEST_CASE("Fawazahmed0CurrencyConverter", "[requestCurrency]")
{
	Fawazahmed0CurrencyConverter converter;

	// prepared currency 
	const auto test_cases = {
		std::pair{"2022-04-04", 85.749912},
		std::pair{"2022-04-03", 85.750395},
		std::pair{"2022-04-02", 85.750395},
		std::pair{"2022-04-01", 81.750148},
		std::pair{"2022-03-31", 83.501335},
		std::pair{"2022-03-10", 138.750066},
		std::pair{"2022-03-05", 124.000301}
	};
	for (const auto [date, actually] : test_cases) {
		// receive currency by testing class
		const auto received = converter.requestCurrency(date);

		// require small difference
		REQUIRE(std::abs(received - actually) < 0.01);
	}
}
