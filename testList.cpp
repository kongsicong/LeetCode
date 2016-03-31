#include "list/Solution.h"
#include "testList.h"
#include <stdio.h>
#include <stdlib.h>

void testList() {
	using namespace list;
	Solution s;
	/*{
	ListNode* l1 = CreateList(3);
	PrintList(l1);
	ListNode* l2 = CreateList(3);
	PrintList(l2);
	ListNode* ls = s.addTwoNumbers(l1, l2);
	PrintList(ls);

	}*/
	/*{
	ListNode* l1 = CreateList(2);
	PrintList(l1);
	ListNode* rs = s.reverseBetween(l1, 1, 2);
	PrintList(rs);
	}*/
	/*{
	ListNode* l1 = CreateList(6);
	PrintList(l1);
	ListNode *re = s.partition(l1, 5);
	PrintList(re);
	}*/
	/*{
	ListNode* l1 = CreateList(3);
	PrintList(l1);
	ListNode *re = s.deleteDuplicates(l1);
	PrintList(re);
	}*/
	/*{
	ListNode* l1 = CreateList(3);
	PrintList(l1);
	ListNode *re = s.deleteDuplicatesII(l1);
	PrintList(re);
	}*/
	/*{
	ListNode* l1 = CreateList(5);
	PrintList(l1);
	ListNode *re = s.rotateRight(l1, 5);
	PrintList(re);
	}*/
	{
		ListNode* l1 = CreateList(2);
		PrintList(l1);
		ListNode *re = s.reverseKGroup(l1, 3);
		PrintList(re);
	}
	system("pause");
}