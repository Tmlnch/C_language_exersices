#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_SIZE];
    int size;
    int is_active;
} File;

typedef struct {
    File files[MAX_FILES];
    int file_count;
} FileSystem;

void initializeFileSystem(FileSystem *fs) {
    fs->file_count = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        fs->files[i].is_active = 0;
    }
}

void createFile(FileSystem *fs, const char *name) {
    if (fs->file_count >= MAX_FILES) {
        printf("Error: Maximum file limit reached.\n");
        return;
    }
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].is_active && strcmp(fs->files[i].name, name) == 0) {
            printf("Error: File with name '%s' already exists.\n", name);
            return;
        }
    }

    for (int i = 0; i < MAX_FILES; i++) {
        if (!fs->files[i].is_active) {
            strcpy(fs->files[i].name, name);
            fs->files[i].content[0] = '\0';
            fs->files[i].size = 0;
            fs->files[i].is_active = 1;
            fs->file_count++;
            printf("File '%s' created successfully.\n", name);
            return;
        }
    }
}

void writeFile(FileSystem *fs, const char *name, const char *content) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].is_active && strcmp(fs->files[i].name, name) == 0) {
            strncpy(fs->files[i].content, content, MAX_FILE_SIZE - 1);
            fs->files[i].content[MAX_FILE_SIZE - 1] = '\0';
            fs->files[i].size = strlen(content);
            printf("Content written to file '%s'.\n", name);
            return;
        }
    }
    printf("Error: File '%s' not found.\n", name);
}

void readFile(FileSystem *fs, const char *name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].is_active && strcmp(fs->files[i].name, name) == 0) {
            printf("Reading File '%s':\n%s\n", name, fs->files[i].content);
            return;
        }
    }
    printf("Error: File '%s' not found.\n", name);
}

void deleteFile(FileSystem *fs, const char *name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].is_active && strcmp(fs->files[i].name, name) == 0) {
            fs->files[i].is_active = 0;
            fs->file_count--;
            printf("File '%s' deleted successfully.\n", name);
            return;
        }
    }
    printf("Error: File '%s' not found.\n", name);
}

void listFiles(FileSystem *fs) {
    printf("List of Files:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].is_active) {
            printf(" - %s (Size: %d bytes)\n", fs->files[i].name, fs->files[i].size);
        }
    }
    if (fs->file_count == 0) {
        printf("No files found.\n");
    }
}

int main() {
    FileSystem fs;
    initializeFileSystem(&fs);

    int choice;
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_SIZE];

    while (1) {
        printf("\n--- Simple File System ---\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read File\n");
        printf("4. Delete File\n");
        printf("5. List Files\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                fgets(name, MAX_FILE_NAME, stdin);
                name[strcspn(name, "\n")] = '\0'; 
                createFile(&fs, name);
                break;
            case 2:
                printf("Enter file name: ");
                fgets(name, MAX_FILE_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter content to write: ");
                fgets(content, MAX_FILE_SIZE, stdin);
                content[strcspn(content, "\n")] = '\0';
                writeFile(&fs, name, content);
                break;
            case 3:
                printf("Enter file name: ");
                fgets(name, MAX_FILE_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';
                readFile(&fs, name);
                break;
            case 4:
                printf("Enter file name: ");
                fgets(name, MAX_FILE_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';
                deleteFile(&fs, name);
                break;
            case 5:
                listFiles(&fs);
                break;
            case 6:
                printf("Exiting File System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}