#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"main.h"

Status search_contact(address *add)
{
    
      int read;
      char name[30];
      char digit[30];
      char email[30];
      add->sl_no=0;
      int serial;
      do
      {
	      printf("0 Back\n1 Name      :\n2 Phone no  :\n3 Email ID  :\n4 Serial No :\nPlease select an option : ");
	      scanf(" %d",&read);

	      switch(read)
	      {
		      case 1 : 
			      printf("Enter the name     : ");
			      scanf(" %[^\n]",name);
			      if(search_in_file(add,name)==a_success)
			      {
				      print_search(add);
				      return a_success;
			      }
			      else
				      return a_failure;	     
			  
			      break;
		      case 2 :
			      printf("Enter the phone no : ");
			      scanf("%s",digit);
			      if(search_in_file(add,digit)==a_success)
			      {
				      print_search(add);
				      return a_success;
			      }
			      else
			           return a_failure;

			      break;
		      case 3:
			      printf("Enter the email ID : ");
			      scanf("%s",email);
			      if(search_in_file(add,email)==a_success)
			      {
				      print_search(add);
				      return a_success;
			      }
			      else
				      return a_failure;
			 
			      break;
		      case 4:
			      printf("Enter the serial no : ");
			      scanf("%d",&serial);
			      add->sl_no = serial;
			      if(search_in_file(add,"NULL")==a_success)
			      {
				      print_search(add);
				      return a_success;
			      }
			      else
				      return a_failure;
			     
			      break;
		      default:
			      break;
	      }

      }while(read!=0);

      return a_success;
}
Status search_in_file(address *add,char *check)
{
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
	char store[360];
	char temp[2];
	int i=0,j=0,k=0;
	int count=0;
	while(!feof(add->file))
	{
		count++;
       //      read the name of the contact

		fread(alpha,1,32,add->file);                                                    
		while(alpha[i]!='-')
		{
			add->name[0][i]=alpha[i];
			i++;
		}
		add->name[0][i]='\0';i=0;
       //	printf("%s  \n",add->name[0]);
       //       Read the phone numbers of the contact

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
	//	printf("%s   \n",add->ph[0]);
        //      read the email of the contact
		
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
	//	printf("%s   \n",add->email[0]);
        //      check the contact is present

		if(strcmp(add->name[0],check)==0 || strcmp(add->ph[0],check)==0 || strcmp(add->email[0],check)==0)
		{
			add->sl_no = count;
			fclose(add->file);
			return a_success;
		}
		else if(count == add->sl_no)
		{
			add->sl_no=count;
			fclose(add->file);
			return a_success;
		}
		else
		{
			alpha[0]='\0';digit[0]='\0';punt[0]='\0';
		}
		for(int i=0;i<4;i++)
		{
		add->ph[i][0]='\0';
		add->email[i][0]='\0';
		}

		fread(temp,1,1,add->file);
       }
      return a_failure;
}
Status print_search(address *add)
{
	char ch;
	printf("================================================================================\n");
	printf("%-5s %-20s %-25s %-17s\n","S.No","Name","Phone_no","Email_Id");
        printf("================================================================================\n");
        printf("%-5d %-20s %-25s %-17s\n",add->sl_no,add->name[0],add->ph[0],add->email[0]);
	for(int i=1;i<4;i++)
	{
		if(add->ph[i]!="\0",add->email[i]!="\0")
			printf("  %35s %30s",add->ph[i],add->email[i]);
	}
        printf("\n\n\n\n================================================================================\n");
	printf("Press : [q] | cancel : ");
	scanf(" %c",&ch);
          if(ch=='q')
            {
               return a_success;
            }
}
