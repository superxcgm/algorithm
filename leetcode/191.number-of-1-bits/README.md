# Number of 1 Bits

## 标签
* 位运算

## 解法一

### 时间复杂度
O(1)

### 空间复杂度
O(1)

### 详解
最笨的办法，一个一个数。

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            if (n & 1) {
                count++;
            }
            n /= 2;
        }
        return count;
    }
};
```

