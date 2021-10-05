# Length of Last Word

## 标签
* 水题

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
比较简单的题，直接从右向左遍历，先跳过空格，然后数字母的个数即可。

```c++
class Solution {
public:
    int lengthOfLastWord(string &s) {
        int right = s.size() - 1;

        while (s[right] == ' ') {
            right--;
        }
        
        int count = 0;
        while (right >= 0 && s[right] != ' '){
            count++;
            right--;
        }
        return count;
    }
};
```

