#include "../include/flight.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int generate_reference_number() 
{
    srand(time(NULL));
    
    int referenceNumber = rand() % (9999 - 1000 + 1) + 1000;
    
    return referenceNumber;
}

void generate_flight_ticket(char fullname[], char destination[])
{
    FILE *ticket;

    int ref_num = generate_reference_number();
    char file_path[128];
    sprintf(file_path, "%d", ref_num);
    strcat(file_path, ".txt");

    ticket = fopen(file_path, "w");

    if (ticket == NULL)
    {
        printf("ERROR\n");
        return;
    }

    fprintf(ticket, "===========================\n");
    fprintf(ticket, "           TICKET          \n");
    fprintf(ticket, "===========================\n");
    fprintf(ticket, "Reference Number: %d\n", ref_num);
    fprintf(ticket, "===========================\n");
    fprintf(ticket, "Customer Name: %s\n", fullname);
    fprintf(ticket, "Destination: %s\n", destination);
}