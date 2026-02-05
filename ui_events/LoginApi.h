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


int loginMenu(const char *iuser,const char *ipass);//登录api
bool regMenu(const char *iuser,const char *ipass);//注册api
bool setUserType(int uid,int type);
userInfo getUserInfo(int uid);
bool outLogin(); //退出登录
bool delUser(int uid); //删除

#endif