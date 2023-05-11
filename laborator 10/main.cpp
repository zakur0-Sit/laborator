#include <iostream>
#include <filesystem>
#include <fstream>
#include "header.h"

using namespace std;

int main(int argc,char* argv[])
{
    CommandManager manager;

    auto ping = [](vector<string> args) 
    { 
        cout << "pong!" << endl; 
    };
    manager.add("ping", ping);

    auto count = [](vector<string> args) 
    { 
        cout << "Counted " << args.size() << " args" << endl; 
    };
    manager.add("count", count);

    auto times = [counter = 1](vector<string> args) mutable 
    {
        cout << "Called " << counter++ << " times" << endl;
    };
    manager.add("times", times);

    auto copy = [](vector<string> args) {
        if (args.size() < 2) {
            throw FileException("", "Insufficient arguments for copy command");
        }

        const string& source = args[0];
        const string& destination = args[1];
        char BUFFER[4096];

        try {
            ifstream sourceFile(source, ios::binary);
            if (!sourceFile) {
                throw FileException(source, "Failed to open source file");
            }

            ofstream destFile(destination, ios::binary);
            if (!destFile) {
                throw FileException(destination, "Failed to create destination file");
            }
            while (!sourceFile.eof()) {
                sourceFile.read(BUFFER, sizeof(BUFFER));
                destFile.write(BUFFER, sourceFile.gcount());
            }

            sourceFile.close();
            destFile.close();

            cout << "File copied successfully from " << source << " to " << destination << endl;
        }
        catch (const exception& ex) {
            throw FileException("", ex.what());
        }
    };
    manager.add("copy", copy);

    auto greet = [](vector<string> args) {
        if (args.size() < 1) {
            throw invalid_argument("Insufficient arguments for greet command");
        }

        cout << "Hello, " << args[0] << "!" << endl;
    };
    manager.add("greet", greet);

    manager.run();

    cout << "Goodbye." << endl;

    return 0;
}
