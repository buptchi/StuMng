#ifndef _MYGETSTUINFO_
#define _MYGETSTUINFO_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>
#include<conio.h>

#include "MyDefine.h"
#include "MyStruct.h"
#include "GlobalValue.h" 
#include "MyInputTool.h"
#include "MyFile.h"


int GetStuInfo(STSTUDENT* pstInput);

int GetId();

int GetName(char szName[]);

int GetSex(char szSex[]);

double GetTuition();


#endif