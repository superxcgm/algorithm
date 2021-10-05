# Balanced Binary Tree

## 标签
* 二叉树

## 解法一：

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
根据本题中的定义，要判断一棵树是否平衡，需要判断每个节点的左右子树的高度的差的绝对值不对超过1。所以，一方面我们需要遍历树的每个节点，另一方面，我们需要计算树高。
最好能将这两部分结合起来，避免多余的遍历。我这里使用了一个输出参数保存树高，用返回值标识是否平衡。

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
    bool isBalanced(TreeNode *root, int &height) {
        if (root == nullptr) {
            return true;
        }

        int height_l = 0;
        if (!isBalanced(root->left, height_l)) {
            return false;
        }

        int height_r = 0;
        if (!isBalanced(root->right, height_r)) {
            return false;
        }
        height = 1 + max(height_l, height_r);
        return abs(height_l - height_r) <= 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int height = 0;
        return isBalanced(root, height);
    }
};
```

