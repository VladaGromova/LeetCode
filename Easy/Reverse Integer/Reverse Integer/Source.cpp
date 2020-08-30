#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
int Reverse(int x) {
  if ((x > 2147483647) || (x < -2147483648)) {
    return 0;
  }
  int remainder, whole;
  bool positive;
  std::vector<int> nums = {};
  (x > 0) ? (positive = true) : (positive = false);
  x = abs(x);
  while (x > 10) {
    whole = x / 10;
    remainder = x - whole * 10;
    nums.push_back(remainder);
    x /= 10;
  }
  if (x == 10) {
    if (nums.size() != 0) {
      nums.push_back(0);
    }
    nums.push_back(1);
  } else if (x != 0) {
    nums.push_back(x);
  }
  if ((nums.size() >= 9) && (nums[0] >= 3)) {
    return 0;
  }
  whole = (nums.size() - 1);
  long long myNumber = 0;
  int j = 0;
  for (int i = whole; i >= 0; --i) {
    myNumber += (nums[j] * (pow(10, i)));
    ++j;
    
      if (myNumber > 2147483647) {
        return 0;
      }
    
  }
  if (!positive) {
    myNumber *= (-1);
  }
  return myNumber;
}

int main() {
  std::cout << Reverse(1563847412);
  return 0;
}

/*
LEETCODE SOLUTION

    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
*/