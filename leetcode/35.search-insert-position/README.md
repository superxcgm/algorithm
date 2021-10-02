# Search Insert Position

## 标签
二分查找

## 解法一

### 时间复杂度
O(logn)

### 空间复杂度
O(1)

### 详解
提示里面有提到，nums为无重复元素的升序排列数组，所以可以自然而然地想到二分查找。这里可以直接用STL里面的`lower_bound`，`lowber_bound`会返回第一个大于或者等于targer的数的迭代器。

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
```

