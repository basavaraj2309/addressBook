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
#include<ctype.h>
#include<string.h>
#include"contact.h"

int validate_name(char *str) // this function call for name validate.
{
    int i=0,count=0;
    int len=strlen(str); // get the lenth of the str.
    for(i=0;i<len;i++) //run the loop based on len.
    {
	if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z'|| str[i]==' ') // checking there should be onliy upper case and lower case and space .
	{
	    count++; // taking the count of the true condition.
	}
    }
    if(len==count) // compare of the length and count.
    {
	return 1;
    }
    else
    {
	return 0;
    }
}

int validate_phone(char *str) // it is for number validetion.
{
    int count=0;
    int len=strlen(str); // finding the length.
    if(len==10) // checking the condition.
    {
	for(int i=0;i<len;i++)
	{
	    if(isdigit(str[i])) // checking the condition like only digits.
	    {
		count++; // taking count.
	    }
	}
    }
    if(count==10)
    {
	return 1; // return 1 or 0.
    }
    else
    {
	return 0;
    }
}


int validate_email(char *str) // it is for email validation.
{
    int len=strlen(str);
    int count=0,found=0,flag=0;
    for(int i=0;i<len;i++)
    {
	if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z' || str[i]>='0' && str[i]<='9'|| str[i]=='@' || str[i]=='.')
	{
	    if(str[i]=='@' || str[i] =='.') // using the nested if condition,taking the count of who many @ and . present in the string.
	    {
		count++;
	    }
	    if(str[i]=='@' && str[i+1]!='.') // checking if @ and . is together.
	    {
		flag=1;
	    }
	    if(str[len-1]=='m'&& str[len-2]=='o' && str[len-3]=='c' && str[len-4]=='.') // here we checking that com is together or not.
	    {
		found=1;
	    }
	}
    }
    if(count==2 && found==1 && flag==1) // based on this codtion we return 0 or 1.
    {
	return 1;
    }
    else
    {
	return 0;
    }
}


