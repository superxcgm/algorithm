# Longest Common Prefix

## 标签
水题

## 解法一：

### 时间复杂度
O(n^2)

### 空间复杂度
O(1)

### 详解
取第一个字符串作为模板，然后遍历其他字符串，如果其他字符串的长度小于当前长度，或者当前字符不一样，返回前一个结果。

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i > strs[j].size() - 1 || strs[j][i] != ch) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
```
