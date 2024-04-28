/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>
//<stdio.h>,<stdlib.h> 라이브러리를 포함시켜 컴파일 전에 소스 확장

/* 필요한 헤더파일 추가 */

// Node 구조체 listNode를 선언함
typedef struct Node {
	int key;	//변수 key를 선언함(값을 저장하기 위해 쓰임)
	struct Node* link;	//다음 값을 가리키는 변수 link를 선언함(포인터 변수)
} listNode;

// Head구조체 headNode를 선언함
typedef struct Head {
	struct Node* first;	//첫번째 값을 가리키는 Node 변수 first 선언함(포인터 변수)
}headNode;


/* 함수 리스트 */
headNode* initialize(headNode* h);  //initialize는 초기에 singly-linked-list를 초기화시키는 명령어
int freeList(headNode* h);

int insertFirst(headNode* h, int key);  //singly-linked-list 앞쪽에 Node 하나를 추가하는 함수
int insertNode(headNode* h, int key);   //하나의 node를 insertion하는 함수
int insertLast(headNode* h, int key);   //singly-linked-list의 마지막에 하나를 추가하는 함수

int deleteFirst(headNode* h);   //맨 처음 Node를 삭제하는 함수
int deleteNode(headNode* h, int key);   //Node 하나를 삭제하는 함수
int deleteLast(headNode* h);    //마지막 Node를 삭제하는 함수
int invertList(headNode* h);    //singly-linked-list를 역순으로 배열하는 함수

void printList(headNode* h);    //현재 singly-linked-list의 상태를 보이는 함수

int main()  // 메인 함수의 시작
{   
	char command;	//command를 선언하여 사용자로부터 명령을 입력받음
	int key;		//key를 선언하여 사용자로부터 값을 입력받음	
	headNode* headnode=NULL;	//headNode 포인터 변수 headNode를 선언하고 0으로 초기화함 (초기화하지 않으면 쓰레기값이 저장됨)
	int count = 0; 	//변수 count를 선언하여 연결 리스트 생성 전까지 다른 명령을 실행하지 못하게 함

	printf("[----- [Lee yesol] [2023070002] -----]\n"); //학번과 이름을 출력함
	// q 또는 Q가 입력되어야 프로그램이 종료됨 

    do{
		//메뉴를 출력힘
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Enter your command = ");   //사용자가 command를 입력하도록 해당 문구를 출력함
		scanf(" %c", &command);	//command 값을 사용자로부터 입력받음

		switch(command) {	//switch문이 command의 값에 따라 실행됨
		case 'z': case 'Z':	//사용자가 입력한 command가 z 또는 Z일 때 (대소문자 구분 X)
			if(count == 0)
			{
				headnode = initialize(headnode);
				count++;
				break;
			}
		case 'p': case 'P':	// 사용자가 입력한 command가 p 또는 P일 때
			if(count == 0)
			{
				printf("Linked-list Initialize first\n"); 
				break;
			}
			else
			{
				printList(headnode);
				break;
			}
		case 'i': case 'I':	//사용자가 입력한 command가 i 또는 I 일 때
			if(count == 0)
			{
				printf("Linked-list Initialize first\n");
				break;
			}
			else
			{
				printf("Your Key = ");
				scanf("%d", &key);
				insertNode(headnode, key);
				break;
			}
		case 'd': case 'D':	//사용자가 입력한 command가 d 또는 D일 때
			if(count == 0)
			{
				printf("Linked-list Initialize first\n");
				break;
			}
			else
			{
				printf("Your Key = ");
				scanf("%d", &key);
				deleteNode(headnode, key);
				break;
			}
		case 'n': case 'N':	//사용자가 입력한 command가 n 또는 N 일 때
			if(count == 0)
			{
				printf("Linked-list Initialize first\n");
				break;
			}
			else
			{
				printf("Your Key = ");
				scanf("%d", &key);
				insertLast(headnode, key);
				break;
			}
		case 'e': case 'E':	// 사용자가 입력한 command가 e 또는 E일 떄
			if(count == 0)
			{
				printf("Linked-list Initialize first\n");
				break;
			}
			else
			{
				deleteLast(headnode);
				break;
			}
		case 'f': case 'F':	//사용자가 입력한 command가 f 또는 F일 때
			if(count == 0)
			{
				printf("Linked-list Initialize first\n");
				break;
			}
			{
				printf("Your Key = ");
				scanf("%d", &key);
				insertFirst(headnode, key);
				break;
			}
		case 't': case 'T':	// 사용자가 입력한 command가 t 또는 T 일 때
			if(count == 0)
			{
				printf("Linked-list Initialize first\n");
				break;
			}
			else
			{
				deleteFirst(headnode);
				break;
			}
		case 'r': case 'R':	// 사용자가 입력한 command가 r 또는 R일 때
			if(count == 0)
			{
				printf("Linked-list Initialize first.\n");
				break;
			}
			else
			{
				invertList(headnode);
				break;
			}
		case 'q': case 'Q':	// 사용자가 입력한 command가 q 또는 Q일 때
			freeList(headnode);
			break;

		default:			//사용자가 위에 정의된 command가 아닌 잘못된 command를 입력했을 때
			printf("\n       !!!!!!  Concentration  !!!!!!     \n");    //해당 경고문을 출력함
			break;
		}

	}while(command != 'q' && command != 'Q');   // Q나 q를 입력할 때까지 위 과정이 반복됨(입력하면 프로그램 종료)

	return 1;	//return 함수를 통해 1을 반환함
}

