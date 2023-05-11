#include "header.h"
#include <iostream>

FileException::FileException(const string& fileName, const string& message): fileName(fileName), message(message) {}

const char* FileException::what() const noexcept 
{
    return message.c_str();
}

void CommandManager::add(string name, function<void(vector<string>)> fn) 
{
    commands[name] = fn;
}

void CommandManager::run() 
{
    string input;
    while (true) 
    {
        cout << "> ";
        getline(cin, input);
        vector<string> args = splitInput(input);
        if (args.empty())
            continue;

        string commandName = args[0];
        args.erase(args.begin());

        if (commandName == "stop")
            return;

        if (commands.find(commandName) != commands.end()) 
        {
            try 
            {
                commands[commandName](args);
            }
            catch (const exception& ex) 
            {
                cout << "Exception occurred: " << ex.what() << endl;
            }
        }
        else 
        {
            cout << "Command not found: " << commandName << endl;
        }
    }
}

vector<string> CommandManager::splitInput(const string& input) 
{
    vector<string> result;
    string::size_type start = 0;
    string::size_type end = input.find(' ');

    while (end != string::npos) 
    {
        result.push_back(input.substr(start, end - start));
        start = end + 1;
        end = input.find(' ', start);
    }

    if (start < input.length()) 
{
        result.push_back(input.substr(start));
    }

    return result;
}
