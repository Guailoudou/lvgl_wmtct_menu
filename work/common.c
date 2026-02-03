#include "common.h"
lv_obj_t *kb;

static void kb_event_cb(lv_event_t * e){
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *kb = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        uint16_t btn_id = lv_btnmatrix_get_selected_btn(kb);
        const char * txt = lv_btnmatrix_get_btn_text(kb, btn_id);
        printf("按下按键: %s\n", txt);
    }
    else if(code == LV_EVENT_READY) {
        printf("输入完成\n");
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
    else if(code == LV_EVENT_CANCEL) {
        printf("输入取消\n");
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}
void create_kb(){
    kb = lv_keyboard_create(lv_scr_act());
    lv_obj_set_size(kb,  LV_HOR_RES, LV_VER_RES / 2);
    lv_obj_set_style_text_font(kb,&lv_font_montserrat_16,0);
    lv_obj_add_event_cb(kb,kb_event_cb,LV_EVENT_ALL, NULL);
}
void del_kb(){
    lv_obj_del(kb);
    kb == NULL;
}