#ifndef _ORDERDISHESAPI_H
#define _ORDERDISHESAPI_H
#include "Model.h"
#include <stdlib.h>
#include "common.h"
#ifdef DEBUG
#define USERINFOFILE "/home/loudou/file/yue/in/files/dishesInfo.txt"
#else
#define USERINFOFILE "/userdata/dishesInfo.txt"
#endif
extern Dlist dishesHead; //全部菜品数据
extern dishesItem menuData[8];
extern ChoppBoard board; //点菜板
extern int maxpages;
extern bool isEnd;

void getMenuList(int pages,int type);//写入menuData
dishesItem getDishesInfo(int uid); //获取菜品数据
bool rmChoppBoard(int dishesUid);
static Dlist create_head();
static Dlist create_node(DishesData data);
static DishesData create_data(int uid,char imgPath[],char name[],int peice,int type);
static int getListLen(Dlist head); //获取长度
static int getMaxUid(Dlist head);   //  获取目前的uid最大值

#endif