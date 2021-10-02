# Same Tree

## 标签
二叉树

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
只要同时遍历一下这两棵树，然后看一下是不是一样即可。

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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q && p == nullptr) {
            return true;
        }
        if (p == nullptr ||
            q == nullptr ||
            p->val != q->val ||
            !isSameTree(p->left, q->left) ||
            !isSameTree(p->right, q->right)) {

            return false;
        }
        return true;
    }
};
```

