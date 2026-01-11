#pragma once
#include<string>
#include<unordered_map>
using namespace std;

class HttpRequest {
    public:
    string method;
    string uri;
    string version;
    unordered_map<string, string> headers;
    string body;
};