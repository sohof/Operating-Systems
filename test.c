#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

void addpost(struct medlem *);
void printposts();

void printwelcome(){
    printf("Welcome, what do you want to do: \n");
    printf("Add a Post:   (1)\n");
    printf("Delete a Post:(2)\n");
    printf("Print posts   (3)\n");
    printf("Exit          (4)\n");
}

int main() {
struct medlem * head= NULL;

  int RUN = 1;
  int selection =0;
  do {
     printwelcome();
     scanf("%d", &selection);
     switch (selection) { 

      case 1: 
              addpost(head);
              printf("%p\n",head);
              break; 
      case 2:
              //deletepost();
              break; 
      case 3:
              printposts();
              break; 
      case 4: 
        RUN = 0;
        printf("Bye bye \n");
        break; 
      default: 
      printf("Not valid selection \n");
    }

  } while (RUN);

  return 0;
}

void addpost(struct medlem * head){
  printf("addpost allocating:\n");

 
  if(head == NULL ){
    head = malloc(sizeof(struct medlem));
      if (head == NULL)
        printf("Error allocating:\n");

    printf("Give a nr:\n");
    scanf("%d", &head->nr);
    printf("Give a name:\n");
    scanf("%s", head->namn);
    head->next= NULL;

    printf("Added Head at adress %p:\n",head);

  }
  else if (head != NULL) {

  struct medlem * nymedlem = malloc(sizeof(struct medlem)); 
      if (nymedlem == NULL)
        printf("Error allocating:\n");

    printf("Give a nr:\n");
    scanf("%d", &nymedlem->nr);
    printf("Give a name:\n");
    scanf("%s", nymedlem->namn);
    nymedlem->next= NULL;

    struct medlem * tmphead= head;

    while (tmphead->next != NULL)
         tmphead=tmphead->next;
          
   tmphead->next = nymedlem;

   printf("Added ny medlem:\n");

  }
  else 
    printf("Error allocating memory \n");

}
void printposts()
{
  struct medlem * tmphead= NULL;


  while (tmphead != NULL) {

    printf("Nr is %d\n", tmphead->nr);
    printf("Name is %s\n", tmphead->namn);
    tmphead=tmphead->next; 
    }
  printf("printpost was called\n");



}

