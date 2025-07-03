// header.cpp

#include <filesystem>
#include <regex>
#include "header.hpp"

namespace fs = std::filesystem;

// Search for a file by exact name in the "input" directory
bool fileExists(const std::string& filename) {
    // Construct path "input/filename"
    fs::path target = fs::path("input") / filename;
    return fs::exists(target);
}

// // Check if the given output filename is valid
bool isValidFilename(const std::string& name) {
    // Windows
    static const std::regex invalidPattern(R"([<>:"/\\|?*\x00-\x1F'\",`])"); // invalid chars and control chars
    static const std::regex reservedPattern(R"(^(CON|PRN|AUX|NUL|COM[1-9]|LPT[1-9])(\..*)?$)", std::regex::icase);

    if (name.empty() || name == "." || name == "..") return false;
    if (std::regex_search(name, invalidPattern)) return false;
    if (std::regex_match(name, reservedPattern)) return false;
    if (name.back() == ' ' || name.back() == '.') return false;

    // Linux/macOS
    if (name.empty() || name == "." || name == "..") return false;
    if (name.find('/') != std::string::npos || name.find('\0') != std::string::npos) return false;

    // Reject whitespace character: space, tab, newline, etc.
    if (std::regex_search(name, std::regex(R"(\s)"))) return false;

    return true;
}