/*
  HW3

  Created by Dor David & Omri Ifrah on 20/12/2019.
  Copyright © 2019 Dor David & Omri Ifrah. All rights reserved.
*/

#include "main.h"
#include "bank.h"
#include "branch.h"
#include "client.h"
#include "globalFunction.h"

int nameCheck(char* str){

    int i;
    unsigned char c;

    for (i=0; i<strlen(str)-1; i++)
    {
        c=str[i];

        if (!isalpha(c))
        {
            return 0;
        }
    }

    return 1;
}

char* getName(void){

    char name[NAME_SIZE];
    char* tmp =NULL;

    do{
        fgets(name, NAME_SIZE, stdin);
      
        if (nameCheck(name)==0)
        {
            printf("Plseas enter only alphabet character(try again):\n");
        }
    }while(nameCheck(name)==0);

    tmp = (char*)malloc(strlen(name)+1);

    strcpy(tmp, name);

    return tmp;

}

void sortedInsert(clientNode** head, clientNode* new)
{
    clientNode* current;
    /* Special case for the head end */
    if (*head == NULL || (*head)->data.id >= new->data.id)
    {
        new->next = *head;
        *head = new;
    } else {
      
        /* Locate the node before the point of insertion */
        current = *head;
        while (current->next!=NULL &&
               current->next->data.id < new->data.id)
        {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
      }
}


void display_options(void){

    printf("\n------------------------------------------------------\n");
    printf("Please enter the option you want:                    |\n");
    printf("------------------------------------------------------\n");
    printf("|1.  Add new branch.                                 |\n");
    printf("|2.  Add new client to branch.                       |\n");
    printf("|3.  Deposite money to client account.               |\n");
    printf("|4.  Loan to client.                                 |\n");
    printf("|5.  The number of clients in the bank.              |\n");
    printf("|6.  Client number with given balance.               |\n");
    printf("|7.  Client number with bigger loans than balance.   |\n");
    printf("|8.  Find client by ID.                              |\n");
    printf("|9.  Find client by Account Balance.                 |\n");
    printf("|10. Average number of clients per branch.           |\n");
    printf("|11. Print Client Accounts Number And Balance.       |\n");
    printf("------------------------------------------------------\n");
    printf("|0. EXIT                                             |\n");
    printf("------------------------------------------------------\n\n");

}


void printInorder(clientTree* client)
{
     if (client == NULL)
          return;
  
     /* first recur on left child */
     printInorder(client->left);
  
     /* then print the data of node */
     printf("|Account Number: %d, current balance: %g|\n ", client->client.accuont_number, client->client.current_balance);
  
     /* now recur on right child */
     printInorder(client->right);
}
