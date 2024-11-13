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
#include <stdlib.h>
#include <string.h>
#include "contact.h"
//#include "populate.h"
int flag=1;
void listContacts(AddressBook *addressBook) // receive the address by using pointer.
{
    int i,a=1;
    printf("SI.NO\tNAME");
    printf("%17s%26s","PHONE","E-mail\n"); // for give a proper space.
    printf("*====*=================*===================*===============================*\n");
    for(int i=0;i<addressBook->contactCount;i++) // runing the loop upto contact count.
    {

	printf("%d\t",a++);
	printf("%-10s",addressBook->contacts[i].name); // printing the name.
	printf("\t%-20s",addressBook->contacts[i].phone); // printing the phone.
	printf("\t%-10s",addressBook->contacts[i].email); // printing the email.

	printf("\n");
    }
    printf("*====*=================*===================*===============================*\n");
    // Sort contacts based on the chosen criteria

}

void initialize(AddressBook *addressBook)
{
    //  addressBook->contactCount = 0;
    //    populateAddressBook(addressBook);

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook); // function calling.
}
void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook);
    // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
a1:
    printf("Enter the name :\n");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    if(!validate_name(addressBook->contacts[addressBook->contactCount].name)) // validateion for the name.
    {
	printf("Invalid name,please Re-enter :\n");
	goto a1;  // it goto the lable a1.
    }
a2:
    printf("Enter Phone number :\n");
    char str_phone[100],flaggg=1; // store the phone number into array.
    scanf(" %s",str_phone);

    if(validate_phone(str_phone)) // validete the number.
    {
	for(int j=0;j<addressBook->contactCount;j++)
	{
	    if(strcmp(addressBook->contacts[j].phone,str_phone)==0) // comper the number that as in the data.cnv file.
	    {
		flaggg=0; // here we make flagg =0.
		printf("It already exit\n");
		goto a2; 
	    }
	}
	if(flaggg) // condition is true then only strcpy get execute. 
	{
	    strcpy(addressBook->contacts[addressBook->contactCount].phone,str_phone); // copy the arr into struct and stored in particular line.
	}
	else
	{
	    printf("This number alreary exit,Re-enter: ");
	    goto a2; // it go to the lable a2.
	}

    }
    //if(!validate_phone(addressBook->contacts[addressBook->contactCount].phone))
    else
    {
	printf("Invalid Number,please Re-enter :\n");
	goto a2;
    }

a3:
    printf("Enter the Email :\n"); // for email validetion.
    scanf(" %s",addressBook->contacts[addressBook->contactCount].email);
    if(!validate_email(addressBook->contacts[addressBook->contactCount].email))
    {
	printf("Invalid email Id,plz try again\n");
	goto a3;
    }
    addressBook->contactCount++; // incrementing the address book count bec we adding the new contact.
    printf("contact added successfully\n");

    /* Define the logic to create a Contacts */

}

void searchContact(AddressBook *addressBook) 
{
    int ch;
    printf("Enter the option.\n1.NAME\n2.PHONE\n3.E-mail\n");
    scanf("%d",&ch); // take the input from the user.


    switch(ch)
    {
	case 1:
	    namevalidate(addressBook);
	    break;
	case 2:
	    phonevalidate(addressBook);
	    break;
	case 3:
	    emailvalidate(addressBook);
	    break;
	default:
	    printf("Invali.\n");
    }


    // Define the logic for search 

}

void editContact(AddressBook *addressBook) // this for edite contact.
{
    int dell;
    printf("Enter the option :\n1.NAME\n2.PHONE\n3.E-mail\n");
    scanf(" %d",&dell);
    switch(dell) // we use switch bec we give a user to like a which one should be edite,inside again calling the another function.
    {
	case 1:
	    editename(addressBook);
	    break;
	case 2:
	    editephone(addressBook);
	    break;
	case 3:
	    editeemail(addressBook);
	    break;
	default:
	    printf("Invalid.\n");
    }



    /* Define the logic for Editcontact */

}

void deleteContact(AddressBook *addressBook) // this for delete contact.
{
    int infi=0;
    printf("Enter the option :\n1.NAME\n2.PHONE\n3.E-mail\n");
    scanf(" %d",&infi);
    switch(infi) //again we give option for delete,again calling the functions,
	{
	    case 1:
		deletename(addressBook);
		break;
	    case 2:
		deletephone(addressBook);
		break;
	    case 3:
		deleteemail(addressBook);
		break;
	    default:
		printf("Invalid.\n");
	}
    //deletename(addressBook);

    // Define the logic for deletecontact 

}

