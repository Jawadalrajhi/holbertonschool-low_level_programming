# Singly Linked Lists

This project is part of the **Holberton School Low-Level Programming** curriculum.  
It focuses on understanding and implementing **singly linked lists** in C.

---

## 📚 Learning Objectives

At the end of this project, you should be able to explain (without the help of Google):

- What is a linked list
- How to build and use singly linked lists
- The difference between arrays and linked lists
- How to manipulate nodes dynamically using pointers and memory allocation (`malloc` / `free`)

---

## 🧩 Project Structure

| File | Description |
|------|--------------|
| `0-print_list.c` | Prints all elements of a `list_t` list |
| `1-list_len.c` | Returns the number of elements in a `list_t` list |
| `2-add_node.c` | Adds a new node at the beginning of a list |
| `3-add_node_end.c` | Adds a new node at the end of a list |
| `4-free_list.c` | Frees a `list_t` list |
| `100-first.c` | Executes code before the `main` function runs |
| `lists.h` | Header file with structure definitions and function prototypes |

---

## 🧠 Data Structure

```c
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

