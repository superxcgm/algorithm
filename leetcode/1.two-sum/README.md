# Two Sum

## 标签
二分查找

## 解法一

### 时间复杂度
O(n^2)

### 空间复杂度
O(1)

### 详解
直接暴力求解，两层for循环，查找两数和为target的数的下标即可。

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int want = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == want) {
                    return {i, j};
                }
            }
        }
        // 题目保证有解，不会返回这个
        return {};
    }
};
```

## 解法二：

### 时间复杂度
O(nlogn)

### 空间复杂度
O(n)

### 详解
加快查找的一个办法就是使用二分查找法，但是二分查找需要数组是有序的。然后这个题又要求返回两个数的下标，所以排序前需要把数的下标先记一下。

```
class Solution {
    struct NumWithIndex {
        int index;
        int num;
    };

    bool static cmp(const NumWithIndex &a, const NumWithIndex &b) {
        return a.num < b.num;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<NumWithIndex> numsHasOrder;
      for (int i = 0; i < nums.size(); i++) {
          numsHasOrder.push_back({i, nums[i]});
      }
      sort(numsHasOrder.begin(), numsHasOrder.end(), cmp);
      for (int i = 0; i < numsHasOrder.size(); i++) {
          int want = target - numsHasOrder[i].num;
          auto it = lower_bound(numsHasOrder.begin(), numsHasOrder.end(), NumWithIndex{-1, want}, cmp);
          if (it != numsHasOrder.end() && it->num == want && it->index != numsHasOrder[i].index) {
              return {numsHasOrder[i].index, it->index};
          }
      }
      // 题目保证有解，不会执行到这里
      return {};
    }
};
```
使用了结构体保存数字和对应的下标，使用STL里面的`sort`对数组排序，然后使用STL里面的`lower_bound`查到第一个大于或者等于`want`的数，然后返回即可。
