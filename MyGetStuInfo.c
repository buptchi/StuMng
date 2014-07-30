#include "MyGetStuInfo.h"

/**
* @fn		 GetStuInfo
* @brief	 获取学生信息
* @param in  pstHeadNode  链表头节点
* @param out pstStuOut    学生信息
* @return	  
* @li		 RETURN_ESC 退出 RETURN_EXISTED 已存在 RETURN_SUCCESS 成功
*/
int GetStuInfo(STSTUDENT* pstStuOut)
{
	int nId;
	char szName[MAX_NAME_LENGTH+1];
	char szSex[MAX_SEX_LENGTH+1];
	double dTuition;
	char cKey=KEY_ENTER;
	STSTUDENT* pstStu=(STSTUDENT*)malloc(sizeof(STSTUDENT));
	int nReturnFind;

	gstPos.X=20;		
	gstPos.Y=5;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("                                                ");	

	nId=GetId();
	if(RETURN_ESC==nId)
	{	
		return RETURN_ESC;
	}
	
	nReturnFind=FindLineInFile(nId,pstStu);
	free(pstStu);
	pstStu=NULL;
	
	if(FIND_FAILED!=nReturnFind) /**<查看学号是否已经存在 */				
	{
		gstPos.X=4;		
		gstPos.Y=4;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("                                                                 \n");
		printf("|                       学号已存在，添加无效                          ");

		return RETURN_EXISTED;
	}
	else
	{	
		gstPos.X=2;		
		gstPos.Y=5;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("                                                                    ");	

		if(RETURN_ESC==GetName(szName))
		{	
			return RETURN_ESC;	
		}
		if(RETURN_ESC==GetSex(szSex))
		{	
			return RETURN_ESC;
		}
		dTuition=GetTuition();
		if (RETURN_ESC==dTuition)
		{	
			return RETURN_ESC;
		}

		pstStuOut->nId=nId;
		strcpy(pstStuOut->szName,szName);
		strcpy(pstStuOut->szSex,szSex);
		pstStuOut->dTuition=dTuition;

		gstPos.X=0;
		gstPos.Y=4;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("|      学号             姓名             性别             学费         |\n");
		printf("| %8d   %15s      %10s         %9.2f         |\n",nId,szName,szSex,dTuition);
		gstPos.X=20;		
		gstPos.Y=10;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("            添加成功      	                   ");

	}

	return RETURN_SUCCESS;
}

/**
* @fn		 GetId
* @brief	 获取学生学号
* @param in  
* @param out 
* @return	 返回学生学号 
* @li		 RETURN_ESC 退出
*/
int GetId()
{
	char szId[MAX_ID_LENGTH+1];
	int nId=0;

	gstPos.X=1;		
	gstPos.Y=5;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("                                                                      ");
	gstPos.X=25;		
	gstPos.Y=5;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("请输入学号：");

	if(RETURN_ESC==InputModeTool(szId,MAX_ID_LENGTH,INPUT_NUM))
	{
		return RETURN_ESC;
	}
	else
	{	
		nId=atoi(szId);
		return nId;
	}
}


/**
* @fn		 GetSex
* @brief	 获取学生性别
* @param in  
* @param out szSex       学生性别
* @return	  
* @li		 RETURN_ESC 退出 RETURN_SUCCESS 成功
*/
int GetSex(char szSex[])
{
	char szTemp[2];

	while(1)
	{
		gstPos.X=1;		
		gstPos.Y=5;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("                                                                      ");
		gstPos.X=13;		
		gstPos.Y=5;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("请输入性别(1男 or 2女)：");

		if(RETURN_ESC==InputModeTool(szTemp,1,INPUT_NUM))
		{
			return RETURN_ESC;
		}
		else
		{	
			if(!strcmp(szTemp,"1"))
			{
				strcpy(szSex,"男");
				break;
			}
			else if(!strcmp(szTemp,"2"))
			{
				strcpy(szSex,"女");
				break;
			}
			else
			{

			}
		}
	}

	return RETURN_SUCCESS;
}


/**
* @fn		 GetName
* @brief	 获取学生姓名
* @param in  
* @param out szSex       学生姓名
* @return	  
* @li		 RETURN_ESC 退出 RETURN_SUCCESS 成功
*/
int GetName(char szName[])
{
	gstPos.X=1;		
	gstPos.Y=5;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("                                                                      ");
	gstPos.X=25;		
	gstPos.Y=5;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("请输入姓名：");

	if(RETURN_ESC==InputModeTool(szName,MAX_NAME_LENGTH,INPUT_NUM|INPUT_LETTER|INPUT_CHINESE))
	{
		return RETURN_ESC;
	}

	return RETURN_SUCCESS;
}

/**
* @fn		 GetTuition
* @brief	 获取学生学费
* @param in  
* @param out 
* @return	 学生学费 
* @li		 RETURN_ESC 退出
*/
double GetTuition()
{
	double dTuition=0.0;
	char szTuition[MAX_TUITION_LENGTH+1];
	char cTemp;
	int nCnt=0;

	strcpy(szTuition,"        ");

	gstPos.X=1;		
	gstPos.Y=5;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("                                                                      ");
	gstPos.X=1;		
	gstPos.Y=10;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("                                                                      ");
	gstPos.X=23;		
	gstPos.Y=5;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("请输入学费：%9.2f 元",dTuition);

	while(1)
	{
		cTemp=getch();

		if(KEY_ESC==cTemp)
		{	
			return RETURN_ESC;
		}
		if (KEY_ENTER==cTemp)
		{	
			if(nCnt>0)	
			{	
				break;
			}
		}
		if(KEY_BACKSPACE==cTemp)
		{
			if(nCnt>0)
			{
				gstPos.X=20;
				gstPos.Y=10;
				SetConsoleCursorPosition(gHandleOut,gstPos);
				printf("                                            ");

				nCnt=nCnt-1;
				szTuition[nCnt]=' ';
				dTuition=(double)atoi(szTuition)/100.0;

				gstPos.X=23;
				gstPos.Y=5;
				SetConsoleCursorPosition(gHandleOut,gstPos);
				printf("请输入学费：%9.2f 元",dTuition);				

				continue;
			}
		}

		if(nCnt<MAX_TUITION_LENGTH)
		{
			if(cTemp>=KEY_ZERO && cTemp<=KEY_NINE)
			{
				if(0==nCnt && KEY_ZERO==cTemp)
				{	
					continue;
				}

				szTuition[nCnt]=cTemp;
				dTuition=(double)atoi(szTuition)/100.0;
				nCnt++;

				gstPos.X=10;
				gstPos.Y=10;
				SetConsoleCursorPosition(gHandleOut,gstPos);
				printf("                                                         ");

				gstPos.X=23;
				gstPos.Y=5;
				SetConsoleCursorPosition(gHandleOut,gstPos);
				printf("请输入学费：%9.2f 元",dTuition);
			}
			else
			{
				gstPos.X=10;
				gstPos.Y=10;
				SetConsoleCursorPosition(gHandleOut,gstPos);
				printf("                     请输入数字                              ");
			}
		}
		else
		{
			gstPos.X=10;
			gstPos.Y=10;
			SetConsoleCursorPosition(gHandleOut,gstPos);
			printf("               最大输入位数限制为8位                         ");
		}
	}

	gstPos.X=5;
	gstPos.Y=5;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("                                                        ");
	gstPos.X=25;
	gstPos.Y=10;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("                                 ");

	return dTuition;
}