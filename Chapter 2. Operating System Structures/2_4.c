#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool FileExists(char* fileName) // 파일 존재 여부를 체크하는 함수
{
    FILE* filePtr = fopen(fileName, "r");

    if (!filePtr) // 존재하지 않는 경우 false return
    {
        return false;
    }
    return true;
}

void Copy(char* out, char* in) // in 파일 내용을 out 파일로 복사하는 함수
{
    int c;

    FILE* inPtr = fopen(in, "r"); // 읽기 모드로 파일 열기
    FILE* outPtr = fopen(out, "w"); // 쓰기 모드로 파일 열기

    if (!inPtr) // inPtr이 null인 경우 파일 열기 불가, 프로그램 종료
    {
        perror("Source file can't be opened: ");
        exit(1);
    }

    if (!outPtr) // outPtr이 null인 경우 파일 열기 불가, 프로그램 종료
    {
        perror("Destination file can't be opened: ");
        exit(1);
    }

    // inPtr이 파일의 끝에 도달할 때 까지 내용 복사
    while ((c = fgetc(inPtr)) != EOF) 
    {
        fputc(c, outPtr);
    }

    printf("\nSuccess\n"); // 파일 복사를 성공한 경우 Success 출력

    // 파일 닫기
    fclose(inPtr);
    fclose(outPtr);
}

int main()
{
    /*
    사용자로부터 파일 이름 입력 받기
    input 파일명은 이미 존재해야 하며, output 파일명은 존재햐지 않아야 한다.
    파일의 확장명 까지 입력해야 함!
    */
    char str[32], inStr[32], outStr[32];
    char* strPtr = str;
    char* inPtr = inStr;
    char* outPtr = outStr;

    // input 파일 이름 입력 받기
    while (strcmp(inStr, ""))
    {
        printf("Enter name of source file: ");
        scanf("%s", strPtr);

        if (FileExists(strPtr)) // input 파일이 존재하는 경우
        {
            strcpy(inStr, str);
            break;
        }
        else // 존재하지 않는 파일인 경우 경고 출력
        {
            printf("File does not exist. File can't be opened!\n");
            continue;
        }
    }

    // output 파일 이름 입력 받기
    while (strcmp(outStr, ""))
    {
        printf("Enter name of destination file: ");
        scanf("%s", strPtr);

        if (!FileExists(strPtr)) // output 파일이 존재하지 않는 경우
        {
            strcpy(outStr, str);
            break;
        }
        else  // 파일 명이 이미 존재하는 파일인 경우 경고 출력
        {
            printf("File already exists! Please enter a different namme.\n");
            continue;
        }
    }

    Copy(outStr, inStr); // 파일명을 전달해 파일 복사하기

    return EXIT_SUCCESS;
}