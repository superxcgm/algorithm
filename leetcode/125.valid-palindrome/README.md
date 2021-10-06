# Valid Palindrome

## 标签
* 水题

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
跳过不是字符和数字的字符，然后正常判断回文即可。

```c++
class Solution {
    bool isAlphaOrDigit(char ch) {
        return ch >= 'a' && ch <= 'z' ||
               ch >= 'A' && ch <= 'Z' ||
               ch >= '0' && ch <= '9';
    }
public:
    bool isPalindrome(const string &s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (!isAlphaOrDigit(s[left])) {
                left++;
                continue;
            }
            if (!isAlphaOrDigit(s[right])) {
                right--;
                continue;
            }
            
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
```

