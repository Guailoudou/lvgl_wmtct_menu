#ifndef _ORDERDISHESAPI_H
#define _ORDERDISHESAPI_H
#include "Model.h"
#include <stdlib.h>
#include "common.h"
#ifdef DEBUG
#define USERINFOFILE "/home/loudou/file/yue/in/files/dishesInfo.txt"
#else
#define USERINFOFILE "/userdata/files/dishesInfo.txt"
#endif
extern Dlist dishesHead; //全部菜品数据
extern dishesItem menuData[8];
extern ChoppBoard board; //点菜板
extern int inventoryBoard[]; //库存板
extern int maxpages;
extern bool isEnd;

char *getMenuList(char pagestr[],int pages,int type);//写入menuData
dishesItem getDishesInfo(int uid); //获取菜品数据
bool rmChoppBoard(int dishesUid);   //删除
bool addChoppBoard(int dishesUid,bool isplus); //添加到菜单
bool checkout();    //结账 清除库存
bool replenishment();  //补货 添加库存


#endif