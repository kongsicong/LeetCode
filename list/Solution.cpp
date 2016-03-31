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
		
		//�ҵ�m��ǰһ���ڵ㣬������
		ListNode *current = head;
		ListNode *rh;
		for (int i = 1; current != nullptr; current = current->next, i++) {
			if (i == m - 1) rh = current;
			if (i >= m) break;
		}
		
		//��m��n��һ�ε������ã����нڵ�mָ��nullptr
		ListNode *prev = nullptr;
		ListNode *next;
		for (int i = m; i <= n; i++) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		//��m=1����û��m��ǰһ���ڵ㣬ֱ�����׽ڵ�ָ��n�ĺ�һ���ڵ㣬�������
		if (m == 1) {
			head->next = current;
			return prev;
		}
		//��m>1������m��ǰһ���ڵ㣬��m��ǰһ���ڵ�ָ��ڵ�n���ýڵ�mָ��n�ĺ�һ���ڵ�
		else {
			rh->next->next = current;//m->n+1
			rh->next = prev;//m-1->n
			return head;
		}
	}
	
	ListNode* Solution::partition(ListNode* head, int x) {
		if (!head || !head->next) return head; //ͷ���Ϊ�ջ���������Ϊһ���򷵻�ͷ���


		ListNode *lsHd;  //�洢С��x�Ľڵ��е�ͷ���
		ListNode *lsEd;  //�洢С��x�Ľڵ��е�β�ڵ�
		ListNode *gtHd;  //�洢����x�Ľڵ��е�ͷ���
		ListNode *gtEd;  //�洢����x�Ľڵ��е�β�ڵ�
		int fls = 1;
		int fgt = 1;

		//��С��x�Ľڵ����lsEd�ĺ��棬����x�Ľڵ����gtEd�ĺ��棬���lsEdָ��gtHd��gtEdָ��nullptr
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
		if (fls || fgt) return head; //������������ֵ�����ڻ���С��x������ͷ���
		

		gtEd->next = nullptr;
		lsEd->next = gtHd;
		return lsHd;
	}
	
	ListNode* Solution::deleteDuplicates(ListNode* head) {
		if (!head) return head;
		ListNode *current = head;
		ListNode *tmp;
		while ( current->next != nullptr) {
			//�����ǰ�ڵ�����һ�ڵ�ֵ��ͬ��ɾ����һ�ڵ㣬�õ�ǰ�ڵ�ֱ������һ�ڵ��next
			if (current->val == current->next->val){
				tmp = current->next;
				current->next = current->next->next;
				delete tmp;
			}
			//�����ǰ�ڵ�����һ�ڵ㲻ͬ���򽫽ڵ�������
			else {
				current = current->next;
			}
		}
		return head;
	}
	ListNode* Solution::deleteDuplicatesII(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode dummy(-1);
		ListNode *end = nullptr; //��������unique�Ľڵ�������ĩβ�ڵ�
		ListNode *prev = head;
		ListNode *cur = head->next;
		int flag = 0; //�ж�ǰһ�ڵ��Ƿ�Ϊ�ظ��ڵ�
		int first = 1; //�ж�ǰһ�ڵ��Ƿ�Ϊunique������׽ڵ�
		while (cur) {
			//��ǰ�ڵ����ǰһ�ڵ�ʱ��ɾ����ǰ�ڵ㣬��ǰ�ڵ����
			if (prev->val == cur->val) {
				flag = 1;
				prev->next = cur->next;
				delete cur;
				cur = prev->next;
			}
			//��ǰ�ڵ㲻����ǰһ�ڵ�ʱ
			else {
				//���ǰһ�ڵ����ظ��ڵ�����һ����ɾ����ǰһ�ڵ�͵�ǰ�ڵ�ͬʱ����
				if (flag) {
					delete prev;
					prev = cur;
					cur = cur->next;
					flag = 0;
				}
				//���ǰһ�ڵ㲻���ظ��ڵ�����һ����������뵽unique��������һ����ǰһ�ڵ�͵�ǰ�ڵ�ͬʱ����
				else {
					//����unique�ڵ�Ϊ�׽ڵ㣬�򱣴���λ��
					if (first) {
						end = prev;
						dummy.next = prev;
						first = 0;
					}
					//����unique�ڵ㲻���׽ڵ㣬������ӵ�unique����ĩβ
					else {
						end->next = prev;
						end = prev;
					}
					prev = cur;
					cur = cur->next;
				}
			}
		}

		//�������һ���ڵ�

		//������һ���ڵ����ظ��ڵ㣬ɾ���󷵻�unique����
		if (flag) {
			delete prev;
			if (!dummy.next) return nullptr;
			else end->next = nullptr;
			return dummy.next;
		}
		//������һ���ڵ㲻���ظ��ڵ㣬�������unique����󷵻�
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
		//����������
		for (i = 1, cur = head; cur->next != nullptr; cur = cur->next, i++);
		ListNode *last = cur;//�������һ���ڵ�
		int len = i;//������
		ListNode *newHead;//��λ����µ�ͷ���
		k = k % len;//�����λ������
		if (!k) return head; //��λ����Ϊ��ʱ����ͷ���


		//�ҵ���len-k���ڵ㣬���ýڵ�ָ��nullptr���ýڵ����һ���ڵ���Ϊ�µ�ͷ��㣬���һ���ڵ�ָ��ͷ��㣬��λ���
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
		for (cur = head, i = 1; cur->next != nullptr; cur = cur->next, i++);//��������
		int len = i;

		if (n > len) return nullptr;
		if (n == len) return head->next; //��ɾ��ͷ��㣬��ֱ�ӷ��صڶ����ڵ�
		//ɾ����β������n���ڵ㣬��������len-n+1���ڵ�
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
			//�жϵ�ǰ�ڵ���ܷ����һ��group��������group��ͷ��β�ڵ㱣��
			for (i = 1; i < k && end->next != nullptr; i++) end = end->next;
			next = end->next;
			//��ǰ�ڵ�����k���ڵ����group������������
			if (i == k ) {
				prev = reverse(cur, end, prev);//���÷��鷴�򣬲���ǰһ�����β�ڵ�ָ��÷��飬���÷�����µ�β�ڵ���Ϊ�µ�ǰһ�ڵ�
				cur = next;//��ǰ�ڵ����kΪ����һ����
			}
			//��ǰ�ڵ㲻����k���ڵ����group������������
			else {
				prev->next = cur; //ֱ�ӽ�ǰһ����ڵ�ָ��ǰ�ڵ㣬�������䣬���ý���
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
		//ѭ����һ�飬����һ��ȫ�µ�����
		for (cur = head; cur != nullptr; cur = cur->next) {
			RandomListNode *newNode = new RandomListNode(cur->label);
			prev->next = newNode;
			prev = newNode;
		}
		RandomListNode *newCur = dummy.next;
		int i = 1;
		//ѭ���ڶ��飬��ȫ�������randomָ�����¸�ֵ
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
	
	/*���ÿ�������ָ�룬��ָ����һ������ָ���������������������л���������*/
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
	��fast��slow����ʱ��slow�϶�û���������������fast�Ѿ��ڻ���ѭ����nȦ������slow����s������fast����2s����Ҳ����s+nȦ���軷��Ϊr������ 2s = s + nr���� s = nr
	������������ΪL,����ڵ������������Ϊa�� ��㵽����ڵ�ľ���Ϊx������ x + a = nr = (n-1)r + L - x; ���� x = (n-1)r + (L - x - a)
	L-x-aΪ�����㵽����ڵ�ľ��룬�ɴ˿�֪��������ͷ������ڵ����n-1Ȧ�ڻ�+�����㵽����ڵ㣬�������ǿ��Դ�head��ʼ����һ��ָ��slow2��������ָ��ÿ��ǰ��һ��������һ�����ڻ���ڳ�������
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

		//�ҵ�������м�ڵ�
		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *prev = nullptr;
		while (fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
			
		}
		prev->next = nullptr;
		//����һ��������
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