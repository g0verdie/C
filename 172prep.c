#include <stdlib.h>
#include <stdio.h>
int main(int argv, char **argc)
{
	int nums[] = {1,2,3,4};
	printf("4th element in the array - %d\n", nums[3]);
	printf("4th element in the array using pointers - %d\n", *nums + 3);
	printf("%p\n", &nums);	//give me the address
	//pointers to pointers...good luck
	//FUNCTION POINTERS SYNTAXIS:
	//void bubble_sort(int m, int a[],int (*p)(int, int));
	return 0;
}