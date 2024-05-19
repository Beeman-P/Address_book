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
      int serial;
      do
      {
	      printf("0 Back\n1 Name      :\n2 Phone no  :\n3 Email ID  :\n4 Serial No :\nPlease select an option : ");
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
			  if(search_in_file(add,email)==a_success)
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
			 scanf("%d",&serial);
			 add->sl_no = serial;
			 if(search_in_file(add,"NULL")==a_success)
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
      int count=0;
         while(fscanf(add->file,"%[^\n]",get)==1)
	  {
		  count++;
                   strcpy(add->name,strtok(get,","));
	        //   printf("%s   \n",add->name);
		  
                  digit=strtok(NULL,",");
	          strcpy(add->ph,digit);
	        //  printf("%s   \n",add->ph);

	 
	          punt=strtok(NULL,",");
	          strcpy(add->email,punt);
		//  printf("%s   \n",add->email);
	    if(strcmp(add->name,check)==0 || strcmp(add->ph,check)==0 || strcmp(add->email,check)==0)
	    {
		add->sl_no = count;
	      return a_success;
	    }
	   else if(count == add->sl_no)
	   {
		   add->sl_no=count;
		  return a_success;
	   }
            fseek(add->file,1,SEEK_CUR);

      }
      return a_failure;
}
Status print_search(address *add)
{
	char ch;
	printf("================================================================================\n");
	printf("%-5s %-20s %-17s %-20s\n","S.No","Name","Phone_no","Email_Id");
        printf("================================================================================\n");
        printf("%-5d %-20s %-17s %-20s\n",add->sl_no,add->name,add->ph,add->email);
        printf("================================================================================\n");
	printf("Press : [q] | cancel : ");
	scanf(" %c",&ch);
          if(ch=='q')
            {
               return a_success;
            }
}
