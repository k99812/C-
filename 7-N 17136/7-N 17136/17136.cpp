#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

const int n = 10, INF = 1e9;
int a[14][14], ret = INF;
map<int, int> m;

bool check(int y, int x, int size)
{
	if (y + size > n || x + size > n) return false;
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (a[i][j] == 0) return false;
		}
	}
	return true;
}  

void draw(int y, int x, int size, int value)
{
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			a[i][j] = value;
		}
	}
}

void dfs(int y, int x, int cnt)
{
	if (cnt >= ret) return;

	if (x == n)
	{
		dfs(y + 1, 0, cnt);
		return;
	}

	if (y == n)
	{
		ret = min(ret, cnt);
		return;
	}

	if (a[y][x] == 0)
	{
		dfs(y, x + 1, cnt);
	}

	for (int size = 5; size > 0; size--)
	{
		if (m[size] == 5) continue;
		if (check(y, x, size))
		{
			m[size]++;
			draw(y, x, size, 0);
			dfs(y, x + 1, cnt + 1);
			draw(y, x, size, 1);
			m[size]--;
		}
	}
	return;
}

int main()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	dfs(0, 0, 0);

	cout << (ret == INF ? -1 : ret) << "\n";

	return 0;
}