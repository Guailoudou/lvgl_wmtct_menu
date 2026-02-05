#include "OrderDishesApi.h"
extern userInfo loginUser;
static Dlist create_head();
static Dlist create_node(DishesData data);
static DishesData create_data(int uid,char imgPath[],char name[],int peice,int type,int inventory);
static int getListLen(Dlist head,int type); //获取长度
static int getMaxUid(Dlist head);   //  获取目前的uid最大值
//////////////////////文件操作///////////////////////////////
static void readtxt(){
    if(dishesHead==NULL){
        dishesHead = create_head();
    }
    // FILE *fp = openfile(USERINFOFILE,"r");
    FILE *fp = openfile(USERINFOFILE,"r");
    char buf[100] = {0};
    int i = 0;
    if(fp!=NULL){
        while(fgets(buf,sizeof(buf),fp) != NULL){
            int uid;
            char name[32] = {0};
            int peice,type,inventory;
            char imgPath[1024] = {0};
            sscanf(buf,"%d %s %s %d %d %d",&uid,imgPath,name,&peice,&type,&inventory);
            Dlist newnode = create_node(create_data(uid,imgPath,name,peice,type,inventory));
            list_add_tail(&newnode->my,&dishesHead->my);
            memset(buf,0,sizeof(buf));
        }
        closefile(fp);
        
    }
    return;
}

static void writetxt(){
    if(dishesHead==NULL){
        dishesHead = create_head();
    }
    // userdata *users  = user_data;
    FILE *fp = openfile(USERINFOFILE,"w+");

    // int len = getListLen(dishesHead);
    Dlist p=NULL,n=NULL;
    //从头结点到末尾进行遍历  安全遍历
    list_for_each_entry_safe(p,n,&(dishesHead->my),my)
    {
        fprintf(fp,"%d %s %s %d %d %d\n",p->data.data.uid,p->data.data.imgPath,
            p->data.data.name,p->data.data.peice,
            p->data.data.type,p->data.data.inventory);
    }

    closefile(fp);
}

////////////////////////API/////////////////////
char *getMenuList(char pagestr[],int pages,int type) //写入menuData
{
    if(dishesHead==NULL)readtxt();
    int len = getListLen(dishesHead,type);
    maxpages = (len/8) + (len%8==0?0:1);
    if(pages>=maxpages)isEnd=true;  //判断末页
    if(pages<=0)pages=maxpages; //循环翻页
    pages %= maxpages+1; 
    if(pages<=0)pages=1;
    char buf[20];
    printf("len=%d,maxp=%d,np=%d\n",len,maxpages,pages);
    sprintf(buf,"%d/%d",pages,maxpages);
    strcpy(pagestr,buf);
    int head = (pages-1)*8;
    
    Dlist p=NULL,n=NULL;
    int i=0,data_i=0;
    for(int i=0;i<8;i++){
        menuData[i].uid = -1;
    }
    list_for_each_entry_safe(p,n,&(dishesHead->my),my)
    {   
        
        if(i<head){
            if(p->data.data.type<=type)
                i++;
            continue;
        }
        if(p->data.data.type<=type){
            menuData[data_i++] = p->data.data;
            inventoryBoard[p->data.data.uid] = p->data.data.inventory;
            printf("%s ",p->data.data.name);
        }
        if(data_i==8){
            break;
        }
    }
    printf("\n");
    return pagestr;
}

bool addChoppBoard(int dishesUid,bool isplus)
{
    bool inventory = true;
    if(inventoryBoard[dishesUid]==0 && loginUser.type<=1){
        inventory = false;
        return inventory;
    }
    for(int i=0;i<board.len;i++){
        if(board.dishesUids[i].dishesUids==dishesUid){
            if(isplus)board.dishesUids[i].num++;
            else board.dishesUids[i].num--;
            if(board.dishesUids[i].num>inventoryBoard[dishesUid]  && loginUser.type<=1){
                board.dishesUids[i].num--;
                inventory = false;
            }
            if(board.dishesUids[i].num<=0){
                rmChoppBoard(dishesUid);
            }
            return inventory;
        }
    }

    board.dishesUids[board.len].dishesUids = dishesUid;
    board.dishesUids[board.len++].num = 1;
    return inventory;
}
bool rmChoppBoard(int dishesUid)
{
    for(int i=0;i<board.len;i++){
        if(board.dishesUids[i].dishesUids==dishesUid){
            for(int j=i+1;j<=board.len;j++){
                board.dishesUids[j-1].dishesUids=board.dishesUids[j].dishesUids;
                board.dishesUids[j-1].num=board.dishesUids[j].num;
            }
            board.len--;
            return true;
        }
    }
    return false;
}

