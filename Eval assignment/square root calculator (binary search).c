#include<stdio.h>
#include<math.h>

int main() {
	
	int n;
	double start,end,mid;
	
	printf("Enter a Number: ");
	scanf("%d",&n);
	
	start = 0, end = n;
	
	while((end - start)>=0.000001){
		
		mid = (start + end)/2;
		
		if(mid*mid < n)
			start = mid;
		if(mid*mid >= n)
			end = mid;
		
	}
	
	printf("Square Root of %d is %f",n,mid);
	
}