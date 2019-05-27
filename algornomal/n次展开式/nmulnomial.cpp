#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct
{
	unsigned int c;
	unsigned int am;
	unsigned int bm;
}ITEM;

int main()
{
	int n;
	cin>>n;
	ITEM items[n+1];
	// scanf("%d",&n);
	

	if(n==0)
	{
		items[0]={1,0,0};
		return 0;
	}
	
	for(unsigned int i = 1;i<n+1;i++)
	{
		unsigned int count = i + 1;
		items[count-1] = {1,0,i};
		for(unsigned int j = count-2;j>0;j--)
		{
			unsigned c = items[j].c+items[j-1].c;
			items[j] = {c,i-j,j};
		}
		items[0]={1,i,0};
		cout<<n<<endl;
	}

	for(unsigned int i = 0;i<n+1;i++)
	{
		cout<<i<<endl;
		printf("第%d项:%d\n",i,items[i].c);
	}
	
}
