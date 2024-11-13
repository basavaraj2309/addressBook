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

void editename(AddressBook *addressBook) //edite name validation.
{

    char editname[30];
    char editphone[20]; // taking the 2 char str to store the new nmae and number.
    int found = 0;
    int found1=0;
    printf("Enter the name: \n");
    scanf(" %[^\n]", editname);  // taking the input from the user.
    if(validate_name(editname)) // checking he condition ,calling the function.
    {
	for (int i = 0; i < addressBook->contactCount; i++) // runing the loop based on contact count.
	{ 
	    if (strcmp(addressBook->contacts[i].name, editname) == 0)  // compare the new name and stored name in the struct,using strcmp.
	    {
		found++; // count how many time this conditio get true.
	    }
	}

    }
    if (found==0) // if found ==0 then condition is not getting true .
    {
	printf("name not found\n"); // this msg will display and call the function again.
	editContact(addressBook);    
    }
    else if(found==1) // this like only one time it get true.
    {
a1:
	for(int j=0;j<addressBook->contactCount;j++)
	{
	    if(strcmp(addressBook->contacts[j].name,editname)==0)
	    {
		printf("Enter the new name: ");
		scanf(" %[^\n]", editname); // take the input from the user.
					    //	printf("%s",addressBook->contacts[1].name); 
					    //	printf("%d",j);
		if(validate_name(editname)) // validate the newname.
		{

		    strcpy(addressBook->contacts[j].name,editname); //copy the new name into old name which is store in strct.
		    printf("Edite successfully\n");
		}
		else
		{
		    printf("Invalid name,Re-enter:\n"); // if condition is not true this will execute.
		    goto a1; // it is go to the lable a1.

		}
	    }
	}
    }
    else if(found>1) // it is for more then one time condition is get true.
    {

	printf("Multi-contact found\n Enter the numer :\n");
	char neweditname[40];
	scanf(" %[^\n]",editphone); // taking the number from the user.

	if(validate_phone(editphone)) // validate the number by calling the function.
	{
	    for (int k = 0; k < addressBook->contactCount; k++)
	    {
		if (strcmp(addressBook->contacts[k].phone, editphone) == 0)  // compare the number is present in the strct or not.
		{
		    found1=1;
		    break;
		}
	    }
	    if(found1) // if this get true the below condition will excute
	    {
		//goto a1;
a2:
		for(int j=0;j<addressBook->contactCount;j++)
		{
		    if(strcmp(addressBook->contacts[j].phone,editphone)==0) // compare the new number into struct.
		    {
			printf("Enter the new name: ");
			scanf(" %[^\n]", editname); //take the new name from user.
						    //	printf("%s",addressBook->contacts[1].name);
						    //	printf("%d",j);
			if(validate_name(editname))
			{

			    strcpy(addressBook->contacts[j].name,editname); //copy the name where that number phone found index that name.
			    printf("Edite successfully\n");
			}
			else
			{
			    printf("Invalid name,Re-enter:\n"); // if not this msg will print and go to lable.
			    goto a2;

			}
		    }
		}

	    }
	    else
	    {
		printf("no contact found");
		editContact(addressBook); // calling the function.
	    }
	}

    }
}


void editephone(AddressBook *addressBook) //it is for edite number.
{
c1:
    char editephone[50];
    char new_phone[50];
    int flag=0;
    printf("Enter the phone :\n");
    scanf(" %[^\n]",editephone); 
    if(validate_phone(editephone)) // validate the number.
    {
	for(int i=0;i<addressBook->contactCount;i++)
	{
	    if(strcmp(addressBook->contacts[i].phone,editephone)==0) // compare the new number with the stored name.
	    {
c2:
		printf("Enter the new phone : ");
		scanf(" %[^\n]",new_phone); // if condition is get true ,this will excuteand ask for the new nmber.
		if(validate_phone(new_phone)) // calling the validate function and sending our new number.
		{

		    strcpy(addressBook->contacts[i].phone,new_phone);
		    printf("Edite successfully\n");// if all ok this msg print.
		    flag=1;
		    break;
		}
		else
		{
		    printf("Invalid phone,Re-enter:\n"); //if number is wrong this msg will print.
		    goto c2; // goto lable c2,where it ask new numberagain.

		}
	    }
	}
	if(flag==0)
	{
	    printf("No contact found.\n"); //if print if there is no contact.
	    goto c1;
	}
    }
    else
    {
	printf("Invalid phone,Re-enter.\n");
	goto c1; // it validate the number number is wrong this will print,goto lable c1.
    }
}
void editeemail(AddressBook *addressBook) // edite the email ,validate
{
d1:
    char editeemail[50];
    char new_email[50];
    int flag=0;
    printf("Enter the email :\n");
    scanf(" %[^\n]",editeemail);
    if(validate_email(editeemail)) // validate the email ,by sending the email into validate function.
    {
	for(int i=0;i<addressBook->contactCount;i++)
	{
	    if(strcmp(addressBook->contacts[i].email,editeemail)==0) // compare here to find is present in the stored contact or not.
	    {
d2:
		printf("Enter the new email : "); // if condition is get true this will print this msg.
		scanf(" %[^\n]",new_email);
		if(validate_email(new_email)) // validate the email by calling the validate function.
		{

		    strcpy(addressBook->contacts[i].email,new_email); // copy the new email where our old email found.
		    printf("Edite successfully\n");
		    flag=1;
		    break;
		}
		else
		{
		    printf("Invalid email,Re-enter:\n"); // it is print when there is no email found.
		    goto d2;

		}
	    }
	} 
	// this are for if the contact is found or not and validate part.
	if(flag==0)
	{
	    printf("No contact found.\n");
	    goto d1;
	}
    }
    else
    {
	printf("Invalid email,Re-enter.\n");
	goto d1;
    }
}


