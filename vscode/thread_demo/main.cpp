//运行命令 g++ -o main main.cpp -lpthread && ./main
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* handler1(void *arg);
void* handler2(void * arg);

int var = 0;

int main()
{

pthread_t pthid1,pthid2;
if(pthread_create(&pthid1,NULL,handler1,NULL) != 0)
{
    printf("创建线程pthid1失败\n");
    return -1;
}

if(pthread_create(&pthid2,NULL,handler2,NULL) != 0)
{
    printf("创建线程pthid2失败\n");
    return -1;
}

printf("pthid1 = %lu,pthid2=%lu\n",pthid1, pthid2);
printf("等待子线程退出\n");
pthread_join(pthid1, NULL);
printf("子线程1已退出\n");
pthread_join(pthid2, NULL);
printf("子线程2已退出\n");

}

void* handler1(void* arg)
{
    for(int i=0;i<5;i++)
    {
        sleep(1);
        ++var;
        printf("handler1 sleep 1sec ok,%d\n",var);
    }
    pthread_exit(0);
}

void* handler2(void* arg)
{
    for(int i=0; i<30;i++)
    {
        sleep(1);
        printf("handler2 sleep 1sec ok,%d\n",var);
    }
}