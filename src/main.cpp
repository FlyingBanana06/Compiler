// main.cpp

#include <sstream>   // For parsing input string
#include <stdexcept> // For std::runtime_error
#include <cstdlib>   // For system()
#include "header.hpp"

using namespace std;

int main() {
    string input, name, extension, output;

    // get target filename
    cout << "Please enter your filename (e.g., file.py): ";
    while (true) {
        getline(cin, input);
        if (fileExists(input)) break;
        else cerr << red("Target file doesn't exist. Please Try again: ");
    }
    // parsing
    stringstream ss;
    ss << input;
    getline(ss, name, '.');
    getline(ss, extension);
    
    // get output name if the file is a compiled language
    if (extension != "py") {
        cout << "Please enter your output name (e.g., name or name.output): ";
        while (true) {
            getline(cin, output);
            if (isValidFilename(output)) break;
            else cerr << red("Invalid filename. Please Try again: ");
        }
    }
    
    // compiile & run code
    compileRun(name, extension, output);

    return 0;
}

// Compile, run & Carch errors
void compileRun(const std::string& name, const std::string& extension, const std::string& output) {
    try {
        string cmd = name + "." + extension; // return to input e.g., test.py

        if (extension == "c") { // C
            cmd = "gcc input/" + cmd + " -o output/" + output; // e.g., gcc input/file.c -o output/name
            if (system(cmd.c_str()) != 0)
                throw runtime_error("C nameilation failed.");

            cout << green("nameile nameleted. Running program...\n");
            cmd = "output\\" + output;
            if (system(cmd.c_str()) != 0) // e.g., output\name
                throw runtime_error("Running C outputcutable failed.");
        }

        else if (extension == "cpp") { // C++
            cmd = "g++ input/" + cmd + " -o output/" + output; // e.g., g++ input/file.cpp -o output/name
            if (system(cmd.c_str()) != 0)
                throw runtime_error("C++ nameilation failed.");

            cout << green("nameile nameleted. Running program...\n");
            cmd = "output\\" + output; // e.g., output\name
            if (system(cmd.c_str()) != 0) 
                throw runtime_error("Running C++ outputcutable failed.");
        }

        else if (extension == "py") { // Python
            cout << green("nameile nameleted. Running program...\n");
            cmd = "py input/" + cmd; // e.g., py input/file.py
            if (system(cmd.c_str()) != 0) 
                throw runtime_error("Running Python script failed.");
        }

        else {
            throw invalid_argument("Unsupported extensionuage: " + extension);
        }
    }

    catch (const exception &e) {
        cerr << red("ERROR: ") << e.what() << endl;
    }
}