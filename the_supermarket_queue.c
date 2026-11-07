/*
6 kyu
The Supermarket Queue
https://www.codewars.com/kata/57b06f90e298a7b53d000a86
*/

int queue_time(const int customers[], int customers_length, int n) {
  int tills[n];
  for (int j = 0; j < n; j++)
    tills[j] = 0;
  int max_time = 0;
  for (int i = 0; i < customers_length; i++) {
    int min = 0;
    for (int j = 1; j < n; j++) {
      if (tills[j] < tills[min])
        min = j;
    }
    tills[min] += customers[i];
    if (tills[min] > max_time)
      max_time = tills[min];
  }
  return max_time;
}
