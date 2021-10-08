# Binary Tree Preorder Traversal

## 标签
* 二叉树

## 解法一
递归

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
递归的写法应该是比较直观的。

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
    void print(TreeNode *root, vector<int> &vecOut) {
        if (!root) {
            return;
        }
        vecOut.push_back(root->val);
        print(root->left, vecOut);
        print(root->right, vecOut);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vecOut;

        print(root, vecOut);

        return vecOut;
    }
};

```

## 解法二
迭代

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解

迭代的解法其实是类似的，只不过手动模拟了栈操作。

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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> vecOut;
        stack<TreeNode *> st;
        TreeNode *p = root;

        while (!st.empty() || p) {
            while (p) {
                vecOut.push_back(p->val);
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            p = p->right;
        }

        return vecOut;
    }
};
```
