#pragma once
#include <map>
#include <vector>
#include <functional>
#include <string>

using namespace std;

class FileException : public exception 
{
private:
    string fileName;
    string message;

public:
    FileException(const string& fileName, const string& message);

    const char* what() const noexcept override;
};

class CommandManager 
{
private:
    map<string, function<void(vector<string>)>> commands;

public:
    void add(string name, function<void(vector<string>)> fn);
    void run();

private:
    vector<string> splitInput(const string& input);
};

