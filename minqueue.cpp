#include<stack>
#include<iostream>
using namespace std;

class min_deque{
	public:
		void my_push(int x);
		int my_pop();
		int show_min() const;
	private:
		stack<int> out_stack;
		stack<int> in_stack;
		stack<int> min;
};

void min_deque::my_push(int x)
{
	if(my_push.empty())
	{
		in_stack.push(x);
		min.push(x);
	}
	else
	{
		in_stack.push(x);
		if(x<min.top())
		{
			min.push(x);
		}else{
			min.push();
		}
	}
}

int min_deque::show_min() const
{
	if(!min.empty())
		return min.top();
	else
		cout<<"biaome limian sha dou meiyou"<<endl;
}
