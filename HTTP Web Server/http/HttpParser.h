#pragma once
#include<string>
#include "HttpRequest.h"
using namespace std;
class HttpParser {
    public:
    static HttpRequest parse(const string& raw);
};