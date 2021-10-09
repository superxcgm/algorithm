# Read n Characters Given read4

## 标签
* 字符串

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
直接用read4把字符串读到buf指向的内存，不用额外开内存。正常来说，每次能读4个字符，如果读的字符数小于4，说明文件里已经没有字符了。另外，如果读的字符已经满足用户的要求，就不用继续往下读了。

```c++
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char *p = buf;
        while (p - buf < n) {
            int bytes_read = read4(p);
            p += bytes_read;
            if (bytes_read < 4) {
                break;
            }
        }
        if (p - buf > n) {
            buf[n] = '\0';
            return n;
        } else {
            return p - buf;
        }
    }
};
```

