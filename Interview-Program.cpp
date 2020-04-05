
/*2020.03.06*/

/*Tree*/
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode *P)
{
	if(p == NULL)
		return ;

	cout << p->val << endl;
	preOrder(p->left);
	preOrder(p->right);
}

void preoOrder(TreeNode *p)
{
	if(p == NULL)
		return ;
	vector<int> res;
	vector<TreeNode *> vec;
	TreeNode *cur = p;
	while(!res.empty() || !vec.empty())
	{
		if(cur != NULL)
		{
			res.push_back(cur->val);
			vec.push_back(cur->right);
			cur = cur->left;
		}
		else
			cur = vec.pop_back();
	}
	for(const auto &val :res)
		cout << val << " ";
	cout << endl;
}

void inOrder(TreeNode *p)
{
	if(p == NULL)
		return ;

	inOrder(p->left);
	cout << p->val << endl;
	inOrder(p->right);
}

void inOrder(TreeNode *p)
{
	if(p == NULL)
		return ;
	vector<int> res;
	vector<TreeNode *> vec;
	TreeNode *cur = p;
	while(!res.empty() || !vec.empty())
	{
		if(cur != NULL)
		{
			vector.push_back(cur);
			cur = cur->left;
		}
		else
		{	
			TreeNode *tmp = vec.pop_back();
			res.push_back(tmp.val);
			cur = cur->right;
		}
	}
	for(const auto &val :res)
		cout << val << " ";
	cout << endl;
}

void posOrder(TreeNode *p)
{
	if(p == NULL)
		return ;

	posOrder(p->left);
	posOrder(p->right);
	cout << p->val << endl;
}

void posOrder(TreeNode *p)
{
	if(p == NULL)
		return ;
	vector<int> res;
	vector<TreeNode *> vec;
	TreeNode *cur = p;
	while(!res.empty() || !vec.empty())
	{
		if(cur != NULL)
		{
			res.push_back(cur->val);
			vec.push_back(cur->left);
			cur = cur->right;
		}
		else
		{
			cur = cur.pop_back();
		}
	}
	reverse(res.begin(), res.end());
	for(const auto &val :res)
		cout << val << " ";
	cout << endl;	
}

void levelOrder(TreeNode *p)
{
	if(p == NULL)
		return ;

	vector<int> res;
	queue<TreeNode *> que;
	queue.push(p);
	while(!queue.empty())
	{
		TreeNode *tmp = que.front();
		res.push_back(tmp->val);
		que.pop();                   //首元素
		if(tmp->left != NULL)
			que.push(tmp->left);
		if(tmp->right != NULL)
			que.push(tmp->right);
	}
	for(const auto &val :res)
		cout << val << " ";
	cout << endl;		
}

