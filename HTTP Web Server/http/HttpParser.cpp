#include "HttpParser.h"
#include <sstream>
using namespace std;

HttpRequest HttpParser::parse(const string& raw) {
    HttpRequest request;
    istringstream stream(raw);
    string line;

    // Parse request line
    if (getline(stream, line)) {
        istringstream lineStream(line);
        lineStream >> request.method >> request.uri >> request.version;
    }

    // Parse headers
    while (getline(stream, line) && line != "\r") {
        size_t colonPos = line.find(':');
        if (colonPos != string::npos) {
            string key = line.substr(0, colonPos);
            string value = line.substr(colonPos + 1);
            // Remove leading spaces from value
            size_t firstNonSpace = value.find_first_not_of(" ");
            if (firstNonSpace != string::npos) {
                value = value.substr(firstNonSpace);
            }
            // Remove trailing carriage return
            if (!value.empty() && value.back() == '\r') {
                value.pop_back();
            }
            request.headers[key] = value;
        }
    }

    // Parse body
    string body;
    while (getline(stream, line)) {
        body += line + "\n";
    }
    if (!body.empty() && body.back() == '\n') {
        body.pop_back(); // Remove the last newline added
    }
    request.body = body;

    return request;
}