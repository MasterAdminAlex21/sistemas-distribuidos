#include<stdio.h>

//using namespace std;

int main() { 
	int ent, ent2;
	float res1;
	float flo, res2;
	
	printf("Escribe el numero entero uno\n");
	scanf("%d", &ent);	 

	printf("Escribe el numero entero 2\n");
	scanf("%d", &ent2);

	printf("Escribe el numero flotante\n");
	scanf("%f", &flo);
	
	res1= ent/ent2;
	res2=flo/ent;	

	printf("El resultado entre enteros es: %f\n",res1);
	printf("El resultado entre flotante y entero es: %f\n",res2);
	
	return 0;
	

}
