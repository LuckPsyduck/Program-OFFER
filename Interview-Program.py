"""
2020.03.06
"""

#Tree#
class TreeNode():
	def __init__(self, x):
		self.value = x
		self.left = None
		self.right = None

	def preOrder(self, root):
		stack, res, cur = [], [], root
		while stack or cur:
			if cur:
				res.append(cur.value)
				stack.append(cur.right)
				cur = cur.left
			else:
				cur = stack.pop()
		return res

	def inOrder(self, root):
		stack, res, cur = [], [], root
		while stack or cur:
			if cur:
				stack.append(cur)
				cur = cur.left
			else:
				node = stack.pop()
				res.append(node.value)
				cur = cur.right
		return res

	def posOrder(self, root):
		stack, res, cur = [], [], root
		while stack or cur:
			if cur:
				res.append(cur.value)
				stack.append(cur.left)
				cur = cur.right
			else:
				cur = stack.pop()
		return res[::-1]

	def preOrder(self, root):
		if not root:
			return []
		return [root.value] + self.preOrder(root.left) + self.preOrder(root.right)

	def inOrder(self, root):
		if not root:
			return []
		return self.inOrder(root.left) + [root.value] + self.inOrder(root.right)

	def posOrder(self, root):
		if not root:
			return []
		return self.posOrder(root.left) + self.posOrder(self.right) + [root.value]

	def levelOrder(self, root):
		if not root:
			return 
		queue, res = [], []
		queue.append(root)
		while queue:
			length = len(queue)
			level = []
			for i in range(length):
				node = queue.pop(0)
				level.append(node.value)
				if node.left:
					queue.append(node.left)
				if node.right:
					queue.append(node.right)
			res.append(level)
		return res

	def depthTree(self, root):
		if not root:
			return 0
		left = self.deepthtree(root.left) + 1
		right = self.deepthtree(root.right) + 1
		return max(left, right)

	def buildTree(self, preorder, inorder):
		if not preorder and not inorder:
			return None
		if len(preorder) > 0:
			root = TreeNode(preorder[0])
			index = inorder.index(root.val)
			root.left = self.buildTree(preorder[1: index + 1], inoder[:index])
			root.right = self.buildTree(preorder[index + 1:], inoder[index + 1:])
		return root

	def mirrorTree(self, root):
		if not root:
			return 
		root.left, root.right = root.right, root.left
		self.mirrorTree(root.left)
		self.mirrorTree(root.right)
	return root

	def isSubtree(self, pRoot1, pRoot2):
		result = False
		if pRoot1 != None and pRoot2 != None:
			if pRoot1.val == pRoot2.val:
				result = self.DoesTree1haveTree2(pRoot1, pRoot2)
			if not result:
				result = self.isSubtree(pRoot1.left, pRoot2)
			if not result:
				result = self.isSubtree(pRoot1.right, pRoot2)
		return result    
	def DoesTree1haveTree2(self, pRoot1, pRoot2):
		if pRoot2 == None:
			return True
		if pRoot1 == None:
			return False
		if pRoot1.val != pRoot2.val:
			return False
		return self.DoesTree1haveTree2(pRoot1.left, pRoot2.left) and self.DoesTree1haveTree2(pRoot1.right, pRoot2.right)

	def __init__(self):
		self.flag = True
	def IsBalanced(self, pRoot):
		self.getDepth(pRoot)
		return self.flag
	def getDepth(self, root):
		if not root:
			return 0
		left = self.getDepth(root.left) + 1
		right = self.getDepth(root.right) + 1
		if abs(left - right) > 1:
			self.flag = False  
	return max(left, right)

	def isValidBST(root):
		minnum = -10000000  # 设置一个最小值
		if not root:
			return False
		prenum = minnum  # 存储前一个节点值
		stack = []
		while root or len(stack) > 0:
			# 先找到左子树的最左节点
			if root:
				stack.append(root)
				root = root.left
			else:
				root = stack.pop()
				# 满足当前值大于上一个值，并更新prenum
				if root.val > prenum:
					prenum = root.val
				else:
					return False
				root = root.right
		return True

