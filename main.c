
#include "main.h"

/**
* @fn		 PrintTitle
* @brief	 ��ӡ����
* @param in  
* @param out 
* @return	 
* @li
*/
void PrintTitle()
{
	printf("|----------------------------------------------------------------------|\n");
	printf("|                             ѧ������ϵͳ                             |\n");
	printf("|----------------------------------------------------------------------|\n");
}

/**
* @fn		 PrintBody
* @brief	 ��ӡ����
* @param in  
* @param out 
* @return	 
* @li
*/
void PrintBody()
{
	printf("|                                                                      |\n");
	printf("|                                                                      |\n");
	printf("|                                                                      |\n");
	printf("|                                                                      |\n");
	printf("|                                                                      |\n");
	printf("|                                                                      |\n");
	printf("|                                                                      |\n");
	printf("|                                                                      |\n");
	printf("|----------------------------------------------------------------------|\n");
	printf("|                                                                      |\n");
	printf("|----------------------------------------------------------------------|\n");
}

/**
* @fn		 PrintMenu
* @brief	 ��ӡ�˵�
* @param in  
* @param out 
* @return	 
* @li
*/
void PrintMenu()
{
		system("cls");		
		PrintTitle();
		PrintBody();
		
		gstPos.X=32;
		gstPos.Y=5;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("1---���\n");
		gstPos.X=32;
		gstPos.Y=6;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("2---�鿴\n");
		gstPos.X=32;
		gstPos.Y=7;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("3---����\n");
		gstPos.X=32;
		gstPos.Y=8;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("4---ɾ��\n");
		gstPos.X=26;
		gstPos.Y=12;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("������������Ӧ������\n");
}

/**
* @fn		 AddLine
* @brief	 ���ѧ����Ϣ
* @param in  
* @param out 
* @return	 
* @li
*/
void AddLine()
{
	int nGetReturn=0;
	char cKey=KEY_ENTER;				
	STSTUDENT* pstStuInput=(STSTUDENT*)malloc(sizeof(STSTUDENT));
	
	system("cls");
	PrintTitle();
	PrintBody();
	gstPos.X=19;
	gstPos.Y=12;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("������� �밴enter ; ���� �밴ESC");
	
	while(KEY_ENTER==cKey)
	{
		nGetReturn=GetStuInfo(pstStuInput);
		if (RETURN_ESC==nGetReturn)
		{
			break;
		}
		if(RETURN_EXISTED!=nGetReturn)
		{
			AddLineToFile(*pstStuInput);
		}
					
		cKey=getch();

		while(KEY_ESC!=cKey && KEY_ENTER!= cKey)
		{
			cKey=getch();
		}
		
		gstPos.X=1;
		gstPos.Y=4;
		SetConsoleCursorPosition(gHandleOut,gstPos);
		printf("                                                                      \n");
		if(KEY_ESC==cKey)
		{
			break;
		}
	}
	free(pstStuInput);
	pstStuInput=NULL;
}


/**
* @fn		 LookForFile
* @brief	 �鿴ȫ������ڵ�
* @param in  
* @param out 
* @return	 
* @li
*/
void LookForFile()
{	
	char cKey;
	int nInputPage=1;
	int nLength=GetLineNumInFile();
	int nTotlePage=ceil((double)nLength/ONE_PAGE_ITEMS);
	
	if(0==nTotlePage)
	{
		nTotlePage=1;
	}

	PrintFile(1,nTotlePage);
	
	while(1)
	{
		/**
		*��ҳ����
		*/
		cKey=getch();
		if( KEY_PAGE==cKey )
		{
			cKey=getch();
			if(KEY_PAGE_UP==cKey)   
			{
				if(nInputPage>1)
				{
					nInputPage--;		
					PrintFile(nInputPage,nTotlePage);
				}
			}
			if(KEY_PAGE_DOWN==cKey)
			{
				if(nInputPage< nTotlePage)
				{
					nInputPage++;
					PrintFile(nInputPage,nTotlePage);
				}
			}
		}
		if(KEY_ESC==cKey)
		{	
			break;
		}
	}
}

