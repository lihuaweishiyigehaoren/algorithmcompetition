/*
贪婪法
0-1背包问题
有一个背包,最多承重C=150的物品,现在有7个物品(物品不能分割成任意大小),编号为1~7,
重量分别为wi=[35,30,60,50,40,10,25],价值分别为pi=[10,40,30,50,35,40,30]
现在从这7个物品中选择一个或多个装入背包,要求在物品总重量不超过C的前提下,所装入的物品总价值最高.

warning : 这里只写出了一种关于价格使用贪婪法的计算方式;
*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// 物品的数据结构设计
typedef struct
{
    int weight;
    int price;
    int status; //0:未选中,1:已选中,2:已经不可选
}OBJECT;

// 背包,可选物品列别,背包的总重量
typedef struct
{
    std::vector<OBJECT> objs;
    int totalC;
}KNAPSACK_PROBLEM;

typedef int (*SELECT_POLICY)(std::vector<OBJECT>& objs,int c);

int Choosefunc1(std::vector<OBJECT>& objs,int c)
{
    int index = -1;// 表示背包的容量已满
    int mp = 0;
    for(int i = 0;i<static_cast<int>(objs.size());i++)
    {
        if((objs[i].status==0)&&(objs[i].price>mp))
        {
            mp = objs[i].price;
            index = i;
        }
    }
    return index;
}


void PrintResult(std::vector<OBJECT> & objs)
{
    int totalW = 0;
    int totalP = 0;

    for(int i = 0;i<static_cast<int>(objs.size());i++)
    {
        if(objs[i].status == 1)
        {
            totalW += objs[i].weight;
            totalP += objs[i].price;
            cout<<"object"<<i+1<<":weight="<<objs[i].weight<<
            ",price"<<objs[i].price<<endl;

        }
    }
    cout<<"total weight"<<totalW<<",total price"<<totalP<<endl;
}

void GreedyAlgo(KNAPSACK_PROBLEM *problem,SELECT_POLICY spFunc)
{
    int idx;
    int ntc = 0;

    // spFunc 每次选最符合侧罗的那个物品,然后再检查
    while((idx = spFunc(problem->objs,problem->totalC-ntc)) != -1)
    {
        // 所选物品是否满足背包承重要求?
        if((ntc+problem->objs[idx].weight)<=problem->totalC)
        {
            problem->objs[idx].status = 1;
            ntc += problem->objs[idx].weight;
        }
        else
        {
            // 不能选这个物品了,做个标记再重新选
            problem->objs[idx].status = 2;
        }
        
    }
    PrintResult(problem->objs);

}


OBJECT objects[]={{35,10,0},{30,40,0},{60,30,0},{50,50,0},
                  {40,35,0},{10,40,0},{25,30,0}};

int main()
{
    KNAPSACK_PROBLEM problem;

    // assign para1-数组开始的地方 para2-数组结束的地方
    problem.objs.assign(objects,objects+7);
    problem.totalC = 150;

    GreedyAlgo(&problem,Choosefunc1);

    return 0;
}