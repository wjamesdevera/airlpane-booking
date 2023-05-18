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