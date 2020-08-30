#include <cstring>
#include <iostream>
#include <string>
#pragma warning(disable : 4996)

int romanToString(std::string s) {
  /*  I 1             C 100
      V 5             D 500
      X 10            M 1000
      L 50                           */
  int number = 0;
  int n = s.length();
  char *char_array = new char[n + 1];
  int *nums_array = new int[n + 1];
  strcpy(char_array, s.c_str());
  for (int i = 0; i < n; ++i) {
    switch (char_array[i]) {
      case 'I':
        nums_array[i] = 1;
        break;
      case 'V':
        nums_array[i] = 5;
        break;
      case 'X':
        nums_array[i] = 10;
        break;
      case 'L':
        nums_array[i] = 50;
        break;
      case 'C':
        nums_array[i] = 100;
        break;
      case 'D':
        nums_array[i] = 500;
        break;
      case 'M':
        nums_array[i] = 1000;
        break;
    }
  }
  nums_array[n] = 0;
  for (int i = 0; i < n; ++i) {
    if (nums_array[i + 1] == 0) {
      number += nums_array[i];
      return number;
    } else if (nums_array[i + 1] > nums_array[i]) {
      number += (nums_array[i+1] - nums_array[i]);
      ++i;
    } else {
      number += nums_array[i];
    }
  }
  return number;
}

int main() {
  std::cout << romanToString("MCMXCIV");
  return 0;
}