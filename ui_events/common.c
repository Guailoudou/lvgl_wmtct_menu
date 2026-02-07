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
    logprint("path=%s mode=%s\n",path,mode);
    FILE *fp=fopen(path,mode);
    if(fp == NULL)
    {
        perror("fopen failed mode");
        return NULL;
    }
    else
    {
        logprint("打开文件成功\n");
        logprint("文件流指针：%p\n",fp);
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
        logprint("关闭文件流成功\n");
        return 0;
    }
}
//自定义日志
void logprint(char *str, ...) {
    time_t now;
    struct tm *time_now;
    va_list args;  // 可变参数列表
    
    time(&now);
    time_now = localtime(&now);

    // 开始处理可变参数
    va_start(args, str);
    
    // 先打印时间戳
    printf("[system:%d:%d:%d] ", 
           time_now->tm_hour, 
           time_now->tm_min, 
           time_now->tm_sec);
    
    // 处理格式化字符串
    vprintf(str, args);  // 使用vprintf处理可变参数
    printf("\n");
    
    // 结束可变参数处理
    va_end(args);
    
    return;
}