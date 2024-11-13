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

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"contact.h"

// It is for searchvalidation name,number,email.
void namevalidate(AddressBook *addressBook)
{
    char searchname[30];
    char searchphone[20];
    int found = 0;
    printf("Enter the name: \n");
    scanf(" %[^\n]", searchname);
    if(validate_name(searchname)) //validate the name is good or bad.
    {
	for (int i = 0; i < addressBook->contactCount; i++) // run loop based on count.
	{
	    if (strcmp(addressBook->contacts[i].name, searchname) == 0) //compare the name with stored contact. 
	    {

		found++; // taking the count .
	    }
	}

    }
    else
    {
	printf("Invalid name\n");
        namevalidate(addressBook);
    }
    // based on count all below conditon get excute.
    if (found==0)
    {
	printf("name not found\n");
	searchContact(addressBook); // if ther is no name it again call the function again ask the user for input.	    
    }
    else if(found==1) //if it found one time this will get true.
    {
	for(int j=0;j<addressBook->contactCount;j++)
	{
	    if(strcmp(addressBook->contacts[j].name,searchname)==0) // comapre the name with stored name to find is there or not.
	    {
		printf("Contact found:\nNAME\tPHONE\tE-mail\n"); // if the above condition all true then only it print that conatcat details.
		printf("%s\t%s\t%s\n", addressBook->contacts[j].name,addressBook->contacts[j].phone, addressBook->contacts[j].email);
		break;
	    }
	}
    }
    else if(found>1) // it is for multipal conatact.
    {

	printf("Multi-contact found\n Enter the numer :\n");
	scanf(" %[^\n]",searchphone);
	if(validate_phone(searchphone)) // validate the number.
	{
	    for (int k = 0; k < addressBook->contactCount; k++)
	    {
		if (strcmp(addressBook->contacts[k].phone, searchphone) == 0) // compare it in the stored file to find is there or not. 
		{
		    printf("Contact found:\nNAME\tPHONE\tE-mail\n");
		    printf("%s\t%s\t%s\n", addressBook->contacts[k].name,addressBook->contacts[k].phone, addressBook->contacts[k].email);
		    break;
		}
	    }

	}
	else
	{
	    printf("Invalid number\n");
	}
    }

}
void phonevalidate(AddressBook *addressBook) // it is number validation ,we seen some function calling in above line.
{
    char searchname[30];
    char searchphone[20];
    int found = 0;
    printf("Enter the phone: \n");
    scanf(" %[^\n]", searchphone);
    if(validate_phone(searchphone)) // doing the number validation by calling the function validate function by sending the that number.
    {
	for (int i = 0; i < addressBook->contactCount; i++)
	{
	    if (strcmp(addressBook->contacts[i].phone, searchphone) == 0)  // compare the number inside stored  stored file.
	    {
		found++; // taking the count how many time it get true.
	    }
	}

    }
    else
    {
	printf("Invalid number\n");
	phonevalidate(addressBook);
    }
    if (found==0) // based on the count value if conditon get true or falues.
    {
	printf("number not found\n");
	searchContact(addressBook); // again calling the function.	    
    }
    else if(found==1)
    {
	for(int j=0;j<addressBook->contactCount;j++)
	{
	    if(strcmp(addressBook->contacts[j].phone,searchphone)==0)
	    {
		printf("Contact found:\nNAME\tPHONE\tE-mail\n"); // print the contact if the  above condition all get true. 
		printf("%s\t%s\t%s\n", addressBook->contacts[j].name,addressBook->contacts[j].phone, addressBook->contacts[j].email);
		break;
	    }
	}
    }
    else if(found>1)
    {

	printf("Multi-contact found\n Enter the name :\n");
	scanf(" %[^\n]",searchname);
	if(validate_name(searchname))
	{
	    for (int k = 0; k < addressBook->contactCount; k++)
	    {
		if (strcmp(addressBook->contacts[k].name, searchname) == 0) 
		{
		    printf("Contact found:\nNAME\tPHONE\tE-mail\n");
		    printf("%s\t%s\t%s\n", addressBook->contacts[k].name,addressBook->contacts[k].phone, addressBook->contacts[k].email);
		    break;
		}
	    }

	}
    }

}
void emailvalidate(AddressBook *addressBook) // get the address by using pointer.
{
    char searchemail[30]; // taking a one char str.
    int found = 0;
    printf("Enter the email :\n");
    scanf(" %[^\n]", searchemail); // get the input from the user.
    for (int i = 0; i < addressBook->contactCount; i++) // run the loop upto contactcout.
    {
	if (strcmp(addressBook->contacts[i].email, searchemail) == 0)  // compare the enter email and stored mail.
	{
	    found = 1; // if it good this print that contact details.
	    printf("Contact found:\nNAME\t\tPHONE\t\tE-mail\n");
	    printf("%s\t%s\t%s\n", addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
	    break;
	}
    }
    if (!found) // this condition for contact is found or not.
    {
	printf("email not found\n");
	searchContact(addressBook); // again calling the searchcontact function
    }
}

