# sqrtx

## 标签
二分查找

## 解法一

### 时间复杂度
O(logn)

### 空间复杂度
O(1)

### 详解
x的平方根肯定在0到x之间，所以可以在这个有序区间内进行二分查找。

```c++
class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (1ll * mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
```

