# Longest Substring Without Repeating Characters

## 标签
滑动窗口

## 解法一：

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
可以使用滑动窗口的思想解这个题，窗口内的字符是不重复的，所以需要记录窗口内都包含哪些字符，这里使用STL里的`unordered_map`进行存储。
每次循环，向右不断地扩大窗口，如果扩大之后，发现字符重了，就要向左不断缩减窗口，直到没有字符重复。

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> mp;
        int start = 0;
        int max_len = 0;

        for (int i =  0; i < s.size(); i++) {
            char ch = s[i];
            if (mp[ch]) {
                while(mp[ch]) {
                    mp[s[start]] = false;
                    start++;
                }
            }
            mp[ch] = true;
            max_len = max(max_len, i - start + 1);
        }
        return max_len;
    }
};
```

