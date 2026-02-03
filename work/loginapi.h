#ifndef _LOGINAPI_H
#define _LGOINAPI_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"
//打开文件
static FILE *openfile(const char *path,char *mode);
//关闭文件
static int closefile(FILE *fp);
static userdata *readtxt();//读取数据
static void writetxt(); //写入数据
static bool check_username(const char *iuser);//检查用户名是否重复
bool checkloginAPI(const char *iuser,const char *ipass);//登录api
bool regAPI(const char *iuser,const char *ipass);//注册api


#endif