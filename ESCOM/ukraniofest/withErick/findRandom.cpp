
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define max 1000000

using namespace std;

vector<vector<unsigned long>> nums(max);

int findNum(unsigned long);
int genNum();
int getIndice(unsigned long);
unsigned long TELgen();

int main()
{
  unsigned int time_ui = static_cast<unsigned int>( time(NULL)%1000 );
  srand(time_ui);

  for(int i = 0; i < max; i++) {
    int x = genNum();
  }

  for(int i = 0; i < max; i++) {
    for(int j = 0; j < nums[i].size(); j++) {
      printf("%ld\n", nums[i][j]);
    }
  }

  return 0;
}

int getIndice(unsigned long num)
{
  int suma = 0, resto;
  while(num != 0){
    resto = num%10;
    suma = suma + resto;
    num = num/10;
  }
  return suma;
}

int findNum(unsigned long num)
{
  unsigned long i = 0;
  int indice = getIndice(num);

  if ( std::find(nums[indice].begin(), nums[indice].end(), num) != nums[indice].end() ) {
    return indice;
  } else {
    return -1;
  }
}

int genNum()
{
    unsigned long aux = TELgen();
    int find = findNum(aux);

    if (find == -1) {
      int indice = getIndice(aux);
      nums[indice].push_back(aux);
      return indice;
    } else {
      genNum();
    }
}

unsigned long TELgen()
{
	char* tel = (char *)malloc(10*sizeof(char));
  tel[0] = '5';
  tel[1] = '5';

	for (int i = 2; i <= 10; i++) {
		tel[i] = 48+(rand()%10);
	}

	return strtoul(tel, NULL, 0);
}
