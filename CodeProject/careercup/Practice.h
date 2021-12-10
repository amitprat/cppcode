#pragma once
#include "../Header.h"

class Practice {
public:
	Practice() {
		srand(time(nullptr));
	}
	static void test() {
		cout << rand7() << endl;
		cout << numWaysToMakeChange(10, { 2,3,5 }) << endl;
		cout << numWaysToMakeChangeDP(10, { 2,3,5 }) << endl;
		cout << putCommas(1010503) << endl;
		cout << putCommas("1010503") << endl;
		{
			vector<int> input = { 1, 2, 3, 4, 5, 6, 7 };
			reverse(input, 3);
			cout << input << endl;
		}

		cout << reverseBits3(11) << endl;

		cout << multiply(5, 9) << endl;

		//printNumsInLexographicalOrder1(125, 1);

		KMP("ABABDABACDABABCABAB", "ABABCABAB");

		friendSuggestionTest();

		printTasksWithCoolDown({ "A","A","A","B","B","B","A","A" }, 2);
		cout << endl;

		cout << consecutive1s(11, 1) << endl;

		{
			vector<int> num = { 9,9,9 };
			addNum(num, 9, 0);
			cout << to_string(num) << endl;
		}

		{
			string str = "ababab";
			string period;
			int cnt = 0;
			getPeriod(str, period, cnt);
			cout << period << " " << cnt << endl;
		}

		cout << "LCS: " << lcs("abcd", "cdac") << endl;

		cout << "Longest repeating subsequence: " << findRepeatingSubsequence("abab") << endl;

		cout << isRepeat("abcd", "dabcdabc") << endl;

		cancelOutList();

		printLargestSubset();

		printLongestPositiveSequence();

		minimizeProduct();
	}

	struct GraphNode {
		string id;
		unordered_map<string, GraphNode*> friends;

		GraphNode(string id) : id(id) {}

		void addFriend(GraphNode* other) {
			friends[other->id] = other;
		}

		vector<GraphNode*>getFriends() {
			vector<GraphNode*> result;
			for (auto e : friends) result.push_back(e.second);

			return result;
		}
	};

	class Graph {
		unordered_map<string, GraphNode*> peoples;

	public:
		void add(string id) {
			peoples[id] = new GraphNode(id);
		}

		void addFriend(string id1, string id2) {
			if (peoples.find(id1) == peoples.end()) return;
			if (peoples.find(id2) == peoples.end()) return;

			auto first = peoples[id1];
			auto second = peoples[id2];

			first->addFriend(second);
			second->addFriend(first);
		}

		vector<GraphNode*> getFriends(string id) {
			if (peoples.find(id) == peoples.end()) return {};

			return peoples[id]->getFriends();
		}
	};

	static void friendSuggestionTest() {
		Graph g;
		g.add("A");
		g.add("B");
		g.add("C");
		g.add("D");
		g.addFriend("A", "B");
		g.addFriend("B", "C");
		g.addFriend("B", "D");

		// suggest friends for 'A'
		auto friends = g.getFriends("A");
		vector<string> result;
		unordered_map<string, int> freq;
		for (auto f : friends) {
			auto f1 = g.getFriends(f->id);
			for (auto e : f1) if (e->id != "A") freq[e->id]++;
		}
		priority_queue<pair<int, string>> pq;
		for (auto e : freq) pq.push({ e.second,e.first });

		while (!pq.empty()) {
			cout << pq.top().second << " " << pq.top().first << endl;
			pq.pop();
		}
		cout << endl;
	}

	static void printTasksWithCoolDown(vector<string> tasks, int k) {
		int n = tasks.size();
		deque<pair<int, string>> coolDownList;
		unordered_map<string, int> freq;
		for (auto task : tasks) freq[task]++;
		priority_queue<pair<int, string>> pq;
		for (auto e : freq) pq.push({ e.second, e.first });
		pq.push({ 0,"_" });

		int i = 0;
		while (pq.size() > 1 || !coolDownList.empty()) {
			auto f = pq.top();
			if (f.first > 1) coolDownList.push_back(f);
			if (f.second != "_") pq.pop();
			cout << f.second;
			if (i >= k && !coolDownList.empty()) {
				auto x = coolDownList.front();
				if (x.second != "_") pq.push({ x.first - 1,x.second });
				coolDownList.pop_front();
			}

			i++;
		}
	}

