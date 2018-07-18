#ifndef __db_h
#define __db_h

#define DB_FILE "/usr/local/.devpkg/db"
#define DB_DIR "/usr/local/.devpkg"

int DB_init();
int DB_update();
int DB_list();
int DB_find();

#endif