# Symmetric Tree

## 标签
二叉树

## 解法一：

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
两棵树是对称的，当且仅当：树A的val等于树B的val，并且树A的左子树与树B的右子树对称，树A的右子树与树B的左子树对称。

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
    bool isSymmetric(TreeNode* l, TreeNode *r) {
        if (l == r && l == nullptr) {
            return true;
        }
        if (l == nullptr || r == nullptr) {
            return false;
        }
        if (l->val != r->val || !isSymmetric(l->left, r->right) || !isSymmetric(l->right, r->left)) {
            return false;
        }
        return true;
    }

public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
};

```

