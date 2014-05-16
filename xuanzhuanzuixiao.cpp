#include<iostream>
using namespace std;

int find(int* a, int l, int r)
{
	if(r-l==1) return a[r];

	int tmp = (r+l)/2;
	if(a[tmp]>a[l])
		return find(a,tmp,r);
	else
		return find(a,l,tmp);

}

int main()
{
	int a[7] = {3,4,5,1,2,3,3};
	unsigned int t = 7;
	t = t>>1;
	cout<<t<<" "<<(t&(0x01))<<endl;
	cout<<find(a,0,5)<<endl;
}
