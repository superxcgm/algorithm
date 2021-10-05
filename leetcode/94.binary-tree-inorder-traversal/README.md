# Binary Tree Inorder Traversal

## 标签
* 二叉树

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
中序遍历的话，用递归写的话，比较简单。
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
    void dfs(TreeNode *node, vector<int> &ans) {
        if (node == nullptr) {
            return;
        }
        dfs(node->left, ans);
        ans.push_back(node->val);
        dfs(node->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};
```

## 解法二

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
比递归稍微复杂一点，但原理还是模拟递归的调用栈。
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode * p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            ans.push_back(p->val);
            p = p->right;
        }
        return ans;
    }
};
```