#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#pragma warning(disable : 4996)

  bool isValid(std::string s) {
    std::vector<char> chs = {};
    int n = s.length();
    char *char_array = new char[n + 1];
    strcpy(char_array, s.c_str());
    for (int i = 0; i < n; ++i) {
      if ((char_array[i] == '(') || (char_array[i] == '{') ||
          (char_array[i] == '[')) {
        chs.push_back(char_array[i]);
      } else {
        int size = chs.size();
        if (size == 0) {
          return false;
        }
        if (((char_array[i]=='}')&&(chs[(size-1)]=='{'))||((char_array[i]==']')&&(chs[(size-1)]=='['))||((char_array[i]==')')&&(chs[(size-1)]=='('))) {
          chs.pop_back();
        } else {
          return false;
        }
      }
    }
    return chs.empty();
  }

  int main() { std::cout << isValid("{}");
  }