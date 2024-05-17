#ifndef MAIN_H
#define MAIN_H


typedef enum
{
	a_success,
	a_failure,
}Status;
typedef struct _address
{
	 char name[20];
	 char ph[30];
	 char email[40];
	 FILE *file;
	 int serial;
	 char store[10];
}address;

Status add_contact(address *);
Status read_and_validate(char *[],address *);
Status search_contact(address *);
Status search_in_file(address *,char *);
Status print_search(address *);
#endif
