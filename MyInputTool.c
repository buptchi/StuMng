#include "MyInputTool.h"
 
/**
* @fn		 InputModeTool
* @brief	 ���뷨
* @param in  nMaxLen  �ַ�������󳤶�
*			 nMode    INPUT_NUMΪֻ��������ģʽ��INPUT_LETTERΪ��ĸģʽ��������㣩��INPUT_CHINESEΪֻ���뺺��ģʽ��������ģʽ�������ʹ��
* @param out szOut    Ҫ������ַ���
* @return	 ����ESC���˳�
* @li		 RETURN_ESC ȡ��  RETURN_SUCCESS �ɹ�
*/
int InputModeTool(char* szOut,int nMaxLen,int nMode)
{
	switch(nMode)
	{	
		case INPUT_NUM:		

			if(RETURN_ESC==InputTool(szOut,nMaxLen,2,KEY_ZERO,KEY_NINE))
			{
				return RETURN_ESC;
			}
			break;
		
		case INPUT_LETTER:		

			if(RETURN_ESC==InputTool(szOut,nMaxLen,4,KEY_DISPLAY_BEGIN,KEY_BEFORE_NUM,KEY_AFTER_NUM,KEY_DISPLAY_END))
			{
				return RETURN_ESC;
			}
			break;

		case INPUT_CHINESE:		

			if(RETURN_ESC==InputTool(szOut,nMaxLen,2,KEY_BEGIN,KEY_CTRL_BEGIN))
			{
				return RETURN_ESC;
			}
			break;

		case INPUT_NUM|INPUT_LETTER:		

			if(RETURN_ESC==InputTool(szOut,nMaxLen,2,KEY_DISPLAY_BEGIN,KEY_DISPLAY_END))
			{
				return RETURN_ESC;
			}
			break;

		case INPUT_NUM|INPUT_CHINESE:		

			if(RETURN_ESC==InputTool(szOut,nMaxLen,4,KEY_BEGIN,KEY_CTRL_BEGIN,KEY_ZERO,KEY_NINE))
			{
				return RETURN_ESC;
			}
			break;

		case INPUT_LETTER|INPUT_CHINESE:		

			if(RETURN_ESC==InputTool(szOut,nMaxLen,6,KEY_BEGIN,KEY_CTRL_BEGIN,KEY_DISPLAY_BEGIN,KEY_BEFORE_NUM,
									 KEY_AFTER_NUM,KEY_DISPLAY_END))
			{
				return RETURN_ESC;
			}
			break;	

		case INPUT_NUM|INPUT_LETTER|INPUT_CHINESE:		

			if(RETURN_ESC==InputTool(szOut,nMaxLen,2,KEY_BEGIN,KEY_END))
			{
				return RETURN_ESC;
			}
			break;

		default:
			break;			
	}

	return RETURN_SUCCESS;
}


