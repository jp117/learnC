# Comparison: `remove_by_value` in C – My Version vs. Reference Solution

This document compares two versions of a C function to remove the first node in a linked list by value: one written during a learning session, and a more polished reference implementation.

---

## 🧠 My Version

```c
int remove_by_value(node_t ** head, int val) {
    if (*head == NULL) return -1;

    if ((*head)->val == val) {
        return pop(head);
    }

    node_t * current = *head;
    while (current->next != NULL) {
        if (current->next->val == val){
            node_t * to_delete = current->next;
            current->next = current->next->next;
            free(to_delete);
            return 0;
        }
        current = current->next;
    }
    return -1;
}
```

### ✅ Strengths
- Simple and clean logic
- Avoids needing a `previous` pointer
- Handles `head` node via `pop`

### ⚠️ Tradeoffs
- Returns `0` on success (less descriptive)
- Slightly tighter pointer coupling with `current->next`
- No general list cleanup function

---

## 📘 Reference Version

```c
int remove_by_value(node_t ** head, int val) {
    node_t *previous, *current;

    if (*head == NULL) {
        return -1;
    }

    if ((*head)->val == val) {
        return pop(head);
    }

    previous = *head;
    current = (*head)->next;
    while (current) {
        if (current->val == val) {
            previous->next = current->next;
            free(current);
            return val;
        }

        previous = current;
        current  = current->next;
    }
    return -1;
}

void delete_list(node_t *head) {
    node_t  *current = head, 
            *next = head;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}
```

### ✅ Strengths
- Returns the actual value removed
- Uses two-pointer logic (`previous`, `current`) for clarity
- Includes a full `delete_list()` cleanup utility
- Easier to adapt to more complex list logic

---

## 🔍 Summary Comparison

| Feature               | My Version                  | Reference Version                |
|------------------------|-----------------------------|-----------------------------------|
| ✅ Handles head delete | Yes (`pop`)                 | Yes (`pop`)                       |
| 🧠 Traversal style     | Single pointer (`current`)  | Two pointers (`previous`, `current`) |
| 🧪 Return value        | `0` on success              | `val` on success                  |
| 🧼 Cleanup helper      | ❌ None                     | ✅ `delete_list()` included        |
| 🧩 Flexibility         | Concise but less general    | More adaptable and readable       |

---

Both approaches are valid and demonstrate a strong grasp of linked list traversal, pointer management, and memory cleanup.  **Theirs is more production ready.**
