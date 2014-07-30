#include "MyLink.h"

/**
* @fn		 AddList
* @brief	 �������ڵ�
* @param in  pstHeadNode   ����ͷ�ڵ� 
*			 stStu         ѧ����Ϣ
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
* @brief	��ȡ������
* @param in pstHeadNode ����ͷ�ڵ� 
* @return	������ 
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
* @brief	��ӡ�б��ȫ���ڵ���Ϣ
* @param in pstHeadNode ����ͷ�ڵ�
*			nInputPage  ������ʾ��ҳ��
*			nTotlePage  �ܵ�ҳ����
* @return	 
* @li
*/
void PrintList(STNODE* pstHeadNode,int nInputPage,int nTotlePage)
{	
	int i;
	STNODE* p = pstHeadNode->next;

	system("cls");
	printf("|----------------------------------------------------------------------|\n");
	printf("|                             ѧ������ϵͳ                             |\n");
	printf("|----------------------------------------------------------------------|\n");
	printf("|      ѧ��             ����             �Ա�             ѧ��         |\n");
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
	printf("|                              ��%d/%dҳ                                 |\n",nInputPage,nTotlePage);
	printf("|----------------------------------------------------------------------|\n");
	if (nInputPage==nTotlePage && 1!=nInputPage)
	{
		printf("|              ESC�������˵�; �������һҳ���밴PgUp��ҳ               |\n");
		printf("|----------------------------------------------------------------------|");
	}
	else
	{
		printf("|                    ESC�������˵�; PgDn��PgUp��ҳ                     |\n");
		printf("|----------------------------------------------------------------------|");		
	}
}


/**
* @fn		FindNode
* @brief	����ѧ��Ѱ������ڵ�
* @param in pstHeadNode ����ͷ�ڵ�
*			nId         ҪѰ�ҵ�ѧ��ѧ��
* @return	���ҳɹ����򷵻�ָ���ѧ���ڵ��ָ�룬���򷵻ؿ�ָ��
* @li		NULL ����ʧ��
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
			printf("|      ѧ��             ����             �Ա�             ѧ��         |\n");
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
		printf("   û����Ҫ�ҵ�ѧ��\n");

		return NULL;
	}
	else
	{
		return p;
	}
}

/**
* @fn		DeleteNode
* @brief	ɾ������ڵ�
* @param in pstHeadNode ����ͷ�ڵ� 
*			pstNode     Ҫɾ���Ľڵ�ָ��
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
