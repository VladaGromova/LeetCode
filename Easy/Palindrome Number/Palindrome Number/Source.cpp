#include<iostream>
#include<vector>
#include<algorithm>
bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  } else if (x < 10) {
    return true;
  }
  int whole, remainder;
  std::vector<int> nums = {};
  while (x > 10) {
    whole = x / 10;
    remainder = x - whole * 10;
    nums.push_back(remainder);
    x /= 10;
  }
  if (x % 10 == 0) {
    nums.push_back(0);
    x /= 10;
    nums.push_back(x);
  } else {
    nums.push_back(x);
  }
  int size = nums.size();
  --size;
  int median = (nums.size() / 2);
  for (int i = 0; i <= median; ++i) {
    if (nums[i] != nums[size - i]) {
      return false;
    }
  }
  return true;
}