//연결리스트를 생성 하는 함수
headNode* initialize(headNode* h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(h != NULL)
		freeList(h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode));	
	//headNode 포인터 변수인 temp 선언하고 malloc을 통해 동적으로 할당함

	temp->first = NULL;	// first값을 NULL로 초기화함
	return temp;	// return 함수를 통해 temp 반환
}

//연결리스트를 free해주는 함수
int freeList(headNode* h){
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first;	
	//listNode 포인터 변수 p 선언한 후, first값을 저장함

	listNode* prev = NULL;
	//listNode 포인터 변수 prec을 선언함
	while(p != NULL) {
		//p의 값이 NULL이 될 때까지 이동해
		prev = p;		//prev에 p에 해당하는 값을 저장함
		p = p->link;	//p는 다음 연결리스트로 이동함
		free(prev);		//prev값을 free함
	}
	free(h);	//마지막에 h(헤드 노드)를 free함
	return 0;	//return 함수를 통해 0을 반환함
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));	
	//listNode 포인터 변수 node를 선언 후 동적으로 할당함
	node->key = key;	//node의 key에 사용자가 입력한 key 값을 저장함
	node->link = NULL;	//node의 link에 NUll 값을 저장함

	if (h->first == NULL)
	{   //연결리스트가 비어 있다면
		h->first = node;	//first에 node를 저장함
		return 0;	//return을 통해 0 반환
	}

	listNode* n = h->first;	    
	listNode* trail = h->first; //listNode 포인터 변수 n과 trail을 선언하고 first값을 저장함

	while(n != NULL)	//연결리스트 n이 NULL이 되는 처음부터 끝까지
	{	
		if(n->key >= key) 
		{	//n의 key값이 node의 key값보다 크거나 같다면
			
			if(n == h->first) //n의 값이 first의 값과 같다면
			{	
				h->first = node; 	//first에 node를 저장함
				node->link = n;		//node를 n에 연결함
			} 

			else 	//n의 값이 first의 값과 같지 않다면
			{ /* 중간이거나 마지막인 경우 */
				node->link = n;	//node link를 n으로,
				trail->link = node;	//n의 직전 노드인 trail을 node에 연결함
			}

			return 0;	//return을 통해 0 반환
		}

		//n의 key값이 node의 key 값보다 작다면
		trail = n;		//trail에 n을 저장함
		n = n->link;	//n을 다음 연결 리스트로 이동시킴
	}

	//마지막까지 찾지 못한 겨우 마지막에 삽입함
	trail->link = node;	//trail을 node에 연결시킴
	return 0;	//retrun을 통해 0 반환
}

//연결리스트의 마지막에 노드를 추가하는 함수
int insertLast(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	//listNode 구조체변수 node를 선언하고 malloc을 통해 동적으로 할당함
	node->key = key;	//node의 key에 사용자로가 입력한 key의 값을 저장함
	node->link = NULL;	//node의 link 값에 NULL 값을 저장함

	if (h->first == NULL)	//연결 리스트가 비어 있을 경우
	{
		h->first = node;	//first 값에 node의 값을 저장함
		return 0;	//return을 통해 0 반환
	}

	listNode* n = h->first;	
	//listNode 포인터 변수 n을 선언하고 first 값을 저장함
	while(n->link != NULL) {	//n의 link 값이 NULL이 될 때까지
		n = n->link;	//n을 다음 연결리스트로 이동시킴
	}

	//n의 link가 NULL일 경우
	n->link = node;	//n을 node에 연결함
	return 0;	//return을 통해 0 반환
}

//연결리스트의 맨 처음에 노드를 추가하는 함수
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));	
	//listNode 포인터 변수 node를 선언하고 malloc을 통해 동적으로 할당함
	node->key = key;	//node의 key에 사용자가 입력한 key의 값을 저장함

	node->link = h->first;	//node를 first에 연결함
	h->first = node;	//first에 node 값을 저장함

	return 0;	// retrun을 통해 0 반환
}

