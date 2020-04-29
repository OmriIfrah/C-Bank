/*
  HW3

  Created by Dor David & Omri Ifrah on 20/12/2019.
  Copyright © 2019 Dor David & Omri Ifrah. All rights reserved.
*/

#ifndef globalFunction_h
#define globalFunction_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



int nameCheck(char* str);
char* getName(void);
void sortedInsert(clientNode** head, clientNode* new);
void display_options(void);
void printInorder(clientTree* client);
#endif /* globalFunction_h */
