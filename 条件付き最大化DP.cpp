//高橋君とお肉
//https://atcoder.jp/contests/arc029/tasks/arc029_1
// 入力
int n;

// DPテーブル
int dp[5][210];
int main()
{

	cin >> n;
	int sum = 0;
	vector<int>meat(n);
	for (int i = 0; i < n; ++i)
		cin >>meat[i];
	sum = accumulate(all(meat), 0);
	// DP初期条件: dp[0][j] = 0
	for (int j = 0; j <= sum/2; ++j)
		dp[0][j] = 0;

	// DPループ
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= sum/2; ++j)
		{
			if (j >=meat[i])
				dp[i + 1][j] = max(dp[i][j -meat[i]] +meat[i], dp[i][j]);
			else
				dp[i + 1][j] = dp[i][j];
		}
	}
}