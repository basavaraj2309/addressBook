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
#include <stdio.h>
#include "contact.h"
//#include "populate.h"
#include <stdio_ext.h>
#include <stdlib.h>
// here we adding the number of header file to get connect thuse file.
int main()
{
    int choice;
    AddressBook addressBook;
    //    populateAddressBook(&addressBook); 
    initialize(&addressBook); //calling the function.

    do {
	printf("\nAddress Book Menu:\n");
	printf("1. Create contact\n");
	printf("2. Search contact\n");
	printf("3. Edit contact\n");
	printf("4. Delete contact\n");
	printf("5. List all contacts\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	__fpurge(stdin);  // we use for invalid key .
	switch (choice) // here we choose the option forcalling the function. 
	{
	    case 1:
		createContact(&addressBook);
		break;
	    case 2:
		searchContact(&addressBook);
		break;
	    case 3:
		editContact(&addressBook);
		break;
	    case 4:
		deleteContact(&addressBook);
		break;

	    case 5:
		/*  printf("Select sort criteria:\n");
		    printf("1. Sort by name\n");
		    printf("2. Sort by phone\n");
		    printf("3. Sort by email\n");
		    printf("Enter your choice: ");
		    int sortChoice; 
		    scanf("%d", &sortChoice); */
		listContacts(&addressBook);
		break;
	    case 6:
		printf("Saving and Exiting...\n");
		//	loadContactsFromFile(&addressBook);	
		saveContactsToFile(&addressBook);
		break;
	    default: // if we enter the invalid option.
		printf("Invalid choice. Please try again.\n");
	}
    } while (choice != 6);

    return 0;
}
