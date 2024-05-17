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
      char serial[2];
      do
      {
	      printf("0 Back\n1 Name      :\n2 Phone no  :\n3 Email ID  :\n4 Serial No\nPlease select an option : ");
	      scanf("%d",&read);

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
			  {
				  printf("- - - - Searching name is no prsent - - - -\n");
			  }
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
			  {
				  printf("- - - - Searching no is not presnt - - - - \n");
			  }
			  break;
		  case 3:
			  printf("Enter the email ID : ");
			  scanf("%s",email);
			  if(search_in_file(add,email))
			  {
				  print_search(add);
				  return a_success;
			  }
			  else
			  {
				  printf("- - - - Searching mail is not present - - - - \n");
			  }
			  break;
		  case 4:
			 printf("Enter the serial no : ");
			 scanf("%s",serial);
			 add->serial=0;
			 if(search_in_file(add,serial))
		          {
				  print_search(add);
				  return a_success;
			  }
			 else
			 {
				 printf("- - - - Searching no is not present - - - - \n");
			 }
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
      char get[200];
      char *alpha;
      char *digit;
      char *punt;
      int no = atoi(check);
      int count=0;
         while(fscanf(add->file,"%[^\n]",get)==1)
	  {
                   strcpy(add->name,strtok(get,","));
	           printf("%s   \n",add->name);
		  
                  digit=strtok(NULL,",");
	          strcpy(add->ph,digit);
	          printf("%s   \n",add->ph);

	 
	          punt=strtok(NULL,",");
	          strcpy(add->email,punt);
		  printf("%s   \n",add->email);
	    if(strcmp(add->name,check)==0 || strcmp(add->ph,check)==0 || strcmp(add->email,check)==0)
	      return a_success;
	    else if(count == no)
	    {
		   add->serial=count;
		  return a_success;
	    }
	    else
	    { 
	      count++;
	    }
            fseek(add->file,1,SEEK_CUR);

      }
      return a_failure;
}
Status print_search(address *add)
{
	printf("================================================================================\n");
	printf("%-5s %-20s %-17s %-20s\n","S.No","Name","Phone_no","Email_Id");
        printf("================================================================================\n");
        printf("%-5d %-20s %-17s %-20s\n",add->serial,add->name,add->ph,add->email);
        printf("================================================================================\n");
       return a_success;
}
