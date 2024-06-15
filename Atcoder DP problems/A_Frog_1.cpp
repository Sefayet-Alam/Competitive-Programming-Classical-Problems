#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> height(N);
	for (int i = 0; i < N; i++) { cin >> height[i]; }

	// dp[N] is the minimum cost to get to the Nth stone
	vector<int> dp(N, INT_MAX);
	// dp[0] = 0 is our base case since we're already at the first stone
	dp[0] = 0;

	// for each state, calculate the states it leads to
	for (int i = 0; i < N - 1; i++) {
		// jump one stone
		dp[i + 1] = min(dp[i + 1], dp[i] + abs(height[i] - height[i + 1]));
		// jump two stones
		if (i + 2 < N) {
			dp[i + 2] = min(dp[i + 2], dp[i] + abs(height[i] - height[i + 2]));
		}
	}

	cout << dp[N - 1] << endl;
}
