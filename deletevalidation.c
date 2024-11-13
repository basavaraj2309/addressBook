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
#include"contact.h"


void deletename(AddressBook *addressBook) //it is for deletename validation.
{
    char dname[30]; // taking the character str to store the new name.
    int found=0;
    int found1 = 0;
    printf("Enter the name:\n");
    scanf(" %[^\n]",dname); // take the input from the user.
    if(validate_name(dname)) // calling the validation function it return 0 or 1.
    {
	for (int i = 0; i < addressBook->contactCount; i++) // run the loop upto  contactcount.
	{
	    if (strcmp(addressBook->contacts[i].name, dname) == 0) //here compareing the str with the stored name.
	    {
		found++; //taking the count inthe variable name found.
	    }
	}

    }
    if (found==0)
    {
	printf("name not found\n");
	deletename(addressBook);	     // again calling the funtion
    }
    else if(found==1) 
    {
	for(int i=0;i<addressBook->contactCount;i++) // run the loop upto contactcount
	{
	    if(strcmp(addressBook->contacts[i].name,dname)==0) // inside the if condition we doing the compare.
	    {

		found1 = 1;  // it the abovecondition true that found1 become a 1.
		printf("contact deleted successfully: %s\n", dname);

		for (int j = i; j < addressBook->contactCount - 1; j++)
		{
		    addressBook->contacts[j] = addressBook->contacts[j + 1]; // it replace the string it more like delete.
		}
		addressBook->contactCount--; // decrementing the count bec we delete the one contact.
		break;
	    }
	}
    }
    else if(found>1) // it is for more then one contact.
    {

	printf("Multi-contact found\n");
	deletephone(addressBook); // calling function.

    }


    /*
       for (int i = 0; i < addressBook->contactCount; i++) 
       {
       if (strcmp(addressBook->contacts[i].name, dname) == 0) 
       {
       found1 = 1;
       printf("contact deleted successfully: %s\n", dname);

       for (int j = i; j < addressBook->contactCount - 1; j++) 
       {
       addressBook->contacts[j] = addressBook->contacts[j + 1];
       }
       addressBook->contactCount--;  
       break;
       }
       }

       if (!found1) 
       {
       printf("Details not found for the name: %s\n", dname);
    // deleteContact(AddressBook *addressBook);
    }
     */
}
void deletephone(AddressBook *addressBook)  // this for delete phone number
{
    char dphone[30];
    int found = 0;
    printf("Enter the phone:\n");
    scanf(" %[^\n]",dphone);
    for (int i = 0; i < addressBook->contactCount; i++)  // run a loop upto address count.
    {
	if (strcmp(addressBook->contacts[i].phone, dphone) == 0) // checking the condition of strcmp. 
	{
	    found = 1;
	    printf("contact deleted successfully:\n %s\n", dphone);

	    for (int j = i; j < addressBook->contactCount - 1; j++) 
	    {
		addressBook->contacts[j] = addressBook->contacts[j + 1]; // replace is happening here.
	    }
	    addressBook->contactCount--; // decrement the count.  
	    break;
	}
    }

    if (!found) 
    {
	printf("phone not found:\n %s\n", dphone); // if the number is not found in the list this will execute.
						   // deleteContact(AddressBook *addressBook);
    }
}
void deleteemail(AddressBook *addressBook) // this for edite email,validatio.
{
    char demail[50];
    int found = 0;
    printf("Enter the email:\n");
    scanf(" %[^\n]",demail); // take input from uder.
    for (int i = 0; i < addressBook->contactCount; i++) // run the loop based on count. 
    {
	if (strcmp(addressBook->contacts[i].email, demail) == 0) 
	{
	    found = 1;
	    printf("contact deleted successfully :\n %s\n", demail);

	    for (int j = i; j < addressBook->contactCount - 1; j++) 
	    {
		addressBook->contacts[j] = addressBook->contacts[j + 1];
	    }
	    addressBook->contactCount--;  // decreass the count value.
	    break;
	}
    }

    if (!found) 
    {
	printf("email not found:\n %s\n", demail); // it print if condition is true.
						   //  deleteContact(AddressBook *addressBook);
    }
}
