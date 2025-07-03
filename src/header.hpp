// header.hpp

#pragma once
#include <iostream>
#include <string>

// Define platform
#ifdef _WIN32
    #define PATH_SEP '\\'
#else
    #define PATH_SEP '/'
#endif

// Colored output
#define red(text) "\033[31m" text "\033[0m"
#define green(text) "\033[32m" text "\033[0m"

void compileRun(const std::string& name, const std::string& extension, const std::string& output);

bool fileExists(const std::string& filename);

bool isValidFilename(const std::string& outputName);