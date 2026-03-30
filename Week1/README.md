## Big O

------------------------

### What is Big O?

Big O describes time complexity (how runtime grows with input size n).

---

### Common Complexities:

| Big O      | Meaning           | Example            |
| ---------- | ----------------- | ------------------ |
| O(1)       | Constant time     | Access array index |
| O(log n)   | Logarithmic       | Binary search      |
| O(n)       | Linear            | Loop through array |
| O(n log n) | Efficient sorting | Merge sort         |
| O(n²)      | Nested loops      | Bubble sort        |

---

### Examples :

#### Step 1: Ignore constants

```java
for(int i = 0; i < n; i++) {
    System.out.println("Hi");
}
```
Runs n times →  
👉 O(n) (not O(2n), not O(n+5))


### Step 2: Look at loops

🟢 Single loop → O(n)

```java
for(int i = 0; i < n; i++)
```
👉 Runs n times → O(n)


🔴 Nested loop → Multiply
```java
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        // work
    }
}
```

👉 n × n = O(n²)


🟡 Dependent loops
```java
for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
    }
}
```

👉 Runs: 1 + 2 + 3 + ... + n

👉 ≈ n²/2 → O(n²)


Step 3: Logarithmic loops
```java
for(int i = 1; i < n; i = i * 2)
```

👉 1 → 2 → 4 → 8 → ...

👉 Grows exponentially

👉 Runs log n times

👉 O(log n)


Step 4: Multiple parts → Add

```java
for(int i = 0; i < n; i++) { }   // O(n)
for(int i = 0; i < n; i++) { }   // O(n)
```

👉 O(n + n) = O(n)


Step 5: Focus on worst case
```java
if(x == target) return; // best case O(1)

for(int i = 0; i < n; i++) {
    if(arr[i] == target)
        return;
}
```

👉 Worst case → loop runs fully → O(n)

🔁 Short Revision
👉 Loop → O(n)
👉 Nested loop → O(n²)
👉 Doubling/halving → O(log n)
👉 Multiple blocks → add
👉 Ignore constants
