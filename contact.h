/*
NAME:Basavaraja BN
DATE:1/10/2024
D:WAP to create a addressbook and store the data in a file.
Sample IP:
To create a contact

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit

Sample OP:
Enter your choice: 1
Enter Name: swamy
Enter Phone (10 digits): 1111111111
Enter Email: swamy@gmail.com
Contact created successfully.


 */

#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100 // here we defineing the size of contacts

typedef struct {  // creating the structer of name,phone & email.
    char name[50];
    char phone[20];
    char email[50];
} Contact;  // give a variable name to that structer 

typedef struct { // again creating the structure.
    Contact contacts[MAX_CONTACTS];
    int contactCount;
    FILE *fptr_file;  //define the file pointer.
} AddressBook;
// here all the function calling prototype.
void createContact(AddressBook *addressBook);
int validate_name(char *str);
int validate_phone(char *str);
int validate_email(char *str); 

void searchContact(AddressBook *addressBook);
void namevalidate(AddressBook *addressBook);
void phonevalidate(AddressBook *addressBook);
void emailvalidate(AddressBook *addressBook);

void editContact(AddressBook *addressBook);
void editename(AddressBook *addressBook);
void editephone(AddressBook *addressBook);
void editeemail(AddressBook *addressBook);

void deleteContact(AddressBook *addressBook);
void deletename(AddressBook *addressBook);
void deletephone(AddressBook *addressBook);
void deleteemail(AddressBook *addressBook);

void listContacts(AddressBook *addressBook);

void initialize(AddressBook *addressBook);

void saveContactsToFile(AddressBook *AddressBook);

void loadContactsFromFile(AddressBook *addressBook);
#endif
