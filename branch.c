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

branch getBranch(bank* bank ,int* branchCnt){

    branch new;
    
    new.bankName = (char*)malloc(strlen(bank->name)+1);

    strcpy(new.bankName, bank->name);
    new.number_of_clients =0;
    new.clients_branch_money=0.0;
    new.net_profit_last_year =0;
    new.active_loans =0;
    if((*branchCnt)+1 > 500){
        printf("ERROR! No place for new branch.");
        exit(0);
    }
    new.branch_ID = (*branchCnt);
    printf("Please enter the name of the branch: \n");
    new.name = getName();

    printf("Please enter when the branch opens(24-hour clock): \n");
    do {
        scanf("%d", &new.open);
        if(new.open > 24 || new.open < 0)
        printf("Wrong Hour! please try again:\n" );
        getchar();
    } while (new.open > 24 || new.open < 0);


    printf("Please enter when the branch is closed(24-hour clock):\n");
    do {
        scanf("%d", &new.close);
        if(new.close > 24 || new.close < 0)
        printf("Wrong Hour! please try again:\n" );
        getchar();
      } while (new.close > 24 || new.close < 0);

    new.branchClientTree=NULL;;


    (*branchCnt)++;
    bank -> number_of_brunch++;

    return new;

}

branchTree* addNewBranch(branchTree* tree,branch value) {
    if (!tree) {
        branchTree* p = (branchTree*) malloc(sizeof(branchTree));
        p->branch = value;
        p->left = p->right = NULL;
        return p;
    }
    if (value.branch_ID > tree->branch.branch_ID) {
        tree->right = addNewBranch(tree->right,value);
    } else {
        tree->left = addNewBranch(tree->right,value);
    }
    return tree;
}

int getBranchNumber(void){
    int branchNumber;
    printf("add New Client: \n");
    do{
        printf("Please enter branch number (1-500): \n");
        scanf("%d", &branchNumber);
        getchar();
    }while (branchNumber>500 || branchNumber<1);
          
    return branchNumber;
}

branchTree* findBranch(branchTree* branchHead, int branchNumber){
  
    /* Base Cases: branchHead is null or key is present at branchHead */
    if (branchHead == NULL || branchHead->branch.branch_ID == branchNumber)
       return branchHead;
     
    /* Key is greater than branchHead's key */
    if (branchHead->branch.branch_ID < branchNumber)
       return findBranch(branchHead->right, branchNumber);
  
    /* Key is smaller than branchHead's key */
    return findBranch(branchHead->left, branchNumber);
}

void printBranch(branch* value){
    printf("Bank name %s\n",value->bankName);
    printf("Branch name %s\n",value->name);
    printf("Branch number %d\n",value->branch_ID);
}
