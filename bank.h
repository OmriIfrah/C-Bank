/*
  HW3

  Created by Dor David & Omri Ifrah on 20/12/2019.
  Copyright © 2019 Dor David & Omri Ifrah. All rights reserved.
*/

#ifndef bank_h
#define bank_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


bank getBank(void);
void printInorder(clientTree* client);
void clientNumberOfBank(bank *bank);
double averageNumberOfAccountsInBranches(branchTree* branchTree, int *numOfNodes);
int clientNumberWithGivenBalance(clientTree* clientTree, double balace, int *cntBalance);
int clientNumberWithBiggerLoansThanBalance(clientTree* clientTree, int *cntBalance);

#endif /* bank_h */
