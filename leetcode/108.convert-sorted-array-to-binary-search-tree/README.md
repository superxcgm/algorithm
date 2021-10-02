# Convert Sorted Array To Binary Search Tree

## 标签
分治
二叉树

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
因为输入是严格递增的，所以如果选择中间的元素作为二叉树的根，然后中间向左的元素作为左子树，中间向右的元素作为右子树，显然树就是平衡的。

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* divCon(vector<int> & nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        return new TreeNode(nums[mid], divCon(nums, left, mid - 1), divCon(nums, mid + 1, right));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return divCon(nums, 0, nums.size() - 1);
    }
};
```

