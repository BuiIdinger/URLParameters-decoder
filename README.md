# URLParameters-decoder
Extracts parameters from urls

# Get a parameter
```cpp
const std::string query = "https://example.com/?userId=2488148";
URLParameters urlParameters(query);

std::string userId = urlParameters.getParameterValue("userId");
if (userId.empty()) {
  res->writeStatus("400 Bad Request");
  res->end("Amount wasn't included in the URL parameters.");
  return;
}

```

# Converting, use std functions

```cpp
const std::string query = "https://example.com/?userId=2488148&amount=1248";
URLParameters urlParameters(query);

std::string amountString = urlParameters.getParameterValue("userId");
if (amountString.empty()) {
  res->writeStatus("400 Bad Request");
  res->end("Amount wasn't included in the URL parameters.");
  return;
}

int64_t amount = 0;

try {
  amount = std::stoi(amountString);
}
catch (...) {
  res->writeStatus("400 Bad Request");
  res->end("Amount caused an overflow, or wasn't a int type.");
  return;
}
```
