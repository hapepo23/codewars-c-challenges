/*
7 kyu
Adding Arrays
https://www.codewars.com/kata/59778cb1b061e877c50000cc
*/

char* array_adder(int rows,
                  int cols,
                  const char matrix[rows][cols],
                  char string[cols * (rows + 1) + 1]) {
  for (int c = 0, pos = 0; c < cols; c++) {
    for (int r = 0; r < rows && matrix[r][c]; r++)
      string[pos++] = matrix[r][c];
    string[pos++] = (c == cols - 1) ? '\0' : ' ';
  }
  return string;
}
