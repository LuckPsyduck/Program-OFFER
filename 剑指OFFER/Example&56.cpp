#include"List.h"
#include<stdio.h>

unsigned int GetListLength(ListNode *pHead)
{
	unsigned int nlength = 0;
	ListNode *pNode = pHead;
	while (pNode != nullptr)
	{
		++nlength;
		pNode = pNode->m_pNext;
	}
	return nlength;
}

ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	unsigned int nlength1 = GetListLength(pHead1);
	unsigned int nlength2 = GetListLength(pHead2);
	int nlengthDif = nlength1 - nlength2;

	ListNode* pListHeadLong = pHead1;
	ListNode* pListHeadShort = pHead2;

	if (nlength2 > nlength1)
	{
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		nlengthDif = nlength2 - nlength1;
	}

	for (int i = 0; i < nlengthDif; i++)
		pListHeadLong = pListHeadLong->m_pNext;

	while ((pListHeadLong != nullptr) && (pListHeadShort != nullptr) && (pListHeadLong != pListHeadShort))
	{
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}
	ListNode* pFirstCommonNode = pListHeadLong;

	return pFirstCommonNode;
}

// ====================测试代码====================
void DestroyNode(ListNode* pNode);

void Test(char* testName, ListNode* pHead1, ListNode* pHead2, ListNode* pExpected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	ListNode* pResult = FindFirstCommonNode(pHead1, pHead2);
	if (pResult == pExpected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 第一个公共结点在链表中间
// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode6);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	Test("Test1", pNode1, pNode4, pNode6);

	DestroyNode(pNode1);
	DestroyNode(pNode2);
	DestroyNode(pNode3);
	DestroyNode(pNode4);
	DestroyNode(pNode5);
	DestroyNode(pNode6);
	DestroyNode(pNode7);
}

// 没有公共结点
// 1 - 2 - 3 - 4
//            
// 5 - 6 - 7
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	Test("Test2", pNode1, pNode5, NULL);

	DestroyList(pNode1);
	DestroyList(pNode5);
}

// 公共结点是最后一个结点
// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode7);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	Test("Test3", pNode1, pNode5, pNode7);

	DestroyNode(pNode1);
	DestroyNode(pNode2);
	DestroyNode(pNode3);
	DestroyNode(pNode4);
	DestroyNode(pNode5);
	DestroyNode(pNode6);
	DestroyNode(pNode7);
}

// 公共结点是第一个结点
// 1 - 2 - 3 - 4 - 5
// 两个链表完全重合   
void Test4()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test("Test4", pNode1, pNode1, pNode1);

	DestroyList(pNode1);
}

// 输入的两个链表有一个空链表
void Test5()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test("Test5", NULL, pNode1, NULL);

	DestroyList(pNode1);
}

// 输入的两个链表有一个空链表
void Test6()
{
	Test("Test6", NULL, NULL, NULL);
}

void DestroyNode(ListNode* pNode)
{
	delete pNode;
	pNode = NULL;
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}