int depthTree(TreeNode *p)
{
	if(p == NULL)
		return 0;

	int left = 0, right = 0;
	left = depthTree(p->left) + 1;
	right = depthTree(p->right) + 1;
	return (left > right) ? left :right;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
	if(preorder.size() == 0 || inorder.size() == 0)
		return ;
	return buile(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}
TreeNode *build(vector<int> preorder, vector<int> inorder, int prel, int prer, int inl, int inr)
{
	if(prel > prer)
		return ;
	int rootval = preorder[prel];
	TreeNode *root = new TreeNode(rootval);
	int index;
	for(int i = 0; i < inorder.size(); i++)
		if(inorder[i] == rootval)
			index = i;
	int numleft = index - inl;
	root->left = build(preorder, inorder, prel + 1, prel + numleft, inl, index - 1);
	root->right = build(preorder,inorder, prel + numleft + 1, prer, index + 1, inr);
	return root;
}

TreeNode* mirrorTree(TreeNode* root)
{
	if(root == NULL)
		return NULL;
	TreeNode *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	mirrorTree(root->left);
	mirrorTree(root->right);
}

bool isSubtree(TreeNode* s, TreeNode* t)
{
	if(s == NULL)
		return false;
	return isSubtree(s->left, t) || SameTree(s, t) || isSubtree(s->right, t);
}
bool SameTree(TreeNode *s, TreeNode *t)
{
	if(s == NULL & t == NULL)
		return true;
	if(s == NULL || t == NULL)
		return false;
	return s->val == t->val && SameTree(s->left, t->left) && SameTree(s->right, t->right);
}

int depthTree(TreeNode *node)
{
	if(node == NULL)
		return 0;
	return max(depthTree(node->left), depthTree(node->right)) + 1;
}
bool isBalanced(TreeNode* root)
{
	if(root == NULL)
		return true;
	int diff = abs(depth(root->left) - depth(root->right));
	return (diff <= 1) && (isBalanced(root->left)) && (isBalanced(root->right));
}

class Solution 
{
public:
	long last = LONG_MIN; // 父节点值
	bool flag = true; // 父亲结点是否大于子节点
	bool isValidBST(TreeNode* root)
	{
		if(!root)
			return true;
		// 遍历左子树
		if(flag && root->left)
			isValidBST(root->left);
		// 当前结点不大于父节点，不是排序二叉树
		if(root->val <= last)
			flag = false;
		last = root->val; // 记录父节点值
		// 遍历右子树
		if(flag && root->right)
			isValidBST(root->right);	
		// 子树都遍历完 或 不是二叉排序树，就退出	
		return flag;
	}
};

/*List*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}

ListNode *sortList(ListNode *head)
{
	if(!head || !head->next)
		return head;
	ListNode *p = head;
	ListNode *q = head->next;
	while(q && q->next)
	{
		p = p->next;
		q = q->next->next;
	}
	ListNode *right = sortList(p->next);
	p->next = NULL;
	ListNode *left = sortList(head);
	return merge(left, right);
}
ListNode *merge(ListNode *left, ListNode *right)
{
	ListNode *dummy = new ListNode(-1);
	ListNode *p = dummy;
	while(left && right)
	{
		if(left->val < right->val)
		{
			p->next = left; 
			left = left->next;
		}
		else
		{
			p->next = right;
			right = right->next;
		}
		p = p->next;
	}
	if(left)
		p->next = left;
	if(right)
		p->next = right;
	return dummy->next;
}

ListNode* reverseList(ListNode* head)
{
	ListNode *pre = NULL, *cur = head;
	while(cur)
	{
		ListNode *tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	return pre;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode *result = new ListNode(-1);
	ListNode *cur = result;
	while(l1 != NULL && l2 != NULL)
	{
		if(l1->val <= l2->val)
		{
			cur->next = l1;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	cur->next = (l1 != NULL) ? l1 : l2;
	return result->next;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if(headA == NULL || headB == NULL)
		return NULL;
	ListNode *curA = headA;
	ListNode *curB = headB;
	while(curA != curB)
	{
		curA = (curA == NULL) ? headB : curA->next;
		curB = (curB == NULL) ? headA : curB->next;
	}
	return curA;
}

class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head) 
	{
		ListNode temp(0);
		temp.next = head;

		ListNode* cur = &temp;
		ListNode *next1;
		ListNode *next2 = cur->next;
		while (cur->next != NULL) 
		{
			next1 = next2;
			next2 = next1->next;
			if (next2 != NULL && next1->val == next2->val) 
			{
				while (next2->next != NULL && next2->val == next2->next->val) 
					next2 = next2->next;
				next2 = next2->next;
				cur->next = next2;
			} 
			else 
				cur = next1;
		}

		return temp.next;
	}
}

int kthToLast(ListNode* head, int k)
{
	int left = head, right = head;
	while(right != NULL)
	{
		right = right.next;
		if(k > 0)
			k--;
		else
			left = left.next;
	}
	return left.val;
}

/*Sort*/
void merge(vector<int> &nums, int start, int mid, int end)
{
	vector<int> tmp;
	int i = start, j = mid + 1;
	while(i <= mid && j <= end)
	{
		if(nums[i] <= nums[j])
			tmp.push_back(nums[i++]);
		else
			tmp.push_back(nums[j++]);
	}
	while(i <= mid)
		tmp.push_back(nums[i++]);
	while(j <= end)
		tmp.push_back(nums[j++]);
	for(int i = 0 ; i < tmp.size(); i++)
		nums[start + i] = tmp[i];
}
void mergeSort(vector<int> &nums, int start, int end)
{
	if(nums.empty() || start >= end)
		return ;
	int mid = (start + end) / 2;
	mergeSort(nums, start, mid);
	mergeSort(nums, mid + 1, end);
	merge(nums, start, mid, end);
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

void quickSort(int nums[], int left, int right)
{
	int low = left, high = right, pivot = nums[left];
	while(low < high)
	{
		while(low < high && pivot <= nums[high])
			high--;
		nums[low] = nums[high];
		while(low < high && povot > nums[low])
			low++;
		nums[high] = nums[low];
	}
	nums[low] = pivot;
	quickSort(nums, left, low - 1);
	quickSort(nums, low + 1, right);
}

void partition(int nums[], int left, int right)
{
	int low = left + 1, high = right, pivot = nums[left];
	while(low <= high)
	{
		while(nums[i] < pivot)
			i++;
		while(nums[j] > pivot)
			j--;
		if(i < j)
			swap(nums[i++]nums[j--]);
		else
			i++;
	}
	swap(nums[high], nums[left]);
	return high;
}
void quickSort(int nums[], int left, int right)
{
	if(left > right)
		return ;
	int j = partition(nums, left, right);
	quickSort(nums, left, j - 1);
	quickSort(nums, j + 1, right);
}

int int findKthLargest(vector<int>& nums, int k)(vector<int>& nums, int k)
{
	return findKthLargest_(nums, 0, nums.size() - 1, k - 1);
}
int findKthLargest_(vector<int> &nums, int left, int right, int k)
{
	if(left == right)
		return nums[left];
	int mid = partition(nums, left, right);
	if(mid == k)
		return nums[mid];
	else if(mid < k)
		return findKthLargest_(nums, left, mid - 1, k);
	else
		return findKthLargest_(nums, mid + 1, right, k);
}
int partition(vector<int> &nums, int left, int right)
{
	int pivot = nums[left];
	while(left < right)
	{
		while(left < right && pivot <= nums[right])
			right--;
		nums[left] = nums[right];
		while(left < right && pivot > nums[low])
			left++;
		nums[right] = nums[left];
	}
	nums[left] = pivot;
	return left;
}

vector<int> smallestK(vector<int>& nums, int k)
{
	int left = 0, right = nums.size() - 1;
	index = partition(nums, left, right);
	while(index != k)
	{
		if(index > k)
			index = partition(nums, left, index - 1);
		else
			index = partition(nums, index + 1, right);
	}
	return vector<int>(nums.begin(), nums.begin() + k);
}

int findMin(vector<int>& nums)
{
	int left = 0, right = nums.size() - 1;
	while(left < right)
		{
			int mid = (left + right) / 2;
			if(nums[mid] < = nums[right])
				right = mid;
			else
				left = mid + 1;
		}//左右相等
	return nums[right];
}

/*Dp*/
int longestCommonSubsequence(string text1, string text2)
{
	int len1 = text1.length();
	int len2 = text2.length();
	vector<vector<int>> dp(len1 + 1, vector<int>(len2, 0));
	for(int i = 1; i < len1 + 1; i++)
		for(int j = 1; j < len2 + 1; j++)
			if(text1[i] == text2[j])
				dp[i][j] = dp[i][j] + 1
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	return dp[len1][len2];
}

int maxSubArray(vector<int> &nums)
{
	itn result = INT_MIN;
	int len = int(nums.size());
	vector<int> dp(len);
	dp[0] = nums[0];
	result = dp[0];
	for(int i = 1; i < len; i++)
	{
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		result = max(dp[i], result);
	}
	return result;
}

int lengthOfLIS(vector<int> &nums)
{
	int len = nums.size();
	vector<int> dp(len, 1);
	int res = 0;
	for(int i = 1; i < len; i++)
	{
		for(int j = 0; j < i; j++)
			if(nums[j] < nums[i])
				dp[i] = max(dp[i], dp[j] + 1);
		res = max(dp[i], res);
	}
	return res;
}

int maxProduct(vector<int> &nums)
{
	if(nums.empty())
		return 0;
	int pos = nums[0], neg = nums[0], res = num[0], tmp;
	for(int i = 1; i < nums.size(); i++)
	{
		tmp = pos;
		pos = max(nums[i], max(pos * nums[i], neg * nums[i]));
		neg = min(nums[i], min(tmp * nums[i], neg * nums[i]));
		res = max(pos, res);
	}
	return res;
}

int minDistance(string word1, string word2)
{
	int len1 = word1.size(), len2 = word2.size();
	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
	for(int i = 0; i <= len1; i++)
		dp[i][0] = i;
	for(int j = 0; j <= len2; j++)
		dp[0][j] = j;
	for(int i = 0; i <= len1; i++)
		for(int j = 0; j <= len2; j++)
		{
			dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (word1[i] == word2[j] ? 0 : 1));
		}
	return dp[len1][len2];
}

int minPathSum(vector<vector<int>>& grid)
{
	int row = grid.size();
	int col = grid[0].size();
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
		{
			if(i == 0 && j == 0)
				continue;
			else if(i == 0)
				grid[i][j] += grid[i][j - 1];
			else if(j == 0)
				grid[i][j] += grid[i - 1][j];
			else
				grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
		}
	return grid[row - 1][col - 1];
}

/*Others*/
class MyQueue
{
public:
	MyQueue() {}
	void push(int x)
	{
		while(!numsb.empty())
		{
			numsa.push(numsb.top());
			numsb.pop();
		}
		numsa.push(x);
	}
	void pop()
	{
		while(!numsa.top())
		{
			numsb.push(numsa.top());
			numsa.pop();
		}
		int tmp = numsb.top();
		numsb.pop();
		return tmp;
	}
	int peek()
	{
		while(!numsa.empty())
		{
			numsb.push(numsa.top());
			numsa.pop();
		}
		return numsb.top();
	}
	bool empty()
	{
		return numsa.empty() && numsb.empty();
	}
private:
	stack<int> numsa;
	stack<int> numsb;
}

class Minstack
{
public:
	Minstack() {}
	void push(int x)
	{
		stack1.push(x);
		if(stack2.empty())
			stack2.push(x);
		else
		{
			int tmp = stack2.top();
			stack2.push((x < tmp) ? x : tmp);
		}
	}
	void pop()
	{
			stack1.pop();
			stack2.pop();
	}
	int top()
	{
		return stack1.top();
	}
	int getMin()
	{
		return stack2.top();
	}
private:
	stack<int> stack1;
	stack<int> stack2;
}

int fib(int n)
{
	int a = 0, b = 1, tmp;
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	for(int i = 2; i <= n; i++)
	{
		tmp = a;
		a = b;
		b = tmp + b;
		if(b > 1000000007)
			b %= 1000000007;
	}
	return b;
}

int hammingWeight(uint32_t n)
{
	int res = 0;
	while(n)
	{
		res++;
		n = n & (n - 1);
	}
	return res;
}

bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
	int len = pushed.size();
	stack<int> stack1;
	int count = 0;
	for(int i = 0; i < len; i++)
	{
		stack1.push(pushed[i]);
		while(!pushed.empty() && count < len && stack1.top() == popped[count])
		{
			stack1.pop();
			count++;
		}
	}
	return count == len;
}

vector<vector<int>> permute(vector<int>& nums)
{

}

int countDigitOne(int n)
{
	int count = 0; 
	for(int i = 1; i <= n; i++)
		while(i != 0)
		{
			if(i % 10 == 1)
				count += 1
			i = i / 10;
		}
	return count;
}

vector<int> twoSum(vector<int>& nums, int target)
{
	if(nums.empty())
		return ;
	vector<int> res;
	int left = 0, right = nums.size() - 1;
	while(left < right)
	{
		int tmp = nums[left] + nums[right];
		if(tmp > target)
			right -= 1;
		else if(tmp < target)
			left += 1;
		else
		{
			res.push_back(left + 1);
			res.push_back(right + 1);
			return res;
		}
	}
	return res;
}