#define INF 987654321
#define NIL -1
#include<iostream>
#include<algorithm>
using namespace std;
int d[101][101];
int p[101][101];
int main()
{
	int N, M;
	cin >> N >> M;
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= N; j++)
		{
			d[i][j] = INF;
			p[i][j] = NIL;
			if (i == j)
				d[i][j] = 0;
		}

	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;//d[start][end]
		d[x][y] = min(d[x][y],z);
		p[x][y] = x;
		
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (d[k][j] > d[k][i] + d[i][j])
				{
					d[k][j] = d[k][i] + d[i][j];
					p[k][j] = p[i][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (d[i][j] == INF)
			{
				cout << "0 ";
			}
			else
			{
				cout << d[i][j] << " ";
			}
		}
		cout << endl;
	}
}