#include "Solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <iterator>
//#include <algorithm>
namespace array {
	int removeDuplicates(int A[], int n) {
		if (n < 0) return -1;
		int result = n;
		int isDup = 0;
		int numDups = 0;
		int i;
		for ( i = 0; i < result - 1; i++) {
			if (A[i] == A[i + 1]) {
				isDup = 1;
				numDups++;
			}
			else {
				if (isDup) {
					for (int j = i; j < result; j++) {
						A[j - numDups + 1] = A[j + 1];
					}
					result = result - numDups;
					i = i - numDups;
					isDup = 0;
					numDups = 0;

				}
			}
		}
		if (isDup) {
			result = result - numDups;
		}
		return result;
	}

	int removeDuplicatesII(int A[], int n) {
		if (n <= 2) return n;
		int index = 2;

		for (int i = 2; i < n; i++) {
			if (A[index - 2] != A[i]) {
				A[index] = A[i];
				index++;
			}
		}
		return index;
	}

	int search(int A[], int n, int target) {
		for (int i = 0; i < n; i++) {
			if (target == A[i]) return i;
		}
		return -1;
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = m + n;

		int i = 0;
		int j = 0;
		int k = 0;
		int t1;
		int t2;
		int vk;
		int vk1;
		while (i < m || j < n) {
			int v1 = i == m ? INT_MAX : A[i];
			int v2 = j == n ? INT_MAX : B[j];
			if (v1 < v2)  i++;
			else j++;
			k++;
			
			if (k == total / 2) vk = v1 < v2 ? v1 : v2;
			if (k == total / 2 + 1) {
				vk1 = v1 < v2 ? v1 : v2;
				break;
			}
		}
		return total % 2 == 0 ? (double)(vk + vk1) / 2 : (double)vk1;

	}

	int longestConsecutive(const std::vector<int> &num) {
		std::unordered_map<int, bool> visited;
		for (auto i : num) visited[i] = false;
		int longest = 1;
		for (auto i : num) {
			if (visited[i]) continue;
			int length = 1;
			for (auto j = i + 1; visited.find(j) != visited.end(); j++) {
				visited[j] = true;
				length++;
			}
			for (auto j = i - 1; visited.find(j) != visited.end(); j--) {
				visited[j] = true;
				length++;
			}

			if (length > longest) longest = length;
		}
		return longest;
	}


	int removeElement(std::vector<int> &nums, int val) {
		int n = nums.size();
		int index = 0;
		for (int i = 0; i < n; i++) {
			if (nums[i] == val) continue;
			else {
				nums[index++] = nums[i];
			}
		}
		return index;
	}

	void nextPermutation(std::vector<int> &nums) {
		int n = nums.size();
		int turn = -1;
		for (int i = n - 1; i > 0; i--) {
			if (nums[i] > nums[i - 1]) {
				turn = i - 1;
				break;
			}
		}
		if (turn == -1) {
			std::reverse(nums.begin(), nums.end());
			return;
		}
		for (int i = n - 1; i > 0; i--) {
			if (nums[i] > nums[turn]) {
				int tmp = nums[i];
				nums[i] = nums[turn];
				nums[turn] = tmp;
				break;
			}
		}
		std::reverse(nums.begin() + turn + 1, nums.end());
		return;
	}

	std::string getPermutation(int n, int k) {
		std::string s(n, '0');
		for (int i = 0; i < n; i++) {
			s[i] = 49 + i;
		}
		for (int i = 1; i < k; i++) {
			next_permutation(s.begin(), s.end());
		}
		return s;
	}

	template<typename BidiIt>
	bool next_permutation(BidiIt first, BidiIt last) {
		const auto rfirst = std::reverse_iterator<BidiIt>(last);
		const auto rlast = std::reverse_iterator<BidiIt>(first);
		auto pivot = next(rfirst);

		while (pivot != rlast && *pivot >= *prev(pivot)) pivot++;
		if (pivot == rlast) {
			reverse(rfirst, rlast);
			return false;
		}
		auto it = rfirst;
		while (*it < *pivot) it++;
		std::swap(*it, *pivot);
		std::reverse(rfirst, pivot);
		return true;
	}


