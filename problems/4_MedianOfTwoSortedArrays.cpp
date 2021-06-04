#include <iostream>
#include <vector>

using namespace std;

class Solution4 {
public:
	/*
	 * a simple solution
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums;
		int i = 0, j = 0;
		for (; i < nums1.size() && j < nums2.size(); ) {
			if (nums1[i] <= nums2[j]) nums.push_back(nums1[i++]);
			else nums.push_back(nums2[j++]);
		}
		for (; i < nums1.size(); i++) nums.push_back(nums1[i]);
		for (; j < nums2.size(); j++) nums.push_back(nums2[j]);
		
		//for (int k = 0; k < nums.size() - 1; k++) cout << nums[k] << ", ";
		//cout << nums[nums.size() - 1] << endl;
		
		//cout << "size = " << nums.size() << endl;

		double median;
		if (nums.size() % 2 == 0) {
			//cout << nums[(nums.size() - 1) / 2] << ", " << nums[(nums.size() + 1) / 2] << endl;
			median = ((double)nums[(nums.size() - 1) / 2] + (double)nums[(nums.size() + 1) / 2]) / 2.0;
		}
		else {
			//cout << nums[nums.size() / 2] << endl;
			median = (double)nums[nums.size() / 2];
		}
		
		return median;
	}
	*/

	// A smarter solution
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		int halfLen = (m + n + 1) / 2;

		if (m <= n) {
			int iMin = 0, iMax = m;
			while (iMin <= iMax) {
				int i = (iMin + iMax) / 2;
				int j = halfLen - i;

				if (i < iMax && nums2[j - 1] > nums1[i])
					iMin = i + 1;
				else if (i > iMin && nums1[i - 1] > nums2[j])
					iMax = i - 1;
				else {
					int maxLeft = 0;
					if (i == 0) maxLeft = nums2[j - 1];
					else if (j == 0) maxLeft = nums1[i - 1];
					else maxLeft = nums1[i - 1] >= nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
					if ((m + n) % 2 == 1) return maxLeft;

					int minRight = 0;
					if (i == m) minRight = nums2[j];
					else if (j == n) minRight = nums1[i];
					else minRight = nums1[i] <= nums2[j] ? nums1[i] : nums2[j];

					return (maxLeft + minRight) / 2.0;
				}

				cout << endl;
			}
		}
		else {
			int jMin = 0, jMax = n;
			while (jMin <= jMax) {
				int j = (jMin + jMax) / 2;
				int i = halfLen - j;

				if (j < jMax && nums1[i - 1] > nums2[j])
					jMin = j + 1;
				else if (j > jMin && nums2[j - 1] > nums1[i])
					jMax = j - 1;
				else {
					int maxLeft = 0;
					if (j == 0) maxLeft = nums1[i - 1];
					else if (i == 0) maxLeft = nums2[j - 1];
					else maxLeft = nums2[j - 1] >= nums1[i - 1] ? nums2[j - 1] : nums1[i - 1];
					if ((m + n) % 2 == 1) return maxLeft;

					int minRight = 0;
					if (j == n) minRight = nums1[i];
					else if (i == m) minRight = nums2[j];
					else minRight = nums2[j] <= nums1[i] ? nums2[j] : nums1[i];

					return (maxLeft + minRight) / 2.0;
				}

				cout << endl;
			}
		}
		
		return 0.0;
	}
};

int main4() {
	vector<int> nums1, nums2;
	int x;
	cin >> x;
	while (x > 0) {
		nums1.push_back(x);
		cin >> x;
	}
	cin >> x;
	while (x > 0) {
		nums2.push_back(x);
		cin >> x;
	}
	Solution4 solution;
	cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
	system("pause");
	return 0;

}