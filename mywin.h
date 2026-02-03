#ifndef _MYWIN_H
#define _MYWIN_H

#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>

#define DISP_BUF_SIZE (600 * 1024)
LV_FONT_DECLARE(hmosfont)//确定字库对象
//实例化全局变量界面对象
static lv_obj_t *main_win=NULL;//主界面
static lv_obj_t *user1_win=NULL;//功能子界面1
static lv_obj_t *user2_win=NULL;//功能子界面2

//显示页面
void show_main_win(void);
void show_user1_win(void);
void show_user2_win(void);
//事件
void user1_event(lv_event_t *e);
void user2_event(lv_event_t *e);
void main_event1(lv_event_t *e);
void main_event2(lv_event_t *e);

#endif