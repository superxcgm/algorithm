# Pascals Triangle

## 标签
* 水题

## 解法一：

### 时间复杂度
O(n^2)

### 空间复杂度
O(n^2)

### 详解
比较经典的一个练习题，没啥好说的。

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 2; i <= numRows; i++) {
            auto &prev_row = ans[i - 2];
            vector<int> row = {1};
            for (int j = 1; j < i - 1; j++) {
                row.push_back(prev_row[j - 1] + prev_row[j]);
            }
            row.push_back(1);
            ans.push_back(std::move(row));
        }
        return ans;
    }
};
```

