#include "loginapi.h"
userdata *user_data = NULL;
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

static userdata *readtxt(){
    FILE *fp = openfile("/userdata/password.txt","r");
    userdata *users = malloc(sizeof(users));
    users->len = 0;
    char buf[30] = {0};
    int i = 0;
    if(fp!=NULL){
        while(fgets(buf,sizeof(buf),fp) != NULL){
            char name[32] = {0};
            char passwd[32] = {0};
            sscanf(buf,"%s %s",name,passwd);
            strcpy(users->user[i].name,name);
            strcpy(users->user[i++].passwd,passwd);
            users->len++;
            memset(buf,0,sizeof(buf));
        }
        closefile(fp);
        
    }
    return users;
}
void display(userdata *users){
    for (int i = 0; i < users->len; i++)
    {
        printf("账号：%s\t密码：%s\n",users->user[i].name,users->user[i].passwd);
    }
}
static void writetxt(){
    userdata *users  = user_data;
    FILE *fp = openfile("/userdata/password.txt","w+");
    char buf[100] = {0};
    char out[1024] = {0};
    display(users);
    for (int i = 0; i < users->len; i++)
    {
        
        sprintf(buf,"%s %s\n",users->user[i].name,users->user[i].passwd);
        strcat(out,buf);
        memset(buf,0,sizeof(buf));
    }
    printf("out=%s\n",out);
    fprintf(fp,"%s",out);
    closefile(fp);
}
static bool check_username(const char *iuser){
    if(user_data==NULL)
        user_data = readtxt();
    for (int i = 0; i < user_data->len; i++){
        char *user = user_data->user[i].name;
        if(strcmp(user,iuser)==0){
            return false;
        }
    }
    return true;
}
bool checkloginAPI(const char *iuser,const char *ipass){
    if(user_data==NULL)
        user_data = readtxt();
    for (int i = 0; i < user_data->len; i++){
        char *user = user_data->user[i].name;
        char *pass = user_data->user[i].passwd;
        printf("校验读取：%s %s\n",user,pass);
        if(strcmp(user,iuser)==0 && strcmp(pass,ipass)==0){
            return true;
        }
    }
    return false;
}

bool regAPI(const char *iuser,const char *ipass){
    if(!check_username(iuser)){
        return false;
    }
    if(user_data==NULL)
        user_data = readtxt();
    int len = user_data->len;
    printf("注册传入:%s %s\n",iuser,ipass);
    strcpy(user_data->user[len].name,iuser);
    strcpy(user_data->user[len].passwd,ipass);
    user_data->len++;
    display(user_data);
    writetxt();
    return true;
}
