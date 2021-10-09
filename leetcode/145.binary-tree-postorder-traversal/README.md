# Binary Tree Postorder Traversal

## 标签
* 二叉树

## 解法一
递归

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
递归的解法还是比较简单的。

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
    void f(TreeNode *node, vector<int> &vec_out) {
        if (!node) {
            return;
        }
        f(node->left, vec_out);
        f(node->right, vec_out);
        vec_out.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec_out;

        f(root, vec_out);

        return vec_out;
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
和递归的版本类似，栈模拟。

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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> vec_out;
        TreeNode *p = root;
        TreeNode *prev = nullptr;
        stack<TreeNode *> st;

        while (!st.empty() || p) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            if (!p->right || p->right == prev) {
                vec_out.push_back(p->val);
                prev = p;
                p = nullptr;
            } else {
                st.push(p);
                p = p->right;
            }
        }
        

        return vec_out;
    }
};
```
