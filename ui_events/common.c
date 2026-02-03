#include "common.h"

//打开文件
static FILE *openfile(const char *path,char *mode)
{
    //打开文件 获取文件流指针
    FILE *fp=fopen(path,mode);
    if(fp == NULL)
    {
        perror("fopen failed\n");
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
static int closefile(FILE *fp)
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
