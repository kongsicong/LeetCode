#ifndef _ARRAY_SOLUTION_H_
#define _ARRAY_SOLUTION_H_
#include <vector>
#include <string>
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
	int longestConsecutive(const std::vector<int> &num);

	/*Given an array and a value, remove all instances of that value in place and return the new length.
	Do not allocate extra space for another array, you must do this in place with constant memory.
	The order of elements can be changed. It doesn't matter what you leave beyond the new length.*/
	int removeElement(std::vector<int> &nums, int val);

	/*Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
	If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order)*/
	void nextPermutation(std::vector<int> &nums);


	/*Given n and k, return the kth permutation sequence.*/
	std::string getPermutation(int n, int k);
	template<typename BidiIt>
	bool next_permutation(BidiIt first, BidiIt last);


	/*Determine if a Sudoku is valid, according to: Sudoku Puzzles*/
	bool isValidSudoku(const std::vector<std::vector<char>>& board);
	bool check(char ch, bool visited[9]);


	/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.*/
	/*********************************************************************/
	int trap(std::vector<int>& height);
	int max_trap(std::vector<int> &height, bool left);
	/**********************************************************************/

	/*You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).*/
	void rotate(std::vector<std::vector<int>>& matrix);

	/*Given a non-negative number represented as an array of digits, plus one to the number.
	The digits are stored such that the most significant digit is at the head of the list.*/
	std::vector<int> plusOne(std::vector<int> &digits);


	/*You are climbing a stair case. It takes n steps to reach to the top.
	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/
	int climbStairs(int n);
	
	/*The gray code is a binary numeral system where two successive values differ in only one bit.
	Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.*/
	std::vector<int> grayCode(int n);

	/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.*/
	void setZeroes(std::vector<std::vector<int>> &matrix);

	/*There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
	You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
	Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.*/
	int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost);


	/*There are N children standing in a line. Each child is assigned a rating value.
	You are giving candies to these children subjected to the following requirements:
	Each child must have at least one candy.
	Children with a higher rating get more candies than their neighbors.
	What is the minimum candies you must give?*/
	/**********************************************************/
	int candy(std::vector<int>& ratings);
	/***********************************************************/

	/*Given an array of integers, every element appears twice except for one. Find that single one.*/
	int singleNumber(std::vector<int> &nums);


	void PrintArray(int A[], int n);
	int CreateArray(int *a);
	void PrintArray(std::vector<int> A);
	int CreateArray(std::vector<int> &A);
}

#endif //_ARRAY_SOLUTION_H_  