//사용자가 입력한 key의 값을 삭제하는 함수
int deleteNode(headNode* h, int key) {

	if (h->first == NULL)	//연결리스트가 비어 있을 경우
	{
		printf(">>> Nothing to delete. <<<\n");	// 해당 오류 메시지를 출력함
		return 0;	//return을 통해 0 반환	
	}

	listNode* n = h->first;
	//listNode 포인터 변수 n을 선언 후 first값을 저장함
	listNode* trail = NULL;
	//listNode 포인터 변수 trail을 선언함

	//key를 기준으로 삽입할 위치 찾음
	while(n != NULL) {	//n 값이 NULL이 될 때까지
		if(n->key == key) {
			
			if(n == h->first) {	//n의 값이 first의 값과 같을 때
				h->first = n->link;	//n을 first에 저장함
			} 
			
			else { //n의 값이 first의 값과 다를 때
				trail->link = n->link;	//trail에 n을 연결함
			}
			free(n);	//n의 메모리 해제함
			return 0;	//return을 통해 0 반환
		}

		trail = n;	//trail에 n 값을 저장함
		n = n->link;	//n을 다음 연결리스트로 이동시킴
	}

	//찾지 못한 경우에
	printf(">>> No node for key = %d\n", key);	// 해당 오류 메시지를 출력함
	return 0;	//return을 통해 0 반환

}

//연결리스트의 마지막 노드를 삭제하는 함수
int deleteLast(headNode* h) {

	if (h->first == NULL)	//연결 리스트가 비어 있을 때
	{
		printf(">>> nothing to delete.<<<\n");	//해당 오류 메세지를 출력함
		return 0;	//return을 통해 0 반환
	}

	listNode* n = h->first;
	//listNode 포인터 변수 n을 선언 후 first의 값을 저장함
	listNode* trail = NULL;
	//listNode 포인터 변수 trail 선언함

	// first node == last node일 때
	if(n->link == NULL) {	//n이 마지막 노드일 경우
		h->first = NULL;	//first에 NULL을 저장함
		free(n);	//n의 메모리 해제함
		return 0;	//return을 통해 0 반환
	}

	//마지막 노드까지 이동함
	while(n->link != NULL) {	//n이 마지막 노드가 될 때까지
		trail = n;	//trail에 n의 값을 저장함
		n = n->link;	//n을 다음 연결리스트로 이동시킴
	}

	//n의 값이 삭제되어 이전 노드가 NULL이 됨
	trail->link = NULL;	//trail을 마지막 노드로 저장함
	free(n);	//n의 메모리를 해제

	return 0;	//return을 통해 0 반환
}

//연결 리스트의 맨 처음 값을 삭제하는 함수
int deleteFirst(headNode* h) {

	if (h->first == NULL)	// 연결 리스트가 비어 있을 경우
	{
		printf(">>> nothing to delete. <<<\n");	//해당 오류 메세지 출력함
		return 0;	//return을 통해 0 반환
	}
	listNode* n = h->first;
	//listNode 포인텨 변수 n을 선언 후 first의 값을 저장함

	h->first = n->link;	//first에 n의 다음 값을 저장함
	free(n);	//n의 메모리를 해제함

	return 0;	//return을 통해 0 반환
}


//연결 리스트의 배열을 역순으로 바꾸는 함수
int invertList(headNode* h) {

	if(h->first == NULL) {	// 연결 리스트가 비어 있을 경우
		printf("There's nothing to invert.\n");	// 해당 오류 메세지 출력
		return 0;	//return을 통해 0 반환
	}
	listNode *n = h->first;
	//listNode 포인터 변수 n을 선언하고 first의 값을 저장함
	listNode *trail = NULL;
	//listNode 포인터 변수 trail을 선언함
	listNode *middle = NULL;
	//listNode 포인터 변수 middle을 선언함

	while(n != NULL){	//n의 값이 NULL이 될 때까지
		trail = middle;	//trail에 middle의 값을 저장하고
		middle = n;		//middle에 n의 값을 저장함
		n = n->link;	//n을 다음 값으로 이동시킴
		middle->link = trail;	//middle을 trail로 연결시킴
	}	//각각의 노드를 역순으로 순회하면서 middle을 trail에 연결시킴

	//n=NULL, middle이 마지막 노드일 경우
	h->first = middle;	//first에 middle 값을 저장함

	return 0;//return을 통해 0 반환
}

//연결리스트를 출력하는 함수
void printList(headNode* h) {
	int i = 0;	
	listNode* p;
	//listNode 포인터 변수 p를 선언함

	printf("\n---print\n"); //해당 문구를 출력함

	if(h == NULL) {	//연결리스트가 비어 있을 경우
		printf("There's nothing to print.\n");	//해당 오류 메세지 출력
		return;	
	}

	p = h->first;	//p에 first 값을 저장함

	while(p != NULL) {	//p = NULL이 될 때까지
		printf("[ [%d]=%d ] ", i, p->key);	//인덱스의 번호와 p에 해당하는 key 값을 출력함
		p = p->link;	//p를 다음 연결리스트로 이동시킴
		i++;	//i의 값을 증가시킴
	}

	//i++를 연산하고 while문을 벗어남. 따라서 i에는 총 노드 개수가 연산되어 저장됨
	printf("  items = %d\n", i);	// 따라서 i, 즉 총 노드의 개수가 출력됨
}