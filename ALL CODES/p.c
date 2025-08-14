#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct user
{
	char name[20];
	char files[10][20];
	int numFiles;
};
struct user users;
int numUsers=0;
void createUser(char *name)
{
	struct user new_user;
	strcpy(new_user.name, name);\
	new_user.numFiles=0;
	
	users[numUsers++]=new_user;
	
}
void createfile(char *username, char *name)
{
	int userindex=-1;
	for(int i=0;i<numUsers;i++)
	{
		if(strcmp(users[i].name,username)==0)
		userindex=i;	
	}
	strcpy(user.files[users.numFiles++],name);
	
}