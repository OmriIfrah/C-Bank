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

clientTree* findClient(clientTree* clientHead, int accountNumber){
  
    /* Base Cases: clientHead is null or key is present at clientHead */
    if (clientHead == NULL || clientHead->client.accuont_number == accountNumber)
       return clientHead;
     
    /* Key is greater than clientHead's key */
    if (clientHead->client.accuont_number< accountNumber)
       return findClient(clientHead->right, accountNumber);
  
    /* Key is smaller than clientHead's key */
    return findClient(clientHead->left, accountNumber);
}

clientNode *newNode(client new){
  
    /* allocate node */
    clientNode* new_node =
        (clientNode*) malloc(sizeof(clientNode));
  
    /* put in the data  */
    new_node->data  = new;
    new_node->next =  NULL;
  
    return new_node;
}

clientTree* findClientID(clientTree* clientHead, int id){
    /* Base Cases: clientHead is null or key is present at clientHead */
    if (clientHead == NULL || clientHead->client.id == id)
       return clientHead;
     
    /* Key is greater than clientHead's key */
    findClientID(clientHead->right, id);
  
    /* Key is smaller than clientHead's key */
     findClientID(clientHead->left, id);
  
  return NULL;
  
}

clientTree* findClientBalance(clientTree* clientHead, double balance)
{
    /* Base Cases: clientHead is null or key is present at clientHead */
    if (clientHead == NULL || clientHead->client.current_balance == balance)
       return clientHead;
     
     findClientBalance(clientHead->right, balance);
     findClientBalance(clientHead->left, balance);
  
  return NULL;
  
}

client getClient(bank* bank,branchTree* branch,int* clientCnt){

    client new;
    new.bankName = (char*)malloc(strlen(bank->name)+1);

    strcpy(new.bankName, bank->name);
    new.current_balance =0.0;
    new.loans_balance = 0.0;
    new.deposits_balance = 0.0;
    new.accuont_number = *clientCnt;
    new.branch_number = branch->branch.branch_ID;


    printf("Hello there, please enter your details: \n");

        printf("Please enter first name: \n");
        getchar();
         new.first_name = getName();

        printf("Please enter last name: \n");
        getchar();
        new.last_name = getName();

        printf("Please enter client ID: \n");
        scanf("%d", &new.id);


    printf("Please enter the client's max minus:\n");
        do{
        scanf("%d", &new.max_minus);
        if(new.max_minus > 200000 ||new.max_minus < 0){
        printf("ERROR! Try again beetwen 0 to 200000:\n");
        getchar();
        }
        } while(new.max_minus > 200000 ||new.max_minus < 0);

        branch->branch.number_of_clients++;
        bank->number_of_clients++;

        (*clientCnt)++;

        return new;

}


clientTree* addNewClientToBranch(clientTree* t,client value) {
    if (!t) {
        clientTree* p = (clientTree*) malloc(sizeof(clientTree));
        p->client = value;
        p->left = p->right = NULL;
        return p;
    }
    if (value.accuont_number > t->client.accuont_number) {
        t->right = addNewClientToBranch(t->right,value);
    } else {
        t->left = addNewClientToBranch(t->right,value);
    }

    return t;
}

void printClient(client* value){
    printf("Bank name %s\n",value->bankName);
    printf("Branch number %d\n",value->branch_number);
    printf("Client ID %d\n",value->id);
    printf("Client account number %d\n",value->accuont_number);
}

void depositMoneyToClientAccount(bank* bank,branchTree **branchListHead){
    
    branchTree *tmpBranch = NULL;
    clientTree *clientHead;
    clientTree *tmpClient = NULL;

    int branchNumber,clientAccNumber;
    double moneyAmount;

    printf("Please Enter Branch Number :\n");

    do{

      scanf("%d",&branchNumber);
        
      if(!findBranch(*branchListHead, branchNumber)){
              printf("Error! branch not found please try again:\n");
        } else {
            tmpBranch = findBranch(*branchListHead, branchNumber);
                break;
          }
        
    } while(!findBranch(*branchListHead, branchNumber));

  clientHead = tmpBranch->branch.branchClientTree;

    printf("Please enter client account number :\n");
    do{
        scanf("%d",&clientAccNumber);
        if (findClient(clientHead, clientAccNumber)==NULL){
            printf("Error! client not found please try again :\n");
        } else {
            tmpClient = findClient(clientHead, clientAccNumber);
            break;
        }
    } while(!findClient(clientHead, clientAccNumber));

    printf("Please enter money amount you want to deposit X million:\n");
    scanf("%lf",&moneyAmount);

    tmpClient->client.current_balance+=moneyAmount;
    tmpBranch->branch.clients_branch_money+=moneyAmount;
    bank->all_clients_money+=moneyAmount;
    printf("Your current balance now is %g! \n", tmpClient->client.current_balance);
  
  return;

}



void loanToClient(bank* bank,branchTree **branchListHead){
    
    branchTree *branchList = (*branchListHead);
    branchTree *tmpBranch = NULL;
    clientTree *clientHead;
    clientTree *tmpClient = NULL;

    int branchNumber,clientAccNumber;
    double moneyAmount;

    printf("Please Enter Branch Number :\n");

    do{
        scanf("%d",&branchNumber);
        if(findBranch(branchList,branchNumber)==NULL) {
            printf("Error! ,Branch Not Found Please try again\n");
        } else {
            tmpBranch = findBranch(branchList,branchNumber);
            break;
         }
    } while(findBranch(branchList,branchNumber)==NULL);

  clientHead = tmpBranch->branch.branchClientTree;

    printf("Please Enter Client Account number :\n");
    scanf("%d",&clientAccNumber);
    do{
        if(findClient(clientHead,clientAccNumber)==NULL)
        {
            printf("Error! ,Client Not Found Please try again :\n");
            scanf("%d",&clientAccNumber);
        }
        else
    {
      tmpClient = findClient(clientHead,clientAccNumber);
            break;
    }
    }while(!findClient(clientHead,clientAccNumber));

  do{
       printf("Please enter money amount you want to loan:\n");
       scanf("%lf",&moneyAmount);
       if(moneyAmount>(tmpClient->client.max_minus) ||moneyAmount < 0)
       printf("Error! input try again:\n");
  } while (moneyAmount>(tmpClient->client.max_minus) ||moneyAmount < 0 );


    tmpClient->client.loans_balance+=moneyAmount;
    tmpBranch->branch.active_loans++;
    bank->active_loans++;
    
    printf("Hey, Your loan balance now is: %g.\n", tmpClient->client.loans_balance);

  return;

}
