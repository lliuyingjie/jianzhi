#include<iostream>
using namespace std;

void reverse(char* a)
{
	if(a == NULL) return;
	char* begin = a;
	char* end = begin;
	while(*end != '\0')
	{
		end++;
	}
	end--;

	cout<<(*end)<<endl;

	while( begin < end )
	{

		char tmp = *begin;
		char A = *end;

		*begin = A;

		cout<<"once"<<endl;
		*end = tmp;

		begin++;
		end--;
	}

}

int main(){
	char a[] = "I am a student.";
	cout<<a<<endl;
	reverse(a);
	cout<<a<<endl;
	return 0;
}
