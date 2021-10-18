# Reverse Bits

## 标签
* 位运算

## 解法一

### 时间复杂度
O(1)

### 空间复杂度
O(1)

### 详解
把n从低位到高位，一位一位地取，然后转化为结果的高位。

```c++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            char val = 0;
            if (n & 1) {
                val++;
            }
            ans = ans * 2 + val;
            n /= 2;
        }
        return ans;
    }
};
```

