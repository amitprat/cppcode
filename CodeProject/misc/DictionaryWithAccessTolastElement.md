# Dictionary with access to last element

*Write a new data structure, "Dictionary with Last"
Methods:
set(key, value) - adds an element to the dictionary
get(key) - returns the element
delete(key) - removes the element
last() - returns the last key that was added or read.
In case a key was removed, last will return the previous key in order.*


```json
Use a HashMap and a Doubly Linked List, where Hashmap would have a pointer to the list Node such as Map<Key, ListNode> and List would have ListNode(Value, Left, Right)
and the head of the list would be the most recent element added or read.

HEAD -> * Most recently added or read
TAIL -> * Least recently read or added, "oldest" element

For set(Key, value) check if key exists in HashMap, if so get ListNode and set new value make it HEAD, set left and right pointers accordingly. If not create new ListNode, set it as new HEAD and make HEAD -> right point to old HEAD.

For get(Key) check if key exists in HashMap, if so get ListNode and make it HEAD, set left and right pointers accordingly. Return value. If it does not exits return null or throw exception.

For delete(Key) check if key exists in HashMap, if so get ListNode and set left and right pointers accordingly eliminate this node and remove it from hashmap . Return value. If it does not exits return null or throw exception.

For last() check if list is empty, if not return HEAD, If empty return null.
```

Other solution

```json
Self-Balancing Binary Tree: Red-Black Tree I think is the best choice because it gives you the best worst case (log).
Other options might be: AVL tree and Hash Tables... but, depends on what you want to do with this structure.
```