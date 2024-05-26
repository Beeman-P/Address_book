#include<stdio.h>
#include<string.h>
#include "main.h"
#include<ctype.h>

Status add_contact(address *add)
{
	int op;
	char na[32]=" ",p[160]=" ",e[160]=" ";
	char *del =",,";
	char last = '\n';
	int count =0,i;
	char ch;
	add->file = fopen(add->store,"a+");
	do
	{
		printf("0 Back\n1 Add name   : %s\n2 Add number : %s\n3 Add Email  : %s\n",na,p,e);
		printf("plese Select the option : ");
		scanf("%d",&op);
		if(op<=3)
		{
			switch(op)
			{
				case 1:
					{
						char name[32];
					printf("Enter a name(less than 20 charater) : ");
					scanf(" %[^\n]",na);
                                         strcpy(name,na);
					for(i=strlen(na);i<32;i++)
					{
						name[i]='-';
					}
					name[i]='\0';
					fwrite(name,1,32,add->file);
					fwrite(del,1,2,add->file);
					count++;
					break;
					}

				case 2:
					{
						char phone[160];
					printf("Enter the phone number : ");
					scanf("%s",p);
					if(strlen(p)==10)
					{
						strcpy(phone,p);
						add_space(phone);
						fwrite(phone,1,160,add->file);
						fwrite(del,1,2,add->file);
						count++;
					}
					else
					{
						p[0]='\0';
						printf("\nMobile number is not exist\n");
					}
					break;
					}
				case 3:
					{
						char email[160];
					printf("Enter the emailid : ");
					scanf("%s",e);
					if(strstr(e,"@")!=0 && strstr(e,".com")!=0)
					{
						strcpy(email,e);
						add_space(email);
						fwrite(email,1,160,add->file);
						fwrite(&last,1,1,add->file);
						count++;
					}
					else
					{
						e[0]='\0';
						printf("\nEmail address is not present\n");
					}
					break;
					}
			}
			if(count == 3)
			{
				fclose(add->file);
				return a_success;
			}
		}
		else
		{
			printf("\nEnter the Correct option \n");
			printf("*************************\n");
		}
	}while(op!=0); 
	return a_success;	
}
Status add_space(char *na)
{
	int i;
	for(i=strlen(na);i<160;i++)
	{
		na[i]='-';
	}
	na[i]='\0';
}

