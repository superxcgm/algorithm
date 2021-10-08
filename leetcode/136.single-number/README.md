# Single Number

## 标签
* 位运算

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
这里用到了一个位异或操作，位异或有这样的性质: `a^a = 0, 0^a = a`，所以只要将所有的数字进行位异或即可。

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }
};
```

