#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	vector < pair <int,int>> v(N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &v[i].second, &v[i].first);
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
		printf("%d %d\n", v[i].second, v[i].first);
}