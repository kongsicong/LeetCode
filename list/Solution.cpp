#include "Solution.h"
#include <stdlib.h>
#include <stdio.h>
#include <map>
using namespace std;
namespace list {
	ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode head(-1);
		ListNode* current = &head;
		for (ListNode *p1 = l1, *p2 = l2; p1 != nullptr || p2 != nullptr; p1 = p1 == nullptr ? nullptr : p1->next, p2 = p2 == nullptr ? nullptr : p2->next) {
			int n1 = p1 == nullptr ? 0 : p1->val;
			int n2 = p2 == nullptr ? 0 : p2->val;
			int sum = n1 + n2 + carry;
			int val = sum % 10;
			carry = sum / 10;
			current->next = new ListNode(val);
			current = current->next;
		}
		current->next = carry == 1 ? new ListNode(1) : nullptr;
		return head.next;
	}
	
	ListNode* Solution::reverseList(ListNode* head) {
		ListNode *prev = nullptr;
		ListNode *next;
		for (ListNode *current = head; current != nullptr; current = next) {
			next = current->next;
			current->next = prev;
			prev = current;
		}

		return prev;
	}
	ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;
		
		//找到m的前一个节点，并保存
		ListNode *current = head;
		ListNode *rh;
		for (int i = 1; current != nullptr; current = current->next, i++) {
			if (i == m - 1) rh = current;
			if (i >= m) break;
		}
		
		//将m到n这一段的链表倒置，其中节点m指向nullptr
		ListNode *prev = nullptr;
		ListNode *next;
		for (int i = m; i <= n; i++) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		//若m=1，则没有m的前一个节点，直接让首节点指向n的后一个节点，倒置完成
		if (m == 1) {
			head->next = current;
			return prev;
		}
		//若m>1，则有m的前一个节点，让m的前一个节点指向节点n，让节点m指向n的后一个节点
		else {
			rh->next->next = current;//m->n+1
			rh->next = prev;//m-1->n
			return head;
		}
	}
	
	ListNode* Solution::partition(ListNode* head, int x) {
		if (!head || !head->next) return head; //头结点为空或者链表长度为一，则返回头结点


		ListNode *lsHd;  //存储小于x的节点中的头结点
		ListNode *lsEd;  //存储小于x的节点中的尾节点
		ListNode *gtHd;  //存储大于x的节点中的头结点
		ListNode *gtEd;  //存储大于x的节点中的尾节点
		int fls = 1;
		int fgt = 1;

		//将小于x的节点接在lsEd的后面，大于x的节点接在gtEd的后面，最后将lsEd指向gtHd，gtEd指向nullptr
		for (ListNode *current = head; current != nullptr; current = current->next) {
			if (current->val < x) {
				if (fls) {
					lsEd = lsHd = current;
					fls = 0;
				}
				else {
					lsEd->next = current;
					lsEd = current;
				}
				
			}
			else {
				if (fgt) {
					gtEd = gtHd = current;
					fgt = 0;
				}
				else {
					gtEd->next = current;
					gtEd = current;
				}
				
			}
		}
		if (fls || fgt) return head; //若链表中所有值都大于或者小于x，返回头结点
		

		gtEd->next = nullptr;
		lsEd->next = gtHd;
		return lsHd;
	}
	
	ListNode* Solution::deleteDuplicates(ListNode* head) {
		if (!head) return head;
		ListNode *current = head;
		ListNode *tmp;
		while ( current->next != nullptr) {
			//如果当前节点与下一节点值相同，删除下一节点，让当前节点直接向下一节点的next
			if (current->val == current->next->val){
				tmp = current->next;
				current->next = current->next->next;
				delete tmp;
			}
			//如果当前节点与下一节点不同，则将节点往后移
			else {
				current = current->next;
			}
		}
		return head;
	}
	ListNode* Solution::deleteDuplicatesII(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode dummy(-1);
		ListNode *end = nullptr; //用来保存unique的节点的链表的末尾节点
		ListNode *prev = head;
		ListNode *cur = head->next;
		int flag = 0; //判断前一节点是否为重复节点
		int first = 1; //判断前一节点是否为unique链表的首节点
		while (cur) {
			//当前节点等于前一节点时，删除当前节点，当前节点后移
			if (prev->val == cur->val) {
				flag = 1;
				prev->next = cur->next;
				delete cur;
				cur = prev->next;
			}
			//当前节点不等于前一节点时
			else {
				//如果前一节点是重复节点的最后一个则删除，前一节点和当前节点同时后移
				if (flag) {
					delete prev;
					prev = cur;
					cur = cur->next;
					flag = 0;
				}
				//如果前一节点不是重复节点的最后一个，则将其加入到unique链表的最后一个，前一节点和当前节点同时后移
				else {
					//若该unique节点为首节点，则保存其位置
					if (first) {
						end = prev;
						dummy.next = prev;
						first = 0;
					}
					//若该unique节点不是首节点，则将其添加到unique链表末尾
					else {
						end->next = prev;
						end = prev;
					}
					prev = cur;
					cur = cur->next;
				}
			}
		}

		//处理最后一个节点

		//如果最后一个节点是重复节点，删除后返回unique链表
		if (flag) {
			delete prev;
			if (!dummy.next) return nullptr;
			else end->next = nullptr;
			return dummy.next;
		}
		//如果最后一个节点不是重复节点，将其加入unique链表后返回
		else {
			if (!dummy.next) return prev;
			else {
				end->next = prev;
				return dummy.next;
			}
		}
		
	}
	
	ListNode* Solution::rotateRight(ListNode* head, int k) {
		if (!head || !head->next) return head;
		ListNode *cur;
		int i;
		//计算链表长度
		for (i = 1, cur = head; cur->next != nullptr; cur = cur->next, i++);
		ListNode *last = cur;//链表最后一个节点
		int len = i;//链表长度
		ListNode *newHead;//移位后的新的头结点
		k = k % len;//最后移位的数量
		if (!k) return head; //移位次数为零时返回头结点


		//找到第len-k个节点，将该节点指向nullptr，该节点的下一个节点置为新的头结点，最后一个节点指向头结点，移位完成
		for (i = 1, cur = head; cur->next != nullptr; cur = cur->next, i++){
			if (i == len - k) {
				newHead = cur->next;
				cur->next = nullptr;
				break;
			}
		}
		last->next = head;

		return newHead;
	}
	
	ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
		if (!head) return nullptr;
		int i;
		ListNode *cur;
		for (cur = head, i = 1; cur->next != nullptr; cur = cur->next, i++);//求链表长度
		int len = i;

		if (n > len) return nullptr;
		if (n == len) return head->next; //若删除头结点，则直接返回第二个节点
		//删除从尾端数第n个节点，即正数第len-n+1个节点
		for (cur = head, i = 1; cur->next != nullptr; cur = cur->next, i++){
			if (i == len - n) {
				ListNode *tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
				break;
			}
		}
		return head;
	}
	
	ListNode* Solution::swapPairs(ListNode* head) {
		return reverseKGroup(head, 2);
	}
	ListNode* Solution::reverseKGroup(ListNode * head, int k) {
		if (!head || !head->next || k < 2) return head;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *cur = head;
		ListNode *prev = &dummy;
		while (cur) {
			int i = 0;
			ListNode *end = cur;
			ListNode *next;
			//判断当前节点后能否组成一个group，并将该group的头和尾节点保存
			for (i = 1; i < k && end->next != nullptr; i++) end = end->next;
			next = end->next;
			//当前节点满足k个节点组成group的条件，反向
			if (i == k ) {
				prev = reverse(cur, end, prev);//将该分组反向，并将前一分组的尾节点指向该分组，将该分组的新的尾节点置为新的前一节点
				cur = next;//当前节点后移k为到下一分组
			}
			//当前节点不满足k个节点组成group的条件，不变
			else {
				prev->next = cur; //直接将前一分组节点指向当前节点，其他不变，倒置结束
				break;
			}
		}
		return dummy.next;
	}
	ListNode* Solution::reverse(ListNode *first, ListNode *end, ListNode *prev) {
		ListNode *cur = first;
		ListNode *next;
		ListNode *prev2 = nullptr;
		ListNode *term = end->next;
		for (cur = first; cur != term; cur = next) {
			next = cur->next;
			cur->next = prev2;
			prev2 = cur;
		}
		prev->next = end;
		return first;
	}
	
	RandomListNode* Solution::copyRandmList(RandomListNode* head) {
		if (!head) return nullptr;
		RandomListNode dummy(-1);
		RandomListNode *prev = &dummy;

		RandomListNode *cur;
		//循环第一遍，构造一条全新的链表
		for (cur = head; cur != nullptr; cur = cur->next) {
			RandomListNode *newNode = new RandomListNode(cur->label);
			prev->next = newNode;
			prev = newNode;
		}
		RandomListNode *newCur = dummy.next;
		int i = 1;
		//循环第二遍，将全新链表的random指针重新赋值
		for (cur = head, newCur = dummy.next; cur != nullptr; cur = cur->next, newCur = newCur->next) {
			if (!cur->random) {
				newCur->random = nullptr;
				continue;
			}
			RandomListNode *now1 = head;
			RandomListNode *now2 = dummy.next;
			while (now1) {
				if (cur->random == now1) {
					newCur->random = now2;
					break;
				}
				now1 = now1->next;
				now2 = now2->next;
			}
		}
		return dummy.next;
	}
	
	/*设置快慢两个指针，慢指针走一步，快指针走两步，若相遇，则有环，否则无*/
	bool Solution::hasCycle(ListNode* head) {
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) return true;
		}
		return false;
	}
	/*
	当fast与slow相遇时，slow肯定没有走完遍历链表，而fast已经在环内循环了n圈。假设slow走了s步，则fast走了2s步，也走了s+n圈，设环长为r，则有 2s = s + nr；即 s = nr
	设整个链表长度为L,环入口点与相遇点距离为a， 起点到环入口点的距离为x，则有 x + a = nr = (n-1)r + L - x; 即是 x = (n-1)r + (L - x - a)
	L-x-a为相遇点到环入口点的距离，由此可知，从链表头到环入口点等于n-1圈内环+相遇点到环入口点，于是我们可以从head开始另设一个指针slow2，两个慢指针每次前进一步，他们一定会在环入口出相遇。
	*/
	ListNode* Solution::detectCycle(ListNode* head) {
		map<ListNode*, int> flag;
		int prev_len = 0;
		for (ListNode *cur = head; cur != nullptr; cur = cur->next) {
			if (flag.insert(pair<ListNode*, int>(cur, 0)).second == false) return cur;
		}
		return nullptr;
	}


	void Solution::reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next) return;

		//找到链表的中间节点
		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *prev = nullptr;
		while (fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
			
		}
		prev->next = nullptr;
		//将后一半链表反向
		ListNode *head2 = reverseList(slow);
		ListNode *cur1 = head;
		ListNode *cur2 = head2;

		while (cur1) {
			ListNode *tmp1 = cur1->next;
			ListNode *tmp2 = cur2->next;
			cur1->next = cur2;
			cur2->next = tmp1 == nullptr ? cur2->next : tmp1;

			cur1 = tmp1;
			cur2 = tmp2;
		}
	}

	class Solution::LRUCache {
		LRUCache(int capacity) {

		}

		int get(int key) {

		}

		void set(int key, int value) {

		}
	};
	ListNode* CreateList(int n) {
		if (n <= 0){
			printf("error input, n should be greater than 0\n");
			return nullptr;
		}
		ListNode* head = (ListNode*)malloc(sizeof(ListNode));
		printf("please input the number:\n");
		scanf_s("%d", &head->val);
		head->next = nullptr;
		ListNode* current = head;
		for (int i = 1; i < n; i++) {
			ListNode* node = (ListNode*)malloc(sizeof(ListNode));
			printf("please input the number:\n");
			scanf_s("%d", &node->val);
			node->next = nullptr;
			current->next = node;
			current = current->next;
		}

		return head;
	}
	void PrintList(ListNode* head) {
		for (ListNode* current = head; current != nullptr; current = current->next) {
			printf("%d->", current->val);
		}
		printf("\n");
	}
}