	bool isValidSudoku(const std::vector<std::vector<char>>& board) {
		bool visited[9];
		for (int i = 0; i < 9; i++) {
			std::fill(visited, visited + 9, false);
			//check rows
			for (int j = 0; j < 9; j++) {
				if (!check(board[i][j], visited)) return false;
			}
			std::fill(visited, visited + 9, false);
			//check cols
			for (int j = 0; j < 9; j++) {
				if (!check(board[j][i], visited)) return false;
			}
		}
		//check small cells
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::fill(visited, visited + 9, false);
				for (int r = i * 3; r < i * 3 + 3; r++) {
					for (int c = j * 3; c < j * 3 + 3; c++) {
						if (!check(board[r][c], visited)) return false;
					}
				}
			}
		}

		return true;
	}
	bool check(char ch, bool visited[9]) {
		if (ch == '.') return true;
		if (visited[ch - '1']) return false;
		return visited[ch - '1'] = true;
	}

	int trap(std::vector<int>& height) {
		if (height.size() <= 1) return 0;
		int result = 0;
		int maxId = 0;
		//find the max id of the height
		for (int i = 1; i < height.size(); i++) if (height[i] > height[maxId]) maxId = i;

		std::vector<int> subHeight1(height.begin(), height.begin() + maxId);
		std::vector<int> subHeight2(height.begin() + maxId + 1, height.end());
		//for the left part of the height calculate the trap , for the right part of the height calculate the trap. and then sum them up
		result = max_trap(subHeight1, false) + max_trap(subHeight2, true);
		return result;
	}
	int max_trap(std::vector<int> &height, bool left) {
		if (height.size() <= 1) return 0;
		int result = 0;
		int maxId = 0;
		std::vector<int> subHeight;
		//find the max id of the height
		for (int i = 1; i < height.size(); i++) if (height[i] > height[maxId]) maxId = i;
		//if the height is the right part of the parent vecotr ,calculate the trap 
		if (left){
			for (int i = 0; i < maxId ; i++) result += (height[maxId] - height[i]);
			subHeight = std::vector<int>(height.begin() + maxId + 1, height.end());
			result += max_trap(subHeight, true);
		}
		//if the height is the left part of the parent vecotr ,calculate the trap 
		else {
			for (int i = maxId + 1; i < height.size(); i++) result += (height[maxId] - height[i]);
			subHeight = std::vector<int>(height.begin(), height.begin() + maxId);
			result += max_trap(subHeight, false);
		}
		return result;
	}



	void rotate(std::vector<std::vector<int>>& matrix) {
		int n = matrix.size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i; j++) {
				std::swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
			}
		}

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n; j++) {
				std::swap(matrix[i][j], matrix[n - 1 - i][j]);
			}
		}
	}

	std::vector<int> plusOne(std::vector<int> &digits) {
		int n = digits.size();
		int carry = 1;
		for (int i = n - 1; i >= 0; i--) {
			int sum = digits[i] + carry;
			digits[i] = sum % 10;
			carry = sum / 10;
		}
		if (carry == 1) digits.insert(digits.begin(), 1);
		return digits;
	}




	//ì³²¨ÄÇÆõÊýÁÐ
	int climbStairs(int n) {
		int prev = 0;
		int cur = 1;
		for (int i = 1; i <= n; ++i){
			int tmp = cur;
			cur += prev;
			prev = tmp;
		}
		return cur;
	}



	std::vector<int> grayCode(int n) {
		std::vector<int> result(1, 0);
		if (n == 0) return result;
		if (n == 1) {
			result.push_back(1);
			return result;
		}
		std::vector<int> tmp = grayCode(n - 1);
		result = std::vector<int>(tmp.begin(), tmp.end());
		for (int i = tmp.size() - 1; i >= 0; i--) result.push_back(pow(2, n-1) + tmp[i]);
		return result;
	}
	

	void setZeroes(std::vector<std::vector<int>> &matrix) {
		if (matrix.empty()) return;
		int m = matrix.size();
		int n = matrix[0].size();

		std::vector<bool> rows(m, false);
		std::vector<bool> cols(n, false);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					rows[i] = true;
					cols[j] = true;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			if (rows[i]) for (int j = 0; j < n; j++) matrix[i][j] = 0;
		}
		for (int i = 0; i < n; i++) {
			if (cols[i]) for (int j = 0; j < m; j++) matrix[j][i] = 0;
		}
	}


	//this way is too simple. set two variables, one is sum which is used to judge whether the current index is valid, one is total which is used to judge whether the total array is valid.
	int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
		/***********************************************
		int total = 0;
        int j = -1;
        for (int i = 0, sum = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                j = i;
                sum = 0;
            }
        }
        return total >= 0 ? j + 1 : -1;
		************************************************/
		int remain = 0;
		for (int i = 0; i < gas.size(); i++) {
			if (gas[i] < cost[i]) continue;
			remain = gas[i] - cost[i];
			int j = i + 1;
			while (j != i) {
				int total = gas[j] + remain;
				remain = total - cost[j];
				if (remain < 0) break;
				j = (j + 1) % gas.size();
			}
			if (j == i) return i;
		}
		return -1;
	}



	/*int candy(std::vector<int>& ratings) {
		std::vector<int> minIds;
		std::vector<int> maxIds;
		int up = 0;
		int down = 0;
		for (int i = 1; i < ratings.size() - 1; i++) {
			if (ratings[i] > ratings[i - 1]) up = 1;
			if (ratings[i] < ratings[i - 1]) down = 1;
			if (down == 1 && ratings[i] < ratings[i + 1]) {
				minIds.push_back(i);
				down = 0;
				up = 1;
			}
			if (up = 1 && ratings[i] > ratings[i + 1]) {
				maxIds.push_back(i);
				up = 0;
				down = 1;
			}
		}

		if (minIds[0] < maxIds[0]);

		return 0;
		
	}*/


	int singleNumbers(std::vector<int> &nums) {
		const int repeat = 3;
		const int bits = sizeof(int) * 8;
		int count[bits];
		std::fill_n(count, bits, 0);

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < bits; j++) {
				if ((nums[i] >> j) & 1) count[j]++;
			}
		}
		int result = 0;
		for (int i = 0; i < bits; i++) {
			count[i] = count[i] % 3;
			result += count[i] << i;
		}
		return result;
	}

	void PrintArray(int A[], int n) {
		if (n <= 0) return;
		for (int i = 0; i < n; i++) {
			printf("%d - ", A[i]);
		}
		printf("\n");
	}
	int CreateArray(int *a) {
		printf("please input the length of the array:\n");
		int n;
		scanf_s("%d", &n);
		for (int i = 0; i < n; i++) {
			printf("%dth: ", i);
			scanf_s("%d", &a[i]);
			printf("\n");
		}
		return n;
	}

	void PrintArray(std::vector<int> A) {
		int n = A.size();
		if (n <= 0) return;
		for (int i = 0; i < n; i++) {
			printf("%d - ", A[i]);
		}
		printf("\n");
	}
	int CreateArray(std::vector<int> &A) {
		printf("please input the length of the array:\n");
		int n;
		scanf_s("%d", &n);
		for (int i = 0; i < n; i++) {
			printf("%dth: ", i);
			int v;
			scanf_s("%d", &v);
			A.push_back(v);
			printf("\n");
		}
		return n;
	}
}