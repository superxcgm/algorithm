# Majority Element

## 标签
* 哈希

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
用unordered_map记录每个成员出现的次数，然后找到出现次数大于n/2的元素即可。

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (auto [k,v] : mp) {
            if (v > nums.size() / 2) {
                return k;
            }
        }
        
        return -1;
    }
};
```

