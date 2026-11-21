/*
6 kyu
Knight's Reach
https://www.codewars.com/kata/6afde4830e68b231e3fd1c26
*/

#include <stdbool.h>

int many_horse(int x, int y, int n) {
  bool current[8][8] = {{false}};
  bool next[8][8];
  int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
  int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
  current[x - 1][y - 1] = true;
  for (int step = 0; step < n; step++) {
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        next[i][j] = false;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (current[i][j]) {
          for (int k = 0; k < 8; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
              next[nx][ny] = true;
          }
        }
      }
    }
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        current[i][j] = next[i][j];
  }
  int count = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      if (current[i][j])
        count++;
  return count;
}
