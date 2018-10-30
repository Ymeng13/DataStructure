#include <stdio.h>
#include <stdlib.h>

#define NewNode(node,type,len)  do{\
 node  = (type *)malloc(len);\
}while(0);

#define DelNode(node)  do{\
 free(node);\
}while(0);

typedef struct List{
 unsigned int data;
 struct List *next;
}List_t;

struct List* ListAdd(struct List **Cur)
{
	struct List *Member=NULL;
	NewNode(Member,struct List,sizeof(struct List));
	if(Member == NULL) return NULL;
	(*Cur)->next=Member;
	Member->next = NULL;
	*Cur = Member;
	return Member;
}

 struct List *ListFindNode(struct List *head,unsigned int data)
 {
	 struct List *pList = head;
	 while(1)
	 {
		 if(pList->data == data) break;
		 else if(pList->next == NULL) return NULL;
		 else pList = pList->next; 
	 }
	 return pList;
 }

unsigned int ListDelNode(struct List *head,struct List **Cur,unsigned int data)
{
	 struct List *pList = head;
	 while(1)
	 {
		 if(pList->next == NULL) return 0;
		 else if(pList->next->data == data)
		 {
			struct List *pDelNode = pList->next;
			if(pDelNode->next == NULL) //删除的是最后一个节点
			{
				pList->next  = NULL;
				*Cur = pList;
			}
			else
			{
				pList->next = pDelNode->next;
			}
			DelNode(pDelNode);
			break;
		 }
		 else pList = pList->next; 
	 }
	 return 1;
}

struct List *ListInsertNode(struct List *head,struct List **Cur,unsigned int data)
{
	 struct List *pList = head;
	 struct List *InsertMember = NULL;
	 while(1)
	 {
		 if(pList->data == data)
		 {
			NewNode(InsertMember,struct List,sizeof(struct List));
			if(pList->next == NULL) //插入的位置是最后一个节点
			{
				pList->next = InsertMember;
				InsertMember->next=NULL;
				*Cur = InsertMember;
			}
			else
			{
				InsertMember->next = pList->next->next;
				pList->next = InsertMember;	
			}
			
			break;
		 }
		 else if(pList->next == NULL) break;
		 else pList = pList->next; 
	 }
	 return InsertMember;
}


int main(int argc ,char *argv)
{
   unsigned int i=0;
   struct List head ={77,NULL};
   struct List *pCurNode =&head;
   while(1)
   {
	  for(i=0;i<10;i++)
	  {
		  struct List *NewNode = ListAdd( &pCurNode); //在末尾插入节点测试
		  if(NewNode== NULL)
		  {
			   printf("Node%d,Add Fail\n",i);  
		  }
		  NewNode->data = i;
	  }
	  struct List* FindResult = ListFindNode(&head,9); //查找节点测试
	  if(FindResult != NULL)
		  printf("FindResult:%d\n",FindResult->data);
	  struct List* InsertResult = ListInsertNode(&head,&pCurNode,9); //插入节点测试
	  if(InsertResult != NULL)
		InsertResult->data = 77;
	    printf("pCurNode:%d\n",pCurNode->data);
	  //ListDelNode(&head,&pCurNode,9);
	
	  struct List *pList =head.next;
	 while(pList != NULL) 
	 {
		  printf("Node%d:%d\n",i,pList->data);
		  pList = pList->next;
	  } 
	  return 0;	  
   }
    return 0;	 
}















