# Minimum Depth of Binary Tree

## 标签
二叉树

## 解法一：

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
这个题和树的最大深度差不多。其中，树的最大深度 ＝ 1 + MAX(左子树的最大深度, 右子树的最大深度)。
同理可得树的最小深度 ＝ 1 + MIN(左子树的最小深度, 右子树的最小深度)。只是对于只有左子树或者只有右子树的节点需要特殊处理，因为这种节点不是叶子节点，所以其实他的深度为不空的子树的深度加一。

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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        if (!root->left && !root->right) {
            return 1;
        }

        if (root->left && root->right) {
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
        if (!root->left) {
            return 1 + minDepth(root->right);
        }
        if(!root->right) {
            return 1 + minDepth(root->left);
        }
        return 0;
    }
};
```
