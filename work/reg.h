#ifndef _REG_H
#define _REG_H

#include "head.h"
static void ta_event_cb(lv_event_t * e); //处理输入框点击事件
static void reg_kb(lv_event_t * e); //处理登录按钮点击事件
static void show_username_input(); //显示登录输入相关元件
static void show_password_input(); //显示密码输入相关元件
static void show_topassword_input(); //显示重复密码输入相关元件
static void show_title(); //显示标题
static void show_reg_button(); //显示注册按钮
void reg_main_meun(); //注册主窗口

#endif