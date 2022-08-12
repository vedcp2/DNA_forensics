#include "functions.hpp"

std::string MultiplyStringByInt(std::string string, int x) {
  std::string new_string;
  for (int i = 0; i < x; i++) {
    new_string += string;
  }
  return new_string;
}

std::string FindStr(std::string dna,
                    std::vector<std::vector<std::string>> vect) {
  int match_count = 0;
  std::string person;
  std::vector<std::string> largest;
  for (int i = 1; i < (int)vect.size(); i++) {
    int matches = 0;
    for (int j = 1; j < (int)vect.at(0).size(); j++) {
      int str_count = std::stoi(vect.at(i).at(j));
      std::string str_sequence =
          MultiplyStringByInt(vect.at(0).at(j), str_count);
      if (dna.find(str_sequence) != std::string::npos) {
        matches++;
      }
    }
    std::vector<std::string> temp = vect.at(i);
    if (matches == (int)(vect.at(0).size() - 1)) {
      if (Compare(largest, temp) == 1) {
        return "No match";
      }
      match_count++;
      person = vect.at(i).at(0);
    }
  }
  if (match_count == 1) {
    return person;
  }
  return "No match";
}

std::string ReadFile(std::string file_name, std::string dna) {
  std::ifstream ifs(file_name);
  std::string line;
  std::vector<std::vector<std::string>> vect;

  while (getline(ifs, line)) {
    vect.push_back(utilities::GetSubstrs(line, ','));
  }

  std::string print = FindStr(dna, vect);
  return print;
}

int Equals(std::vector<std::string> old_row, std::vector<std::string> new_row) {
  for (int i = 1; i < (int)old_row.size(); i++) {
    int old_row_num = std::stoi(old_row.at(i));
    int new_row_num = std::stoi(new_row.at(i));
    if (new_row_num != old_row_num) {
      return 0;
    }
  }
  return 1;
}

/*std::vector<std::string> temp = vect.at(i);
      if (match_count > 1) {
        if (Compare(largest, temp) == 1) {
          largest = temp;
          match_count--;
          person = vect.at(i).at(0);
        }
      } */