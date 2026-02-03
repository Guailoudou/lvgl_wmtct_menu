#include <stdio.h>
#include "Model.h"
userInfo utest(){
    userInfo info = {
        .name = "dd",
        .password = "aa",
        .type = 3,
        .uid = 2
    };
    return info;
}

int main(){
    userInfo info = utest();
    printf("%d\n",info.type);
}