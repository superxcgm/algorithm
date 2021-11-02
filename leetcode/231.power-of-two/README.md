# Power of Two

## 标签
* 位运算

## 解法一

### 时间复杂度
O(1)

### 空间复杂度
O(1)

### 详解
如果n小于等于0，显然不是2的幂次方。如果n是2的幂次方，则他的二进制位里只有1个1，那么n&(n-1)必为0。

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <=0 ) {
            return false;
        }
        return (n & (n - 1)) == 0;
    }
};
```

