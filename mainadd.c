#include<stdio.h>
#include "main.h"
#include<string.h>


int main(int argc,char *argv[])
{
    address add;
	if(argc <= 2)
	{
             read_and_validate(argv,&add);
		int option;
		printf("= = = = = = Address Book = = = = = =\n");
		printf("- - - - - - Features - - - - - - \n");
		while(1)
		{
			printf("0 Exit \n1 Add Contact \n2 Search Contact\n3 Edit Contact\n4 Delect Contact \n5 List \n6 Save\n");
			printf("Please select the option : ");
			scanf("%d",&option);
			switch(option)
			{
				case 0:
					return 0;
				case 1:
					if(add_contact(&add)==a_sucess)
						printf("Add contact is sucessfull\n");
					else
						printf("Enter the valid options :\n");
					break;
				case 2:
			}

		}
	}
}
Status read_and_validate(char *argv[],address *add)
{
	if(argv[1]!=NULL)
	{
		if(strstr(argv[1],".csv")!=NULL)                                 //check the file is present or not
			strcpy(add->store,argv[1]);         
		else
		{
			strcpy(add->store,argv[1]);                              //if .csv file is not present just add
		        strcat(add->store,".csv");	     
		}
	}
	else
	{
	strcpy(add->store,"address.csv");                                        //output file is not present means create the file
	}
    add->file = fopen(add->store,"a+");
}

