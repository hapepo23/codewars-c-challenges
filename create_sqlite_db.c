/*
6 kyu
I Liked the SQL Better...
https://www.codewars.com/kata/53d2c97d7152a59b64001033
*/

#include <sqlite3.h>
#include <stdio.h>

void create_db(void) {
  char* create_command =
      "CREATE TABLE MOVIES(Name TEXT NOT NULL, Year INT NOT NULL, Rating INT "
      "NOT NULL); "
      "INSERT INTO MOVIES VALUES('Rise of the Planet of the Apes', 2011, 77); "
      "INSERT INTO MOVIES VALUES('Dawn of the Planet of the Apes', 2014, 91); "
      "INSERT INTO MOVIES VALUES('Alien', 1979, 97); "
      "INSERT INTO MOVIES VALUES('Aliens', 1986, 98); "
      "INSERT INTO MOVIES VALUES('Mad Max', 1979, 95); "
      "INSERT INTO MOVIES VALUES('Mad Max 2: The Road Warrior', 1981, 100);";
  sqlite3* DB = NULL;
  int exit = 0;
  exit = sqlite3_open("/tmp/movies.db", &DB);
  if (exit != SQLITE_OK)
    printf("Error open DB: %s\n", sqlite3_errmsg(DB));
  else {
    printf("Opened Database successfully\n");
    char* error_message;
    exit = sqlite3_exec(DB, create_command, NULL, 0, &error_message);
    if (exit != SQLITE_OK) {
      printf("Error create MOVIES table: %s\n", error_message);
      sqlite3_free(error_message);
    } else
      printf("Table MOVIES created successfully\n");
  }
  sqlite3_close(DB);
  printf("Closed Database\n");
}
