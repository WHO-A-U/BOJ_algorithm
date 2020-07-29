#include<iostream>
#include<algorithm>
using namespace std;
int n, m, k; //n 세로 m가로 k스티커수
bool sheet[41][41];
bool sticker[101][11][11]; // 몇번스티커 , row,col
pair<int, int> stickerinfo[101]; //height ,  width
//test
void printsheet() {

   cout << "****************************************************************\n";
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         cout << sheet[i][j] << " ";
      }
      cout << '\n';
   }
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {

      }
   }
}
//90도 돌려

void clockwise(int snum) {
   bool tmp[11][11];
   int width = stickerinfo[snum].second;
   int height = stickerinfo[snum].first;

   for (int i = 1; i <= height; i++)
   {
      for (int j = 1; j <= width; j++)
      {
         tmp[j][height - i + 1] = sticker[snum][i][j];
      }

   }

   for (int i = 1; i <= 10; i++)
   {
      for (int j = 1; j <= 10; j++)
      {
         sticker[snum][i][j] = tmp[i][j];
      }
   }

   stickerinfo[snum] = { width,height };
}
//죄측 상단( pc,pr) 기준 덮기가능여부
bool ispossible(int snum, int pr, int pc) { //point row ,point col
   int height = stickerinfo[snum].first;
   int width = stickerinfo[snum].second;
   if (pr + height > n + 1 || pc + width > m + 1) {
      return false;
   }
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++)
      {
         if (sheet[i + pr][j + pc] && sticker[snum][i + 1][j + 1]) {
            return false;
         }
      }
   }
   return true;
}

void paint(int snum, int pr, int pc) {
   int height = stickerinfo[snum].first;
   int width = stickerinfo[snum].second;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++)
      {
         sheet[pr + i][pc + j] = (sticker[snum][i + 1][j + 1] || sheet[pr + i][pc + j]);
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m >> k; //n세로 M가로 k개수
   int row, col;
   for (int i = 1; i <= k; i++)
   {
      cin >> row >> col;
      stickerinfo[i] = { row,col };
      for (int j = 1; j <= row; j++)
      {
         for (int z = 1; z <= col; z++)
         {
            cin >> sticker[i][j][z];
         }
      }
   }

   int flag=0;
   for (int t = 1; t <= k; t++)
   {
      for (int z = 0; z < 4; z++)
      {
         for (int i = 1; i <= n; i++)
         {
            for (int j = 1; j <= m; j++)
            {
               if (ispossible(t, i, j))
               {
                  paint(t, i, j);
                  flag=1;
               }
               if(flag==1)
                    break;
            }
            if(flag==1)
                    break;
         }
         clockwise(t);
         if(flag==1)
                    break;
      }
      flag=0;
   }

   int cnt = 0;
   for (int i = 1; i <= m; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         if (sheet[j][i])
            cnt++;
      }
   }
   cout << cnt;
}