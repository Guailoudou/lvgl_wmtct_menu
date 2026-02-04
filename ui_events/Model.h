#ifndef _MODEL_H
#define _MODEL_H

#define STRLEN 1024
#define USERSTR 24
#include <stdbool.h>
#include "dlist.h"
typedef struct ChoppItem //点菜板单品
{
    int dishesUids; //菜品uid
    int num;    //数量
    
}ChoppItem;

typedef struct ChoppBoard //点菜板
{
    ChoppItem dishesUids[STRLEN]; //菜品uid表
    int len; //种类数量
}ChoppBoard;

typedef struct dishesItem   //单个菜
{
    int uid;    //菜品唯一标识
    char imgPath[STRLEN];   //图片路径  png图片
    char name[STRLEN];  //菜品名称
    int peice;  //菜品价格
    int type;   //类型  权限等级>=菜品等级，则允许返回
}dishesItem;


typedef struct userInfo//账号信息
{
    int uid;    //  用户uid
    char name[USERSTR]; //用户名
    char password[USERSTR]; //密码
    int type;   //权限等级
}userInfo;

//用户数据表数据
typedef struct UserData
{
    userInfo data;
}UserData;
//用户数据双向循环链表
typedef struct UserList
{
    struct UserData data;//数据域
    struct list_head my;//指针域 前驱和后继
}*Ulist;//NODE结构体指针类型

//总菜单结构
typedef struct DishesData
{
    dishesItem data;
}DishesData;
//双向循环链表节点管理
typedef struct DishesList
{
    struct DishesData data;//数据域
    struct list_head my;//指针域 前驱和后继
}*Dlist;
// dishesItem dishesList[STRLEN];  //总菜品列表
// userInfo userList[STRLEN];  //用户列表
#endif