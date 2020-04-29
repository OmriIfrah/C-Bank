

#ifndef main_h
#define main_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define NAME_SIZE 30
#define N 50
#define M pow(10,4)
#define L pow(10,2)



typedef struct bank_t {

    char*  name;
    int    number_of_brunch;
    int    number_of_clients;
    double all_clients_money;
    double net_profit_last_year;
    int    active_loans;

} bank;

typedef struct Client_t {

    char*   first_name;
    char*   last_name;
    int     id;
    char*   bankName;
    int    branch_number;
    int    accuont_number;
    int    max_minus;
    double current_balance;
    double loans_balance;
    double deposits_balance;

} client;

typedef struct tree_c {
    client client; 
    struct tree_c *left, *right;
	
} clientTree;


typedef struct branch_t {

    char*  bankName;
    int    branch_ID;
    char*   name;
    int    number_of_clients;
    double clients_branch_money;
    double net_profit_last_year;
    int    active_loans;
    int    open;
    int    close;
    clientTree* branchClientTree;

} branch;



typedef struct tree_b {
    branch branch; 
    struct tree_b *left, *right;
	
} branchTree;

typedef struct Node
{
    client data;
    struct Node* next;
}clientNode;


#endif /* main_h */
