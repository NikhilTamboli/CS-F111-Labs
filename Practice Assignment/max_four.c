#include <stdio.h>

int max_four(int a, int b, int c, int d){
	int max=a;
	if(b>max){
		max=b;
	}
	if(c>max){
		max=c;
	}
	if(d>max){
		max=d;
	}
	return max;
}

int main(void){
	int a,b,c,d;
	printf("Enter four values: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("The maximum number amongst these values is %d.\n", max_four(a,b,c,d));
	return 0;
}