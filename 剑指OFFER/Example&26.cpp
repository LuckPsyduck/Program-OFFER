#include"List.h"

ListNode* ReverseList(ListNode * pHead)
{
	ListNode* pReversedHead = nullptr;
	ListNode* pNode = pHead;
	ListNode* pPrev = nullptr;
	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext;
		//if (pNext == nullptr)
		//	pReversedHead = pNode;

		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	//return pReversedHead;
	return pPrev;
}

//== == == == == == == == == == 测试代码 == == == == == == == == == ==
// 测试要找的结点在链表中间
void Test1()
{
	printf("=====Test1 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result:\n");

	PrintListNode(ReverseList(pNode1));
	PrintList(ReverseList(pNode1));

	DestroyList(pNode1);
}

void Test2()
{
	printf("=====Test3 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);

	printf("expected result: 1.\n");
	PrintListNode(ReverseList(pNode1));
	PrintList(ReverseList(pNode1));

	DestroyList(pNode1);
}

// 测试空链表
void Test3()
{
	printf("=====Test4 starts:=====\n");
	printf("expected result: NULL.\n");

	printf("expected result: 1.\n");
	PrintListNode(ReverseList(nullptr));
	PrintList(ReverseList(nullptr));
}


int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}

