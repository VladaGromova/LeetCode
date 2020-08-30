#include <algorithm>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
  int size = nums.size();
  if (size == 1) {
    return 1;
  }
  if (size == 2) {
    if (nums[0] == nums[1]) {
      nums.pop_back();
      return 1;
    } else {
      return 2;
    }
  }
  int j = 0;
  size -= 2;
  for (int i = 0; i < size; ++i) {
    if (nums[i] == nums[i + 1]) {
      int additional = (i + 1);
      while (nums[i] == nums[additional]) {
        ++additional;
      }
      nums[i + 1] = nums[additional];
      --additional;
      nums.erase(nums.begin() + (i + 1), nums.begin() + additional);
    size = (nums.size() - 2);
    }
  }
  return nums.size();
}

int main() {
  std::vector<int> nums = {0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  removeDuplicates(nums);
}