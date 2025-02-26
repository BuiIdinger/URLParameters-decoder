#include <string>
#include <sstream>
#include <pair>
#include <algorithm>
#include "URLParameters.h"

URLParameters::URLParameters(const std::string& query) noexcept {
	std::stringstream ss(query);
	std::string pair;

	while (std::getline(ss, pair, '&')) {
		const size_t position = pair.find('=');
		if (position == std::string::npos) {
			continue;
		}

		m_parameters.insert({ std::move(pair.substr(0, position)), std::move(pair.substr(position + 1)) });
	}
}

std::string URLParameters::getParameterValue(const std::string& parameterName) const noexcept {
	for (const std::pair<const std::string, const std::string>& parameter : m_parameters) {
		if (parameterName == parameter.first) {
			return parameter.second;
		}
	}

	return "";
}
