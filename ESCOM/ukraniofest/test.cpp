#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
	char *tel;
	char *rfc;
	char *partido;
} Voto;

char *TELgen();

int main()
{
	char *tel;
  unsigned long i = 0;

	vector<unsigned long> ar(88700000);

	for (i; i < 88700000; i++) {
		ar[i] = i;
	}

	if ( std::find(ar.begin(), ar.end(), 88699999) != ar.end() ) {
		printf("FIND IT!");
	} else {
		printf("Oh no! :(");
	}

	return 0;
}

char *TELgen()
{
	srand(time(NULL));
	char *tel=(char *)malloc(10*sizeof(char));
	for(int i=0;i<10;i++)
	{
		tel[i]=48+(rand()%10);
	}
	return tel;
}
