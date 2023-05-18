#ifndef FLIGHT_H
#define FLIGHT_H

#define MAX_STR_LEN 128

int generate_reference_number();
void generate_flight_ticket(char fullname[], char destination[]);
typedef struct
{
    char destination[MAX_STR_LEN];
} flight;


#endif