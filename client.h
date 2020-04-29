/*
  HW3

  Created by Dor David & Omri Ifrah on 20/12/2019.
  Copyright © 2019 Dor David & Omri Ifrah. All rights reserved.
*/

#ifndef client_h
#define client_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



clientTree* findClient(clientTree* clientHead, int accountNumber);
clientNode *newNode(client new);
clientTree* findClientID(clientTree* clientHead, int id);
clientTree* findClientBalance(clientTree* clientHead, double balance);

client getClient(bank* bank,branchTree* branch,int* clientCnt);
clientTree* addNewClientToBranch(clientTree* t,client value);
void printClient(client* value);
void depositMoneyToClientAccount(bank* bank,branchTree **branchListHead);

void loanToClient(bank* bank,branchTree **branchListHead);

#endif /* client_h */
