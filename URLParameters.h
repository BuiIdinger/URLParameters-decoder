#pragma once 

#include <string>
#include <map>

class URLParameters {
private:
	std::map<std::string, std::string> m_parameters;
public:
	URLParameters(const std::string& query) noexcept;
	std::string getParameterValue(const std::string& parameterName) const noexcept;
};
