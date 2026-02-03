#ifndef _COMMON_H
#define _COMMON_H

#include "../lvgl/lvgl.h"
#include "../lvgl/demos/lv_demos.h"
#include "../lv_drivers/display/fbdev.h"
#include "../lv_drivers/indev/evdev.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>

typedef struct user
{
    char name[20];
    char passwd[20];
}user;
typedef struct users
{
    user user[20];
    int len;
}userdata;

LV_FONT_DECLARE(hmosfont)

void create_kb(); //生成输入
void del_kb(); //删除输入
#endif