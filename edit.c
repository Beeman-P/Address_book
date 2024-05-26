#include<stdio.h>
#include<string.h>
#include"main.h"



Status edit_contact(address *add)                                                               //search the contact to edit
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
				      edit_in_file(add);
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
				      edit_in_file(add);
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
				      edit_in_file(add);
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
				      edit_in_file(add);
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

Status edit_in_file(address *add)                                                                                 //prints the searching list
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
			read_contact(add);
		else
		{
			printf("x x x x    Enter the correct serial no   x x x x \n");
			edit_contact(add);
		}
	}
	else if(ch=='q')
		return a_success;

}
Status read_contact(address *add)                                                                                       //print the changes and read valus efrom user
{
	int roll;
	do
	{
		printf("0 Back\n1 Name       : %s\n2 Phone      :",add->name[0]);
		for(int i=0;add->ph[i][0]!='\0';i++)
			printf(" [%d] %s",i+1,add->ph[i]);
		printf("\n3 Email      : ");
		for(int i=0;add->email[i][0]!='\0';i++)
			printf("[%d] %s",i+1,add->email[i]);

		printf("Enter the option : ");
		scanf("%d",&roll);

		switch(roll)
		{
			    case 1:
				    char name[30];
				    printf("Enter the name to change : ");
				    scanf(" %[^\n]",name);
				    strcpy(add->name[0],name);
				    write_contact(add);
				    break;
			    case 2:
				    char no[13]="/";
				    int num;
				    printf("Enter the phone no index to change [max 5] : ");
				    scanf("%d",&num);
				    if(num<=5)
				    {
					    printf("Enter phone number %d :",num);
					    scanf("%s",no);
					    strcat(add->ph[num-1],no);
					    write_contact(add);
				    }
				    break;
			    case 3:
				    char mail[30];
				    int i;
				    printf("Enter the mail id on index to change [max 5] : ");
				    scanf("%d",&i);
				    if(i<=5)
				    {
					    printf("Enter the mail %d :",i);
					    scanf("%s",mail);
					    strcpy(add->email[i-1],mail);
					    write_contact(add);
				    }
				    break;
		    }
		    return a_success;
	
	     }while(roll!=0);

}
Status write_contact(address *add)                                                                                 //write back in the file
{
	char name[32];
	int i=0,j=0,k=0;
	strcpy(name,add->name[0]);
	for(i=strlen(add->name[0]);i<32;i++)                                                                      //store name upto 32
	{
		name[i]='-';
	}
	name[i]='\0';
//	printf("%s     \n",name);

	char phone[160];                                                                                          //store phone numbers from 5*32=160
	i=0,j=0,k=0;
	for(i=0;add->ph[i][j]!='\0';i++)
	{
		for(j=0;j<10;j++)
		{
			if(add->ph[i][j]!='\0')
				phone[k++]=add->ph[i][j];
		}
		if(add->ph[i+1][0]=='\0')
			break;

		phone[k++]='/';j=0;
	}
	for(i=k;i<160;i++)
	{
		phone[i]='-';
	}
	phone[i]='\0';
//	printf("%s      \n",phone);


	char email[160];                                                                                          //store email numbers from 5*32=160
	i=0,j=0,k=0;
	for(i=0;add->email[i][j]!='\0';i++)
	{
		for(j=0;add->email[i][j]!='\0';j++)
		{
			email[k++]=add->email[i][j];
		}
		if(add->email[i+1][0]=='\0')
			break;

		     email[k++]='/';j=0;
	     }
	    for(i=k;i<160;i++)
	    {
		    email[i]='-';
	    }
	    email[i]='\0';i=0;j=0;k=0;
//	    printf("%s     \n",email);


	    add->file = fopen(add->store,"r+");
            int count=0;
	    char temp[357];

		    while(!feof(add->file))
		    {
			    count++;
			    if(count==add->sl_no)                                                                  //check the position of the file we write
			    {
				    fwrite(name,1,32,add->file);
				    fwrite(",,",1,2,add->file);
				    fwrite(phone,1,160,add->file);
				    fwrite(",,",1,2,add->file);
				    fwrite(email,1,160,add->file);
				    fwrite("\n",1,1,add->file);
				    fclose(add->file);
				    return a_success;
			    }
			    else
			            fread(temp,1,357,add->file);                                                   //set the cursour to the next line (1*32)+2+(5*32)+2(5*32)+1=357
		    }

}
