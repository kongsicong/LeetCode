#include "array/Solution.h"
#include "testArray.h"
#include <stdio.h>
#include <stdlib.h>
using namespace array;

void testArray() {
	int choice = 1;
	while (choice) {
		printf("please input the choice of the problem:\n");
		scanf_s("%d", &choice);
		switch (choice) {
			case 1 : 
				testRemoveDuplicates();
				break;
			case 2:
				testRemoveDuplicatesII();
				break;
			case 3:
				testFindMedianSortedArrays();
				break;
			default:
				break;
		}
	}
	printf("test RemoveDuplicates:\n");
	testRemoveDuplicates();
}

void testRemoveDuplicates() {
	int A1[1] = { 1 };
	int A2[2] = { 1, 1 };
	int A3[3] = { 1, 1, 2 };
	int A4[5] = { 1, 2, 3, 3, 3 };
	int A5[8] = { 1, 1, 1, 2, 2, 2, 3, 3 };

	int n;
	printf("test A1\n");
	PrintArray(A1, 1);
	printf("result A1\n");
	n = removeDuplicates(A1, 1);
	PrintArray(A1, n);

	printf("test A2\n");
	PrintArray(A2, 2);
	printf("result A2\n");
	n = removeDuplicates(A2, 2);
	PrintArray(A2, n);

	printf("test A3\n");
	PrintArray(A3, 3);
	printf("result A3\n");
	n = removeDuplicates(A3, 3);
	PrintArray(A3, n);

	printf("test A4\n");
	PrintArray(A4, 5);
	printf("result A4\n");
	n = removeDuplicates(A4, 5);
	PrintArray(A4, n);

	printf("test A5\n");
	PrintArray(A5, 8);
	printf("result A5\n");
	n = removeDuplicates(A5, 8);
	PrintArray(A5, n);
}
void testRemoveDuplicatesII() {
	int a[20];
	int n = CreateArray(a);

	PrintArray(a, n);
	n = removeDuplicatesII(a, n);
	PrintArray(a, n);


}

void testFindMedianSortedArrays() {
	int A[20];
	int B[20];
	int n = CreateArray(A);
	int m = CreateArray(B);
	printf("A:\n");
	PrintArray(A, n);
	printf("B:\n");
	PrintArray(B, m);
	printf("median:\t%lf\n", findMedianSortedArrays(A, n, B, m));
}