#include "login.h"

static lv_obj_t *superior;
static lv_obj_t *username_in;
static lv_obj_t *password_in;
extern lv_obj_t *kb;
static void ta_event_cb(lv_event_t * e)
{
    
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED || code == LV_EVENT_FOCUSED) {
        /*Focus on the clicked text area*/
        if(kb==NULL)create_kb();
        lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_obj_move_foreground(kb);
        if(kb != NULL) lv_keyboard_set_textarea(kb, ta);
        
        // printf("%s\n",lv_btnmatrix_get_btn_text(kb,lv_btnmatrix_get_selected_btn(kb)));
    }

    else if(code == LV_EVENT_READY) {
        LV_LOG_USER("Ready, current text: %s", lv_textarea_get_text(ta));
    }
}
static void reg_kb(lv_event_t * e){
    lv_event_code_t code = lv_event_get_code(e);
    if(code==LV_EVENT_CLICKED){
        lv_obj_add_flag(superior, LV_OBJ_FLAG_HIDDEN);
        reg_main_meun();
    }
    
}
static void login_kb(lv_event_t * e){
    lv_event_code_t code = lv_event_get_code(e);
    // lv_obj_t *kb = lv_event_get_target(e);
    if(code==LV_EVENT_CLICKED){
        const char *user = lv_textarea_get_text(username_in);
        const char *pass = lv_textarea_get_text(password_in);
        if(strcmp(user,"")==0||strcmp(pass,"")==0){
            lv_obj_t * mbox1 = lv_msgbox_create(NULL, "提示", "账号或密码为空", NULL, true);
            lv_obj_set_style_text_font(mbox1,&hmosfont,0);
            lv_obj_center(mbox1);
            return;
        }
        if(checkloginAPI(user,pass)){
            printf("登录成功！");
            lv_obj_t * mbox1 = lv_msgbox_create(NULL, "提示", "登录成功！", NULL, true);
            lv_obj_set_style_text_font(mbox1,&hmosfont,0);
            lv_obj_center(mbox1);
            lv_obj_add_flag(superior, LV_OBJ_FLAG_HIDDEN);

        }else{
            printf("登录失败！");
            lv_obj_t * mbox1 = lv_msgbox_create(NULL, "提示", "登录失败！", NULL, true);
            lv_obj_set_style_text_font(mbox1,&hmosfont,0);
            lv_obj_center(mbox1);
        }
    }
}

static void show_username_input(){
    username_in = lv_textarea_create(superior);
    lv_obj_center(username_in);
    lv_textarea_set_text(username_in, "");
    lv_textarea_set_password_mode(username_in, false);
    lv_textarea_set_one_line(username_in, true);
    lv_obj_set_width(username_in, lv_pct(40));
    lv_obj_set_pos(username_in, 0, -100);
    lv_obj_add_event_cb(username_in, ta_event_cb, LV_EVENT_ALL, NULL);

    lv_obj_t * oneline_label = lv_label_create(superior);
    lv_label_set_text(oneline_label, "用户名");
    lv_obj_align_to(oneline_label, username_in, LV_ALIGN_OUT_TOP_LEFT, 0, 0);
}

static void show_password_input(){
    password_in = lv_textarea_create(superior);
    lv_obj_center(password_in);
    lv_textarea_set_text(password_in, "");
    lv_textarea_set_password_mode(password_in, true);
    lv_textarea_set_one_line(password_in, true);
    lv_obj_set_width(password_in, lv_pct(40));
    lv_obj_set_pos(password_in, 0, 0);
    lv_obj_add_event_cb(password_in, ta_event_cb, LV_EVENT_ALL, NULL);

    lv_obj_t * oneline_label = lv_label_create(superior);
    lv_label_set_text(oneline_label, "密码");
    lv_obj_align_to(oneline_label, password_in, LV_ALIGN_OUT_TOP_LEFT, 0, 0);
}
static void show_title(){
    lv_obj_t *title = lv_label_create(superior);
    lv_label_set_text(title, "LOGIN");
    lv_obj_set_style_text_font(title,&lv_font_montserrat_40,0);
    lv_obj_set_style_text_color(title,lv_color_hex(0x1f74cf),0);
    lv_obj_center(title);
    lv_obj_set_pos(title, 0, -170);
    // lv_obj_set_size(title,400,200);
}
static void show_login_button(){
    lv_obj_t *btn = lv_btn_create(superior);
    lv_obj_center(btn);
    lv_obj_t * label = lv_label_create(btn);
    lv_label_set_text(label, "登录");
    lv_obj_center(label);
    lv_obj_set_pos(btn,0,80);
    lv_obj_add_event_cb(btn,login_kb,LV_EVENT_ALL, NULL);

}

static void show_reg_button(){
    lv_obj_t *btn = lv_btn_create(superior);
    lv_obj_center(btn);
    lv_obj_t * label = lv_label_create(btn);
    lv_label_set_text(label, "注册");
    lv_obj_center(label);
    lv_obj_set_pos(btn,0,140);
    lv_obj_add_event_cb(btn,reg_kb,LV_EVENT_ALL, NULL);
}
void login_main_meun(){
    if(superior!=NULL){
        lv_obj_clear_flag(superior, LV_OBJ_FLAG_HIDDEN);
        return;
    }

    superior = lv_obj_create(lv_scr_act());
    lv_obj_set_size(superior,800,500);
    lv_obj_set_style_bg_opa(superior,LV_OPA_40,0);
    lv_obj_center(superior);
    show_username_input();
    show_password_input();
    show_title();
    show_login_button();
    show_reg_button();
    // create_kb();
}