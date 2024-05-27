#include<stdio.h>
#include "main.h"
#include<string.h>
#include<ctype.h>


Status list_contact(address *add)
{

	printf("================================================================================\n");
	printf("%-5s %-20s %-25s %-17s\n","S.No","Name","Phone_no","Email_Id");
        printf("================================================================================\n");
     
        
	add->file = fopen(add->store,"r");
	if(add->file == NULL)
	{
		printf("File is not open    \n");
		return a_failure;
	}
	fseek(add->file,0,SEEK_SET);
	char alpha[32];
	char digit[165];
	char punt[165];
	char store[357];
	char temp[2];
	int i=0,j=0,k=0;
	int count=0;
	while(!feof(add->file))
	{
		count++;
		fread(alpha,1,32,add->file);                                                    
		while(alpha[i]!='-')
		{
			add->name[0][i]=alpha[i];
			i++;
		}
		add->name[0][i]='\0';i=0;
      

		fread(temp,1,2,add->file);
		fread(digit,1,160,add->file);
		while(digit[k]!='-')
		{
			if(isdigit(digit[k]))
			{
				add->ph[j][i++]=digit[k];
			}
			else if(digit[k]=='/'|| i==10)
			{
				j++;i=0;
			}
			k++;
		}
		add->ph[j][i]='\0';i=0;j=0;k=0;
	
		fread(temp,1,2,add->file);
		fread(punt,1,160,add->file);

		while(punt[k]!='\0')
		{
			if(isalpha(punt[k])||punt[k]=='@'||punt[k]=='.')
			{
				add->email[j][i++]=punt[k];
			}
			else if(punt[k]=='/' || i==10)
			{
				j++;i=0;
			}
			else if(punt[k]=='-' || j==4)
			{
				break;
			}
			k++;
		}
		add->email[j][i]='\0';i=0;j=0;k=0;
		fread(temp,1,1,add->file);
		if(!feof(add->file))
		{
			printf("%-5d %-20s %-25s %-17s\n",count,add->name[0],add->ph[0],add->email[0]);
			for(int i=1;i<4;i++)
			{
				if(add->ph[i]!="\0",add->email[i]!="\0")
					printf("  %35s %30s",add->ph[i],add->email[i]);
			}
			printf("\n\n\n\n================================================================================\n");
			for(int i=0;i<4;i++)
			{
				add->ph[i][0]='\0';
				add->email[i][0]='\0';
			}
		}
	}
}
