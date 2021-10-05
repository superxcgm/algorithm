# Remove Duplicates From Sorted List

## 标签
* 链表

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(1)

### 详解
因为链表已经是有序的，所以我们可以从左向右遍历，然后如果当前结点和前结点相同的话，删除当前结点即可。

```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *cur = head->next;
        ListNode *prev = head;

        while (cur) {
            if (cur->val == prev->val) {
                prev->next = cur->next;                
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};
```

