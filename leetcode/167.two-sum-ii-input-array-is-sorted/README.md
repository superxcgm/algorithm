# Two Sum II Input Array is Sorted

## 标签
* 二分查找

## 解法一

### 时间复杂度
O(nlogn)

### 空间复杂度
O(1)

### 详解
简单的二分题，遍历数组的每个元素x，在x的后面的有序区间内二分查找target - x。

```c++
class Solution {
    int find(vector<int> &numbers, int start, int target) {
        int left = start;
        int right = numbers.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (numbers[mid] == target) {
                return mid;
            } else if (numbers[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int x = numbers[i];
            int y = target - x;
            int j = find(numbers, i + 1, y);
            if (j != -1) {
                return {i + 1, j + 1};
            }
        }

        return {};
    }
};
```
