#include <stdio.h>
#define MAX 4
int main()
{
	int i, j, a[MAX];
	printf("\nEnter elements (row major):\n");
	for (i = 0; i < MAX; i++)
		scanf("%d", &a[i]);
	printf("\nThe matrix is...\n");
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (i == j)
				printf("%d ", a[i]);
			else
				printf("0 ");
		}
		printf("\n");
	}
	return 0;
}w