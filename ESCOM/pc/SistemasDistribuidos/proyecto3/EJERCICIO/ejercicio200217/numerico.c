#include <stdio.h>
#include <math.h>


#define Cal 1e6 *3


int main ()
{
	int i=0;

	double cose=0, seno=0 ,tang=0,loga=0,raiz=0;
	 while (i<Cal)
	 {
	 	cose+=cos(i);
	 	seno+=sin(i);
	 	tang+=tan(i);
	 	loga+=log10(i);
	 	raiz+=sqrt(i);
	 		i++;
	 }

return 0;
}

