/*
警察抓了A B C D四个罪犯,其中一名是小偷,审讯的时候:
A说:我不是小偷
B说:C是小偷
C说:小偷肯定是D
D说:C是在冤枉人
三个人说的真话,一个人说了假话,请判断到底谁是小偷?
*/

//#include<iostream>
//using namespace std;
#include<stdio.h>

void who_is_thief(){
	for(auto x=0;x<4;x++)
	{
		int dis_a = (x!=0)? 1:0;
		int dis_b = (x==2)? 1:0;
		int dis_c = (x==3)? 1:0;
		int dis_d = 1-dis_c;
		
		if((dis_a+dis_b+dis_c+dis_d)==3)
		{
			printf("小偷是:%d\r\n",x);
		}
	}
}


int main(){

	//scanf("%d",
	who_is_thief();
	return 0;
}
