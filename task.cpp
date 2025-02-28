#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

int index_number(const std::vector<int>& numbers, int find_index_number) {
	if (numbers.size() == 0) {
		return -1;
	}
	int first_number = numbers[0];
	int i = (numbers.size()+1) >> 1;
	int j = i;
	if (find_index_number == first_number) return 0;
	if (find_index_number == numbers[numbers.size()-1]) return numbers.size() - 1;
	while (i > 0 && i != (numbers.size() - 1) && numbers[i]!=find_index_number) {

		if ((j >> 1) == 0) return -1;
		if (numbers[i] < find_index_number && find_index_number < first_number) {
			i = i + (j >> 1);
		}
		if (numbers[i] > find_index_number && find_index_number < first_number && numbers[i] < first_number) {
			i = i - (j >> 1);
		}
		if (numbers[i] > find_index_number && find_index_number < first_number && numbers[i] > first_number) {
			i = i + (j >> 1);
		}
		if (numbers[i] < find_index_number && find_index_number > first_number && numbers[i] < first_number) {
			i = i - (j >> 1);
		}
		if (numbers[i] < find_index_number && find_index_number > first_number && numbers[i] > first_number) {
			i = i + (j >> 1);
		}
		if (numbers[i] > find_index_number && find_index_number > first_number) {
			i = i - (j >> 1);
		}
		j = j >> 1;
	}
	return i;
}

int main() {
	std::vector<int> v = {10, 11, 11, 12, 12, 13, 3, 3, 4, 5, 6, 7, 7, 8, 9};
	std::cout << index_number(v, 13);
}
