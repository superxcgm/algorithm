# Remove Linked List Elements

## 标签
* 链表

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
按照规则操作即可，如果能加一个伪头结点，可能更方便操作。

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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }
        ListNode before_head(0, head);
        ListNode *pre = &before_head;
        ListNode *p = head;
        while (p) {
            if (p->val == val) {
                pre->next = p->next;
                p = p->next;
                continue;
            }
            pre = p;
            p = p->next;
        }
        return before_head.next;
    }
};
```