	static void KMP(string txt, string pat) {
		vector<int> lps = computeLPS(pat);
		int i = 0, j = 0;
		while (i < txt.length()) {
			if (txt[i] == pat[j]) {
				i++, j++;
			}
			else {
				if (j != 0) j = lps[j - 1];
				else i += 1;
			}
			if (j == pat.length()) {
				cout << "Found at " << i - j << endl;
				j = lps[j - 1];
			}
		}
	}

	static vector<int> computeLPS(string pat) {
		vector<int> lps(pat.length(), 0);
		int len = 0, j = 1;
		while (j < pat.length()) {
			if (pat[j] == pat[len]) {
				len++;
				lps[j] = len;
				j++;
			}
			else {
				if (len != 0) len = lps[len - 1];
				else {
					lps[j] = 0;
					j++;
				}
			}
		}

		return lps;
	}

	static void printNumsInLexographicalOrder(int N, int k)
	{
		if (k > N) { return; }

		for (int i = 0; i < 10; i++)
		{
			if (k <= N)
			{
				cout << k << " ";

				k *= 10;
				printNumsInLexographicalOrder(N, k);
				k /= 10;
				k++;
				if (k % 10 == 0) return;
			}
		}
	}

	static void printNumsInLexographicalOrder1(int N, int k)
	{
		if (k > N) return;

		cout << k << ", ";
		printNumsInLexographicalOrder1(N, k * 10);
		if (k % 10 != 9) printNumsInLexographicalOrder1(N, k + 1);
	}

	static int multiply(int a, int b) {
		int sign = (a ^ b) >> 31;
		a = abs(a);
		b = abs(b);

		int res = 0;
		while (b) {
			if (b & 1) res = sum(res, a);

			a <<= 1;
			b >>= 1;
		}

		return sign ? (~res + 1) : res;
	}

	static int sum(int a, int b) {
		while (b) {
			int carry = (a & b) << 1;
			a = a ^ b;
			b = carry;
		}

		return a;
	}

	static int reverseBits(int n) {
		int rev = 0;
		int offset = 32 - 1;

		for (int i = 0; i <= offset; i++) {
			if (n & (1 << i)) rev |= (1 << (offset - i));
		}

		return rev;
	}

	static int reverseBits2(int n) {
		int rev = 0;
		while (n) {
			rev <<= 1;
			rev |= n & 1;
			n >>= 1;
		}

		return rev;
	}

	static int reverseBits3(int n) {
		int rev = n;
		int cnt = 31;

		n >>= 1;
		while (n) {
			rev <<= 1;
			rev |= n & 1;
			n >>= 1;
			cnt--;
		}

		//rev <<= cnt;

		return rev;
	}

	static void reverse(vector<int>& input, int n) {
		int len = input.size();
		for (int i = 0; i < input.size(); i += n) {
			reverse(input, i, min(i + n - 1, len - 1));
		}
	}

	static void reverse(vector<int>& cur, int l, int r) {
		while (l < r) {
			swap(cur[l++], cur[r--]);
		}
	}

	static string putCommas(string num) {
		if (num.size() < 3) return num;
		auto cur = putCommas(num.substr(0, num.size() - 3));
		return cur + "," + num.substr(num.size() - 3);
	}

	static string putCommas(int num) {
		if (num == 0) return "";
		if (num < 1000) return to_string(num);
		auto cur = putCommas(num / 1000);
		string formatted(5, '\0');
		sprintf_s(const_cast<char*>(formatted.c_str()), 5, ",%03d", num % 1000);
		return cur + formatted;
	}

	static int rand7() {
		int val;
		do {
			val = rand5() * 5 + rand5();
		} while (val >= 21);
		return val % 7 + 1;
	}

	static int rand5() {
		return rand() % 5;
	}

	static int numWaysToMakeChange(int amount, vector<int> coins, int index = 0) {
		if (amount == 0) return 1;
		if (index >= coins.size() || amount < 0) return 0;

		return numWaysToMakeChange(amount, coins, index + 1) + numWaysToMakeChange(amount - coins[index], coins, index);
	}

	static int numWaysToMakeChangeDP(int amount, vector<int> coins) {
		int* dp = new int[amount + 1];
		memset(dp, 0, sizeof(int) * (amount + 1));
		dp[0] = 1;

		for (auto coin : coins) {
			for (int am = coin; am <= amount; am++) {
				dp[am] += dp[am - coin];
			}
		}

		return dp[amount];
	}

