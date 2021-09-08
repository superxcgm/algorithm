# Roman to Integer

## 标签
水题

## 解法一：

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
和阿拉伯数字类似，罗马数子正常也是从大往小写，但是会有例外，比如IV，代表的是4，先写小的，然后写大的。
所以可以对大部分情况按正常情况解析，如果有异常的情况（当前位的数字比之前的位大），就减去两次之前的数字。

```c++
class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int sum = 0;

        for (int i = 0; i < s.size(); i++) {
            sum += mp[s[i]];
            if (i > 0 && mp[s[i]] > mp[s[i - 1]]) {
                sum -= 2 * mp[s[i - 1]];
            }
        }

        return sum;
    }
};

```
