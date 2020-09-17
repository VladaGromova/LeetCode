#include <algorithm>
#include <vector>
class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int size = nums.size();
    if (nums[0] == nums[(size - 1)]) {
      return 1;
    }
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
    --size;
    int j = 0;
    for (int i = 0; i < size; ++i) {
      j = (i + 1);
      while ((nums[i] == nums[j]) && ((j + 1) <= size)) {
        ++j;
      }
      if ((nums[i] == nums[j]) && ((j + 1) > size)) {
        nums.erase(nums.begin() + (i + 1), nums.end());
        return nums.size();
      } else if ((nums[i] != nums[j]) && ((j + 1) <= size)) {
        nums[i + 1] = nums[j];
        nums.erase(nums.begin() + (i + 1), nums.begin() + j);
        size = (nums.size() - 1);
      } else {
        nums[i + 1] = nums[j];
        nums.erase(nums.begin() + (i + 1), nums.begin() + j);
        return nums.size();
      }
    }
    return nums.size();
  }
};