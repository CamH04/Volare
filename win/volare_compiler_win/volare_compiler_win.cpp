#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <cctype>
#include <algorithm>

//help funcitons
void printWorkingDirectory() {
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    std::cout << "Working At: " << buffer << std::endl;
}

bool has_vpw_extension(const std::string& filename) {
    if (filename.length() < 4) { 
        return false; 
    }
    std::string ext = filename.substr(filename.length() - 4);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    return ext == ".vpw";
}
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    if (first == std::string::npos || last == std::string::npos)
        return "";
    return str.substr(first, last - first + 1);
}

std::vector<std::string> loadFileLines(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return lines;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty())
            lines.push_back(line);
    }
    return lines;
}


int main(int argc, char* argv[]) {
    std::cout << "Volare Windows Interpreter\n";
    printWorkingDirectory();
    if (argc < 2) {
        std::cerr << "Usage: volare_compiler_win <file.vpw>\n";
        return 1;
    }

    std::string filename = trim(argv[1]);
    std::cout << "File: " << filename << std::endl;

    if (!has_vpw_extension(filename)) {
        std::cerr << "Error: File must have .vpw extension\n";
        return 1;
    }

    std::vector<std::string> lines = loadFileLines(filename);
    if (lines.empty()) {
        std::cerr << "Error: File is empty or could not be read.\n";
        return 1;
    }

    std::stack<int> stack;
    std::unordered_map<std::string, int> labelMap;

    // loop through labels in .vpw files
    for (size_t i = 0; i < lines.size(); ++i) {
        std::string& line = lines[i];
        if (line.back() == ':') {
            std::string label = line.substr(0, line.size() - 1);
            labelMap[label] = static_cast<int>(i);
        }
    }

    // interpret lables
    for (int ip = 0; ip < (int)lines.size(); ) {
        std::string line = lines[ip];
        if (line.back() == ':') {// skipping definitions
            ip++;
            continue;
        }

        std::istringstream iss(line);
        std::string instr;
        iss >> instr;
        //the if else of death
        if (instr == "PUSH") {
            int val;
            iss >> val;
            stack.push(val);
        }
        else if (instr == "POP") {
            if (stack.empty()) {
                std::cerr << "Stack underflow at line " << ip + 1 << "\n";
                return 1;
            }
            stack.pop();
        }
        else if (instr == "ADD") {
            if (stack.size() < 2) {
                std::cerr << "Stack underflow on ADD at line " << ip + 1 << "\n";
                return 1;
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(a + b);
        }
        else if (instr == "SUB") {
            if (stack.size() < 2) {
                std::cerr << "Stack underflow on SUB at line " << ip + 1 << "\n";
                return 1;
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(a - b);
        }
        else if (instr == "READ") {
            int input;
            std::cout << "Enter number: ";
            std::cin >> input;
            stack.push(input);
        }
        else if (instr == "PRINT") {
            std::string msg;
            std::getline(iss, msg);
            size_t start = msg.find_first_not_of(" \t\"");
            size_t end = msg.find_last_not_of(" \t\"");
            if (start != std::string::npos && end != std::string::npos)
                msg = msg.substr(start, end - start + 1);
            std::cout << msg << "\n";
        }
        else if (instr == "JEQ" || instr == "JGT" || instr == "JLT") {
            std::string label;
            iss >> label;
            if (stack.empty()) {
                std::cerr << "Stack underflow on " << instr << " at line " << ip + 1 << "\n";
                return 1;
            }
            int val = stack.top(); stack.pop();

            bool should_jump = (instr == "JEQ" && val == 0) ||
                (instr == "JGT" && val > 0) ||
                (instr == "JLT" && val < 0);

            if (should_jump) {
                if (labelMap.find(label) == labelMap.end()) {
                    std::cerr << "Unknown label: " << label << "\n";
                    return 1;
                }
                ip = labelMap[label];
                continue;
            }
        }
        else if (instr == "HALT") {
            break;
        }
        else {
            std::cerr << "Unknown instruction: " << instr << " at line " << ip + 1 << "\n";
            return 1;
        }
        ip++;
    }

    return 0;
}
