# Summary Ranges

## 标签
* 数组

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
从左向右遍历，如果发现当前的元素和之前的元素不连续时，就可以把之前的元素打印出来。


```c++
class Solution {
    string formatRange(const vector<int>& nums, int left, int right) {
        if (left == right) {
            return to_string(nums[left]);
        }
        return to_string(nums[left]) + "->" + to_string(nums[right]);
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        int left = 0;
        vector<string> ans;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                continue;
            }
            ans.push_back(formatRange(nums, left, i - 1));
            left = i;
        }
        if (left != nums.size()) {
            ans.push_back(formatRange(nums, left, nums.size() - 1));
        }
        return ans;
    }
};
```
