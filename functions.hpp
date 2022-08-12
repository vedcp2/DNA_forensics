#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "utilities.hpp"
std::string ReadFile(std::string file_name, std::string dna);
std::string MultiplyStringByInt(std::string string, int x);
std::string FindStr(std::string dna,
                    std::vector<std::vector<std::string>> vect);
int Compare(std::vector<std::string> old_row, std::vector<std::string> new_row);

#endif