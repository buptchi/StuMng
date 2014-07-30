#ifndef _MYINPUTTOOL_
#define _MYINPUTTOOL_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include<conio.h>

#include "MyDefine.h"
#include "GlobalValue.h"
#include "MyStruct.h"

int InputTool(char* szOut,int nMaxLen,int nArgNum,...);

int InputModeTool(char* szOut,int nMaxLen,int nMode);

#endif