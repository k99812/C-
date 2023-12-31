#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, x, l, r, ret;

int main()
{
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cin >> x;

	sort(v.begin(), v.end());

	l = 0;
	r = n - 1;

	while (l != r)
	{
		if (v[l] + v[r] == x) ret++, r--;
		else if (v[l] + v[r] > x) r--;
		else if (v[l] + v[r] < x) l++;
	}

	cout << ret << "\n";

	return 0;
}