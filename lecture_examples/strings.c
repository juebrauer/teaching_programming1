#include <stdio.h>
#include <string.h>

int main()
{
	// 1. read in a string
	printf("\n1.\n");
	char name1[100];
	printf("What is your name?\nYour name: ");
	fgets(name1, sizeof(name1), stdin);
	name1[strlen(name1)-1] = '\0';
	printf("Hello %s\n", name1);
	printf("Length of your name: %ld characters\n", strlen(name1));
	
	
	// 2. define a string directly in your code
	printf("\n2.\n");
	char name2[] = "Bart Simpson";
	char* name3 = "Lisa Simpson";
	printf("name2: %s\n", name2);
	printf("name3: %s\n", name3);
	
	
	// 3. change some part of the string (works!)
	printf("\n3.\n");
	name2[0] = 'G';
	printf("name2: %s\n", name2);
	
	
	// 4. change some part of the string (does not work!)
	printf("\n4.\n");
	//name3[0] = 'G';
	printf("name3: %s\n", name3);
	
	
	// 5. copy strings
	printf("\n5.\n");
	char text[500];		
	printf("text: %s\n", text);
	
	strcpy(text, name1);
	printf("text: %s\n", text);
	
	
	// 6. copy only some part of the string
	printf("\n6.\n");
	char text2[500];	
	printf("text2: %s\n", text2);
	
	int n = 3;
	strncpy(text2, name1, n);
	text2[n] = '\0';
	printf("text2: %s\n", text2);
	
	
	// 7. concatenate strings
	printf("\n7.\n");
	strcat(name2, " is very clever.");
	printf("concatenation result: %s\n", name2);
	
	
	// 8. erase a string
	printf("\n8.\n");
	memset(name2, 0, sizeof(name2));
	printf("name2: %s\n", name2);
	
	
	// 9. declare an array of strings
	printf("\n9.\n");
	char weekdays[][50] = { "monday", "tuesday", "wednesday" };
	for (int i=1; i<=3; i++)
	{
		printf("day of week #%d: %s\n", i, weekdays[i-1]);
	}
	
}
