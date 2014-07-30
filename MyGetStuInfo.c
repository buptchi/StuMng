#include "MyGetStuInfo.h"

/**
* @fn		 GetStuInfo
* @brief	 ��ȡѧ����Ϣ
* @param in  pstHeadNode  ����ͷ�ڵ�
* @param out pstStuOut    ѧ����Ϣ
* @return	  
* @li		 RETURN_ESC �˳� RETURN_EXISTED �Ѵ��� RETURN_SUCCESS �ɹ�
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
	
	if(FIND_FAILED!=nReturnFind) /**<�鿴ѧ���Ƿ��Ѿ����� */				
	{
		gstPos.X=4;		
		gstPos.Y=4;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("                                                                 \n");
		printf("|                       ѧ���Ѵ��ڣ������Ч                          ");

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
		printf("|      ѧ��             ����             �Ա�             ѧ��         |\n");
		printf("| %8d   %15s      %10s         %9.2f         |\n",nId,szName,szSex,dTuition);
		gstPos.X=20;		
		gstPos.Y=10;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("            ��ӳɹ�      	                   ");

	}

	return RETURN_SUCCESS;
}

/**
* @fn		 GetId
* @brief	 ��ȡѧ��ѧ��
* @param in  
* @param out 
* @return	 ����ѧ��ѧ�� 
* @li		 RETURN_ESC �˳�
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
	printf("������ѧ�ţ�");

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
* @brief	 ��ȡѧ���Ա�
* @param in  
* @param out szSex       ѧ���Ա�
* @return	  
* @li		 RETURN_ESC �˳� RETURN_SUCCESS �ɹ�
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
		printf("�������Ա�(1�� or 2Ů)��");

		if(RETURN_ESC==InputModeTool(szTemp,1,INPUT_NUM))
		{
			return RETURN_ESC;
		}
		else
		{	
			if(!strcmp(szTemp,"1"))
			{
				strcpy(szSex,"��");
				break;
			}
			else if(!strcmp(szTemp,"2"))
			{
				strcpy(szSex,"Ů");
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
* @brief	 ��ȡѧ������
* @param in  
* @param out szSex       ѧ������
* @return	  
* @li		 RETURN_ESC �˳� RETURN_SUCCESS �ɹ�
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
	printf("������������");

	if(RETURN_ESC==InputModeTool(szName,MAX_NAME_LENGTH,INPUT_NUM|INPUT_LETTER|INPUT_CHINESE))
	{
		return RETURN_ESC;
	}

	return RETURN_SUCCESS;
}

/**
* @fn		 GetTuition
* @brief	 ��ȡѧ��ѧ��
* @param in  
* @param out 
* @return	 ѧ��ѧ�� 
* @li		 RETURN_ESC �˳�
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
	printf("������ѧ�ѣ�%9.2f Ԫ",dTuition);

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
				printf("������ѧ�ѣ�%9.2f Ԫ",dTuition);				

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
				printf("������ѧ�ѣ�%9.2f Ԫ",dTuition);
			}
			else
			{
				gstPos.X=10;
				gstPos.Y=10;
				SetConsoleCursorPosition(gHandleOut,gstPos);
				printf("                     ����������                              ");
			}
		}
		else
		{
			gstPos.X=10;
			gstPos.Y=10;
			SetConsoleCursorPosition(gHandleOut,gstPos);
			printf("               �������λ������Ϊ8λ                         ");
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