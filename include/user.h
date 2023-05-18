#ifndef USER_H
#define USER_H

#define STR_LENGTH 128
#define MAX_USER 100
#define BUFFER_SIZE 1024
#define USER_DATA_PATH "./accounts/user_records.txt"

#include <stdbool.h>

void create_user(char username[], char password[]);
bool find_user(char username[]);
void store_user_records();
void load_user_data();
bool authenticate_user(char username[], char password[]);

typedef struct 
{
    char username[STR_LENGTH];
    char password[STR_LENGTH];
    char full_name[STR_LENGTH];
    int age;
    char address[STR_LENGTH];
    char occupation[STR_LENGTH];
    char nationality[STR_LENGTH];
    float height;
    float weight;
    char status[STR_LENGTH];
    bool is_active;
} user;

extern int user_count;
extern user users[MAX_USER];

#endif