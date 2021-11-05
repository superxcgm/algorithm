# Strobogrammatic Number

## 标签
* 水题

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
0~10这些数字中，`1,0,8`这三个数字，翻转之后还是自身，然后6翻转之后是9，9翻转之后是6。所以可以用类似回文字符串的判断方法。

```c++
class Solution {
public:
    bool isStrobogrammatic(string &num) {
        int left = 0;
        int right = num.size() - 1;
        string identity = "108";
        while (left <= right) {
            if (num[left] == num[right] && identity.find(num[left]) != string::npos) {
                left++;
                right--;
                continue;
            }
            if ((num[left] == '6' && num[right] == '9') || (num[left] == '9' && num[right] == '6')) {
                left++;
                right--;
                continue;
            }
            return false;
        }
        return true;
    }
};
```

