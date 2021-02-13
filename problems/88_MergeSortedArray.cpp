#include <iostream>
#include <vector>

using namespace std;

class Solution88 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (i >= 0 && j >= 0) {
			if (nums1.at(i) > nums2.at(j))
				nums1.at(k--) = nums1.at(i--);
			else
				nums1.at(k--) = nums2.at(j--);
		}
		while (i >= 0) nums1.at(k--) = nums1.at(i--);
		while (j >= 0) nums1.at(k--) = nums2.at(j--);
	}
};

int main88() {
	vector<int> nums1, nums2;
	int m, n;
	cin >> m >> n;

	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		nums1.push_back(x);
	}
	for (int i = m; i < m + n; i++)
		nums1.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> x;
		nums2.push_back(x);
	}
	for (int i = 0; i < m + n; i++)
		cout << nums1[i] << " ";
	cout << endl;

	cout << "size: " << nums1.size() << ", " << nums2.size() << endl;
	
	Solution88 solution;
	solution.merge(nums1, m, nums2, n);
	for (int i = 0; i < m + n; i++)
		cout << nums1[i] << " ";
	cout << endl;
	
	system("pause");
	return 0;
}