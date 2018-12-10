
#include<iostream>
#include<set>

std::set<unsigned long> setOfNumbers;

#define max 100000

using namespace std;

int checkAndInsert(unsigned long num)
{
  if(setOfNumbers.insert(num).second) {
    return 1;
	} else {
    return 0;
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


int main()
{
	for(int i = 0; i < max; i++) {
		unsigned long x = TELgen();
    checkAndInsert(x);
}
   std::cout<<setOfNumbers.size()<<std::endl;

 return 0;
}