#List#
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

	def sortList(self, head):
		if head is None or head.next is None:
			return head
		mid = self.get_mid(head)
		left = head
		right = mid.next
		mid.next = None
		return self.merge(self.sortList(left), self.sortList(right))
    def merge(self, list1, list2):
		dummy = ListNode(-1)
		cur = dummy
		while list1 and list2:
			if list1.val < list2.val:
				cur.next = list1
				list1 = list1.next
			else:
				cur.next = list2
				list2 = list2.next
			cur = cur.next
			if list1:
				cur.next = list1
			if list2:
				cur.next = list2
		return dummy.next
	def get_mid(self, node):
		if node is None:
			return node
		fast = slow = node
		while fast.next and fast.next.next:
			slow = slow.next
			fast = fast.next.next
		return slow

	def reverseNode(self, root):
		if not root:
			return 
		cur, res = root, []
		while cur:
			res.insert(0, cur.val)
			cur = cur.next
		return res

	def reverseList(self, head):
		pre, pReversed, cur = None, None, head
		while cur != None:
			tmp = cur.next
			if tmp == None:
				pReversed = cur
			pre.next = tmp
			pre = cur
			cur = tmp
		return pReversed

	def mergeTwoLists(self, head1, head2):
		if head1 == None:
			return head2
		if head2 == None:
			return head1
		newhead = None
		if head1.value < head2.value:
			newhead = head1
			newhead.next = self.fun(head1.next, head2)
		else:
			newhead = head2
			newhead.next = self.fun(head1, head2.next)
		return newhead


	def getIntersectionNode(self, headA, headB):
		len_A, len_B, temp_A, temp_B = 0, 0, headA, headB
		while headA:
			len_A += 1
			headA = headA.next
		while headB:
			len_B += 1
			headB = headB.next
		if len_A > len_B:
			headA = temp_A
			headB = temp_B
			for i in range(len_A - len_B):
				headA = headA.next
			while headA != headB and headA:
				headA = headA.next
				headB = headB.next
		else:
			headA = temp_A
			headB = temp_B
			for i in range(len_B - len_A):
				headB = headB.next
			while headA != headB and headA:
				headA = headA.next
				headB = headB.next
		if not headA:
			return None
		else:
			return headA

	def deleteDuplicates(self, head):
		if head == None or head.next == None:
			return head        
		dummy = ListNode(-1)
		dummy.next = head
		pre = dummy        
		cur = head
		while cur:
			while cur.next and cur.val == cur.next.val:
				cur = cur.next
			if pre.next.val == cur.val:          # 如果只此一个值，不删除，pre后移
				pre = cur
			else:
				pre.next = cur.next      # 如果不只一个，删除这些结点，pre暂不后移
			cur = cur.next
		return dummy.next

	def kthToLast(self, head, k):
		if not head:
			return
		left = head 
		for i in range(k - 1):
			if left.next != None:
				left = left.next
			else:
				return None
		right = head
		while left and left.next:
			left = left.next
			right = right.next
		return right

#Sort#
def merge(left, right):
	lengthl = len(left)
	lengthr = len(right)
	i, j = 0, 0
	res = []
	while i < lenght1 and j < lengthr:
		if left[i] <= right[j]:
			res.append(left[i])
			i += 1
		else:
			res.append(right[j])
			j += 1
		res += [i:]
		res += [j:]
	return res
def mergeSort(nums):
	if len(nums) <= 1:
		return nums
	mid = len(nums) // 2
	left = mergeSort(nums[:mid])
	right = mergeSort(nums[mid:])
	return merge(left, right)

