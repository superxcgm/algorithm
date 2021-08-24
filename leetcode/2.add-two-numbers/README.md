# Add Two Numbers

## 标签
链表
模拟

## 解法一：

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
两数相加的话，从右往左加，然后要注意考虑进位，例如：

```
  1 2 3 4
+   5 6 7
---------
  1 8 0 1
```

先算个位和：4 + 7等于11，大于9了，要进位，所以当前位记1，记1的进位。

再算十位和：3 + 6 + 1（进位）等于10，大于9了，要进位，所以当前位记0，记1的进位。

再算百位和：2 + 5 + 1（进位）等于8，没有大于9，不进位

再算千位和：1 + 0 等于 1，没有大于9，不进位

由于这两个数，题目中已经使用链表倒序存储，所以我们用的时候，正序遍历即可：

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int carry = 0;

        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (sum > 9) {
                sum %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            p->next = new ListNode(sum);
            p = p->next;
        }

        if (carry) {
            p->next = new ListNode(1);
        }

        return head->next;
    }
};
```

这里使用了一个额外的头节点，方便代码处理。算法题不考虑内存泄漏。