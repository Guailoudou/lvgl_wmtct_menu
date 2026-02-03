#include "mywin.h"

//界面1事件
void user1_event(lv_event_t *e)
{
    //获取事件编码
    lv_event_code_t code=lv_event_get_code(e);
    //判断操作为单击
    if(code == LV_EVENT_CLICKED)
    {
        //隐藏main_win
        lv_obj_add_flag(main_win,LV_OBJ_FLAG_HIDDEN);
        //显示界面1
        show_user1_win();
    }
}

//界面2事件
void user2_event(lv_event_t *e)
{
     //获取事件编码
    lv_event_code_t code=lv_event_get_code(e);
    //判断操作为单击
    if(code == LV_EVENT_CLICKED)
    {
        //隐藏main_win
        lv_obj_add_flag(main_win,LV_OBJ_FLAG_HIDDEN);
        //显示界面2
        show_user2_win();
    }
}

//主界面
void show_main_win(void)
{
    //将主界面显示定位到屏幕
    main_win =lv_obj_create(lv_scr_act());
    //设置主界面大小
    lv_obj_set_size(main_win,1024,600);
    //在主界面实例化两个按钮
    lv_obj_t *btn1=lv_btn_create(main_win);//显示按钮到屏幕
    lv_obj_set_size(btn1,200,200);//按钮尺寸
    lv_obj_set_pos(btn1,100,100);//按钮显示起点
    lv_obj_set_style_bg_img_src(btn1,"F:/userdata/files/user1.png",0);//设置按钮背景图

    lv_obj_t *btn2=lv_btn_create(main_win);//显示按钮到屏幕
    lv_obj_set_size(btn2,200,200);//按钮尺寸
    lv_obj_set_pos(btn2,400,100);//按钮显示起点
    lv_obj_set_style_bg_img_src(btn2,"F:/userdata/files/user2.png",0);//设置按钮背景图
    
    //给按钮添加事件
    lv_obj_add_event_cb(btn1,user1_event,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(btn2,user2_event,LV_EVENT_CLICKED,NULL);
}

//主界面返回事件
void main_event1(lv_event_t *e)
{
    //获取事件编码
    lv_event_code_t code=lv_event_get_code(e);
    //判断操作为单击
    if(code == LV_EVENT_CLICKED)
    {
        //删除界面1
        lv_obj_del(user1_win);
        //清除隐藏main_win
        lv_obj_clear_flag(main_win,LV_OBJ_FLAG_HIDDEN);
        //显示界面
        show_main_win();
    }
}


void show_user1_win(void)
{
    //将主界面显示定位到屏幕
    user1_win =lv_obj_create(lv_scr_act());
    //设置主界面大小
    lv_obj_set_size(user1_win,1024,600);
    //在主界面实例化两个按钮
    lv_obj_t *btn1=lv_btn_create(user1_win);//显示按钮到屏幕
    lv_obj_set_size(btn1,200,200);//按钮尺寸
    lv_obj_set_pos(btn1,100,100);//按钮显示起点
    lv_obj_t *label=lv_label_create(btn1);
    lv_label_set_text(label,"返回");
    lv_obj_set_style_text_font(label,&hmosfont,0);//设置字体样式
    lv_obj_center(label);
    //给按钮添加事件
    lv_obj_add_event_cb(btn1,main_event1,LV_EVENT_CLICKED,NULL);
}

//主界面返回事件
void main_event2(lv_event_t *e)
{
    //获取事件编码
    lv_event_code_t code=lv_event_get_code(e);
    //判断操作为单击
    if(code == LV_EVENT_CLICKED)
    {
        //删除界面2
        lv_obj_del(user2_win);
        //清除隐藏main_win
        lv_obj_clear_flag(main_win,LV_OBJ_FLAG_HIDDEN);
        //显示界面
        show_main_win();
    }
}
void show_user2_win(void)
{
    //将主界面显示定位到屏幕
    user2_win =lv_obj_create(lv_scr_act());
    //设置主界面大小
    lv_obj_set_size(user2_win,1024,600);
    //在主界面实例化两个按钮
    lv_obj_t *btn1=lv_btn_create(user2_win);//显示按钮到屏幕
    lv_obj_set_size(btn1,200,200);//按钮尺寸
    lv_obj_set_pos(btn1,100,100);//按钮显示起点
    lv_obj_t *label=lv_label_create(btn1);
    lv_label_set_text(label,"返回");
    lv_obj_set_style_text_font(label,&hmosfont,0);//设置字体样式
    lv_obj_center(label);
    //给按钮添加事件
    lv_obj_add_event_cb(btn1,main_event2,LV_EVENT_CLICKED,NULL);
}