	class TernarySearchTree {
	public:
		struct Node {
			char ch;
			Node* left = nullptr;
			Node* right = nullptr;
			Node* eq = nullptr;
			bool end = false;
			Node(char ch) : ch(ch) {}
		};

		Node* root = nullptr;
	};

	static int consecutive1s(int n, int k) {
		int l = 0;
		int zeros = 0;
		int mx = 0;
		for (int i = 0; i < 32; i++) {
			if (!(n & (1 << i))) zeros++;
			while (zeros > k) {
				if (!(n & (1 << i))) zeros--;
				l++;
			}

			mx = max(mx, i - l + 1);
		}

		return mx;
	}

	static int calculateResult(string input) {
		stack<char> st;
		int depth = 0;
		for (auto ch : input) {
			if (ch == ' ' || ch == ', ') continue;
			if (ch == '[') { st.push(ch); depth++; }
			else if (isdigit(ch)) st.push(ch);
			else if (ch == ']') {
				int cur = 0;
				while (!st.empty() && st.top() != ']') {
					cur += st.top(); st.pop();
				}
				st.push(depth * cur);
				depth--;
			}
		}

		return st.top();
	}

	static int addNum(vector<int>& cur, int newVal, int index) {
		if (index >= cur.size()) return newVal;
		int carry = addNum(cur, newVal, index + 1);
		int val = cur[index] + carry;
		cur[index] = val % 10;

		if (index == 0 && val >= 10) {
			cur.insert(cur.begin(), val / 10);
		}

		return val / 10;
	}

	static bool getPeriod(string& str, string& period, int& cnt) {
		int l = str.length();
		for (int i = 1; i <= (l / 2); i++) {
			period = str.substr(0, i);
			int currentCnt = 1;
			int j;
			for (j = i; j <= l; j += i) {
				string cur = str.substr(j, i);
				if (cur != period) break;
				currentCnt++;
			}
			if (j == l) {
				cnt = currentCnt;
				return true;
			}
		}
		return false;
	}

