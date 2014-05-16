#include<iostream>
using namespace std;
bool find(int (*a)[4], int i, int j, int goal)
{
	if(a == NULL || i <1 ||j<1) return false;
	int x = 0;
	int y = j-1;

	while(x < i && y >=0 )
	{
		while(a[x][y] > 7 && y > 0)
		{
			y--;
		}

		cout<<a[x][y]<<endl;
		if( y == 0 && a[x][y] != 7) return false; 

		while(a[x][y] < 7 && x < i-1)
		{
			x++;
		}

		cout<<a[x][y]<<endl;
		if( x == i-1 && a[x][y] != 7)  return false;

		cout<<a[x][y]<<endl;
		if(a[x][y] == 7) return true;
		else return false;
	}
}

int main()
{
	int a[4][4] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	if(find(a,4,4,7)) cout<<"ok"<<endl;
	return 0;
}
