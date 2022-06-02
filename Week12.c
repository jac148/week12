#include <stdio.h>
#include <string.h>
#define SIZE 1000

typedef struct STUDENT
{
    char name[50];
    char student_id[50];
    char major[50];
    int age;
    char address[50];
}STUDENT;

int main(void)
{
    STUDENT list[SIZE];

    int answer;
    int i;
    int index = 0; //current person
    while (1)
    {
        printf("1. Search by name 2. Enroll  3. Remove 4. Quit");
        scanf_S("%d", &answer);

        if (answer == 1)
        {
            char name[20];
            printf("Input name for search :  ");
            scanf_s("%s", name);
            for (i = 0; i < index; i++)
            {
                //strcmp == 두 문자열이 같으면 0
                if (strcmp(list[i].name, name) == 0)
                {
                    printf("Searched : %s\n", list[i].name);
                    printf("student_id : %s\n", list[i].student_id);
                    printf("major : %s\n", list[i].major);
                    printf("age : %d\n", list[i].age);
                    printf("address : %s\n", list[i].address);
                    printf("Done.\n");
                }
            }
            printf("Search Complete.\n");
        }
        else if (answer == 2)// Enroll
        {
            if (index > SIZE)
            {
                printf("Student Already FULL\n");
                continue;
            }
            char input_student_id[50];
            printf("Input ID for Enroll :  ");
            scanf_s("%s", input_student_id);
            for (i = 0; i < index; i++) //check same ID
            {
                //strcmp == 두 문자열이 같으면 0
                if (strcmp(list[i].student_id, input_student_id) == 0)
                {
                    printf("Already Enrolled\n");
                    break;
                }
            }
            if (i == index) //Never show before
            {
                char input_name[50];
                printf("Input name :  ");
                scanf_s("%s", input_name);

                char input_major[50];
                printf("Input major :  ");
                scanf_s("%s", input_major);

                int input_age;
                printf("Input age :  ");
                scanf_s("%d", &input_age);

                char input_address[50];
                printf("Input address :  ");
                scanf_s("%s", input_address);
                //string copy
                strcpy(list[index].name, input_name);
                strcpy(list[index].student_id, input_student_id);
                strcpy(list[index].major, input_major);
                list[index].age = input_age;
                strcpy(list[index].address, input_address);

                index++;
                printf("Enroll Complete.\n");
            }

        }
        else if (answer == 3)// Remove
        {
            char input_student_id[50];
            printf("Input ID for Remove :  ");
            scanf_s("%s", input_student_id);

            for (i = 0; i < index; i++)
                if (strcmp(list[i].student_id, input_student_id) == 0)
                    for (int j = i; j < index - 1; j++) list[j] = list[j + 1];

            index--;                                // 인원 수 줄이기
        }
        else if (answer == 4)// Search All
        {
            printf("Quit \n");
            break;
        }
    }
}

