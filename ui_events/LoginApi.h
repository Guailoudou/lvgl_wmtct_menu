#ifndef _LOGINAPI_H
#define _LGOINAPI_H

#include "common.h"
#include "Model.h"

extern Ulist userhead;
extern userInfo loginUser;

#ifdef DEBUG
#define USERINFOFILE "/home/loudou/file/yue/in/files/userInfo.txt"
#else
#define USERINFOFILE "/userdata/files/userInfo.txt"
#endif

static void readtxt();//读取数据
static void writetxt(); //写入数据
static bool check_username(const char *iuser);//检查用户名是否重复
int loginMenu(const char *iuser,const char *ipass);//登录api
bool regMenu(const char *iuser,const char *ipass);//注册api
bool setUserType(int uid,int type);
userInfo getUserInfo(int uid);
bool outLogin(); //退出登录




////////////////////////////链表操作//////////////////////////
static Ulist create_head();
static Ulist create_node(UserData data);
static UserData create_data(int uid,const char name[],const char password[],int type);
static int getListLen(Ulist head); //获取长度
static int getMaxUid(Ulist head);   //  获取目前的uid最大值


#endif