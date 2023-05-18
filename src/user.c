#include "../include/user.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

int user_count = 0;
user users[MAX_USER];

void create_user(char username[], char password[])
{
    if (find_user(username))
    {
        printf("Username Already Exists\n");
        return;
    }

    if (user_count >= MAX_USER)
    {
        printf("ERROR: Maxed User Reached\n");
        return;
    }
    strcpy(users[user_count].username, username);
    strcpy(users[user_count].password, password);
    users[user_count].is_active = false;
    user_count++;
}

bool find_user(char username[])
{
    for (int i = 0; i < user_count; i++)
    {
        if (strcasecmp(users[i].username, username) == 0)
        {
            return true;
        }
    }
    return false;
}

void store_user_records()
{
    FILE *file;

    file = fopen(USER_DATA_PATH, "w");

    if (file == NULL)
    {
        return;
    }

    for (int i = 0; i < user_count; i++)
    {
        fprintf(file, "%s\n", users[i].username);
        fprintf(file, "%s\n", users[i].password);
    }

    fclose(file);
}

void load_user_data()
{
    FILE *file;

    file = fopen(USER_DATA_PATH, "r");

    if (file == NULL)
    {
        printf("ERROR: Loading employee data");
        return;
    }

    char buffer[BUFFER_SIZE];
    int line = 0;
    while(fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (line % 2 == 0)
        {
            strcpy(users[user_count].username, buffer);
        }
        if (line % 2 == 1)
        {
            strcpy(users[user_count].password, buffer);
            user_count++;
        }
        line++;
    }
    fclose(file);
}

bool authenticate_user(char username[], char password[])
{
    for (int i = 0; i < user_count; i++)
    {
        if (strcasecmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            return true;
        }
    }
    return false;
}