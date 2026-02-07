#include "common.h"
//////////////菜单////////////////
Dlist dishesHead = NULL; //全部菜品数据
ChoppBoard board = {.len=0};
int inventoryBoard[1024] = {[0 ... 1023] = 10}; //库存板
dishesItem menuData[8]={0};
int maxpages = 0;
bool isEnd = false;
//////////////登录/////////////////
Ulist userhead = NULL;
userInfo loginUser={.uid=-1,.type=0};
//打开文件
FILE *openfile(const char *path,char *mode)
{
    //打开文件 获取文件流指针
    printf("path=%s mode=%s\n",path,mode);
    FILE *fp=fopen(path,mode);
    if(fp == NULL)
    {
        perror("fopen failed mode");
        return NULL;
    }
    else
    {
        printf("打开文件成功\n");
        printf("文件流指针：%p\n",fp);
        return fp;
    }
}
//关闭文件
int closefile(FILE *fp)
{
    //关闭文件 文件流指针负责关闭
    int ret=fclose(fp);
    if(ret == EOF)
    {
        perror("fclose failed\n");
        return -1;
    }
    else
    {
        printf("关闭文件流成功\n");
        return 0;
    }
}

