#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 3
#define MAX_FILES_PER_USER 3
#define MAX_FILE_NAME_LENGTH 20
#define MAX_PATH_LENGTH (MAX_FILE_NAME_LENGTH * 2 + 2)
typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
} File;
typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    File files[MAX_FILES_PER_USER];
} UserDirectory;
typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    UserDirectory user_directories[MAX_USERS];
} RootDirectory;
RootDirectory root;
void createRootDirectory() {
    strcpy(root.name, "root");
}
void createUserDirectory(int userIndex, const char* userName) {
    strcpy(root.user_directories[userIndex].name, userName);
}
void createFile(int userIndex, int fileIndex, const char* fileName) {
    strcpy(root.user_directories[userIndex].files[fileIndex].name, fileName);
}
void printDirectoryStructure() {
    printf("Root Directory: %s\n", root.name);
    for (int i = 0; i < MAX_USERS; i++) {
        printf("|-- User Directory: %s\n", root.user_directories[i].name);
        for (int j = 0; j < MAX_FILES_PER_USER; j++) {
            printf("    |-- File: %s\n", root.user_directories[i].files[j].name);
        }
    }
}
int main() {
    createRootDirectory();
    createUserDirectory(0, "user1");
    createUserDirectory(1, "user2");
    createUserDirectory(2, "user3");
    createFile(0, 0, "file1_user1");
    createFile(0, 1, "file2_user1");
    createFile(0, 2, "file3_user1");
    createFile(1, 0, "file1_user2");
    createFile(1, 1, "file2_user2");
    createFile(2, 0, "file1_user3");
    createFile(2, 1, "file2_user3");
    printDirectoryStructure();
    return 0;
}
