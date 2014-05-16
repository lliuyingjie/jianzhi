#include<iostream>
using namespace std;

long long  cout_1(long long n)
{
	long long icount = 0;
	long long ifactor = 1;
	long long ilowernum = 0;
	long long icurrnum = 0;
	long long ihighernum = 0;

	while( n / ifactor != 0)
	{
		ihighernum = (n/(ifactor*10));
		ilowernum = n%ifactor;
		icurrnum = (n/ifactor)%10;

		switch(icurrnum)
		{
			case 0:
				icount += ihighernum*ifactor;
				break;
			case 1:
				icount += ihighernum*ifactor+(ilowernum+1);
				break;
			default:
				icount += (ihighernum+1)*ifactor;
				break;
		}

		ifactor *= 10;
	}

	return icount;

}

int main()
{
	long long n = 10000000000000;
	cout<<cout_1(n)<<endl;
	return 0;
}
