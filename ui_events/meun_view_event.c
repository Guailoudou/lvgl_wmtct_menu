#include "../UI/ui_events.h"
#include "../UI/ui.h"
#include "OrderDishesApi.h"
#include <stdio.h>
int pages = 1;
int coinNum = 0;
int Sum = 0;
extern userInfo loginUser;
void viewClearChopp(lv_event_t * e);
void viewAddChopp(lv_event_t * e);
void checkoutChopp(lv_event_t * e);
void replenishmentChopp(lv_event_t * e);
void forDillItem();
//生成菜单元件
void initMeun(int tpages)
{
    char buf[30] = {0};
    sprintf(buf,"< 退出登录 当前用户: %s",loginUser.name);
    lv_label_set_text(ui_OutLoginText, buf);
    memset(buf, 0, sizeof(buf));
    printf("权限等级: %d\n",loginUser.type);
    getMenuList(buf,tpages,loginUser.type);
    lv_label_set_text(ui_PagesInfo, buf);
    sscanf(buf,"%d",&pages);
    printf("外部页:%d\n",pages);
    memset(buf, 0, sizeof(buf));

    if(menuData[0].uid != -1){
        lv_obj_clear_flag(ui_meunItem1,LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_meunimg1, menuData[0].imgPath);
        printf("图片地址：%s\n",menuData[0].imgPath);
        sprintf(buf, "%d", menuData[0].uid);
        lv_label_set_text(ui_meunUid1, buf);
        memset(buf, 0, sizeof(buf));
        if(loginUser.type<=1)
            sprintf(buf, "%s ￥%d", menuData[0].name, menuData[0].peice);
        else
            sprintf(buf, "%s 库存：%d", menuData[0].name, inventoryBoard[menuData[0].uid]);
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
        if(loginUser.type<=1)
            sprintf(buf, "%s ￥%d", menuData[1].name, menuData[1].peice);
        else
            sprintf(buf, "%s 库存：%d", menuData[1].name, inventoryBoard[menuData[1].uid]);
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
        if(loginUser.type<=1)
            sprintf(buf, "%s ￥%d", menuData[2].name, menuData[2].peice);
        else
            sprintf(buf, "%s 库存：%d", menuData[2].name, inventoryBoard[menuData[2].uid]);
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
        if(loginUser.type<=1)
            sprintf(buf, "%s ￥%d", menuData[3].name, menuData[3].peice);
        else
            sprintf(buf, "%s 库存：%d", menuData[3].name, inventoryBoard[menuData[3].uid]);
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
        if(loginUser.type<=1)
            sprintf(buf, "%s ￥%d", menuData[4].name, menuData[4].peice);
        else
            sprintf(buf, "%s 库存：%d", menuData[4].name, inventoryBoard[menuData[4].uid]);
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
        if(loginUser.type<=1)
            sprintf(buf, "%s ￥%d", menuData[5].name, menuData[5].peice);
        else
            sprintf(buf, "%s 库存：%d", menuData[5].name, inventoryBoard[menuData[5].uid]);
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
        if(loginUser.type<=1)
            sprintf(buf, "%s ￥%d", menuData[6].name, menuData[6].peice);
        else
            sprintf(buf, "%s 库存：%d", menuData[6].name, inventoryBoard[menuData[6].uid]);
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
        if(loginUser.type<=1)
            sprintf(buf, "%s ￥%d", menuData[7].name, menuData[7].peice);
        else
            sprintf(buf, "%s 库存：%d", menuData[7].name, inventoryBoard[menuData[7].uid]);
        lv_label_set_text(ui_meuntext8, buf);
        memset(buf, 0, sizeof(buf));
    }else{
        lv_obj_add_flag(ui_meunItem8,LV_OBJ_FLAG_HIDDEN);
    }
    lv_obj_set_style_img_recolor(ui_meunimg1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_meunimg2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_meunimg3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_meunimg4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_meunimg5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_meunimg6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_meunimg7, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_meunimg8, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    if(inventoryBoard[menuData[0].uid]==0){
        lv_obj_set_style_img_recolor_opa(ui_meunimg1, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    }else{
        lv_obj_set_style_img_recolor_opa(ui_meunimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if(inventoryBoard[menuData[1].uid]==0){
        lv_obj_set_style_img_recolor_opa(ui_meunimg2, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    }else{
        lv_obj_set_style_img_recolor_opa(ui_meunimg2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if(inventoryBoard[menuData[2].uid]==0){
        lv_obj_set_style_img_recolor_opa(ui_meunimg3, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    }else{
        lv_obj_set_style_img_recolor_opa(ui_meunimg3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if(inventoryBoard[menuData[3].uid]==0){
        lv_obj_set_style_img_recolor_opa(ui_meunimg4, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    }else{
        lv_obj_set_style_img_recolor_opa(ui_meunimg4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if(inventoryBoard[menuData[4].uid]==0){
        lv_obj_set_style_img_recolor_opa(ui_meunimg5, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    }else{
        lv_obj_set_style_img_recolor_opa(ui_meunimg5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if(inventoryBoard[menuData[5].uid]==0){
        lv_obj_set_style_img_recolor_opa(ui_meunimg6, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    }else{
        lv_obj_set_style_img_recolor_opa(ui_meunimg6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if(inventoryBoard[menuData[6].uid]==0){
        lv_obj_set_style_img_recolor_opa(ui_meunimg7, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    }else{
        lv_obj_set_style_img_recolor_opa(ui_meunimg7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if(inventoryBoard[menuData[7].uid]==0){
        lv_obj_set_style_img_recolor_opa(ui_meunimg8, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    }else{
        lv_obj_set_style_img_recolor_opa(ui_meunimg8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }

}
//创建结算元件
void createCoinMunItem(int num)
{
    lv_obj_t *temp_Container2 = lv_obj_create(ui_Bill);
    lv_obj_remove_style_all(temp_Container2);
    lv_obj_set_width(temp_Container2, 327);
    lv_obj_set_height(temp_Container2, 54);
    lv_obj_set_align(temp_Container2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(temp_Container2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(temp_Container2, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(temp_Container2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_move_to_index(temp_Container2, 0);

    lv_obj_t *temp_Container7 = lv_obj_create(temp_Container2);
    lv_obj_remove_style_all(temp_Container7);
    lv_obj_set_width(temp_Container7, 208);
    lv_obj_set_height(temp_Container7, 50);
    lv_obj_set_align(temp_Container7, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(temp_Container7, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(temp_Container7, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(temp_Container7, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t *temp_coinText = lv_label_create(temp_Container7);
    lv_obj_set_width(temp_coinText, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(temp_coinText, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(temp_coinText, LV_ALIGN_CENTER);
    if(loginUser.type<=1)
        lv_label_set_text(temp_coinText, "总金额: ￥");
    else
        lv_label_set_text(temp_coinText, "总补货数: ");
    lv_obj_set_style_text_font(temp_coinText, &ui_font_harmonyOS, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *temp_coinMun = lv_label_create(temp_Container7);
    lv_obj_set_width(temp_coinMun, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(temp_coinMun, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(temp_coinMun, LV_ALIGN_CENTER);
    char buf[20] = {0};
    sprintf(buf,"%d",num);
    lv_label_set_text(temp_coinMun, buf);
    lv_obj_set_style_text_align(temp_coinMun, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(temp_coinMun, &ui_font_harmonyOS, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    

    lv_obj_t *temp_coinBtn = lv_btn_create(temp_Container2);
    lv_obj_set_width(temp_coinBtn, 100);
    lv_obj_set_height(temp_coinBtn, 50);
    lv_obj_set_align(temp_coinBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(temp_coinBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(temp_coinBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    if(loginUser.type<=1)
        lv_obj_add_event_cb(temp_coinBtn,checkoutChopp,LV_EVENT_ALL, NULL);
    else
        lv_obj_add_event_cb(temp_coinBtn,replenishmentChopp,LV_EVENT_ALL, NULL);

    lv_obj_t *temp_coinBtnText = lv_label_create(temp_coinBtn);
    lv_obj_set_width(temp_coinBtnText, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(temp_coinBtnText, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(temp_coinBtnText, LV_ALIGN_CENTER);
    if(loginUser.type<=1)
        lv_label_set_text(temp_coinBtnText, "结算");
    else
        lv_label_set_text(temp_coinBtnText, "补货");
    lv_obj_set_style_text_font(temp_coinBtnText, &ui_font_harmonyOS, LV_PART_MAIN | LV_STATE_DEFAULT);
}
//创建账单元件
void createBillItem(char *name,int num,int uid)
{
    char buf[10] = {0};
    lv_obj_t *temp_Container = lv_obj_create(ui_Bill);
    lv_obj_remove_style_all(temp_Container);
    lv_obj_set_width(temp_Container, 327);
    lv_obj_set_height(temp_Container, 54);
    lv_obj_set_align(temp_Container, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(temp_Container, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(temp_Container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(temp_Container, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t *temp_Container4 = lv_obj_create(temp_Container);
    lv_obj_remove_style_all(temp_Container4);
    lv_obj_set_width(temp_Container4, 208);
    lv_obj_set_height(temp_Container4, 50);
    lv_obj_set_align(temp_Container4, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(temp_Container4, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(temp_Container4, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(temp_Container4, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t *temp_BillItemName = lv_label_create(temp_Container4);
    lv_obj_set_width(temp_BillItemName, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(temp_BillItemName, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(temp_BillItemName, LV_ALIGN_CENTER);
    lv_label_set_text(temp_BillItemName, name); //名字
    lv_obj_set_style_text_align(temp_BillItemName, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(temp_BillItemName, &ui_font_harmonyOS, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *temp_Container5 = lv_obj_create(temp_Container);
    lv_obj_remove_style_all(temp_Container5);
    lv_obj_set_width(temp_Container5, 121);
    lv_obj_set_height(temp_Container5, 50);
    lv_obj_set_align(temp_Container5, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(temp_Container5, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(temp_Container5, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(temp_Container5, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t *temp_BillItemClear = lv_btn_create(temp_Container5);  //减少按钮
    lv_obj_set_width(temp_BillItemClear, 40);
    lv_obj_set_height(temp_BillItemClear, 40);
    lv_obj_set_align(temp_BillItemClear, LV_ALIGN_CENTER);
    lv_obj_add_flag(temp_BillItemClear, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(temp_BillItemClear, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t *temp_BillItemUid11 = lv_label_create(temp_BillItemClear);
    lv_obj_set_width(temp_BillItemUid11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(temp_BillItemUid11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(temp_BillItemUid11, LV_ALIGN_CENTER);
    sprintf(buf,"%d",uid);
    lv_label_set_text(temp_BillItemUid11, buf);     // uid
    memset(buf, 0, sizeof(buf));
    lv_obj_add_flag(temp_BillItemUid11, LV_OBJ_FLAG_HIDDEN);     /// Flags

    lv_obj_t *temp_BillItemClearLabel = lv_label_create(temp_BillItemClear);
    lv_obj_set_width(temp_BillItemClearLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(temp_BillItemClearLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(temp_BillItemClearLabel, LV_ALIGN_CENTER);
    lv_label_set_text(temp_BillItemClearLabel, "-");

    lv_obj_t *temp_BillItemNum = lv_label_create(temp_Container5);
    lv_obj_set_width(temp_BillItemNum, 25);
    lv_obj_set_height(temp_BillItemNum, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(temp_BillItemNum, LV_ALIGN_CENTER);
    sprintf(buf,"%d",num);
    lv_label_set_text(temp_BillItemNum, buf);   //数量
    memset(buf, 0, sizeof(buf));
    lv_obj_set_style_text_align(temp_BillItemNum, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *temp_BillItemAdd = lv_btn_create(temp_Container5);    //添加按钮
    lv_obj_set_width(temp_BillItemAdd, 40);
    lv_obj_set_height(temp_BillItemAdd, 40);
    lv_obj_set_align(temp_BillItemAdd, LV_ALIGN_CENTER);
    lv_obj_add_flag(temp_BillItemAdd, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(temp_BillItemAdd, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t *temp_BillItemUid12 = lv_label_create(temp_BillItemAdd);
    lv_obj_set_width(temp_BillItemUid12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(temp_BillItemUid12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(temp_BillItemUid12, LV_ALIGN_CENTER);
    sprintf(buf,"%d",uid);
    lv_label_set_text(temp_BillItemUid12, buf);
    memset(buf, 0, sizeof(buf));
    lv_obj_add_flag(temp_BillItemUid12, LV_OBJ_FLAG_HIDDEN);     /// Flags

    lv_obj_t *temp_BillItemAddLabel = lv_label_create(temp_BillItemAdd);
    lv_obj_set_width(temp_BillItemAddLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(temp_BillItemAddLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(temp_BillItemAddLabel, LV_ALIGN_CENTER);
    lv_label_set_text(temp_BillItemAddLabel, "+");

    lv_obj_add_event_cb(temp_BillItemAdd,viewAddChopp,LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(temp_BillItemClear,viewClearChopp,LV_EVENT_ALL, NULL);
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
//页面初始化
void viewMenuInit(lv_event_t * e)
{
    printf("初始化\n");
    pages = 1;
    board.len = 0;
    coinNum = 0;
    
    forDillItem();
    initMeun(pages);
    if(loginUser.type<=1)
        lv_obj_add_flag(ui_OpenAdminBtn,LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_clear_flag(ui_OpenAdminBtn,LV_OBJ_FLAG_HIDDEN);
    _ui_basic_set_property(ui_Bill, _UI_BASIC_PROPERTY_POSITION_Y,  460);
}
void forDillItem(){  //渲染菜版返回总金额
    int len = board.len;
    coinNum = 0;
    Sum = 0;
    lv_obj_clean(ui_Bill);
    for(int i=0;i<len;i++){
        int uid = board.dishesUids[i].dishesUids;
        int num = board.dishesUids[i].num;
        Sum += num;
        dishesItem data = getDishesInfo(uid);
        coinNum += data.peice * num;
        createBillItem(data.name,num,uid);
    }
    if(loginUser.type<=1)
        createCoinMunItem(coinNum);
    else
        createCoinMunItem(Sum);
    printf("当前总金额：%d 总数量%d\n",coinNum,Sum);
    return;
}
void viewAddChopp(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code != LV_EVENT_CLICKED)return;
    printf("添加\n");
    // 遍历 target 的所有子对象
    uint32_t child_cnt = lv_obj_get_child_cnt(target);
    for (uint32_t i = 0; i < child_cnt; i++) {
        lv_obj_t * child = lv_obj_get_child(target, i);
        // 检查该子对象是否是 label
        if (lv_obj_check_type(child, &lv_label_class)) {
            // 找到了 label！
            const char * uid_str = lv_label_get_text(child);
            printf("Label text: %s\n", uid_str);
            if(strcmp(uid_str,"+")==0)continue;
            int uid = atoi(uid_str);
            printf("intuid = %d\n",uid);
            if(!addChoppBoard(uid,true))
            {
                lv_obj_t *mbox11 = lv_msgbox_create(NULL, "提示", "当前商品已售罄！", NULL, true);
                printf("设置字体\n");
                lv_obj_set_style_text_font(mbox11,&ui_font_harmonyOS,0);
                lv_obj_center(mbox11);
            }

            break; // 如果只需要第一个 label，可以 break
        }
    }
    forDillItem();
}
void viewClearChopp(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code != LV_EVENT_CLICKED)return;
    printf("减少\n");
    // 遍历 target 的所有子对象
    uint32_t child_cnt = lv_obj_get_child_cnt(target);
    for (uint32_t i = 0; i < child_cnt; i++) {
        lv_obj_t * child = lv_obj_get_child(target, i);
        // 检查该子对象是否是 label
        if (lv_obj_check_type(child, &lv_label_class)) {
            // 找到了 label！
            const char * uid_str = lv_label_get_text(child);
            printf("Label text: %s\n", uid_str);
            if(strcmp(uid_str,"-")==0)continue;
            int uid = atoi(uid_str);
            addChoppBoard(uid,false);

            break; // 如果只需要第一个 label，可以 break
        }
    }
    forDillItem();
}
//结账
void checkoutChopp(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code != LV_EVENT_CLICKED)return;
    //付钱ing....
    printf("付款开始！\n");
    checkout();
    //生成账单
    char buf[4196] = {0};
    sprintf(buf,"菜名\t单价\t数量\n");
    for(int i=0;i<board.len;i++)
    {
        char temp[200] = {0};
        int uid = board.dishesUids[i].dishesUids;
        dishesItem info = getDishesInfo(uid);
        sprintf(temp,"%s\t%d\t%d\n",info.name,info.peice,board.dishesUids[i].num);
        strcat(buf,temp);
    }
    ///////
    
    sprintf(buf,"%s总共消费：%d 菜品总数：%d\n付款成功！老板欢迎下次再来！",buf,coinNum,Sum);
    lv_obj_t *mbox11 = lv_msgbox_create(NULL, "明细", buf, NULL, true);
    printf("设置字体\n");
    lv_obj_set_style_text_font(mbox11,&ui_font_harmonyOS,0);
    lv_obj_center(mbox11);

    //清空菜板
    board.len = 0;
    coinNum = 0;
    forDillItem();
    initMeun(pages);
}

void replenishmentChopp(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code != LV_EVENT_CLICKED)return;

    replenishment();
    
    char buf[4196] = {0};
    sprintf(buf,"菜名\t数量\n");
    for(int i=0;i<board.len;i++)
    {
        char temp[200] = {0};
        int uid = board.dishesUids[i].dishesUids;
        dishesItem info = getDishesInfo(uid);
        sprintf(temp,"%s\t%d\n",info.name,board.dishesUids[i].num);
        strcat(buf,temp);
    }
    sprintf(buf,"%s补货成功！\n总共补货%d件",buf,Sum);
    lv_obj_t *mbox11 = lv_msgbox_create(NULL, "补货单", buf, NULL, true);
    printf("设置字体\n");
    lv_obj_set_style_text_font(mbox11,&ui_font_harmonyOS,0);
    lv_obj_center(mbox11);

    //清空菜板
    board.len = 0;
    coinNum = 0;
    forDillItem();
    initMeun(pages);

}