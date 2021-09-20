#include <iostream>

int my_lower_bound(int *begin, int *end, int target) {
	int *l = begin;
	int *r = end - 1;
	int *ans = end;

	while (l <= r) {
		int *mid = l + (r - l) / 2;
		if (*mid < target) {
			l = mid + 1;
		} else {
			ans = mid;
			r = mid - 1;
		}
	}
	return ans - begin;
}

int main(void) {
	int x[] = {1, 3, 5, 6};
	int ans = my_lower_bound(x, x + 4, 5);
	std::cout << ans << std::endl;
	return 0;
}
