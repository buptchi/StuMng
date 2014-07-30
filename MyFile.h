#ifndef _MYFILE_
#define _MYFILE_


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>
#include <malloc.h>

#include "MyDefine.h"
#include "MyStruct.h"
#include "GlobalValue.h"


int GetLineNumInFile();

void AddLineToFile(STSTUDENT stStu);

int FindLineInFile(int nId,STSTUDENT* pstStu);

void ReviseLineInFile(int nLine,STSTUDENT* pstStu);

void DeleteLineInFile(int nLineFile);

void PrintFile(int nInputPage,int nTotlePage);



#endif