def quickSort(nums, left, right):
	if left >= right:
		return 

	low, high, mid = left, right, nums[left]
	while low < high:
		while low < high and mid <= nums[high]:
			high -= 1
		nums[low] = nums[high]
		while low < high and mid > nums[low]:
			low += 1
		nums[high] = nums[low]
	nums[low] = mid
	quickSort(nums, left, low - 1)
	quickSort(nums. low + 1, right)

def findKthLargest(nums, low, high, k):
	if low >= high:
		return nums[low]
	mid = partition(nums, low, high)
	if mid == k:
		return nums[mid]
	elif k < mid:
		return findKthLargest(nums, low, mid - 1, k)
	else:
		return findKthLargest(nums, mid + 1, high, k)
def partition(nums, low, high):
	pivot = nums[low]
	while low < high:
		while low < high and pivot <= nums[high]:
			high -= 1
		nums[low] = nums[high]
		while low < high and pivot > nums[low]:
			low += 1
		nums[high] = nums[low]
	nums[low] = pivot
	return low

def smallestK(nums, k):
	left, right = 0, len(nums) - 1
	index = partition(nums, left, right)
	while index != k:
		if index > k:
			index = partition(nums, left, index - 1)
		else:
			index = partition(nums, index + 1, right)
	return nums[:k]
def partition(nums, low, high):
	if low >= high:
		return 
	left, right, mid = low, high, nums[low]
	while left < right:
		while left < right and mid <= nums[right]:
			right -= 1
		nums[low] = nums[high]
		while left < right and mid > nums[left]:
			left += 1
		nums[hight] = nums[left]
	nums[left] = mid
	return left

#Dp#
def longestCommonSubsequence(text1, text2):
	n, m = len(text1), len(text2)
	dp = [[0 for i in range(m + 1)] for j in range(n + 1)]
	for i in range(1, n + 1):
		for j in range(1, m + 1):
			if text1[i - 1] == text2[j - 1]:
				dp[i][j] = dp[i - 1][j - 1] + 1
			else:
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
	return dp[n][m]

def maxSeries(nums):
	length = len(nums)
	for i in range(1, length):
		nums[i] = nums[i] + max(nums[i - 1], 0)
	return nums[-1]

def maxSubArray(nums):
	maxtmp, maxsum = 0, 0
	length = len(nums)
	for i in range(length):
		if maxtmp <= 0:
			maxtmp = nums[i]
		else:
			maxtmp += nums[i]
		if maxtmp > maxsum:
			maxsum = maxtmp
	return maxsum

def minDistance(word1, word2):
	len1, len2 = len(word1), len(word2)
	dp = [[0 for i in range(len2 + 1)] for j in range(len1 + 1)]
	for i in range(len1 + 1):
		dp[i][0] = i
	for j in range(len2 + 1):
		dp[0][j] = j
	for i in range(len1 + 1):
		for j in range(len2 + 1):
			if word1[i - 1] == word2[j - 1]:
				cost = 0
			else:
				cost = 1
			dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j  -1] + cost)
	return dp[-1][-1]

def minPathSum(grid):
	row, col = len(grid), len(grid[0])
	for i in range(1, row):
		grid[i][0] += grid[i - 1][0]
	for j in range(1, col):
		grid[0][j] += grid[0][j - 1]
	for i in range(1, row):
		for j in range(1, col):
			 grid[i][j] += min(grid[i][j - 1], grid[i - 1][j])
	return grid[-1][-1]

def lengthOfLIS(nums):
	dp = [1 for i in range(len(nums))]
	res = 0
	for i in range(1, len(nums)):
		for j in range(0, i):
			if(nums[j] < nums[i]):
				dp[i] = max(dp[i], dp[j] + 1)
		res = max(dp[i], res)
	return res

def numIslands(grid):
	if not grid:
		return None
	m = len(grid)
	n = len(grid[0])
	res = 0
	for i in range(m):
		for j in range(n):
			if grid[i][j]:
				res += 1
				inToZero(grid, i, j)
	return res
