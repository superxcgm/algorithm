# Missing Ranges

## 标签
* 数组

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
可以试着把lower和upper插入数组中，然后找出数组中每两个相邻的数的缺少的区间。或者也可以不插入，lower和upper只能用一次，用完标记一下。

```c++
class Solution {
    string format(int lower, int upper) {
        if (lower == upper) {
            return to_string(lower);
        }
        return to_string(lower) + "->" + to_string(upper);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) {
            return {format(lower, upper)};
        }
        vector<string> ans;
        int left = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (lower < left) {
                ans.push_back(format(lower, left - 1));
                lower = INT_MAX;
            } else if (lower == left) {
                lower = INT_MAX;
            }
            if (nums[i] - left > 1) {
                if (nums[i] > upper) {
                    ans.push_back(format(left + 1, upper - 1));
                    left = INT_MAX;
                    break;
                } else {
                    ans.push_back(format(left + 1, nums[i] - 1));
                }
                
            }
            left = nums[i];
        }
        if (left < upper) {
            ans.push_back(format(left + 1, upper));
        }
        return ans;
    }
};
```
