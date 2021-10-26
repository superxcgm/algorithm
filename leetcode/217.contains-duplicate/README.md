# Contains Duplicate

## 标签
* 哈希

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
使用一个哈希存储访问过的元素，然后每次遍历的时候检查一下即可。

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
```

