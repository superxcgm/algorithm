# Climbling Stairs

## 标签
动态规划

## 解法一：

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
由题意，显然可以得出如下递归方程：dp[n] = dp[n - 1] + dp[n - 2] 且 dp[1] = 1, dp[2] = 2, dp[3] = 3。dp[x] 表示爬到x的不同方法的总和。
由于每次只能爬1个或者2个台阶，那么，你爬到n阶的时候，肯定是从n - 1或者n - 2过来的。所以只要把dp[n-1]和dp[n-2]一加就行。


```c++
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) {
            return n;
        }
        int p = 2;
        int q = 3;

        int x;

        for (int i = 4; i <= n; i++) {
            x = p + q;
            p = q;
            q = x;
        }
        return x;
    }
};
```

