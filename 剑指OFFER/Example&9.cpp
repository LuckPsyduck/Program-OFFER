#include"BinaryTree.h"

BinaryTreeNode* GetNext(BinaryTreeNode *pNode)
{
	if (pNode == nullptr)
		return nullptr;
	BinaryTreeNode *pNext = nullptr;
	if (pNode->m_pRight != nullptr)
	{
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr)
			pRight = pRight->m_pLeft;
		pNext = pRight;
	}
	else if (pNode->m_pParent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		while (pParent != nullptr && pCurrent == pParent->m_pRight)
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		pNext = pParent;
	}
	return pNext;
}



int main(int argc, char * argv[])
{
	BinaryTreeNode* p1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* p2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* p3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* p4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* p5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* p6 = CreateBinaryTreeNode(6);
	ConnectTreeNodes(p1, p2, p3);
	ConnectTreeNodes(p2, p4, nullptr);
	ConnectTreeNodes(p3, p5, p6);

	BinaryTreeNode* poutcome =  GetNext(p1);//只能是有下一个结点的
	printf("value: %d\n", poutcome->m_nValue);
	return 0;
}

