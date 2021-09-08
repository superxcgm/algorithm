#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void print_vector(vector<T> &vec) {
  for (auto ele : vec) {
    cout << ele << ", ";
  }
  cout << endl;
}

struct NumberWithIndex {
  int num;
  int index;

  friend ostream &operator<<(ostream &os,
                      const NumberWithIndex &d) {
    os << "{ num: " << d.num << ", index: " << d.index << "}";
    return os;
  }
};

void sort_demo() {
  vector<int> nums{1, 3, 2, 5, 4};
  sort(nums.begin(), nums.end()); // ascending by default
  print_vector(nums); // 1, 2, 3, 4, 5

  // descending
  sort(nums.begin(), nums.end(), greater<int>());
  print_vector(nums); // 5, 4, 3, 2, 1

  // struct
  vector<NumberWithIndex> vec = {
      {1, 0},
      {3, 1},
      {2, 2},
      {5, 3},
      {4, 4},
  };
  sort(vec.begin(), vec.end(), [](auto &a, auto &b) -> bool { return a.num < b.num; }); // ascending
  print_vector(vec); // { num: 1, index: 0}, { num: 2, index: 2}, { num: 3, index: 1}, { num: 4, index: 4}, { num: 5, index: 3},
}

void binary_search_demo() {
  vector<int> nums{1, 2, 3, 4, 5};

  // find first element greater or equals to target
  auto it = lower_bound(nums.begin(), nums.end(), 3);
  cout << *it << endl; // 3

  // struct
  vector<NumberWithIndex> vec = {
      {1, 0},
      {2, 2},
      {3, 1},
      {4, 4},
      {5, 3},
  };
  auto nit = lower_bound(vec.begin(), vec.end(), NumberWithIndex{3, -1}, [](auto &a, auto &b) -> bool { return a.num < b.num; });
  cout << *nit << endl; // { num: 3, index: 1}
}

void unordered_map_demo() {
    unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5}
    };
    cout << mp['I'] << " " << mp['V'] << endl;
}

int main() {
//  sort_demo();

//  binary_search_demo();

//  unordered_map_demo();

  return 0;
}
