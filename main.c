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

int main(){

    int branchCnt = 1, clientCnt = 1, i, id;
    int cnt, option, branchNumber = 0, numOfNodes = 0;
    double balance = 0.0;
    
    bank bank;
    branch branchValue;
    client clientValue;
    branchTree *branchHead = NULL, *currect_branch = NULL;
    clientTree *currect_client = NULL;
    clientNode *tmpClient = NULL, *clientHead = NULL;
  
    bank = getBank();
      printf("\n >>> Wellcome to %s Bank! <<<", bank.name);
    
    while(1) {

    display_options();

      scanf("%d",&option);
      switch(option){

        case 1:
                    
            printf("Add new branch: \n");
            getchar();
            
            branchValue=getBranch(&bank,&branchCnt);
            branchHead=addNewBranch(branchHead, branchValue);
          
            printf("New branch(%d) successfully created!\n", branchValue.branch_ID);

        break;
          
        case 2:
                    
            branchNumber = getBranchNumber();
            currect_branch = findBranch(branchHead,branchNumber);
            
                if(currect_branch==NULL){
                  printf("Error! Branch not found!\n");
                  break;
                }
          
            clientValue=getClient(&bank,currect_branch,&clientCnt);
            currect_branch->branch.branchClientTree=
                      addNewClientToBranch(currect_branch->branch.branchClientTree, clientValue);
          
            printf("New client(%d) in branch %d successfully created!\n", clientValue.accuont_number, clientValue.branch_number);

        break;
                 
        case 3:
                    
                printf("Deposit money to client:\n");
                depositMoneyToClientAccount(&bank,&branchHead);
          
        break;
                
        case 4:
                printf("Loan money to client:\n");
                loanToClient(&bank,&branchHead);
          
        break;
                 
        case 5:
                clientNumberOfBank(&bank);
        break;
                
        case 6:
                
                cnt=0;
                
                printf("Please enter balance:\n");
                scanf("%lf", &balance);
            
                for(i=1; i<= branchCnt ;i++){
                  
                    currect_branch = findBranch(branchHead,i);
                      if(currect_branch==NULL){ break; }
                  
                  currect_client = currect_branch->branch.branchClientTree;
                  clientNumberWithGivenBalance(currect_client, balance, &cnt);
                }
          
                printf("Number of the most richest in the bank is: %d. \n", cnt);
                    
        break;
                
        case 7:
                cnt=0;

                printf("Please enter branch number :\n");
                scanf("%d", &branchNumber);
          
                currect_branch = findBranch(branchHead, branchNumber);
                if(currect_branch==NULL){
                  printf("Branch not found!");
                  break;
                }
                
                clientNumberWithBiggerLoansThanBalance(currect_branch->branch.branchClientTree, &cnt);
                printf("Branch has %d clients with a higher loan balance then current balance.\n", cnt);
        break;

        case 8:
                cnt=0;
          
                printf("Search for the client by ID:\n ");
                printf("Enter ID:\n");
                scanf("%d", &id);
                      
                for(i=1; i<= branchCnt ;i++){
                    currect_branch = findBranch(branchHead,i);
                      if(currect_branch==NULL){ break; }
                
                    currect_client = findClientID(currect_branch->branch.branchClientTree, id);
                      if(currect_client!=NULL){
                          printf("Client found! his name is %s %s.", currect_client->client.first_name, currect_client->client.last_name);
                          break;
                      }
                }
          
                if(currect_client==NULL){
                  printf("Not found clients!");
                }

        break;
          
        case 9:
                    
            clientHead = NULL;
            
            printf("Search for the client by current balance:\n ");
            scanf("%lf", &balance);

             for(i=1; i<= branchCnt ;i++){
                 currect_branch = findBranch(branchHead,i);
               if(currect_branch==NULL){ break; }
               do{
                  currect_client = findClientBalance(currect_branch->branch.branchClientTree, balance);
                  if(currect_client!=NULL){
                   tmpClient = newNode(currect_client->client);
                   sortedInsert(&clientHead, tmpClient);
                  }
               } while (currect_client);
                 
               }
               if(clientHead==NULL){
                 printf("Not found clients!");
               }
        break;
                
        case 10:
                numOfNodes = 0;
                printf("The average clients per branchs is: %g.\n", averageNumberOfAccountsInBranches(branchHead, &numOfNodes));
        break;
                
        case 11:
                
                printf("Enter branch number:\n");
                scanf("%d", &branchNumber);
                
                currect_branch = findBranch(branchHead, branchNumber);
                if(currect_branch==NULL){
                  printf("Branch not found!");
                   break;
               }
                printf("-------------------------------------------\n");
                printInorder(currect_branch->branch.branchClientTree);
                printf("-------------------------------------------\n");

        break;

        case 0:
                printf("Thanks for choosing our bank software!\n HAVE A GOOD DAY!\n");
    
        break;
          
        default:
        break;
            }
      
      }
  
    return 0;
}
