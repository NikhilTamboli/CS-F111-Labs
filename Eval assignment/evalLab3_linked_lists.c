#include<stdio.h>
#include<stdlib.h>
 
struct report
{
 	int id;
 	int marks[3];
 	struct report* next;
};
 
typedef struct report R;
 
R* start;
R* end;
 
void insert();
void display();
void del();
 
int main()
{
 	start = 0;
 	end = 0;
 	int option;
 	while(1)
  	{
 	  printf("\nEnter option: \n");
 	  printf("1 to insert report, 2 to display marklist, 3 to delete report, 4 to exit.\n");
 	  scanf(" %d",&option);
 	  switch(option)
	  {
	  	case 1:	
	  			insert();
	  			break;

	  	case 2: 
	  			display();
	  			break;

        case 3: 
                del();
                break;

	  	case 4: return 0;

	  	default: printf("Invalid Option.\n");
	  }
	}
	return 0;
}

void insert()
{
	R* x = (R*)malloc(sizeof(R));
	printf("Enter id and marks of subject 1, subject 2 and subject 3\n");
	scanf(" %d", &(x->id));
	scanf(" %d", &(x->marks[0]));
	scanf(" %d", &(x->marks[1]));
	scanf(" %d", &(x->marks[2]));
	x->next = 0;
    
	if(start == 0)
	{
		start = x;
		end = x;
	}
	else
	{
	    R* r = start;
	    int flag = 1;
	    while(r->next!=0){
	        if(r->id==x->id){
	            printf("ID already exists.");
	            int flag=0;
	            break;
	        }
	        r = r->next;
	    }
	    if(flag){
            end->next = x;
    	    end = x;	        
	    }
	    sort();
	}
	
}

void display()
{
	R* x = start;
	while(x != 0)
	{
		printf("ID: %d , Subject 1: %d , Subject 2: %d , Subject 3: %d\n", x->id, x->marks[0], x->marks[1], x->marks[2]);
		x = x->next;
	}
}
 
void del()
{
    int x;
    printf("Enter the id of the report to delete: ");
    scanf(" %d", &x);
    R* r = start;
    R* prev = r;
    while(r!=0){
        if(r->id==x) break;
        else {
            prev = r;
            r = r->next;
        }
    }
    prev->next = r->next;
}

void sort()
{
    // printf("sorting\n");
	R* r = start;
	R* temp = r;
	R* r2 = r->next;
	while(r2->next!=0){
		if(r->id>r2->id){
			temp->id = r2->id;
			temp->marks[0] = r2->marks[0];
			temp->marks[1] = r2->marks[1];
			temp->marks[2] = r2->marks[2];
			r2->id = r->id;
			r2->marks[0] = r->marks[0];
			r2->marks[1] = r->marks[1];
			r2->marks[2] = r->marks[2];
			r->id = temp->id;
			r->marks[0] = temp->marks[0];
			r->marks[1] = temp->marks[1];
			r->marks[2] = temp->marks[2];
		}
		r = r->next;
		r2 = r2->next;
	}
}