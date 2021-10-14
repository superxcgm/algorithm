# Two Sum III Data Structure Design

## 标签
* 哈希
* 双指针

## 解法一

### 时间复杂度
O(nlogn)

### 空间复杂度
O(n)

### 详解
这个题中，add的调用次数会比find多很多，所以add要尽可能地快。

```c++
class TwoSum {
    vector<int> nums;
    bool is_sorted = false;
public:
    TwoSum() {

    }
    
    void add(int number) {
        nums.push_back(number);
        is_sorted = false;
    }
    
    bool find(int value) {
        if (!is_sorted) {
            sort(nums.begin(), nums.end());
            is_sorted = true;
        }
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == value) {
                return true;
            }
            if (sum > value) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
```

