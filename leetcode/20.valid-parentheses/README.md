# Valid Parentheses

## 标签
栈

## 解法一：

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
栈的模板题，如果看到左括号，直接入栈，如果看到右括号，看下和左括号是否匹配，如果不匹配就返回假。

```c++
class Solution {
    string str_left_ = "([{";
    string str_right = ")]}";

    bool isLeft (char ch) {
        return str_left_.find(ch) != string::npos;
    }

    bool isMatch(char left, char right) {
        auto pos_left = str_left_.find(left);
        auto pos_right = str_right.find(right);

        return pos_left == pos_right;
    }
public:
    bool isValid(const string &s) {
        stack<char> st;

        for (auto ch: s) {
            if (isLeft(ch)) {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                auto top = st.top();
                if (!isMatch(top, ch)) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
```

