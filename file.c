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
#include<string.h>
#include<stdlib.h>
#include "file.h"
#include"contact.h"

void saveContactsToFile(AddressBook *addressBook) 
{

    FILE *fptr_temp = fopen("temp.csv", "w"); // here open the temp.csv file in write mode.
    if (!fptr_temp)
    {
	perror("fopen");
    }

    fprintf(fptr_temp ,"%d\n",addressBook->contactCount); // printing inside the file by using fprintf.
    for (int i = 0; i < addressBook->contactCount; i++)
    {
	fprintf(fptr_temp, "%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
	// here print the prit the already stored contact into fptr_temp.  
    }

    fclose(fptr_temp); //colse the file.
    remove("data.csv"); // here removeing the date.csv bec now the all contact stored in temp file, below we rename the temp into data.csv. 
    rename("temp.csv", "data.csv");

}

void loadContactsFromFile(AddressBook *addressBook)
{
    //  FILE *fptr=fopen("data.csv","r"); // here we open the filein the read mood.
    addressBook->fptr_file = fopen("data.csv","r");
    if(addressBook->fptr_file == NULL)
    {
	perror("fopen");
	printf("error file not open\n");
	return ;
    }
    addressBook->contactCount=0;
    rewind(addressBook->fptr_file);
    fscanf(addressBook->fptr_file,"%d\n",&addressBook->contactCount); // it will scan the file.
    int i; 
    for(i=0;i<addressBook->contactCount;i++) // here runing the loop upto contact count.
    {
	fscanf(addressBook->fptr_file,"%[^,]",addressBook->contacts[i].name); // it make saparet when the there is (,),and take the cureser to 1.
	fseek(addressBook->fptr_file,1,SEEK_CUR);
	fscanf(addressBook->fptr_file,"%[^,]",addressBook->contacts[i].phone);
	fseek(addressBook->fptr_file,1,SEEK_CUR);
	fscanf(addressBook->fptr_file,"%[^\n]",addressBook->contacts[i].email);
	fseek(addressBook->fptr_file,1,SEEK_CUR);

    }
    fclose(addressBook->fptr_file); //close the file.
				    // printf("sucess");
    /*
    // fseek(fptr,403,SEEK_SET);
    Contact per;
    char str[200];
    for (int i = 10; i < 	addressBook->contacts[addressBook->contactCount++ ; i++)
    {
    char *s=strtok(str,",");
    strcpy(per.name,s);
    s=strtok(NULL,",");
    strcpy(per.phone,s);
    s=strtok(NULL,",\n");
    strcpy(per.email,s);

    addressBook->contacts[addressBook->contactCount++] = per;
    }
     */
}
