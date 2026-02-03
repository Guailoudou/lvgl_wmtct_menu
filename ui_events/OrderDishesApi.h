#ifndef _ORDERDISHESAPI_H
#define _ORDERDISHESAPI_H
#include "Model.h"
#include <stdlib.h>
#include "common.h"

#define USERINFOFILE "/userdata/dishesInfo.txt"
Dlist dishesHead = NULL; //全部菜品数据
dishesItem menuData[8]={0};
int maxpages = 0;
bool isEnd = false;

dishesItem getDishesInfo(int uid); //获取菜品数据

static Dlist create_head();
static Dlist create_node(DishesData data);
static DishesData create_data(int uid,char imgPath[],char name[],int peice,int type);
static int getListLen(Dlist head); //获取长度
static int getMaxUid(Dlist head);   //  获取目前的uid最大值

#endif