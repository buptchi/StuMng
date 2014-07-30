#include "MyFile.h"

/**
* @fn		 GetLineNumInFile
* @brief	 得到文件里面学生信息个数
* @param in  
* @param out 
* @return	 学生个数 
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
* @brief	 添加学生信息到文件
* @param in  stStu 学生信息
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
* @brief	 根据学号查找学生信息
* @param in  nIdToFind    要查找的学号
* @param out pstStu       找到的学生信息的指针
* @return	 学生信息在文件中的哪一行
* @li		 FIND_FAILED 查找失败
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
			printf("|      学号             姓名             性别             学费         |\n");
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
	printf("   没有你要找的学生\n");

	return FIND_FAILED;	
}

/**
* @fn		 ReviseLineInFile
* @brief	 修改学生信息
* @param in  nLineFile    学生信息所在的行数
* @          pstStu       要修改的学生信息指针
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
* @brief	 删除学生信息
* @param in  nLineFile  学生信息所在的行数
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
* @brief	 打印学生信息
* @param in  nInputPage  请求显示的页码
* @          nTotlePage  总页码
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
	printf("|                             学生管理系统                             |\n");
	printf("|----------------------------------------------------------------------|\n");
	printf("|      学号             姓名             性别             学费         |\n");
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