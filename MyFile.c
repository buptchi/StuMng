#include "MyFile.h"

/**
* @fn		 GetLineNumInFile
* @brief	 �õ��ļ�����ѧ����Ϣ����
* @param in  
* @param out 
* @return	 ѧ������ 
* @li		 
*/
int GetLineNumInFile()
{
	FILE* fp=fopen(szFileAddress,"r");
	int nCnt=0;
	char szTemp[MAX_CHAR_IN_LINE];
	int nId;
	char szName[MAX_NAME_LENGTH+1];
	char szSex[MAX_SEX_LENGTH+1];
	double dTuition;

	fgets(szTemp,MAX_CHAR_IN_LINE,fp);
	while (FSCANF_SUCCESS==fscanf(fp,"%8d  %10s     %2s  %lf",&nId,szName,szSex,&dTuition)) 
	{ 
		nCnt++;	
	} 
	fclose(fp);
	
	return nCnt;
}


/**
* @fn		 AddLineToFile
* @brief	 ���ѧ����Ϣ���ļ�
* @param in  stStu ѧ����Ϣ
* @param out 
* @return	  
* @li		 
*/
void AddLineToFile(STSTUDENT stStu)
{
	FILE* fp=fopen(szFileAddress,"r+");
	int nLineFile=GetLineNumInFile();

	if (NULL==fp)
	{
		printf("fail to open the file!");
	}
	else
	{
		fseek(fp, CHAR_IN_EVERYLINE*(nLineFile+1) ,SEEK_SET);	
		fprintf(fp,"%8d  %10s     %2s  %9.2f\n",stStu.nId,stStu.szName,stStu.szSex,stStu.dTuition);
	}
	fclose(fp);
}


/**
* @fn		 FindLineInFile
* @brief	 ����ѧ�Ų���ѧ����Ϣ
* @param in  nIdToFind    Ҫ���ҵ�ѧ��
* @param out pstStu       �ҵ���ѧ����Ϣ��ָ��
* @return	 ѧ����Ϣ���ļ��е���һ��
* @li		 FIND_FAILED ����ʧ��
*/
int FindLineInFile(int nIdToFind,STSTUDENT* pstStu)
{
	FILE* fp=fopen(szFileAddress,"r");
	int nCnt=0;
	char szTemp[MAX_CHAR_IN_LINE];
	int nId;
	char szName[MAX_NAME_LENGTH+1];
	char szSex[MAX_SEX_LENGTH+1];
	double dTuition;

	fgets(szTemp,MAX_CHAR_IN_LINE,fp);
	while (FSCANF_SUCCESS==fscanf(fp,"%8d  %10s     %2s  %lf",&nId,szName,szSex,&dTuition)) 
	{ 
		nCnt++;	
		if (nId==nIdToFind)
		{
			gstPos.X=0;
			gstPos.Y=4;
			SetConsoleCursorPosition(gHandleOut,gstPos);
			printf("|      ѧ��             ����             �Ա�             ѧ��         |\n");
			printf("| %8d   %15s      %10s         %9.2f         |\n",nId,szName,szSex,dTuition);

			pstStu->nId=nId;
			strcpy(pstStu->szName,szName);
			strcpy(pstStu->szSex,szSex);
			pstStu->dTuition=dTuition;

			fclose(fp);
			return nCnt;
		}
	} 
	fclose(fp);

	gstPos.X=25;
	gstPos.Y=5;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("   û����Ҫ�ҵ�ѧ��\n");

	return FIND_FAILED;	
}

/**
* @fn		 ReviseLineInFile
* @brief	 �޸�ѧ����Ϣ
* @param in  nLineFile    ѧ����Ϣ���ڵ�����
* @          pstStu       Ҫ�޸ĵ�ѧ����Ϣָ��
* @return	  
* @li		 
*/
void ReviseLineInFile(int nLineFile,STSTUDENT* pstStu)
{
	FILE* fp=fopen(szFileAddress,"r+");
	
	fseek(fp, CHAR_IN_EVERYLINE*nLineFile ,SEEK_SET);	
	fprintf(fp,"%8d  %10s     %2s  %9.2f\n",pstStu->nId,pstStu->szName,pstStu->szSex,pstStu->dTuition);
	fclose(fp);
}

/**
* @fn		 DeleteLineInFile
* @brief	 ɾ��ѧ����Ϣ
* @param in  nLineFile  ѧ����Ϣ���ڵ�����
* @return	  
* @li		 
*/
void DeleteLineInFile(int nLineFile)
{
	int nTotleLine=GetLineNumInFile();
	FILE* fp=fopen(szFileAddress,"r+");
	char szTemp[MAX_CHAR_IN_LINE];
	int i;
	
	for (i=0;i<(nTotleLine-nLineFile);i++)
	{
		fseek(fp, CHAR_IN_EVERYLINE*(nLineFile+i+1),SEEK_SET);
		fgets(szTemp,MAX_CHAR_IN_LINE,fp);
		fseek(fp, CHAR_IN_EVERYLINE*(nLineFile+i) ,SEEK_SET);	
		fputs(szTemp,fp);
	}
	fclose(fp);

	fp=fopen(szFileAddress,"r+");
	fseek(fp, CHAR_IN_EVERYLINE*(nTotleLine),SEEK_SET);
	fputs("                                    \n",fp);
	fclose(fp);
}


/**
* @fn		 PrintFile
* @brief	 ��ӡѧ����Ϣ
* @param in  nInputPage  ������ʾ��ҳ��
* @          nTotlePage  ��ҳ��
* @return	  
* @li		 
*/
void PrintFile(int nInputPage,int nTotlePage)
{
	int i;
	FILE* fp=fopen(szFileAddress,"r");
	int nId;
	char szName[MAX_NAME_LENGTH+1];
	char szSex[MAX_SEX_LENGTH+1];
	double dTuition;

	system("cls");
	printf("|----------------------------------------------------------------------|\n");
	printf("|                             ѧ������ϵͳ                             |\n");
	printf("|----------------------------------------------------------------------|\n");
	printf("|      ѧ��             ����             �Ա�             ѧ��         |\n");
	printf("|----------------------------------------------------------------------|\n");


	fseek(fp, CHAR_IN_EVERYLINE*((ONE_PAGE_ITEMS*(nInputPage-1))+1) ,SEEK_SET);	
	for(i=0;i< ONE_PAGE_ITEMS;i++)
	{
		if(FSCANF_SUCCESS==fscanf(fp,"%8d  %10s     %2s  %lf",&nId,szName,szSex,&dTuition))	
		{
			printf("| %8d   %15s      %10s         %9.2f         |\n",nId,szName,szSex,dTuition);
		}
		else
		{
			printf("|                                                                      |\n");
		}
	}
	fclose(fp);
	
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