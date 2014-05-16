#include<iostream>
#include<stdio.h>
using namespace std;

int indexof1(int* a, int len)
{
	int x = 0;
	for(int i = 0; i <= 9; i++)
	{
		x ^= a[i];
	}

	unsigned int filter = 1;
	int index = 1;

	while( (x&filter) == 0)
	{
		index++;
		filter = filter<<1;
	}
	return index;

}

bool ifindexis1(int num, int index){
	unsigned int x = 1;
	for(int i = 1; i < index; i++)
		x = x << 1;

	cout<<x<<endl;
	cout<<(num&x)<<endl;
	return num&x;
}

void find(int* a, int len, int& x, int& y)
{
	if( a==NULL || len <= 3) return;
	int index = indexof1(a,len);
	for(int i = 0; i < len; i++)
	{
		if(ifindexis1(*(a+i),index))
			x = x^(*(a+i));
		else
			y = y^a[i];
	}
}

int main(){
	int a[10] = {2,2,3,3,5,5,9,1,7,7};
	int x=0;
	int y=0;
	//find(a,x,y);

	int index = indexof1(a,10);
	cout<<index<<endl;

	cout<<ifindexis1(9,index)<<endl;
	find(a,10,x,y);
	cout<<x<<" "<<y<<endl;
	return 0;
}
