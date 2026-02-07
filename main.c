#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
// #include "mywin.h"
#define DISP_BUF_SIZE (600 * 1024)
// int bff = 1;
// // LV_FONT_DECLARE(hmosfont);
// static void event_cb(lv_event_t * e)
// {
//     lv_obj_t * obj = lv_event_get_current_target(e);
//     printf("Button %s clicked", lv_msgbox_get_active_btn_text(obj));
// }
// void lv_msgbox(void)
// {
//     static const char * btns[] = {"Apply", "Close", ""};

//     lv_obj_t * mbox1 = lv_msgbox_create(NULL, "警告", "伊蕾娜.notolookmao", btns, true);
//     // lv_obj_set_style_text_font(mbox1,LV_FONT_SIMSUN_16_CJK,LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(mbox1,&hmosfont,0);
//     lv_obj_add_event_cb(mbox1, event_cb, LV_EVENT_VALUE_CHANGED, NULL);
//     lv_obj_center(mbox1);
// }
// static void event_handler(lv_event_t * e)
// {
    
//     lv_event_code_t code = lv_event_get_code(e);
//     lv_obj_t *btn = lv_event_get_target(e);
//     lv_obj_t *label = lv_event_get_user_data(e);
//     if(code == LV_EVENT_CLICKED) {
//         LV_LOG_USER("Clicked");
//         lv_label_set_text(label,"可爱小猫");
//         lv_obj_set_x(btn,lv_obj_get_x(btn)+10);
//         printf("Clicked\n");
//     }
//     else if(code == LV_EVENT_VALUE_CHANGED) {
//         LV_LOG_USER("Toggled");
//         printf("Toggled\n");
//     }else if(code == LV_EVENT_LONG_PRESSED){
//         lv_obj_set_x(btn,lv_obj_get_x(btn)-40);
//         lv_msgbox();
//     }
// }
// static void event_reimg(lv_event_t * e) //更换图片事件
// {
//     lv_event_code_t code = lv_event_get_code(e);
//     lv_obj_t * obj = lv_event_get_current_target(e);
//     lv_obj_t * img = lv_event_get_user_data(e);
//     if(code==LV_EVENT_CLICKED)
//     if(bff){
//         lv_img_set_src(img, "F:/userdata/files/bfmao.png");
//         bff = 0;
//     }else{
//         lv_img_set_src(img, "F:/userdata/files/mao.png");
//         bff = 1;
//     }
    
// }
// void reimgbut(lv_obj_t *img) //生成换图按钮
// {
//     lv_obj_t *btn1 = lv_btn_create(lv_scr_act()); //传入父组件 lv_scr_act() 为屏幕
//     lv_obj_set_size(btn1,100,50); //大小
//     lv_obj_set_pos(btn1,740,310); //起始位置
     
//     lv_obj_t *label = lv_label_create(btn1);
//     lv_label_set_text(label, "芭菲");
//     lv_obj_center(label); //居中

//     lv_obj_add_event_cb(btn1,event_reimg,LV_EVENT_ALL, img);
// }
// void lvgl_img(void){
//     LV_IMG_DECLARE(ylnimg);
//     lv_obj_t *backimg = lv_img_create(lv_scr_act());
//     lv_obj_set_size(backimg,LV_SIZE_CONTENT,LV_SIZE_CONTENT);
//     // lv_img_set_zoom(img, 204);
//     lv_obj_set_pos(backimg,0,0);
//     // lv_img_set_angle(img, -900);
//     lv_img_set_size_mode(backimg, LV_IMG_SIZE_MODE_REAL);
//     lv_img_set_src(backimg, &ylnimg);

//     // lv_obj_t *maoimg = lv_img_create(lv_scr_act());
//     // lv_obj_set_size(maoimg,LV_SIZE_CONTENT,LV_SIZE_CONTENT);
//     // lv_obj_set_pos(maoimg,700,100);
//     // lv_img_set_src(maoimg, "F:/userdata/files/mao.png");
//     // reimgbut(maoimg);
// }
// static lv_style_t sty;

// void zdybtn(){
//     lv_style_init(&sty);
//     lv_style_set_bg_img_src(&sty,"F:/userdata/files/bfmao.png");
//     lv_style_set_bg_color(&sty, lv_color_hex(0x000000));
//     lv_style_set_bg_opa(&sty, LV_OPA_TRANSP);
//     lv_style_set_text_font(&sty,&hmosfont);
//     // lv_style_set_text_font(&sty,&lv_font_montserrat_40);
//     lv_style_set_text_color(&sty,lv_color_hex(0xc1231b));
// }
// void lvgl_btn_demo(void)
// {
//     lv_obj_t *btn1 = lv_btn_create(lv_scr_act()); //传入父组件 lv_scr_act() 为屏幕
//     lv_obj_set_size(btn1,360,160); //大小
//     lv_obj_set_pos(btn1,100,200); //起始位置
     
//     lv_obj_t *label = lv_label_create(btn1);
    
//     lv_obj_center(label); //居中

//     zdybtn();
//     lv_obj_add_style(btn1,&sty,LV_STATE_PRESSED);
//     lv_label_set_text(label, "伊蕾娜和可爱小猫\n请给小猫乐奈芭菲");
//     // lv_obj_set_style_text_font(label,&hmosfont,0);
//     lv_obj_set_style_text_color(label,lv_color_hex(0x000000),0);
//     lv_obj_add_event_cb(btn1,event_handler,LV_EVENT_ALL, label);

// }

int main(void)
{
    /*LittlevGL init*/
    lv_init();

    /*Linux frame buffer device init*/
    fbdev_init();

    /*A small buffer for LittlevGL to draw the screen's content*/
    static lv_color_t buf[DISP_BUF_SIZE];

    /*Initialize a descriptor for the buffer*/
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, DISP_BUF_SIZE);

    /*Initialize and register a display driver*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = fbdev_flush;
    disp_drv.hor_res    = 1024;
    disp_drv.ver_res    = 600;
    lv_disp_drv_register(&disp_drv);

    evdev_init();
    static lv_indev_drv_t indev_drv_1;
    lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
    indev_drv_1.type = LV_INDEV_TYPE_POINTER;

    /*This function will be called periodically (by the library) to get the mouse position and state*/
    indev_drv_1.read_cb = evdev_read;
    lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);


    /*Set a cursor for the mouse*/
    // LV_IMG_DECLARE(mouse_cursor_icon)
    // lv_obj_t * cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
    // lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
    // lv_indev_set_cursor(mouse_indev, cursor_obj);             /*Connect the image  object to the driver*/


    /*Create a Demo*/
    // lv_demo_widgets();
    // lv_obj_set_style_text_font(lv_scr_act(),&hmosfont,0);
    // show_main_win();
    // lvgl_img();
    // login_main_meun();
    ui_init();
    // lvgl_btn_demo();

    /*Handle LitlevGL tasks (tickless mode)*/
    while(1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}

/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
