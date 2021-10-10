# Intersection of two linked lists

## 标签
* 链表
* 双指针
* 哈希

## 解法一
暴力求解

### 时间复杂度
O(n^2)

### 空间复杂度
O(1)

### 详解
直接上双重循环，暴力求解。时间花费比较多，但还是可以AC。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA;
        ListNode *q;
        while (p) {
            q = headB;
            while (q) {
                if (p == q) {
                    return p;
                }
                q = q->next;
            }
            p = p->next;
        }
        return nullptr;
    }
};
```

## 解法二
哈希

### 时间复杂度
O(n + m)

### 空间复杂度
O(n)

### 详解
使用hash存储其中一个链表所有结点的地址，然后遍历另外一个链表，并在hash中查找。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA;
        unordered_set<ListNode *> st;
        while (p) {
            st.insert(p);
            p = p->next;
        }

        ListNode *q = headB;
        while (q) {
            if (st.find(q) != st.end()) {
                return q;
            }
            q = q->next;
        }

        return nullptr;
    }
};
```

## 解法三
双指针

### 时间复杂度
O(n + m)

### 空间复杂度
O(1)

### 详解
详见官方题解。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != pb) {
            pa = pa == nullptr ? headB : pa->next;
            pb = pb == nullptr ? headA : pb->next;
        }
        return pa;
    }
};
```
