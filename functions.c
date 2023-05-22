#include "functions.h"
#include"scheduler.h"
#pragma warning(disable : 4996)

char* toLowerCase(char* str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

void clear_screen()
{
    printf("\033[H\033[J");
}

int checkReminders()
{
    int n = 0;
    Exams* exam = NULL;
    int i = 0;
    int nlines = 1;
    int n_exams = 0;
    FILE* fp = fopen("exam.txt", "r");

    // Get number of exams
    while (!feof(fp)) {
        if (fgetc(fp) == '\n')
            nlines++;
    }
    n_exams = nlines / 3;
    exam = (Exams*)malloc(n_exams * sizeof(Exams));

    // Read exams from file
    fseek(fp, 0, SEEK_SET);
    while (i < n_exams) {
        fgets((exam)[i].courseTitle, 100, fp);
        strtok((exam)[i].courseTitle, "\n");
        fscanf(fp, "%d", &(exam)[i].priority);
        fscanf(fp, "%d", &(exam)[i].reminder);
        fscanf(fp, "%d %d %d", &(exam)[i].date[0], &(exam)[i].date[1], &(exam)[i].date[2]);
        fseek(fp, 2, SEEK_CUR);
        i++;
    }

    fclose(fp);

    for (int i = 0; i < n_exams; i++)
    {
        if (exam[i].reminder == 1) n++;
    }
    return n;
}