def inToZero(grid, i, j):
	if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]):
		return 
	if grid[i][j]:
		grid[i][j] = 0
		inToZero(grid, i + 1, j)
		inToZero(grid, i - 1, j)
		inToZero(grid, i, j - 1)
		inToZero(grid, i, j + 1)

#Others#
class MyQueue(object):
	def __init__(self):
		self.stack1 = []
		self.stack2 = []
	def push(self, x):
		self.stack1.append(x)
	def pop(self):
		if not self.stack1:
			return
		if self.stack2:
			return self.stack2.pop()
		else:
			while self.stack1:
				self.stack2.append(self.stack1.pop())
			return self.stack2.pop()

class Minstack(object):
	def __init__(self):
		self.stack = []
		self.minstack = []
	def push(self, x):
		self.stack.append(x)
		if len(self.minstack) == 0:
			self.minstack.append(x)
		else:
			if x < self.minstack[-1]:
				self.minstack.append(x)
			else:
				pass
	def pop(self):
		if self.stack == None or self.minstack == None:
			return None
		self.stack.pop()
		self.minstack.pop()
	def get_min(self):
		return self.minstack[-1]
	def top(self):
		return self.stack[-1]

def arrayTarget(nums, target):
	if not nums:
		return False
	row, col = len(nums), len(nums[0])
	i, j = 0, col - 1
	while i < row and j >= 0:
		if nums[i][j] > target:
			j -= 1
		elif nums[i][j] < target:
			i += 1
		else:
			return True

def fib(n):
	tmp = [0, 1]
	if n >= 2:	
		for i in range(2, n + 1):
			tmp[i % 2] = sum(tmp)
		return tmp[n % 2]

def hammingWeight(n):
	if n < 0:
		n = n & 0xffffffff
	res = 0
	while n:
		res += 1
		n = n & (n - 1)
	return res

def validateStackSequences(pushnums, popnums):
	if pushnums == None or popnums == None:
		return False
	stack = []
	for i in range(len(pushnums)):
		stack.append(pushnums[i])
		while len(stack) and stack[-1] == popnums[0]:
			stack.pop()
			popnums.pop(0)
	if not stack:
		return True
	else:
		return False

def permute(s):
	if len(s) <= 1:
		return [s]
	res = []
	for i in range(len(s)):
		for j in permute(s[0: i] + s[i + 1: ]):
			res.append(s[i] + j)
	return res

def countDigitOne(n):
	res = 0
	for i in range(1, n + 1):
		while i:
			if i % 10 == 1:
				res += 1
			i = i / 10
	return res

def twoSum(self, nums, target):
	if not nums:
		return 
	left, right = 0, len(nums) - 1
	while left < right:
		tmp = nums[left] + nums[right]
		if tmp > target:
			right -= 1
		elif tmp < taget:
			left += 1
		else:
			return [left + 1, right + 1]
	return []

def listYSF(n, m):
	if n < 1 or m < 1:
		return -1
	con = range(n)
	start, end = 0, 0
	while con:
		k = (start + m - 1) % n
		end = con.pop(k)
		n -= 1
		start = k
	return end

def rotate(nums, k):
	length = len(nums)
	nums[:] = nums[length - k:] + nums[:length - k]

def partitionArray(nums):
	if nums is None:
		return None                                 
	left, right = 0, len(nums) - 1
	while left < right:
		if nums[left] % 2 == 0:
			nums[left], nums[right] = nums[right], nums[left]
			right = right - 1
		else:
			left = left + 1
	return nums

def partitionArray(nums):
	if not nums:
		return 
	if len(nums) == 1:
		return nums
	nums = sorted(nums, key = lambda c : c % 2, reversed = True)
	return nums

def maxNum(nums):
	if len(nums) == 1:
		return nums
	for i in range(len(nums) - 1):
		if int(str(nums[i]) + str(nums[i + 1])) > int(str(nums[i + 1] + str(nums[i]))):
			nums[i], nums[i + 1] = nums[i + 1], nums[i]
	return int("".join([s for s in nums]))




