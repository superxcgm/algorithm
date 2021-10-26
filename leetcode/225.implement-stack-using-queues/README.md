# Implement Stack UsingQueues

## 标签
* 栈
* 队列

## 解法一

### 时间复杂度
O(n)

### 空间复杂度
O(n)

### 详解
栈是LIFO的，而队列是FIFO，所以如果要用队列去实现栈，需要反着存。
当队列存入一个元素之后，要把其他元素都出队，再重新入队。这样一来，头结点就是刚插入的了。

```c++
class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            int num = q.front();
            q.pop();
            q.push(num);
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

