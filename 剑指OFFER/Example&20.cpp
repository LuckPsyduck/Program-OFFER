// DeleteNodeInList.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛
#include<iostream>
#include"List.h"

void DeleteDuplication(ListNode **pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;
	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;
		if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
			needDelete = true;
		if (!needDelete)
		{
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else
		{
			int value = pNode->m_nValue;
			ListNode* pToBeDel = pNode;
			while (pToBeDel != nullptr && pToBeDel->m_nValue == value)
			{
				pNext = pToBeDel->m_pNext;
				delete pToBeDel;
				pToBeDel = nullptr;

				pToBeDel = pNext;
			}
			if (pPreNode == nullptr)
				*pHead = pNext;
			else
				pPreNode->m_pNext = pNext;
			pNode = pNext;
		}
	}
}
// ====================测试代码====================
void Test(ListNode* pListHead)
{
	printf("The original list is: \n");
	PrintList(pListHead);

	DeleteDuplication(&pListHead);

	printf("The result list is: \n");
	PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}


void Test2()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(5);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
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

	Test(pNode1);

	DestroyList(pNode1);
}

// 链表为空
void Test5()
{
	Test(NULL);
}

int main(int argc, char* argv[])
{
	Test3();
	Test4();
	Test5();
	Test1();
	Test2();
	return 0;
}

