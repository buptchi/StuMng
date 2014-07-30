#include "MyLink.h"

/**
* @fn		 AddList
* @brief	 添加链表节点
* @param in  pstHeadNode   链表头节点 
*			 stStu         学生信息
* @return 
* @li
*/
void AddList(STNODE* pstHeadNode,STSTUDENT stStu)
{
	STNODE* pstNextNode=(STNODE* )malloc(sizeof(STNODE));

	pstNextNode->stStu=stStu;
	pstNextNode->next=pstHeadNode->next;
	pstHeadNode->next=pstNextNode;
}

/**
* @fn		GetLength
* @brief	获取链表长度
* @param in pstHeadNode 链表头节点 
* @return	链表长度 
* @li
*/
int GetLength(STNODE* pstHeadNode)
{
	int nCnt=0;
	STNODE* p=pstHeadNode;

	while(p->next!=NULL)
	{
		nCnt++;
		p=p->next;
	}

	return nCnt;
}

/**
* @fn		PrintList
* @brief	打印列表的全部节点信息
* @param in pstHeadNode 链表头节点
*			nInputPage  请求显示的页码
*			nTotlePage  总的页码数
* @return	 
* @li
*/
void PrintList(STNODE* pstHeadNode,int nInputPage,int nTotlePage)
{	
	int i;
	STNODE* p = pstHeadNode->next;

	system("cls");
	printf("|----------------------------------------------------------------------|\n");
	printf("|                             学生管理系统                             |\n");
	printf("|----------------------------------------------------------------------|\n");
	printf("|      学号             姓名             性别             学费         |\n");
	printf("|----------------------------------------------------------------------|\n");

	for(i=0;i<( ONE_PAGE_ITEMS*(nInputPage-1) );i++)
	{	
		p=p->next;
	}
	for(i=0;i< ONE_PAGE_ITEMS;i++)
	{
		if(p!=NULL)	
		{
			printf("| %8d   %15s      %10s         %9.2f         |\n",p->stStu.nId,p->stStu.szName,p->stStu.szSex,p->stStu.dTuition);
			p=p->next;
		}
		else
		{
			printf("|                                                                      |\n");
		}
	}
	printf("|                              第%d/%d页                                 |\n",nInputPage,nTotlePage);
	printf("|----------------------------------------------------------------------|\n");
	if (nInputPage==nTotlePage && 1!=nInputPage)
	{
		printf("|              ESC返回主菜单; 已是最后一页，请按PgUp翻页               |\n");
		printf("|----------------------------------------------------------------------|");
	}
	else
	{
		printf("|                    ESC返回主菜单; PgDn、PgUp翻页                     |\n");
		printf("|----------------------------------------------------------------------|");		
	}
}


/**
* @fn		FindNode
* @brief	根据学号寻找链表节点
* @param in pstHeadNode 链表头节点
*			nId         要寻找的学生学号
* @return	查找成功，则返回指向该学生节点的指针，否则返回空指针
* @li		NULL 查找失败
*/
STNODE* FindNode(STNODE* pstHeadNode,int nId)
{
	STNODE* p=pstHeadNode->next;

	while(p)
	{
		if(p->stStu.nId==nId)
		{
			gstPos.X=0;
			gstPos.Y=4;
			SetConsoleCursorPosition(gHandleOut,gstPos);
			printf("|      学号             姓名             性别             学费         |\n");
			printf("| %8d   %15s      %10s         %9.2f         |\n",p->stStu.nId,p->stStu.szName,p->stStu.szSex,p->stStu.dTuition);
			break;
		}
		p=p->next;
	}
	if (!p)
	{
		gstPos.X=25;
		gstPos.Y=5;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("   没有你要找的学生\n");

		return NULL;
	}
	else
	{
		return p;
	}
}

/**
* @fn		DeleteNode
* @brief	删除链表节点
* @param in pstHeadNode 链表头节点 
*			pstNode     要删除的节点指针
* @return	 
* @li
*/
void DeleteNode(STNODE* pstHeadNode,STNODE* pstNode)
{
	STNODE* p=pstHeadNode;

	while(p->next!=pstNode)
	{
		p=p->next;
	}
	p->next = pstNode->next;	

	free(pstNode);
	pstNode=NULL;
}
