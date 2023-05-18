#ifndef PAGES_H
#define PAGES_H

#define STR_MAX_LENGTH 128
#include "colors.h"
#include "employee.h"
#include "user.h"

void main_menu_page();
void print_main_menu();

void employee_login_page();
void employee_dashboard();
void print_employee_dashboard();
void create_user_page();
void view_all_accounts();
void view_account_by_status();

void user_login_page();
void flight_booking_page();
void book_flight(char dest[]);

#endif