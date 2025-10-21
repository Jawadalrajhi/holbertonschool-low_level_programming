# Hash Tables Project

## Description
This project implements a basic **hash table** in C using **chaining** for collision handling.  
It includes functions to create, set, get, print, and delete key-value pairs.

## Files
- `0-hash_table_create.c` — Create a new hash table.
- `1-djb2.c` — Implement DJB2 hash function.
- `2-key_index.c` — Map a key to an index in the hash table array.
- `3-hash_table_set.c` — Add or update a key-value pair.
- `4-hash_table_get.c` — Retrieve a value by key.
- `5-hash_table_print.c` — Print the hash table.
- `6-hash_table_delete.c` — Delete the hash table and free memory.
- `hash_tables.h` — Header file with structs and function prototypes.
- `0-main.c` — Example/test file for `hash_table_create`.

## Compilation
Compile with:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o test

to run
./test

Memory Management

All memory allocations are checked for failure.

Use valgrind to ensure no leaks:

valgrind --leak-check=full ./test

Author

[Jawad Alrajhi]

--- 
