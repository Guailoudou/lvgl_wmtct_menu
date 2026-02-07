#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Model.h"
#include <time.h>
#include <unistd.h>
#include <stdarg.h>
//打开文件
FILE *openfile(const char *path,char *mode);
//关闭文件
int closefile(FILE *fp);
void logprint(char *str, ...);
#endif