#ifndef MAIN_H
#define MAIN_H


typedef enum
{
	a_sucess,
	a_failure,
}Status;
typedef struct _address
{
	 char name[20];
	 char ph[13];
	 char email[50];
	 FILE *file;
	 char store[10];
}address;

Status add_contact(address *);
Status read_and_validate(char *[],address *);


#endif
