#ifndef MAIN_H
#define MAIN_H


typedef enum
{
	a_success,
	a_failure,
}Status;
typedef struct _address
{
	 char name[1][20];
	 char ph[5][30];
	 char email[5][40];
	 FILE *file;
	 int sl_no;
	 char store[10];
}address;

Status add_contact(address *);
Status add_space(char *);
Status read_and_validate(char *[],address *);


Status search_contact(address *);
Status search_in_file(address *,char *);
Status print_search(address *);

Status edit_in_file(address *);
Status edit_contact(address *);
Status read_contact(address *); 
Status write_contact(address *);

Status delete_contact(address *);
Status delete_in_file(address *);
Status rewrite_the_data(address *);

Status list_contact(address *);
#endif
