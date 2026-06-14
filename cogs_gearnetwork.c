/*
6 kyu
Cogs Gearnetwork
https://www.codewars.com/kata/6a1170dbe815a63a8eabd1d4
*/

#include <stdbool.h>
#include <stddef.h>

void cogsebi(size_t gears_count,
             const int gears[gears_count],
             size_t connections_count,
             const int connections[connections_count][2],
             int driver_id,
             double driver_rpm,
             double rpms[gears_count]) {
  bool done[connections_count];
  for (size_t i = 0; i < connections_count; i++)
    done[i] = false;
  size_t donecnt = 0;
  for (size_t i = 0; i < gears_count; i++)
    rpms[i] = 0.0;
  rpms[driver_id] = driver_rpm;
  while (donecnt < connections_count) {
    size_t prev_donecnt = donecnt;
    for (size_t i = 0; i < connections_count; i++) {
      if (!done[i]) {
        size_t cog0 = connections[i][0];
        size_t cog1 = connections[i][1];
        if (rpms[cog0] != 0.0 && rpms[cog1] == 0.0) {
          rpms[cog1] = -rpms[cog0] * gears[cog0] / gears[cog1];
          done[i] = true;
          donecnt++;
        } else if (rpms[cog1] != 0.0 && rpms[cog0] == 0.0) {
          rpms[cog0] = -rpms[cog1] * gears[cog1] / gears[cog0];
          done[i] = true;
          donecnt++;
        }
      }
    }
    if (donecnt == prev_donecnt)
      break;
  }
}
