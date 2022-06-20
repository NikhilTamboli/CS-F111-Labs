#include <stdio.h>

int main() {
    int n=0,r=1,op=3;
    while(op !=1 && op != 2){
        printf("1) nPr \n2) nCr\n");
        printf("Choose the operation by entering the corresponding number: \n");
        scanf("%d", &op);
    }
    printf("n r: ");
    scanf("%d %d", &n, &r);
    while(n<r){
        printf("n should be greater than r.\n");
        printf("n r:");
        scanf("%d %d", &n, &r);
    }
    
    int nfac=n, nrfac=(n-r), rfac=r, i=n, j=(n-r), k=r;
    if(n!=0 && (n-r)!=0 && r!=0){
        while(i>1){
            i -= 1;
            nfac *= i;
        }
        while(j>1){
            j-=1;
            nrfac *= j;
        }
        while(k>1){
            k-=1;
            rfac *= k;
        }
    } else if(n==0){
        nfac = 1;
        while(j>1){
            j-=1;
            nrfac *= j;
        }
        while(k>1){
            k-=1;
            rfac *= k;
        }
    } else if((n-r)==0){
        nrfac = 1;
        while(i>1){
            i -= 1;
            nfac *= i;
        }
        while(k>1){
            k-=1;
            rfac *= k;
        }
    } else if(r==0){
        rfac = 1;
        while(i>1){
            i -= 1;
            nfac *= i;
        }
        while(j>1){
            j-=1;
            nrfac *= j;
        }
    }
    
    if(op==1){
        int npr = nfac/nrfac;
        printf("%d", npr);
    } else {
        int ncr = nfac/(rfac*nrfac);
        printf("%d", ncr);
    }
    return 0;
}