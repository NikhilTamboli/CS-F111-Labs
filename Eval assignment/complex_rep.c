#include <stdio.h>
#include <math.h>

struct complex{
	double re;
	double im;
};
struct polar{
	double r;
	double theta;
};

typedef struct complex Complex;
typedef struct polar Polar;

#define PI 3.141592653589793238462643383279502884197169399375105820974944

Complex * make_complex(Complex *cm){
	double x,y;
	printf("Real part of the complex number: ");
	scanf("%lf", &x);
	printf("Imaginary part of the complex number: ");
	scanf("%lf", &y);
	cm->re = x;
	cm->im = y;
	return cm;
}

void print_complex(Complex cm){
	printf("The complex number is %.2lf + i%.2lf.", cm.re, cm.im);
}

Polar * make_polar(Polar *pl){
    double x,y;
    printf("Enter r: ");
    scanf(" %lf", &x);
    printf("Enter theta in degrees: ");
    scanf(" %lf", &y);
    pl->r = x;
    pl->theta = y;
}

void print_polar(Polar pl){
    printf("The polar coordinate is (%.2lf, %.2lf).", pl.r, pl.theta);
}

Polar * to_polar(Complex * ct, Polar * p){
    double value = ((ct->re*ct->re) + (ct->im*ct->im));
    double r2 = sqrt(value);
    double arg = ct->im/ct->re;
    double t = (atan(arg)*180)/PI;
    p->r = r2;
    p->theta = t;
    return p;
}

Complex * to_cartesian(Complex * ct, Polar * p){
    double th = (p->theta)*PI/180;
    ct->re = (p->r)*cos(th);
    ct->im = (p->r)*sin(th);
    return ct;
}

void print_cartesian(Complex ct){
    printf("The complex cartesian coordinate is (%.2lf, %.2lf)", ct.re,ct.im);
}

int main(void){
	
	int op;
	printf("1. Polar to Cartesian\n2. Cartesian to Polar\n");
	scanf("%d", &op);
    Complex c;
	Polar p;

	if (op==2) {
	   Complex *cptr = make_complex(&c); 
	   Polar *pptr = to_polar(&c, &p);
	   print_polar(p);
	} else if (op==1){
	    Polar *pptr = make_polar(&p);
	    Complex *cptr = to_cartesian(&c, &p);
	    print_cartesian(c);
	} else {
	    printf("Invalid input");
	}

	printf("\n");
	return 0;
}