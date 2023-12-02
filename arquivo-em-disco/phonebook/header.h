typedef struct contact_data
{
    char name[100];
    char email[50];
    long int number;
} contact_data;

void read_data(contact_data contact[]);
