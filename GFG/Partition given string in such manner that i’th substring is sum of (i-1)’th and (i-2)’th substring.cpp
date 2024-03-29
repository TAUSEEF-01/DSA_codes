#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<int> resultList;

bool check(string chars, int offset1, int offset2, int offset3, bool freezeFirstAndSecond) {

	// Find substrings according to given offsets
	string first = chars.substr(0, offset1);
	string second = chars.substr(offset1, offset2);
	string third = chars.substr(offset1 + offset2, offset3);

	// If condition is satisfied for current substrings
	if (stoi(first) + stoi(second) == stoi(third)) {

		// If whole string is covered.
		if (offset1 + offset2 + offset3 >= chars.length()) {
			resultList.push_back(stoi(first));
			resultList.push_back(stoi(second));
			resultList.push_back(stoi(third));
			return true;
		}

		// Check if remaining array also satisfies the condition
		bool result = check(chars.substr(offset1), offset2, offset3, max(offset2, offset3), true);
		if (result) {
			resultList.push_front(stoi(first));
		}
		return result;
	}

	// If not satisfied, try incrementing third
	if (offset1 + offset2 + offset3 <= chars.length() && (offset3 == max(offset1, offset2) || offset3 == 1 + max(offset1, offset2))) {
		if (check(chars, offset1, offset2, offset3 + 1, false))
			return true;
	}

	// If first and second have been finalized, do not
	// alter already computed results
	if (freezeFirstAndSecond)
		return false;

	// If first and second are not finalized
	if (offset1 + offset2 + offset3 <= chars.length() && (offset3 == max(offset1, offset2) || offset3 == 1 + max(offset1, offset2))) {

		// Try incrementing second
		if (check(chars, offset1, offset2 + 1, max(offset1, offset2 + 1), false))
			return true;
	}

	// Try incrementing first
	if (offset1 + offset2 + offset3 <= chars.length() && (offset3 == max(offset1, offset2) || offset3 == 1 + max(offset1, offset2))) {
		if (check(chars, offset1 + 1, offset2, max(offset1 + 1, offset2), false))
			return true;
	}
	return false;
}

int main() {
	string numStr = "11235813";

	cout << check(numStr, 1, 1, 1, false) << endl;
	for (int i : resultList) {
		cout << i << " ";
	}
	return 0;
}
