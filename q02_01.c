// 12S23010 - Tiffani Rumiris Br Butar - Butar
// 12S23024 - Eska Natasia Silaen

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h" 
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
    char input[100];
    int dorm_count = 0;
    int dorm_size = 0;
    struct dorm_t *drm = malloc(dorm_size * sizeof(struct dorm_t));
    int std_count = 0;
    int std_size = 0;
    struct student_t *mhs = malloc(std_size * sizeof(struct student_t));
    char *token;

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        while (1)
        {
            if (input[strlen(input)-1] == '\n' || input[strlen(input) - 1]== '\r')
            {
                input[strlen(input) - 1] = '\0';
            }
            else
            {
                break;
            }
        }
        token = strtok(input, "#");
        if(strcmp(token, "---")== 0)
        {
            break;
        }
        else if (strcmp(token, "dorm-add") == 0)
        {
            dorm_size++;
            drm = realloc(drm, dorm_size * sizeof(struct dorm_t));
            char *name = strtok(NULL, "#");
            unsigned short capacity = atoi(strtok(NULL, "#"));
            enum gender_t gender = atoi(strtok(NULL, "#"));
            drm[dorm_count] = create_dorm(name, capacity, gender);
            dorm_count++;     
        }
        else if (strcmp(token, "dorm-print-all") == 0)
        {
            for (int i = 0; i < dorm_count; i++)
            {
                print_dorm(drm[i]);
            }
        }
        else if (strcmp(token, "dorm-print-all-detail") == 0)
        {
            for (int i = 0; i < dorm_count; i++)
            {
                print_dorm_detail(drm[i]);
            }
        }
        else if (strcmp(token, "student-add") == 0)
        {
            std_size++;
            mhs = realloc(mhs, std_size * sizeof(struct student_t));
            mhs[std_count] = create_student(input);
            std_count++;
        }
        else if (strcmp(token, "student-print-all") == 0)
        {
            for (int i = 0; i < std_count; i++)
            {
                print_student(mhs[i]);
            }
        }
        else if (strcmp(token, "student-print-all-detail") == 0)
        {
            for (int i = 0; i < std_count; i++)
            {
                print_student_detail(mhs[i]);
            }
        }
        else if (strcmp(token, "assign-student") == 0)
        {
            char *nim = strtok(NULL, "#");
            char *asrama = strtok(NULL, "#");
            assign_student(drm, mhs, nim, asrama, std_count, dorm_count, find_id, find_dorm);
        }
        else if (strcmp(token, "move-student") == 0)
        {
            char *nim = strtok(NULL, "#");
            char *asrama = strtok(NULL, "#");
            move_student(drm, mhs, nim, asrama, std_count, dorm_count, find_id, find_dorm);
        }
        else if (strcmp(token, "dorm-empty") == 0)
        {
            char *asrama = strtok(NULL, "#");
            for (int i = 0; i < std_count; i++)
            {
                if (mhs[i].dorm != NULL && strcmp(mhs[i].dorm->name, asrama) == 0)
                {
                    mhs[i].dorm = NULL;
                }
            }
        }
    }
    printf("%s|%s|%s|%s|%s\n", mhs[std_count - 1].id, mhs[std_count - 1].name, mhs[std_count - 1].year, 
        mhs[std_count - 1].gender == GENDER_MALE ? "male" : "female",
        mhs[std_count - 1].dorm == NULL ? "unassigned" : mhs[std_count - 1].dorm->name);
        
    free(mhs);
    free(drm);

    return 0;
}