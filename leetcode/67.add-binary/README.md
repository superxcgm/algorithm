# Add Binary

## 标签
模拟

## 解法一：

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
与十进制加法类似，也是从权重最小的位开始加，然后注意进位。

```c++
class Solution {
public:
    string addBinary(string &a, string &b) {
        int p = a.size() - 1;
        int q = b.size() - 1;
        string sum;

        int carry = 0;
        while (p >= 0 || q >= 0) {
            int operand1 = 0;
            if (p >= 0) {
                operand1 = a[p--] - '0';
            }

            int operand2 = 0;
            if (q >= 0) {
                operand2 = b[q--] - '0';
            }

            int current_sum = operand1 + operand2 + carry;
            carry = 0;
            if (current_sum >= 2) {
                carry = current_sum / 2;
                current_sum %= 2;
            }
            sum.push_back(current_sum + '0');
        }

        if (carry) {
            sum.push_back(carry + '0');
        }

        return string(sum.rbegin(), sum.rend());
    }
};
```

