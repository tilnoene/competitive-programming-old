void dfs(int x) {
	used[x] = true;

	for (auto e : adj[x]) {
		if (!used[e]) {
			dfs(e);
		}
	}
}