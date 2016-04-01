#include "Solution.h"
#include <stdio.h>
#include <stdlib.h>
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

	int longestConsecutive(const vector<int> &num) {

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
}