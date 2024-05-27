#include<stdio.h>
#include"main.h"

Status delete_contact(address *add)
{
       char name[30];
       char phone[30];
       char email[30];
       int serial;

       int read;

       do
       {
	      printf("0 Back\n1 Name      :\n2 Phone no  :\n3 Email ID  :\n4 Serial No :\nPlease select an option : ");
	      scanf("%d",&read);
	    
	      switch(read)
	      {
		      case 1: 
			      printf("Enter the name     : ");
			      scanf(" %[^\n]",name);
			      if(search_in_file(add,name)==a_success)
			      {
				      delete_in_file(add);
				      return a_success;
			      }
			      else
				      return a_failure;	     
			  
			      break;
		      case 2:
			      printf("Enter the phone no : ");
			      scanf("%s",phone);
			      if(search_in_file(add,phone)==a_success)
			      {
				      delete_in_file(add);
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
				      delete_in_file(add);
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
				      delete_in_file(add);
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

Status delete_in_file(address *add)                                                                                 //prints the searching list
{
	printf("= = = = =   Search result   = = = = =\n");
	char ch;
	printf("================================================================================\n");
	printf("%-5s %-20s %-20s %-20s\n","S.No","Name","Phone_no","Email_Id");
	printf("================================================================================\n");
	printf("%-5d %-20s %-20s %-20s\n",add->sl_no,add->name[0],add->ph[0],add->email[0]);
	for(int i=1;i<4;i++)
	{
		if(add->ph[i]!="\0",add->email[i]!="\0")
			printf("  %35s %25s",add->ph[i],add->email[i]);
	}
	printf("\n\n================================================================================\n");
	printf("Press : [s] = select, [q] | cancel : ");
	scanf(" %c",&ch);
	if(ch=='s')
	{
		int s_no;
		printf("Select a s.no to edit : ");
		scanf("%d",&s_no);
		if(add->sl_no == s_no)
		          rewrite_the_data(add);
		else
		{
			printf("x x x x    Enter the correct serial no   x x x x \n");
			delete_contact(add);
		}
	}
	else if(ch=='q')
		return a_success;
}
Status rewrite_the_data(address *add)
{
	add->file = fopen(add->store,"r");                                             //take two files read the orginal file
	FILE *fptr = fopen("temp.csv","w+");                                      
	char str[357];
	int count=0;
	while(fscanf(add->file,"%[^\n]",str)==1)                                      //write a remining data in temperory files
	{
		count++;
		if(count!=add->sl_no)
		{
			fprintf(fptr,str,356);
			fwrite("\n",1,1,fptr);
		}
		fseek(add->file,1,SEEK_CUR);                                   

	}
	fclose(add->file);
	fclose(fptr);
	remove(add->store);                                                           //remove the orginal file and remane the temp file
	rename("temp.csv","address.csv");
	return a_success;
}


	