bool checkout()
{
    // for(int i=0;i<board.len;i++){
    //     int uid = board.dishesUids[i].dishesUids;
    //     int num = board.dishesUids[i].num;
    //     inventoryBoard[uid] -= num;
    // }
    for(int i=0;i<board.len;i++){
        int uid = board.dishesUids[i].dishesUids;
        int num = board.dishesUids[i].num;
        Dlist p=NULL,n=NULL;
        //从头结点到末尾进行遍历  安全遍历
        list_for_each_entry_safe(p,n,&(dishesHead->my),my)
        {
           if(p->data.data.uid==uid){
                p->data.data.inventory -= num;
           }
        }
    }
    writetxt();
}
bool replenishment()
{
    // for(int i=0;i<board.len;i++){
    //     int uid = board.dishesUids[i].dishesUids;
    //     int num = board.dishesUids[i].num;
    //     inventoryBoard[uid] += num;
    // }
    for(int i=0;i<board.len;i++){
        int uid = board.dishesUids[i].dishesUids;
        int num = board.dishesUids[i].num;
        Dlist p=NULL,n=NULL;
        //从头结点到末尾进行遍历  安全遍历
        list_for_each_entry_safe(p,n,&(dishesHead->my),my)
        {
           if(p->data.data.uid==uid){
                p->data.data.inventory += num;
           }
        }
    }
    writetxt();
}
////////////////////////////链表操作//////////////////////////
static Dlist create_head()
{
    Dlist head = malloc(sizeof(struct DishesList));
    if (head == NULL)
    {
        printf("head failed\n");
        return NULL;
    }
    else
    {
        INIT_LIST_HEAD(&(head->my)); // 初始化指针域
        return head;
    }
}
static Dlist create_node(DishesData data)
{
    Dlist node = malloc(sizeof(struct DishesList));
    if (node == NULL)
    {
        printf("node failed\n");
        return NULL;
    }
    else
    {
        node->data=data;//数据域赋值
        INIT_LIST_HEAD(&(node->my)); // 初始化指针域
        return node;
    }
}

static DishesData create_data(int uid,char imgPath[],char name[],int peice,int type,int inventory){
    DishesData data = {
        // .data.name = name,
        // .data.imgPath=imgPath,
        .data.type = type,
        .data.uid = uid,
        .data.peice = peice,
        .data.inventory = inventory
    };
    strcpy(data.data.name,name);
    strcpy(data.data.imgPath,imgPath);
    return data;
}

static int getListLen(Dlist head,int type)
{
    Dlist p=NULL,n=NULL;
    int len=0;
    //从头结点到末尾进行遍历  安全遍历
    list_for_each_entry_safe(p,n,&(head->my),my)
    {
        if(p->data.data.type<=type)
            len++;
    }
    return len;
}
static int getMaxUid(Dlist head)
{
    Dlist p=NULL,n=NULL;
    int max=0;
    //从头结点到末尾进行遍历  安全遍历
    list_for_each_entry_safe(p,n,&(head->my),my)
    {
        if(p->data.data.uid>max){
            max = p->data.data.uid;
        }
    }
    return max;
}

dishesItem getDishesInfo(int uid)
{
    dishesItem info;
    Dlist p=NULL,n=NULL;
    //从头结点到末尾进行遍历  安全遍历
    list_for_each_entry_safe(p,n,&(dishesHead->my),my)
    {
        if(p->data.data.uid==uid){
            info = p->data.data;
            return info;
        }
    }
    strcpy(info.name,"NO_ITEM");
    return info;
}