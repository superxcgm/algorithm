#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ans;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            if (p->left) {
                que.push(p->left);
                p->left = nullptr;
                que.push(p);
            } else {
                ans.push_back(p->val);
                if (p->right) {
                    que.push(p->right);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    TreeNode *root = new TreeNode(2, new TreeNode(3, new TreeNode(1), nullptr), nullptr);
    auto ans = solution.inorderTraversal(root);

    cout << "Hello" << endl;
}