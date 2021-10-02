# Plus One

## 标签
模拟

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
按照加法的原则，从个位数开始加，然后是十位数，然后是百位数，依此类推，另外需要注意进位。

```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;

        digits[digits.size() - 1]++;

        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = 0;
            if (digits[i] >= 10) {
                carry = 1;
                digits[i] = 0;
            }
        }

        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
```

