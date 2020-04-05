#include<iostream>
#include"List.h"
using namespace std;

ListNode* MeetingNode(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;

	ListNode* pSlow = pHead->m_pNext;
	if (pSlow == nullptr)
		return nullptr;

	ListNode* pFast = pSlow->m_pNext;
	while (pFast != nullptr && pSlow != nullptr)
	{
		if (pFast == pSlow)
			return pFast;

		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
		if (pFast != nullptr)
			pFast = pFast->m_pNext;
	}
	return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);

	if (meetingNode == nullptr)
		return nullptr;

	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;

	while (pNode1->m_pNext != meetingNode)
	{
		pNode1 = pNode1->m_pNext;
		++nodesInLoop;
	}

	pNode1 = pHead;
	for (int i = 0; i < nodesInLoop; i++)
		pNode1 = pNode1->m_pNext;

	ListNode * pNode2 = pHead;
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}
	return pNode1;
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
	ListNode* pNode6 = CreateListNode(6);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);

	PrintListNode(EntryNodeOfLoop(pNode1));

	DestroyList(pNode1);
}

// 测试要找的结点是链表的尾结点
void Test2()
{
	printf("=====Test2 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode3);

	PrintListNode(EntryNodeOfLoop(pNode1));
	DestroyList(pNode1);
}

// 测试空链表
void Test3()
{
	printf("=====Test4 starts:=====\n");
	printf("expected result: NULL.\n");

	PrintListNode(EntryNodeOfLoop(nullptr));
}



int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}

