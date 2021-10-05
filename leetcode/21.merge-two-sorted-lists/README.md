# Merge Two Sorted Lists

## 标签
* 链表

## 解法一

### 时间复杂度
O(n + m)

### 空间复杂度
O(n + m)

### 详解

输入的两个链表已经是有序的，所以只需要从头向后遍历，把小的拿出来，放到结果链表里即可。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *tail = head;

        while (l1 || l2) {
            int val1 = l1 ? l1->val : INT_MAX;
            int val2 = l2 ? l2->val : INT_MAX;

            if (val1 < val2) {
                l1 = l1->next;
                tail->next = new ListNode(val1);
            } else {
                l2 = l2->next;
                tail->next = new ListNode(val2);
            }
            
            tail = tail->next;
        }
        return head->next;
    }
};
```
