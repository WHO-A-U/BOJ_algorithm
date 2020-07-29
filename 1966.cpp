#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int zz;
	cin >> zz;
	while (zz--)
	{
		queue<int> A;
		int N, M;
		cin >> N >> M;
		int num;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			A.push(num);
		}
		int count = 0;
		while (1)
		{
			int max = 0;
			for (int i = 0; i < A.size(); i++)
			{
				if (max < A.front())
					max = A.front();
				A.push(A.front());
				A.pop();
			}
			if (max == A.front())
			{
				A.pop();
				count++;
				if (M == 0)
					break;
			}
			else {
				A.push(A.front());
				A.pop();
			}
			M--;
			if (M < 0)
				M = A.size() - 1;

		}
		cout << count << endl;;
	}
}