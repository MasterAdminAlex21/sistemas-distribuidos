#include <stdio.h>
#include <math.h>

#define Factor 1e6 * 3

int main(){
	int i = 0;
	double s=0,c=0,t=0,l=0,r=0;
	while(i<Factor){
		s+=sin(i);
		c+=cos(i);
		t+=tan(i);
		l=log10(i);
		r=sqrt(i);
		i++;
	}
	return 0;
}

