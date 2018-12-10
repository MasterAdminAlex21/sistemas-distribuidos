#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

using namespace std; 

int main(int argc, char const *argv[])
{
	string cadenota;
	int z=0;
	for (int i = 1; i < 703050000; ++i)
	{
		if(i%4==0)
			cadenota+=(char)32;
		else
			cadenota+=(char)(65+rand()%(91-65));
	}

	for (int i = 1; i <703050000; i++)
		{
			if(cadenota[i]=='I')
				if(cadenota[i+1]=='P')
					if(cadenota[i+2]=='N')
					{
						z++;
						i+=3;
					}
		}

	cout<<z<<endl;
	return 0;
}