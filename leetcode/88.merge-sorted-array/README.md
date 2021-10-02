# Merge Sorted Array

## 标签
数组

## 解法一

### 时间复杂度
O(m + n)

### 空间复杂度
O(1)

### 详解
如果是合并两个有序链表，我们一般都会从左到右遍历这两个链表，然后把他们的头部中小的值取出来，然后放到第一个链表里。但这个题是数组，数组有一个比较头疼的问题是，如果你在某个位置插入了一个元素，然后你还想保持有序的话，你只能把这个位置往后的所有元素向后挪一位。所以，那从左到右不行的话，那从右到左呢？可以的，赞。

```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int r = m + n - 1;
        while (r >= 0) {
            int value_from_nums1 = i >= 0 ? nums1[i] : INT_MIN;
            int value_from_nums2 = j >= 0 ? nums2[j] : INT_MIN;

            if (value_from_nums1 <= value_from_nums2) {
                nums1[r--] = value_from_nums2;
                j--;
            } else {
                nums1[r--] = value_from_nums1;
                i--;
            }
        }
    }
};
```