/**
* @fn		 LookForLine
* @brief	 ����ѧ�Ų���ѧ����Ϣ�������ҵ�֮������޸�
* @param in  
* @param out 
* @return	 
* @li
*/
void LookForLine()
{
	char cKey;
	char cTemp;
	bool bSkipESC=true;
	int nFindId;
	char szName[MAX_NAME_LENGTH+1];
	char szSex[MAX_SEX_LENGTH+1];
	double dTuition;
	STSTUDENT* pstStu=(STSTUDENT*)malloc(sizeof(STSTUDENT));
	int nReturnFind=0;

	system("cls");
	PrintTitle();
	PrintBody();
	gstPos.X=30;
	gstPos.Y=12;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("���� �밴ESC");
	
	nFindId=GetId();
	if(nFindId!=RETURN_ESC)
	{	
		nReturnFind=FindLineInFile(nFindId,pstStu);
	}
	else
	{
		bSkipESC=false;
	}

	if(FIND_FAILED!=nReturnFind)
	{
		while(1)
		{
			gstPos.X=0;
			gstPos.Y=4;
			SetConsoleCursorPosition(gHandleOut,gstPos);
			printf("|      ѧ��             ����             �Ա�             ѧ��         |\n");
			printf("| %8d   %15s      %10s         %9.2f         |\n",
					pstStu->nId,pstStu->szName,pstStu->szSex,pstStu->dTuition	);
			gstPos.X=16;
			gstPos.Y=10;
			SetConsoleCursorPosition(gHandleOut,gstPos);
			printf("��1 �޸���������2 �޸��Ա𣻰�3 �޸�ѧ��               ");
						
			cTemp=getch();

			gstPos.X=1;
			gstPos.Y=4;
			SetConsoleCursorPosition(gHandleOut,gstPos);
			printf("                                                                      \n");

			if(KEY_ONE==cTemp)
			{
				if(RETURN_ESC==GetName(szName))
				{	
					continue;
				}
				strcpy(pstStu->szName,szName);
				ReviseLineInFile(nReturnFind,pstStu);
			}
			else if(KEY_TWO==cTemp)
			{
				if(RETURN_ESC==GetSex(szSex))
				{	
					continue;
				}
				strcpy(pstStu->szSex,szSex);
				ReviseLineInFile(nReturnFind,pstStu);
			}
			else if(KEY_THREE==cTemp)
			{
				dTuition=GetTuition();
				if (RETURN_ESC==dTuition)
				{	
					continue;
				}
				pstStu->dTuition=dTuition;
				ReviseLineInFile(nReturnFind,pstStu);
			}
			else if(KEY_ESC==cTemp)
			{
				bSkipESC=false;
				break;
			}
			else
			{
				
			}
		}
	}

	while(bSkipESC)
	{
		cKey=getch();
		if(KEY_ESC==cKey)
		{	
			break;
		}
	}
	free(pstStu);
	pstStu=NULL;
}

/**
* @fn		 DeleteLine
* @brief	 ɾ��ѧ����Ϣ
* @param in  
* @param out 
* @return	 
* @li
*/
void DeleteLine()
{
	char cKey;
	char cTemp;
	bool bSkipESC=true;
	int nDeleteId; 
	STSTUDENT* pstStu=(STSTUDENT*)malloc(sizeof(STSTUDENT));
	int nReturnFind;

	system("cls");
	PrintTitle();
	PrintBody();
	gstPos.X=30;		
	gstPos.Y=12;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("���� �밴ESC");
	
	nDeleteId=GetId();				
	if(RETURN_ESC==nDeleteId)
	{	
		bSkipESC=false;
	}
	else
	{
		nReturnFind=FindLineInFile(nDeleteId,pstStu);
		if(FIND_FAILED!=nReturnFind)
		{
			gstPos.X=29;
			gstPos.Y=10;
			SetConsoleCursorPosition(gHandleOut,gstPos);
			printf("ȷ��ɾ����ENTER                       ");
				
			while(1)
			{
				cTemp=getch();
				if (KEY_ENTER==cTemp)
				{
					DeleteLineInFile(nReturnFind);

					gstPos.X=20;
					gstPos.Y=10;
					SetConsoleCursorPosition(gHandleOut,gstPos);
					printf("           ɾ���ɹ�                               ");
					break;
				}
				else if(KEY_ESC==cTemp)
				{
					bSkipESC=false;	
					break;
				}
				else
				{
					NULL;
				}
			}
		}
	}

	while(bSkipESC)
	{
		cKey=getch();
		if(KEY_ESC==cKey)
		{
			break;
		}
	}
	
	free(pstStu);
	pstStu=NULL;
}

/**
* @fn		main
* @brief	������
* @param in ��
* @return 
* @li  
*/
void main()
{	
	char cTask;
	FILE* fpStuFile;

	STSTUDENT stu1={1,"С��","��",10.00};
	STSTUDENT stu2={22,"����","��",100220.00};
	STSTUDENT stu3={333,"��С��","��",103230.00};
	STSTUDENT stu4={12345678,"123dd����","��",123456.78};
	STSTUDENT stu5={111,"��ɷɷ���","Ů",126.78};
	STSTUDENT stu6={222222,"1aaa123��","Ů",1236.78};
	STSTUDENT stu7={98765432,"chichichic","Ů",123456.78};

	
	fpStuFile=fopen(szFileAddress,"w+");
	if (NULL==fpStuFile)
	{
		printf("fail to open the file!");
	}
	else
	{
		fprintf(fpStuFile,"      ѧ��     ����     �Ա�   ѧ��   \n"); 
	}
	fclose(fpStuFile);
	
	AddLineToFile(stu1);
	AddLineToFile(stu2);
	AddLineToFile(stu3);
	AddLineToFile(stu4);
	AddLineToFile(stu5);
	AddLineToFile(stu6);
	AddLineToFile(stu7);
	
	gHandleOut=GetStdHandle(STD_OUTPUT_HANDLE);

	while(1)
	{
		PrintMenu();

		cTask=getch();
		switch(cTask)
		{	
			case KEY_ONE:		
				AddLine();
				break;
		
			case KEY_TWO:				
				LookForFile();
				break;

			case KEY_THREE:
				LookForLine();
				break;

			case KEY_FOUR:
				DeleteLine();
				break;

			default:
				break;			
		}		
	}
}
/* End of this file */