#include<iostream>
using namespace std;

void find(int* a, int len, int sum)
{
	if(len < 2) return;
	int small = 0;
	int big = 1;

	int cursum = *(a+small)+ *(a+big);

	while(big < len && small < big)
	{
		while(cursum != sum && small < big && big < len)
		{
			if(cursum < sum)
			{
				big++;`
				cursum += *(a+big);
			}

			if(cursum > sum)
			{
				cursum -= *(a+small);
				small++;
			}
		}

		if(cursum == sum)
		{
			cout<<"ok"<<endl;
			cursum -= *(a+small);
			small++;
		}
	}
}

int main(){
	int a[8] = {1,2,3,4,5,6,7,8};
	find(a,8,15);
	return 0;
}
