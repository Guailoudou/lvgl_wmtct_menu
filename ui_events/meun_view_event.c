#include "../UI/ui_events.h"
#include "../UI/ui.h"
#include "OrderDishesApi.h"
#include <stdio.h>
int pages = 1;
void initMeun(int pages)
{
    char buf[20] = {0};
    getMenuList(buf,pages,1);
    lv_label_set_text(ui_PagesInfo, buf);
    memset(buf, 0, sizeof(buf));
    if(menuData[0].uid != -1){
        lv_obj_clear_flag(ui_meunItem1,LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_meunimg1, menuData[0].imgPath);
        printf("图片地址：%s",menuData[0].imgPath);
        sprintf(buf, "%d", menuData[0].uid);
        lv_label_set_text(ui_meunUid1, buf);
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "%s $%d", menuData[0].name, menuData[0].peice);
        lv_label_set_text(ui_meuntext1, buf);
        memset(buf, 0, sizeof(buf));
    }else{
        lv_obj_add_flag(ui_meunItem1,LV_OBJ_FLAG_HIDDEN);
    }
    if(menuData[1].uid != -1){
        lv_obj_clear_flag(ui_meunItem2,LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_meunimg2, menuData[1].imgPath);
        sprintf(buf, "%d", menuData[1].uid);
        lv_label_set_text(ui_meunUid2, buf);
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "%s $%d", menuData[1].name, menuData[1].peice);
        lv_label_set_text(ui_meuntext2, buf);
        memset(buf, 0, sizeof(buf));
    }else{
        lv_obj_add_flag(ui_meunItem2,LV_OBJ_FLAG_HIDDEN);
    }
    if(menuData[2].uid != -1){
        lv_obj_clear_flag(ui_meunItem3,LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_meunimg3, menuData[2].imgPath);
        sprintf(buf, "%d", menuData[2].uid);
        lv_label_set_text(ui_meunUid3, buf);
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "%s $%d", menuData[2].name, menuData[2].peice);
        lv_label_set_text(ui_meuntext3, buf);
        memset(buf, 0, sizeof(buf));
    }else{
        lv_obj_add_flag(ui_meunItem3,LV_OBJ_FLAG_HIDDEN);
    }
    if(menuData[3].uid != -1){
        lv_obj_clear_flag(ui_meunItem4,LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_meunimg4, menuData[3].imgPath);
        sprintf(buf, "%d", menuData[3].uid);
        lv_label_set_text(ui_meunUid4, buf);
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "%s $%d", menuData[3].name, menuData[3].peice);
        lv_label_set_text(ui_meuntext4, buf);
        memset(buf, 0, sizeof(buf));
    }else{
        lv_obj_add_flag(ui_meunItem4,LV_OBJ_FLAG_HIDDEN);
    }
    if(menuData[4].uid != -1){
        lv_obj_clear_flag(ui_meunItem5,LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_meunimg5, menuData[4].imgPath);
        sprintf(buf, "%d", menuData[4].uid);
        lv_label_set_text(ui_meunUid5, buf);
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "%s $%d", menuData[4].name, menuData[4].peice);
        lv_label_set_text(ui_meuntext5, buf);
        memset(buf, 0, sizeof(buf));
    }else{
        lv_obj_add_flag(ui_meunItem5,LV_OBJ_FLAG_HIDDEN);
    }
    if(menuData[5].uid != -1){
        lv_obj_clear_flag(ui_meunItem6,LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_meunimg6, menuData[5].imgPath);
        sprintf(buf, "%d", menuData[5].uid);
        lv_label_set_text(ui_meunUid6, buf);
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "%s $%d", menuData[5].name, menuData[5].peice);
        lv_label_set_text(ui_meuntext6, buf);
        memset(buf, 0, sizeof(buf));
    }else{
        lv_obj_add_flag(ui_meunItem6,LV_OBJ_FLAG_HIDDEN);
    }
    if(menuData[6].uid != -1){
        lv_obj_clear_flag(ui_meunItem7,LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_meunimg7, menuData[6].imgPath);
        sprintf(buf, "%d", menuData[6].uid);
        lv_label_set_text(ui_meunUid7, buf);
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "%s $%d", menuData[6].name, menuData[6].peice);
        lv_label_set_text(ui_meuntext7, buf);
        memset(buf, 0, sizeof(buf));
    }else{
        lv_obj_add_flag(ui_meunItem7,LV_OBJ_FLAG_HIDDEN);
    }
    if(menuData[7].uid != -1){
        lv_obj_clear_flag(ui_meunItem8,LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_meunimg8, menuData[7].imgPath);
        sprintf(buf, "%d", menuData[7].uid);
        lv_label_set_text(ui_meunUid8, buf);
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "%s $%d", menuData[7].name, menuData[7].peice);
        lv_label_set_text(ui_meuntext8, buf);
        memset(buf, 0, sizeof(buf));
    }else{
        lv_obj_add_flag(ui_meunItem8,LV_OBJ_FLAG_HIDDEN);
    }
        

}

void viewNextPage(lv_event_t * e)
{
    printf("下一页\n");
    initMeun(++pages);
}
void viewLaftPage(lv_event_t * e)
{
    printf("上一页\n");
    initMeun(--pages);
}
void viewMenuInit(lv_event_t * e)
{
    printf("初始化\n");
    initMeun(pages);
}
void viewAddChopp(lv_event_t * e)
{
    printf("添加\n");
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    // 遍历 target 的所有子对象
    uint32_t child_cnt = lv_obj_get_child_cnt(target);
    for (uint32_t i = 0; i < child_cnt; i++) {
        lv_obj_t * child = lv_obj_get_child(target, i);
        // 检查该子对象是否是 label
        if (lv_obj_check_type(child, &lv_label_class)) {
            // 找到了 label！
            const char * uid_str = lv_label_get_text(child);
            printf("Label text: %s\n", uid_str);
            int uid = atoi(uid_str);
            addChoppBoard(uid,true);

            break; // 如果只需要第一个 label，可以 break
        }
    }
}