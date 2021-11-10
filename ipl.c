#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct
typedef struct match
{
  
  int run;
  struct match * next;
}MATCH;

//struct
typedef struct players
{
  char  pname[10];
  char  tname[10];
  MATCH * ptr; 
  struct players * link;
}PLAYERS;

MATCH * create_node(int grun)
{
  MATCH * new_node = (MATCH*)malloc(sizeof(MATCH));
  new_node->run= grun;
  new_node->next = NULL;
  return new_node;
}


MATCH* insert_from_back(MATCH* head,int grun)
{
  MATCH * new_node = create_node(grun);
  if(head != NULL)
  {
    MATCH* dstart = head;
    while (dstart->next!=NULL)
    {
      dstart = dstart->next;
    }
    dstart->next= new_node;
  }
 else
 {
   head = new_node;
 }
return head;
}


void display(MATCH * head)
{
  int i=1;
  MATCH * ddstart = head;
  while (ddstart!= NULL)
  {
    printf("the runs of %d match are : %d \n",i,ddstart->run );
    ddstart = ddstart->next;
    i++;
  }
  
}
//number of matches played by each player



//create node function
PLAYERS * create_node_players(char gpname[10], char gtname[10])
{
 PLAYERS * new_node_players = (PLAYERS * )malloc(sizeof(PLAYERS));
 strcpy(new_node_players->pname , gpname);
 strcpy(new_node_players->tname , gtname);
new_node_players->link = NULL;
MATCH* head = NULL;
int i;
int runval;
/*for ( i = 1; i < 15; i++)
{
  printf("enter the %d match run :",i);
  scanf("%d",&runval);
  head = insert_from_back(head,runval);
}
new_node_players -> ptr = head;
return new_node_players;
}
*/
char ch[5];
int k=0;
for ( i = 1; i < 15; i++)
{
  printf("did he play the %d match ? [yes/no] : ",i);
  scanf("%s",ch);
  if(strcmp(ch,"yes")==0)
  {
    printf("enter the %d match run :",i);
  scanf("%d",&runval);
  head = insert_from_back(head,runval);
  k++;
  }
  else if(strcmp(ch,"no")==0)
  { 
    
    runval = -1;
    head = insert_from_back(head,runval);
  }
}
  new_node_players->ptr = head;
  printf("number of matches played are %d \n",k);
return new_node_players;

}
void MAX(PLAYERS * start, int match_no)
{
  PLAYERS * dstart = start;
  int runstore = -1;
  int runnew;
  PLAYERS * max_ptr = NULL;
  while (dstart != NULL)
  {
    MATCH * head = dstart ->ptr;
    int i =1;
    while (i<(match_no))
    {
      head = head ->next;
      i++;
    }
    runnew = head ->run;
    if (runnew > runstore)
    {
      max_ptr = dstart;
      runstore = runnew;
    }
    dstart = dstart->link;
  }
  printf("maximum runs are : %d\n",runnew);
  printf("the player name is  : %s \n",max_ptr->pname);
  printf("the team name is  : %s \n",max_ptr->tname);
 
}




PLAYERS * insert_from_back_players(PLAYERS * start,char gpname[10],char gtname[10])
{
  PLAYERS * new_node_player = create_node_players(gpname,gtname);
  if(start == NULL) //players ll is empty
  {
    start = new_node_player;
  }
  else
  {
    PLAYERS * dstart = start ;
    while(dstart ->link != NULL)
    {
      dstart = dstart ->link;
    }
    dstart->link = new_node_player;
  }
  return start;
}


//display function 
void display_players(PLAYERS* start)
{
  PLAYERS * dstart = start;
  int i ;
  while(dstart !=NULL)
  {
        
        printf("the player name is %s\n",dstart->pname);
        printf("the team name is %s\n",dstart->tname);
      display(dstart->ptr);
      printf("\n \n");
    dstart = dstart->link;
  }
}

int main()
{
  PLAYERS * start = NULL;
  int no;
  int j;
  int match_no;
  char gpname[10];
  char gtname[10];
  printf("enter the number of players :");
  scanf("%d",&no);
  for ( j = 1; j < (no+1); j++)
  {
    printf("enter the %d player name\n",j);
    scanf("%s",gpname);
    printf("enter the %d team name\n",j);
    scanf("%s",gtname);
   start = insert_from_back_players(start,gpname,gtname);
  }
  display_players(start);
  printf("enter the match number you want : ");
  scanf("%d",&match_no);
  MAX(start,match_no);
  return 0;
}