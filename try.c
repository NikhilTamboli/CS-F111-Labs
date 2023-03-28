#include<stdio.h>

struct report
{
	int id;
	int marks[3];
};

typedef struct report Report;

int insert(Report * list, int size, Report r);

void display(Report * list, int size);

void to_file(Report * list, int size);

int main()
{
  Report list[100];
  int size=0;

  int option;

  while(1)
  {
	  printf("\nEnter option: \n");
	  printf("1 to insert report, 2 to display marklist, 3 to save in file, 4 to exit.\n");
	  scanf(" %d",&option);
	  Report r;
	  int flag, id;
	  switch(option)
	  {
	  	case 1:	
	  			printf("Enter id and marks of subject 1, subject 2 and subject 3\n");
	  			scanf(" %d", &r.id);
	  			scanf(" %d", &r.marks[0]);
	  			scanf(" %d", &r.marks[1]);
	  			scanf(" %d", &r.marks[2]);
	  			flag = insert(list, size, r);
	  			if(flag == 1)
	  				size = size + 1;
	  			else
	  				printf("id already exists.\n");
	  			break;

	  	case 2: 
	  			display(list, size);
	  			break;

	  	case 3: 
	  			to_file(list, size);
	  			break;		

	  	case 4: return 0;

	  	default: printf("Invalid Option.\n");
	  }
	}
}


int insert(Report * list, int size, Report r)
{
	if(size == 0)
	{
		list[0] = r;
		return 1;
	}

	else
	{
		for(int i = 0; i < size; i++)
		{
			if(list[i].id == r.id)
				return 0;
		}
		int i;
		for(i = 0; i < size; i++)
		{
			if(list[i].id > r.id)
			{
				for(int j = size-1; j >= i; j--)
				{
					list[j+1] = list[j];
				}	
				break;	
			}
		}
		list[i] = r;
		return 1;
	}
}

void display(Report * list, int size)
{
	printf("List size: %d\n", size);
	for(int i = 0; i < size; i++)
	{
		printf("ID: %d , Subject 1: %d , Subject 2: %d , Subject 3: %d\n", list[i].id, list[i].marks[0], list[i].marks[1], list[i].marks[2]);
	}
}

void to_file(Report * list, int size)
{

	FILE *fp = fopen("marks.txt", "w+");
 	
	for(int i = 0; i < size; i++)
	{
		fprintf(fp, "ID: %d , Subject 1: %d , Subject 2: %d , Subject 3: %d\n", list[i].id, list[i].marks[0], list[i].marks[1], list[i].marks[2]);
	}

	fclose(fp);
}