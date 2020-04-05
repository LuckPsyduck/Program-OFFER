#include<iostream>
#include"BinaryTree.h"
using namespace std;

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;
	return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}

// ====================测试代码====================
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      6
//       5 7    7  5
void Test1()
{
	BinaryTreeNode* pNode1= CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, pNode6, pNode7);

	printf("=====Test1: ====\n");
	cout << boolalpha << isSymmetrical(pNode1, pNode1)<< endl;

	DestroyTree(pNode1);
}

//            8
//        6      9
//       5 7    7  5
void Test2()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, pNode6, pNode7);

	//PrintTree(pNode1);

	printf("=====Test2: =====\n");
	cout << boolalpha << isSymmetrical(pNode1, pNode1)<< endl;

	DestroyTree(pNode1);
}

//            7
//        7      7
//       7 7    7  
void Test3()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, pNode6, nullptr);

	//PrintTree(pNode1);

	printf("=====Test3:=====\n");
	cout << boolalpha << isSymmetrical(pNode1, pNode1) << endl;

	DestroyTree(pNode1);
}

// 测试空二叉树：根结点为空指针
void Test4()
{
	BinaryTreeNode* pNode1 = NULL;

	printf("=====Test4: =====\n");
	cout << boolalpha << isSymmetrical(pNode1, pNode1)<< endl;
}

// 测试只有一个结点的二叉树
void Test5()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(8);

	/*PrintTree(pNode1)*/;

	printf("=====Test5: =====\n");
	cout << boolalpha << isSymmetrical(pNode1, pNode1)<< endl;
	DestroyTree(pNode1);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}

