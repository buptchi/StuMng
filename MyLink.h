#ifndef _MYLINK_
#define _MYLINK_


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>
#include <malloc.h>

#include "MyDefine.h"
#include "MyStruct.h"
#include "GlobalValue.h"

void AddList(STNODE* pstHeadNode,STSTUDENT stStu);

int GetLength(STNODE* pstHeadNode);

void PrintList(STNODE* pstHeadNode,int nInputPage,int nTotlePage);

STNODE* FindNode(STNODE* pstHeadNode,int nId);

void DeleteNode(STNODE* pstHeadNode,STNODE* pstNode);

#endif