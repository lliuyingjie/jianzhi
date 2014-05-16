#include<iostream>
using namespace std;

void exch(int& i, int& j)
{
	int tmp = i;
	i = j;
	j = tmp;
}

int partition(int* a, int length, bool (*func)(int))
{
	int i = -1;
	int j = length;
	while( i != j)
	{
		while(!(*func)(a[++i]));
		while((*func)(a[--j]))
		{
			if(j == i) break;
		}
		exch(a[i],a[j]);
	}
}

bool iseven(int n)
{
	if((n&0x01)==0) return true;
	else return false;
}

int main()
{
	int a[9] = {1,2,3,4,5,6,7,8,9};
	partition(a,9,iseven);
	for(int i = 0; i<=8; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
