#include<iostream>
using namespace std;

int min(int n1,int n2,int n3)
{
	int min = (n1<n2)?n1:n2;
	min = (min<n3)?min:n3;
	return min;
}

int getuglynum(int index)
{
	int* uglynum = new int[index];
	uglynum[0] = 1;
	int* pm2 = uglynum;
	int* pm3 = uglynum;
	int* pm5 = uglynum;

	int nuxtuglyindex = 1;
	while(nuxtuglyindex < index)
	{
		*(uglynum + nuxtuglyindex) = min((*pm2)*2,(*pm3)*3,(*pm5)*5);
		while((*pm2)*2 <= *(uglynum + nuxtuglyindex))
			pm2++;
		nuxtuglyindex++;
	}

}
