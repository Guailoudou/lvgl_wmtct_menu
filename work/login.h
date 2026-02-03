#ifndef _LOGIN_H
#define _LOGIN_H

#include "head.h"

static void ta_event_cb(lv_event_t * e); //处理输入框点击事件
static void login_kb(lv_event_t * e); //处理登录按钮点击事件
static void reg_kb(lv_event_t * e); //处理注册页面跳转
static void show_username_input(); //显示登录输入相关元件
static void show_password_input(); //显示密码输入相关元件
static void show_title(); //显示标题
static void show_login_button(); //显示登录按钮
static void show_reg_button(); //显示登录按钮
void login_main_meun(); //登录主窗口
#endif