# Contains Duplicate II

## 标签
* 哈希

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
和217题差不多，只不过这次需要多存一个索引信息，然后判断索引的差值是否满足条件。

```c++
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
      auto it = mp.find(nums[i]);
      if (it != mp.end() && abs(it->second - i) <= k) {
        return true;
      } else {
        mp[nums[i]] = i;
      }
    }

    return false;
  }
};
```

