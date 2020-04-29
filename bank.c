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


bank getBank(void){

    bank new ;

    printf("\n >>> Welcome to the new system of the bank! <<<\n\n");

    printf("Please enter the bank's name: \n");

    new.name = getName();
    new.number_of_brunch = 0;
    new.number_of_clients = 0;
    new.all_clients_money = 0.0;
    new.net_profit_last_year = 0.0;
    new.active_loans = 0;

    return new;

}

double averageNumberOfAccountsInBranches(branchTree* branchTree, int *numOfNodes){
  
  int avg_r, avg_l;
  int numOfNodes_r, numOfNodes_l;
  double curr;
  
  
  if(branchTree==NULL){
    *numOfNodes = 0;
      return 0;
  }
  avg_l = averageNumberOfAccountsInBranches(branchTree->left, &numOfNodes_l);
  avg_r = averageNumberOfAccountsInBranches(branchTree->right, &numOfNodes_r);
  
  
  *numOfNodes = 1 + numOfNodes_l + numOfNodes_r;
  curr = ((avg_l*numOfNodes_l)+(avg_r*numOfNodes_r)+(branchTree->branch.number_of_clients));
  
  return  curr/(*numOfNodes);
  
}

void clientNumberOfBank(bank *bank){
 
  printf("%s Bank has %d clients right now!", bank->name, bank->number_of_clients);
  
  return;
  
}

int clientNumberWithGivenBalance(clientTree* clientTree, double balace, int *cntBalance){

      /* Base Cases: clientHead is null or key is present at clientHead */
  if (clientTree == NULL )
    return *cntBalance;
  if(clientTree->client.current_balance >= balace)
          (*cntBalance) ++;
       
      /* Key is greater than clientHead's key */

  clientNumberWithGivenBalance(clientTree->right, balace, cntBalance);
    
      /* Key is smaller than clientHead's key */
  clientNumberWithGivenBalance(clientTree->left, balace, cntBalance);

    return *cntBalance;
}

int clientNumberWithBiggerLoansThanBalance(clientTree* clientTree, int *cntBalance){

      /* Base Cases: clientHead is null or key is present at clientHead */
  if (clientTree == NULL )
    return *cntBalance;
  if(clientTree->client.loans_balance >= clientTree->client.current_balance )
          (*cntBalance) ++;
       
      /* Key is greater than clientHead's key */

  clientNumberWithBiggerLoansThanBalance(clientTree->right,  cntBalance);
    
      /* Key is smaller than clientHead's key */
  clientNumberWithBiggerLoansThanBalance(clientTree->left, cntBalance);

    return *cntBalance;
}
