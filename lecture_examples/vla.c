#include <stdio.h>

int main()
{
	printf("variable length array demo.\n\n");

	printf("How many numbers do you want to read in? ");
	int n;
	scanf("%d", &n);
	
	int vla[n];
	printf("vla has now array size %ld\n", sizeof(vla));
	
	for (int i=0; i<n; i++)
	{
		printf("number #%d: ", i+1);
		scanf("%d", &vla[i] );
	}
	
	printf("\nHere are all your numbers:\n");
	for (int i=0; i<n; i++)
	{
		printf("number #%d: %d\n", i+1, vla[i]);		
	}
	printf("\n");
	
}
