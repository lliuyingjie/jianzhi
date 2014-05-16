#include<iostream>
using namespace std;

void exch(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int partition(int* a, int l, int r)
{
	int i = l-1;
	int j = r;

	for(;;)
	{
		while( a[++i] < a[r] );
		while( a[--j] > a[r] ) if(j == l) break;;

		if(j <= i) break;


		cout<<i<<" "<<j<<endl;

		exch(a[i],a[j]);
	}

	exch(a[i],a[r]);

	return i;
}

void quicksort(int* a, int l, int r)
{
	if(l >= r) return;
	int i = partition(a,l,r);
	quicksort(a,l,i-1);
	quicksort(a,i+1,r);
}

int main()
{
	int a[10] = {3,6,7,5,9,2,0,6,5,5};
	quicksort(a,0,9);
	for(size_t i = 0; i <= 9; i++)
		cout<<a[i]<<" ";
	return 0;
}
