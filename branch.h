/*
  HW3

  Created by Dor David & Omri Ifrah on 20/12/2019.
  Copyright © 2019 Dor David & Omri Ifrah. All rights reserved.
*/

#ifndef branch_h
#define branch_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>




branch getBranch(bank* bank ,int* branchCnt);
branchTree* addNewBranch(branchTree* tree,branch value);
int getBranchNumber(void);
branchTree* findBranch(branchTree* branchHead, int branchNumber);
void printBranch(branch* value);

#endif /* branch_h */
