#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& a, int x);
void printnum(vector<int>& a);

void my_print(int n)
{
	vector<int> a(n);
	print(a,n);
}

void print(vector<int>& a , int x)
{
	if(x == 0)
	{
		printnum(a);
	}
	else
	{
		for(int i = 0; i <= 9; i++)
		{
			a[x-1] = i;
			print(a,x-1);
		}
	}
}

void printnum(vector<int>& a)
{
	vector<int>::iterator i = a.begin();
	for( ;i != a.end(); i++)
	{
		if(*i != 0) break;
	}

	for( ;i != a.end(); i++ )
		cout<<(*i);
	cout<<endl;
}

int main(){
	my_print(3);
	return 0;
}
