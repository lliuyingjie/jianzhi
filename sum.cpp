#include<iostream>
using namespace std;

void two_num(int* a, int len, int sum)
{
	int ahead = 0;
	int behind = len-1;
	while( (a[ahead]+a[behind]) != sum )
	{

	}
}

int main(){
	int a[6] = {1,2,4,7,11,15};
	two_num(a,6,15);
	return 0;
}
