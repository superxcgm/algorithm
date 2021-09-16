# Maximum Subarray

## 标签
dp

## 解法一：

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
很经典的一个题，线性解法为：不断地累加，如果累加的值为0，说明对后面的累加为负贡献，就可以置0了。然后每次判断当前累加的和 和 当前的最大值是多少，是否需要刷新最大值。

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = -0x3f3f3f3f;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > max) {
                max = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }

        return max;
    }
};
```

