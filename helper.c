#include "helper.h"

int quersumme(int a){
	int b = a/10;
	if(b==0) return a;
	else return a%10+quersumme(b);
}


int quersumme_der_summe(int a, int b){
	int c = a+b;
	return quersumme(c);
}