	static int lcs(string s1, string s2) {
		int n = s1.length();
		int m = s2.length();
		vector<vector<int>> memo(n + 1, vector<int>(m + 1));

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 || j == 0) memo[i][j] = 0;
				else {
					memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
					if (s1[i - 1] == s2[j - 1]) {
						memo[i][j] = max(memo[i][j], 1 + memo[i - 1][j - 1]);
					}
				}
			}
		}

		return memo[n][m];
	}

	static string findRepeatingSubsequence(string str) {
		int n = str.length();
		vector<vector<pair<int, string>>> memo(n + 1, vector<pair<int, string>>(n + 1));

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (i == 0 || j == 0) memo[i][j] = { 0,"" };
				else {
					memo[i][j] = memo[i - 1][j];
					if (memo[i][j - 1].first > memo[i][j].first) memo[i][j] = memo[i][j - 1];
					else if (i != j && str[i - 1] == str[j - 1]) {
						if (1 + memo[i - 1][j - 1].first > memo[i][j].first) {
							memo[i][j] = { 1 + memo[i - 1][j - 1].first,memo[i - 1][j - 1].second + str[i - 1] };
						}
					}
				}
			}
		}

		return memo[n][n].second;
	}

	static int isRepeat(string seed, string target) {
		auto tmp = seed;
		auto count = 1;
		for (; tmp.length() < target.length(); count++) {
			tmp += seed;
		}
		if (tmp.find(target) != string::npos) {
			return count;
		}
		tmp += seed;
		if (tmp.find(target) != string::npos) {
			return count + 1;
		}
		return -1;
	}

	/*
	* https://careercup.com/question?id=5717797377146880
		Given some resources in the form of linked list you have to canceled out all the resources whose sum up to 0(Zero) and return the remaining list.

		E.g-->> 6 -6 8 4 -12 9 8 -8

		the above example lists which gets canceled :
		6 -6
		8 4 -12
		8 -8
		o/p : 9
		case 3 : 4 6 -10 8 9 10 -19 10 -18 20 25
		O/P : 20 25
	*/
	static void cancelOutList() {
		LinkedListNode<int>* node = new LinkedListNode<int>(6);
		node->next = new LinkedListNode<int>(-6);
		node->next->next = new LinkedListNode<int>(8);
		node->next->next->next = new LinkedListNode<int>(4);
		node->next->next->next->next = new LinkedListNode<int>(-12);
		node->next->next->next->next->next = new LinkedListNode<int>(9);
		node->next->next->next->next->next->next = new LinkedListNode<int>(8);
		node->next->next->next->next->next->next->next = new LinkedListNode<int>(-8);

		LinkedListNode<int>* prev = nullptr;
		LinkedListNode<int>* newHead = node;
		unordered_set<int> visited;
		stack<LinkedListNode<int>*> st;

		int curSum = 0;
		visited.insert(curSum);

		while (node) {
			curSum += node->val;
			if (visited.find(curSum) == visited.end()) {
				visited.insert(curSum);
				st.push(node);
			}
			else {
				int tmp = curSum - node->val;
				do {
					auto cur = st.top(); st.pop();
					if (tmp != 0) visited.erase(tmp);

					tmp -= cur->val;
				} while (tmp != curSum);
				if (st.empty()) newHead = node->next;
				else st.top()->next = node->next;

				prev = st.empty() ? nullptr : st.top();
			}
			node = node->next;
		}

		cout << to_string(newHead) << endl;
	}

	static void printLargestSubset() {
		vector<int> arr = { 1, 6, 10, 4, 7, 9, 5 };
		unordered_map<int, int> map;
		int beg, end;
		int mxBeg = 0, mxEnd = 0;
		for (auto e : arr) {
			beg = end = e;
			if (map.find(beg - 1) != map.end()) beg = map[beg - 1];
			if (map.find(end + 1) != map.end()) end = map[end + 1];
			map[beg] = end;
			map[end] = beg;
			if (end - beg > mxEnd - mxBeg) {
				mxBeg = beg;
				mxEnd = end;
			}
		}

		for (int i = mxBeg; i <= mxEnd; i++) cout << i << " ";
		cout << endl;
	}

	static void printLongestPositiveSequence() {
		vector<int> arr = { 1,2,-3,2,3,4,-6,1,2,3,4,5,-8,5,6 };

		int startIndex = -1;
		int mxStartIndex = -1;
		int mxLength = 0;
		int currentCnt = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] > 0) {
				if (!currentCnt) startIndex = i;
				currentCnt++;
			}
			else {
				if (currentCnt > mxLength) {
					mxLength = currentCnt;
					mxStartIndex = startIndex;
				}
				currentCnt = 0;
			}
		}

		cout << "Sequence: ";
		for (int i = mxStartIndex; i < mxStartIndex + mxLength; i++) cout << arr[i] << " ";
		cout << endl;
	}

	static void mergeIntervals(vector<Interval>& intervals) {
		if (intervals.empty()) return;
		auto& prev = intervals[0];
		int i = 0;
		for (int j = 1; j < intervals.size(); j++) {
			auto cur = intervals[j];
			if (overlap(prev, cur)) prev = { min(prev.start,cur.start),max(prev.end,cur.end) };
			else i++;
		}

		i++;
		for (; i < intervals.size(); i++) {
			intervals.erase(intervals.begin() + i);
		}
	}

	static bool overlap(Interval& it1, Interval& it2) {
		return it1.end >= it2.start && it2.end >= it1.start;
	}

	static void minimizeProduct()
	{
		vector<int> arr1 = { 1,-1 };
		vector<int> arr2 = { 1, 2, 3, 4 };

		cout << "Minimum product: " << minProduct(arr1, arr2) << endl;
	}

	static int minProduct(vector<int>& arr1, vector<int>& arr2, int index1, int index2) {
		if (index2 >= arr2.size() && index1 >= arr1.size()) return 0;
		if (index2 >= arr2.size()) return 999;
		if (index1 >= arr1.size()) return 0;

		int mnProduct = arr1[index1] * arr2[index2] + minProduct(arr1, arr2, index1 + 1, index2 + 1);
		mnProduct = min(mnProduct, minProduct(arr1, arr2, index1, index2 + 1));

		return mnProduct;
	}

	static int minProduct(vector<int>& arr1, vector<int>& arr2)
	{
		int n = arr1.size();
		int m = arr2.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 && j == 0) dp[i][j] = 0;
				else if (i == 0) dp[i][j] = 0;
				else if (j == 0) dp[i][j] = 999;
				else {
					dp[i][j] = min(dp[i][j - 1], arr1[i - 1] * arr2[j - 1] + dp[i - 1][j - 1]);
				}
			}
		}

		return dp[n][m];
	}
};