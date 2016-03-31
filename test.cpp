#include "test.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(int argc, char* argv[]) {
	char option[20];
	printf("please input the option:\n");
	scanf("%s", option);
	while (strcmp(option, "exit")) {
		if (!strcmp(option, "list")) testList();
		else if (!strcmp(option, "array")) testArray();


		printf("please input the option:\n");
		scanf("%s", option);

	}
	return 0;
}