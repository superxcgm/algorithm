# Happy Number

## 标签
* 哈希

## 解法一

### 时间复杂度
O(logn)

### 空间复杂度
O(logn)

### 详解
按照定义计算即可，然后要注意无限循环的情况，如果检测到环，需要退出。


```c++
class Solution {
    
public:
    bool isHappy(int n) {
        set<int> st;
        while (n != 1 && st.find(n) == st.end()) {
            st.insert(n);
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
```

