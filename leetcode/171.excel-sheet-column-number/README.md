# Excel Sheet Column Number

## 标签
* 进制转换

## 解法一

### 时间复杂度
O(logn)

### 空间复杂度
O(1)

### 详解
二十六进制转十进制，注意一下，不要溢出。

```c++
class Solution {
public:
    int titleToNumber(string &columnTitle) {
        long long weight = 1;
        int sum = 0;

        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            sum += (columnTitle[i] - 'A' + 1) * weight;
            weight *= 26;
        }

        return sum;
    }
};

```

