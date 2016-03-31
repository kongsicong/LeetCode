#ifndef _SOLUTION_H_
#define _SOLUTION_H_
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) { }
};
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
	
};
namespace list {
	class Solution {
	public:
		/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse
		order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.*/
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

		/*Reverse a linked list */
		ListNode* reverseList(ListNode* head);

		/*Reverse a linked list from position m to n. Do it in-place and in one-pass.*/
		ListNode* reverseBetween(ListNode* head, int m, int n);

		/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater
		than or equal to x.*/
		ListNode* partition(ListNode* head, int x);

		/*Given a sorted linked list, delete all duplicates such that each element appear only once.*/
		ListNode* deleteDuplicates(ListNode* head);

		/*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers
		from the original list.*/
		ListNode* deleteDuplicatesII(ListNode* head);

		/*Given a list, rotate the list to the right by k places, where k is non-negative.*/
		ListNode* rotateRight(ListNode* head, int k);

		/*Given a linked list, remove the nth node from the end of list and return its head.*/
		ListNode* removeNthFromEnd(ListNode* head, int n);

		/*Given a linked list, swap every two adjacent nodes and return its head.*/
		ListNode* swapPairs(ListNode* head);

		/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
		If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
		You may not alter the values in the nodes, only nodes itself may be changed. 􀽌􀾟􀑖
		Only constant memory is allowed.*/
		ListNode* reverseKGroup(ListNode * head, int k);

		/*A linked list is given such that each node contains an additional random pointer which could point to
		any node in the list or null.
		Return a deep copy of the list.*/
		RandomListNode* copyRandmList(RandomListNode* head);

		/*Given a linked list, determine if it has a cycle in it.
		Follow up: Can you solve it without using extra space?*/
		bool hasCycle(ListNode* head);

		/*Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
		Follow up: Can you solve it without using extra space?*/
		ListNode* detectCycle(ListNode* head);

		/*Given a singly linked list L : L0 ! L1 !    ! Ln-1 ! Ln, reorder it to: L0 ! Ln ! L1 !
		Ln-1 ! L2 ! Ln-2 !   
		You must do this in-place without altering the nodes’ values.*/
		void reorderList(ListNode* head);

		/*Design and implement a data structure for Least Recently Used (LRU) cache. It should support the
		following operations: get and set.􀑖
		get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise
		return -1.
		set(key, value) - Set or insert the value if the key is not already present. When the cache reached its
		capacity, it should invalidate the least recently used item before inserting a new item.*/
		class LRUCache;

	private:
		ListNode* reverse(ListNode *first, ListNode *end, ListNode *prev);
	};


	ListNode* CreateList(int n);
	void PrintList(ListNode* head);
	
}
#endif //_SOLUTION_H_