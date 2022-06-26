#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void copy(char * source, char * destination) {
    FILE * sourceFilePointer = fopen(source, "r");
    FILE * destinationFilePointer = fopen(destination, "w");
    
    if (!sourceFilePointer) {
        perror("Failed to open source file");
        exit(1);
    }
    
    if (!destinationFilePointer) {
        perror("Failed to open destination file");
        exit(1);
    }
    
    int ch;
    
    while ((ch = fgetc(sourceFilePointer)) != EOF) {
        fputc(ch, destinationFilePointer);
    }
    
    fclose(sourceFilePointer);
    fclose(destinationFilePointer);
}

bool checkExistanceOf(char * fileName) {
    FILE * filePointer = fopen(fileName, "r");
    
    if (!filePointer) {
        fclose(filePointer);
        return false;
    }
    else {
        fclose(filePointer);
        return true;
    }
}

void getFileNames() {
    char temp[100];
    char sourceFileName[100];
    char destinationFileName[100];
    
    while (true) {
        printf("Enter the name of source file: ");
        scanf("%s", temp);
        
        if (checkExistanceOf(temp)) {
            strcpy(sourceFileName, temp);
            break;
        }
        else {
            printf("The file does not exist!\n");
            continue;
        }
    }
    
    while (true) {
        printf("Enter the name of destination file: ");
        scanf("%s", temp);
        
        if (strcmp(sourceFileName, temp) == 0) {
            printf("Source and destination should not be the same file.\n");
            continue;
        }
        
        if (!checkExistanceOf(temp)) {
            strcpy(destinationFileName, temp);
            break;
        }
        else {
            printf("The file alreay exist.\n");
            continue;
        }
    }

    copy(sourceFileName, destinationFileName);
}

int main(int argc, const char * argv[]) {
    getFileNames();
    return 0;
}
