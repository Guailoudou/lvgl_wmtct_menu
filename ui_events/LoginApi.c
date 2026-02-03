#include "LoginApi.h"


/////////////////////////////文件操作////////////////////
static void readtxt(){
    if(userhead==NULL){
        userhead = create_head();
    }
    FILE *fp = openfile(USERINFOFILE,"r");
    char buf[100] = {0};
    int i = 0;
    if(fp!=NULL){
        while(fgets(buf,sizeof(buf),fp) != NULL){
            int uid;
            char name[32] = {0};
            char passwd[32] = {0};
            int type;
            sscanf(buf,"%d %s %s %d",uid,name,passwd,type);
            Ulist newnode = create_node(create_data(uid,name,passwd,type));
            list_add_tail(&newnode->my,&userhead->my);
            memset(buf,0,sizeof(buf));
        }
        closefile(fp);
        
    }
    return;
}
// void display(userdata *users){
//     for (int i = 0; i < users->len; i++)
//     {
//         printf("账号：%s\t密码：%s\n",userList[i].name,userList[i].passwd);
//     }
// }
static void writetxt(){
    if(userhead==NULL){
        userhead = create_head();
    }
    // userdata *users  = user_data;
    FILE *fp = openfile(USERINFOFILE,"w+");

    // int len = getListLen(userhead);
    Ulist p=NULL,n=NULL;
    //从头结点到末尾进行遍历  安全遍历
    list_for_each_entry_safe(p,n,&(userhead->my),my)
    {
        fprintf(fp,"%d %s %s %d\n",p->data.data.uid,
            p->data.data.name,p->data.data.password,
            p->data.data.type);
    }

    closefile(fp);
}
static bool check_username(const char *iuser){
    if(userhead==NULL){
        userhead = create_head();
    }
    Ulist p=NULL,n=NULL;
    //从头结点到末尾进行遍历  安全遍历
    list_for_each_entry_safe(p,n,&(userhead->my),my)
    {
        char *user = p->data.data.name;
        if(strcmp(user,iuser)==0){
            return false;
        }
    }
    return true;
}
//////////////////////API/////////////////////////////
int loginMenu(const char *iuser,const char *ipass){
    if(userhead==NULL){
        userhead = create_head();
    }
    Ulist p=NULL,n=NULL;
    //从头结点到末尾进行遍历  安全遍历
    list_for_each_entry_safe(p,n,&(userhead->my),my)
    {
        char *user = p->data.data.name;
        char *pass = p->data.data.password;
        printf("校验读取：%s %s\n",user,pass);
        if(strcmp(user,iuser)==0 && strcmp(pass,ipass)==0){
            strcpy(loginUser.name,user);
            strcpy(loginUser.password,pass);
            loginUser.uid = p->data.data.uid;
            loginUser.type = p->data.data.type;
            return p->data.data.uid;
        }
    }
    return -1;
}

bool regMenu(const char *iuser,const char *ipass){
    if(!check_username(iuser)){
        return false;
    }
    if(userhead==NULL){
        userhead = create_head();
    }
    // if(user_data==NULL)
    //     user_data = readtxt();
    // int len = user_data->len;
    printf("注册传入:%s %s\n",iuser,ipass);
    int uid = getMaxUid(userhead);
    Ulist newnode = create_node(create_data(++uid,iuser,ipass,0));
    list_add_tail(&newnode->my,&userhead->my);

    writetxt();
    return true;
}
bool setUserType(int uid,int type)
{
    Ulist p=NULL,n=NULL;
    //从头结点到末尾进行遍历  安全遍历
    list_for_each_entry_safe(p,n,&(userhead->my),my)
    {
        if(p->data.data.uid==uid){
            p->data.data.type=type;
            return true;
        }
    }
    return false;
}
bool outLogin()
{
    loginUser.uid=-1;
    loginUser.type=0;
    return true;
}
userInfo getUserInfo(int uid)
{
    userInfo info;
    Ulist p=NULL,n=NULL;
    //从头结点到末尾进行遍历  安全遍历
    list_for_each_entry_safe(p,n,&(userhead->my),my)
    {
        if(p->data.data.uid==uid){
            info = p->data.data;
            return info;
        }
    }
    return ;
}
////////////////////////////链表操作//////////////////////////
static Ulist create_head()
{
    Ulist head = malloc(sizeof(struct UserList));
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
static Ulist create_node(UserData data)
{
    Ulist node = malloc(sizeof(struct UserList));
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

static UserData create_data(int uid,char name[],char password[],int type){
    UserData data ={
        .data.name = name,
        .data.password = password,
        .data.type = type,
        .data.uid = uid
    };
    return data;
}

static int getListLen(Ulist head)
{
    Ulist p=NULL,n=NULL;
    int len=0;
    //从头结点到末尾进行遍历  安全遍历
    list_for_each_entry_safe(p,n,&(head->my),my)
    {
        len++;
    }
}
static int getMaxUid(Ulist head)
{
    Ulist p=NULL,n=NULL;
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