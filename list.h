#ifndef LIST_H
#define LIST_H
#include "draw.h"
struct ListNode
{
    struct ListNode *next;
    struct ListNode *prev;
    Shape shape;
};
struct List
{
    struct ListNode *peek;
    struct ListNode *start;
    int size;
};

static struct List *g_List = NULL;

/*
 * 리스트 노드를 할당해주는 함수입니다.
 */
struct ListNode *CreateNode(Shape shape);

/*
 * 리스트 노드를 삭제합니다. 메모리 해제해줍니다.
 */
void DeleteNode(struct ListNode *removeNode);

/*
 * 리스트의 초기 정보를 설정해주는 함수입니다. 초반에 꼭 불러야합니다.
 */
void InitList();

/*
 * Push와 같다고 보시면 됩니다.
 */
void Append(struct ListNode *newNode);

/*
 * 노드의 정보를 반환합니다. 반환된 노드 안에 도형 구조체가 있으니 이를 사용하면 됩니다. 
 */
struct ListNode *Pop();

/*
 * Pop과 같습니다. 노드의 정보를 반환합니다. 반환된 노드 안에 도형 구조체가 있으니 이를 사용하면 됩니다. 
 * 
 * 해당 파라미터를 인덱스로 하여 노드를 반환합니다.
 */
struct ListNode *IndexPop(int index);

/*
 * 리스트 내부의 도형들을 전부 없앱니다.
 */
void ListClear();

#endif