/**
* @fn		 InputTool
* @brief	 ���뷨
* @param in  nMaxLen  �ַ�������󳤶�
*			 nArgNum  �ڸò�������Ŀɱ�������� 
*			 ...      �ɱ������Ϊһ�Ի��߶�� ���������ASCII�뷶Χ������Ҫ�������֣����������дΪKEY_ZERO,KEY_NINE��
* @param out szOut    Ҫ������ַ���
* @return	 ����ESC�����˳� 
* @li		 RETURN_ESC ȡ�� RETURN_SUCCESS �ɹ�
*/
int InputTool(char* szOut,int nMaxLen,int nArgNum,...)
{		
	int i;
	char cTemp=' ';
	int nCnt=0;
	int nTempMaxLen=0;
	int nNum=0;
	bool bCharInArange=false;
	va_list pArgList;
	int* lnAsciiArange=(int *)malloc(sizeof(int)*(nArgNum+1));
	
	if(1==nArgNum%2 || 0==nArgNum)
	{
		exit(EXIT_FAILURE);
	}
	
	va_start(pArgList,nArgNum);
	for (i=0;i<nArgNum;i++)
	{
		lnAsciiArange[i]=va_arg(pArgList,int);
	}
	va_end(pArgList);

	gstPos.X=1;		
	gstPos.Y=10;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	printf("                                                                      ");
	gstPos.X=37;		
	gstPos.Y=5;
	SetConsoleCursorPosition(gHandleOut,gstPos);
	
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
			else
			{	
				continue;
			}
		}

		if(KEY_BACKSPACE==cTemp)
		{
			if(nCnt>0)
			{				
				if(szOut[nCnt-1]>KEY_SPACE && szOut[nCnt-1]<KEY_DEL)
				{	
					nCnt=nCnt-1;
				}
				else
				{	
					nCnt=nCnt-2;
				}
				gstPos.X=20;		
				gstPos.Y=10;
				SetConsoleCursorPosition(gHandleOut,gstPos);
				printf("                                                ");
				gstPos.X=37+nCnt;		
				gstPos.Y=5;
				SetConsoleCursorPosition(gHandleOut,gstPos);
				printf(" ");				
				gstPos.X=37+nCnt;		
				gstPos.Y=5;
				SetConsoleCursorPosition(gHandleOut,gstPos);
			}
			continue;
		}
		
		if (KEY_PAGE==cTemp ||KEY_CTRL_BEGIN==cTemp)
		{
			cTemp=getch();
			continue;
		}
		
		if(KEY_SPACE==cTemp)
		{	
			continue;
		}

		if(cTemp>=KEY_CTRL_BEGIN && cTemp<=KEY_CTRL_END)
		{
			continue;
		}
		

		/**
		*������������󳤶�
		*/
		if(cTemp>KEY_SPACE && cTemp<KEY_DEL )
		{
			nTempMaxLen=nMaxLen;
		}
		else
		{
			nNum=0;
			for (i=0;i<nCnt;i++)
			{	
				if(szOut[i]>KEY_SPACE && szOut[i]<KEY_DEL)
				{	
					nNum++;
				}
			}
			if(nNum%2)
			{	
				nTempMaxLen=nMaxLen-1;
			}
			else
			{
				nTempMaxLen=nMaxLen;
			}
		}

		if(nCnt<nTempMaxLen)
		{
			/**
			*�ж�����ļ�ֵ�Ƿ�������ķ�Χ֮��
			*/
			bCharInArange=false;
			for (i=0;i<nArgNum;i=i+2)
			{
				if(cTemp>=lnAsciiArange[i] && cTemp<=lnAsciiArange[i+1])
				{
					bCharInArange=true;
				}
			}

			if(bCharInArange)
			{
				if(lnAsciiArange[0]>KEY_CTRL_BEGIN)
				{
					gstPos.X=10;		
					gstPos.Y=10;
					SetConsoleCursorPosition(gHandleOut,gstPos);
					printf("                                                   ");
					gstPos.X=37+nCnt;		
					gstPos.Y=5;
					SetConsoleCursorPosition(gHandleOut,gstPos);
				}
				szOut[nCnt]=cTemp;
				printf("%c",cTemp);
				nCnt++;
			}
			else
			{
				if(lnAsciiArange[0]>KEY_CTRL_BEGIN)
				{
					gstPos.X=10;		
					gstPos.Y=10;
					SetConsoleCursorPosition(gHandleOut,gstPos);
					printf("                 ���볬����Χ                         ");
					gstPos.X=37+nCnt;		
					gstPos.Y=5;
					SetConsoleCursorPosition(gHandleOut,gstPos);				
				}
			}
		}
		else
		{
			gstPos.X=10;		
			gstPos.Y=10;
			SetConsoleCursorPosition(gHandleOut,gstPos);
			printf("               �������λ������Ϊ%dλ                       ",nMaxLen);
			gstPos.X=37+nCnt;		gstPos.Y=5;
			SetConsoleCursorPosition(gHandleOut,gstPos);
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
	
	szOut[nCnt]='\0';

	free(lnAsciiArange);
	lnAsciiArange=NULL;

	return RETURN_SUCCESS;
}
