#================================================
# SQLite C
#================================================
sqlite3_open
sqlite3_libversion
sqlite3_errmsg
sqlite3_prepare_v2
sqlite3_close
sqlite3_step
sqlite3_column_text
sqlite3_finalize
sqlite3_exec
sqlite3_free
sqlite3_last_insert_rowid
sqlite3_bind_int
sqlite3_bind_parameter_index
sqlite3_prepare
sqlite3_bind_blob
#================================================
# SQLite Build for MinGW
#================================================
gcc -shared -o sqlite3.dll sqlite3.c
gcc -L. -lsqlite3 -o sqlite3.exe shell.c
#================================================
# SQLite Command Line
#================================================
sqlite3 test.db
.tables
.exit
.mode column
.headers on

