#include <stdio.h>
#include <string.h>
struct student
{
	char stu_name[30];
	int roll;
	char group;
	float fees;
};
struct student stu;
void set_data()
{
	printf("Enter details of Student:  \n name \nroll \nfees\n  ");
	scanf("%s", &stu.stu_name);
	scanf("%d", &stu.roll);
	scanf("%f", &stu.fees);
}
void print_data()
{
	printf("Details are :\n");
	printf("%s \n %d \n %f ", stu.stu_name, stu.roll, stu.fees);
}
void allocate_group()
{
	if ((stu.stu_name[0] >= 'A' && stu.stu_name[0] <= 'P') || (stu.stu_name[0] >= 'a' && stu.stu_name[0] <= 'p'))
		stu.group = 'A';
	else
		stu.group = 'B';
}
void alternative_charater()
{
	int i;
	for (i = 0; i < strlen(stu.stu_name); i = i + 2)
	{
		printf("%c", stu.stu_name[i]);
	}
}
int main()
{
	char choice;
	int ch;
	struct stu;

	do
	{
		printf("\n Press 1 ENTER DETAILS OF STUDENT EXCEPT GROUP ");
		printf("\n Press 2 TO PRINT THE DETAILS OF STUDENT EXCEPT GROUP ");
		printf("\n Press 3 TO ALLOCATE GROUP A OR B");
		printf("\n Press 4 PRINTING ALTERENATIVE CHARACTER TO STUDENT NAME \n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			set_data();
			break;
		case 2:
			print_data();
			break;
		case 3:
			allocate_group();
			break;
		case 4:
			alternative_charater();
			break;
		default:
			printf("Wrong choice!");
		}
		printf("\n Do you want to continue? (Press y/n)");
		scanf(" %c", &choice);
	} while (choice == 'y');
	return 0;
}