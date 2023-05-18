#include "../include/colors.h"
#include "../include/pages.h"
#include "../include/flight.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main_menu_page()
{
    load_employee_data();
    load_user_data();
    bool page_on = true;
    char choice;
    print_main_menu();
    while (page_on)
    {
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '1':
                employee_login_page();
                print_main_menu();
                break;
            case '2':
                user_login_page();
                print_main_menu();
                break;
            case '3':
                page_on = false;
                break;
            default:
                print_red("Invalid Input\n");
                break;
        }
    }
    store_employee_data();
    store_user_records();
}

void print_main_menu()
{
    print_cyan("=== Airplane Booking System ===\n");
    printf("1 - Employee\n");
    printf("2 - User\n");
    printf("3 - Exit\n");
    printf("Enter choice: ");
}

void employee_login_page()
{
    char choice;
    char username[STR_MAX_LENGTH];
    char password[STR_MAX_LENGTH];
    system("cls");
    print_cyan("== Employee Login == \n");
    printf("Username: ");
    fflush(stdin);
    scanf("%s", username);
    printf("Password: ");
    fflush(stdin);
    scanf("%s", password);
    if (!authenticate_employee(username, password))
    {
        system("cls");
        print_red("ACCESS DENIED\n");
        return;
    }
    system("cls");
    print_green("ACCESS GRANTED\n");
    employee_dashboard();
    return;
}

void employee_dashboard()
{
    bool page_on = true;
    char choice;
    while (page_on)
    {
        print_employee_dashboard();
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '1':
                create_user_page();
                break;
            case '2':
                view_all_accounts();
                break;
            case '3':
                print_green("VIEW SPECIFIC ACCOUNTS (in progress)\n");
                break;
            case '4':
                view_account_by_status();
                break;
            case '5':
                print_green("UPDATE ACCOUNT STATUS (in progress)\n");
                break;
            case '6':
                print_green("VIEW FLIGHT DETAILS (in progress)\n");
                break;
            case '7':
                page_on = false;
                break;
            case '8':
                store_employee_data();
                store_user_records();
                exit(0);
            default:
                print_red("Invalid Input\n");
                break;
        }
    }
}

void print_employee_dashboard()
{
    print_cyan("=== Employee Dashboard ===\n");
    printf("1 - Add new account\n");
    printf("2 - View all accounts\n");
    printf("3 - View specific accounts\n");
    printf("4 - View account by status\n");
    printf("5 - Update Account Status\n");
    printf("6 - View flight details by Account\n");
    printf("7 - Back\n");
    printf("8 - Exit\n");
    printf("Enter choice: ");
}

void create_user_page()
{
    char username[STR_MAX_LENGTH];
    char password[STR_MAX_LENGTH];
    system("cls");
    print_cyan("== User Create Account ==\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    if (find_user(username))
    {
        system("cls");
        print_yellow("Username Already Exist\n");
        return;
    }

    create_user(username, password);
    store_user_records();
    print_green("Account Creation Successful\n");
    return;
}

void view_all_accounts()
{
    print_cyan("===== ALL ACCOUNTS =====\n");
    printf("%-15s\t%-15s\n", "Username", "Status");
    for (int i = 0; i < user_count; i++)
    {
        printf(YELLOW);
        printf("%-15s\t%s%-15s%s\n", users[i].username, users[i].is_active ? GREEN: RED, users[i].is_active ? "Active" : "Inactive", RESET);
        printf(RESET);
    }
    return;
}

void view_account_by_status()
{
    print_green("===== ACTIVE ACCOUNTS ===== \n");
    printf("%-15s\t%-15s\n", "Username", "Status");
    for (int i = 0; i < user_count; i++)
    {
        if (users[i].is_active)
        {
            printf(YELLOW);
            printf("%-15s\t%s%-15s%s\n", users[i].username, users[i].is_active ? GREEN: RED, users[i].is_active ? "Active" : "Inactive", RESET);
            printf(RESET);
        }
    }
    print_yellow("===== INACTIVE ACCOUNTS ===== \n");
    printf("%-15s\t%-15s\n", "Username", "Status");
    for (int i = 0; i < user_count; i++)
    {
        if (!users[i].is_active)
        {
            printf(YELLOW);
            printf("%-15s\t%s%-15s%s\n", users[i].username, users[i].is_active ? GREEN: RED, users[i].is_active ? "Active" : "Inactive", RESET);
            printf(RESET);
        }
    }
}

void user_login_page()
{
    char choice;
    char username[STR_MAX_LENGTH];
    char password[STR_MAX_LENGTH];
    system("cls");
    print_cyan("== Customer Login == \n");
    printf("Username: ");
    fflush(stdin);
    scanf("%s", username);
    printf("Password: ");
    fflush(stdin);
    scanf("%s", password);
    if (!authenticate_user(username, password))
    {
        system("cls");
        print_red("ACCESS DENIED\n");
        return;
    }
    system("cls");
    print_green("ACCESS GRANTED\n");
    flight_booking_page();
    return;
}

void flight_booking_page()
{
    char choice; 
    flight user_flight;
    char full_name[STR_MAX_LENGTH];
    print_cyan("=== Flight Booking ===\n");
    printf("Choose the number of your flight destination\n");
    printf("1 - Caticlan\n");
    printf("2 - Boracay\n");
    printf("3 - Aklan\n");
    printf("4 - Exit\n");
    printf("Enter Choice: ");
    fflush(stdin);
    scanf("%c", &choice);
    switch (choice)
    {
        case '1':
            book_flight("Caticlan");
            break;
        case '2':
            book_flight("Boracay");
            break;
        case '3':
            book_flight("Aklan");
            break;
        case '4':
            return;
        default:
            print_red("Invalid Input\n");
    }
}

void book_flight(char dest[])
{
    char full_name[STR_MAX_LENGTH];
    printf("Full name: ");
    fflush(stdin);
    scanf("%s",full_name);
    generate_flight_ticket(full_name, dest);
    print_green("Booking Successful\n");
}