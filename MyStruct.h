#ifndef _MYSTRUCT_
#define _MYSTRUCT_

typedef struct tagSTSTUDENT
{
	int  nId;
	char szName[MAX_NAME_LENGTH+1];
	char szSex[MAX_SEX_LENGTH+1];
	double dTuition;
}STSTUDENT;


typedef enum
{
	false=0,
	true
}bool;

#endif