#include <iostream>
#include <vector>

using namespace std;

bool cmp(const void* a, const void* b) {
	return *(int*)a > * (int*)b ? true : false;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a > b ? b : a;
}

class Solution11 {
public:
	// initial
	int maxArea1(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int most = (right - left) * min(height[left], height[right]);

		int l = left, r = right;
		
		int storage;
		while (l < r) {
			if (height[l] < height[r]) {
				//cout << 1 << endl;
				for (int h = height[l]; l + 1 < height.size() && height[l + 1] < h; l++);
				l++;
				storage = (r - l) * min(height[l], height[r]);
				if (storage > most) most = storage;
				left = l;
			}
			else if (height[l] > height[r]) {
				//cout << 1 << endl;
				for (int h = height[r]; r - 1 > 0 && height[r - 1] < h; r--);
				r--;
				storage = (r - l) * min(height[l], height[r]);
				if (storage > most) most = storage;
				right = r;
			}
			else {
				//cout << 3 << endl;
				r--;
				l++;
				storage = (r - l) * min(height[l], height[r]);
				if (storage > most) most = storage;
				right = r;
				left = l;
			}
			//cout << "left = " << l << ", right = " << r << ", most storage = " << most << endl;
			//cout << "height[l] = " << height[l] << ", height[r] = " << height[r] << endl;
		}

		return most;
	}

	int maxArea(vector<int>& height) {
		int maxarea = 0, l = 0, r = height.size() - 1;
		while (l < r) {
			int h = min(height[r], height[l]);
			maxarea = max(h * (r - l), maxarea);
			/* simple but not the best
			if (height[l] < height[r]) l++;
			else r--;
			*/

			// a better solution
			/*
			if (height[l] < height[r]) { // move the lower end every turn
				// find the next height which is higher than the current one
				for (int h = height[l]; l + 1 < height.size() && height[l + 1] < h; l++);
				l++;
			}
			else {
				for (int h = height[r]; r - 1 > 0 && height[r - 1] < h; r--);
				r--;
			}
			*/

			// better than better
			while (height[l] <= h && l < r) l++;
			while (height[r] <= h && l < r) r--;
		}
		return maxarea;
	}
};

int main11() {
	Solution11 solution;
	vector<int> height;
	int h;
	cin >> h;
	while (h > 0) {
		height.push_back(h);
		cin >> h;
	}
	// 1 8 6 2 5 4 8 3 7 -1
	cout << solution.maxArea(height) << endl;
	system("pause");
	return 0;
}