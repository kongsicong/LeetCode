#ifndef _ARRAY_SOLUTION_H_
#define _ARRAY_SOLUTION_H_
#include <vector>
namespace array {
	/*Given a sorted array, remove the duplicates in place such that each element appear only once
	and return the new length.
	Do not allocate extra space for another array, you must do this in place with constant memory.*/
	int removeDuplicates(int A[], int n);

	/*Follow up for ¡±Remove Duplicates¡±: What if duplicates are allowed at most twice?
	For example, Given sorted array A = [1,1,1,2,2,3],
	Your function should return length = 5, and A is now [1,1,2,2,3]*/
	int removeDuplicatesII(int A[], int n);

	/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.
	You are given a target value to search. If found in the array return its index, otherwise return -1.
	You may assume no duplicate exists in the array.*/
	int search(int A[], int n, int target);


	/*There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted
	arrays. The overall run time complexity should be O(log(m + n)).*/
	double findMedianSortedArrays(int A[], int m, int B[], int n);

	/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence.*/
	int longestConsecutive(const vector<int> &num);



	void PrintArray(int A[], int n);
	int CreateArray(int *a);
}

#endif _ARRAY_SOLUTION_H_