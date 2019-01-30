#include<cstdio>
#include<cstdlib>

int main()
{
    int tmp = 0;
    for(int i = 1;i <= 10000;i++)
    {
        system("./gen");
        system("./my");
        system("./std");

        if(i/100>tmp) {printf("-- %d --\n",i);tmp=i/100;}
        if(system("diff out1.txt out2.txt"))
        {
            printf("wrong in --> %d \n",i);
            break;
        }
    }
    return 0;
}
