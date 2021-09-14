# Remove Element

## 标签
数组

## 解法一：

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
数组的缺点在于如果删除的时候要保证按原来的顺序，需要将元素后面的所以元素向前移动，这个开销会比较大。但是这个题里说了，元素可以为任意顺序，所以，我们只需要把需要删除的元素，移动到数组的最右边即可，甚至都不用改数组的长度，直接把长度返回就行了。

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = nums.size() - 1;
        int left = 0;

        while (left < right) {
            if (nums[left] == val) {
                swap(nums[right], nums[left]);
                right--;
                continue;
            } else {
                left++;
            }
        }

        if (left == nums.size()) {
            return nums.size();
        }

        return nums[left] == val ? left: (left + 1);
    }
};
```

