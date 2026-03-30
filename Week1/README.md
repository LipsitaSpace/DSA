## Big O

------------------------

### What is Big O?

Big O describes time complexity (how runtime grows with input size n).

---

### Time Complexities:

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


#### Step 3: Logarithmic loops
```java
for(int i = 1; i < n; i = i * 2)
```

👉 1 → 2 → 4 → 8 → ...

👉 Grows exponentially

👉 Runs log n times

👉 O(log n)


#### Step 4: Multiple parts → Add

```java
for(int i = 0; i < n; i++) { }   // O(n)
for(int i = 0; i < n; i++) { }   // O(n)
```

👉 O(n + n) = O(n)


#### Step 5: Focus on worst case
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




### Space Complexities:

how much extra memory your code uses


<img width="424" height="472" alt="Screenshot from 2026-03-30 15-03-50" src="https://github.com/user-attachments/assets/a8764076-3052-426a-9cff-193af6c75590" />
<br></br>
<p>
    <b>Step-by-Step Method to find space complexity </b>
    
        Step 1: Ignore input itself
          If input is given, don’t count it.
        Step 2: Count extra variables
          int, float, etc. → constant → O(1)
        Step 3: Check arrays / data structures
          Size depends on n → contributes to complexity
        Step 4: Check recursion
          Call stack depth matters
</p>

### Examples :

#### O(1)
```java
int sum = 0;
for(int i=0;i<n;i++){
    sum += i;
}
```
Analysis:

sum → 1 variable → constant

i → 1 variable → constant

Loop runs many times but doesn’t store extra memory

👉 Total memory = fixed (2 variables)

✅ Final:

Space = O(1)

#### O(n)
```java
int[] arr = new int[n];
```
Analysis:

Space = O(n)

Array size = n

If n = 10 → 10 spaces

If n = 1000 → 1000 spaces

👉 Memory grows with n

✅ Final:

Space = O(n)


#### O(n²)
```java
int[][] matrix = new int[n][n];
```
Analysis:

Rows = n

Columns = n

Total elements = n × n = n²

👉 Memory grows quadratically

✅ Final:

Space = O(n²)


####  Case 1: Multiple Variables
```java
int a = 10;
int b = 20;
int c = 30;
```

👉 3 variables → still constant

✅ O(1)

#### Case 2: Two Arrays
```java
int[] a = new int[n];
int[] b = new int[n];
```

👉 n + n = 2n

👉 Ignore constant → O(n)

#### Case 3: Different Sizes
```java
int[] a = new int[n];
int[] b = new int[m];
```

👉 O(n + m)

#### Case 4: Recursion (VERY IMPORTANT)
```java
int fun(int n){
    if(n==0) return 0;
    return fun(n-1);
}

```

Analysis:
Calls stack grows like:
fun(5)
fun(4)
fun(3)
fun(2)
fun(1)
fun(0)

👉 Depth = n → memory used

✅ Space = O(n)

#### Case 5: Fibonacci (Tricky)
```java
fib(n-1) + fib(n-2)
```

👉 Many calls, BUT stack depth = n

✅ Space = O(n)

❌ NOT O(2ⁿ)


> Loop count does NOT affect space, Only storage matters


### Recursion Complexities:

A function calling itself again and again. Each call uses memory → stack grows


Two things matter:

1. Number of function calls
   
2. Space used by call stack

#### Linear Recursion
```java
int fun(int n){
    if(n == 0) return 0;
    return fun(n-1);
}
```
Understanding

Each call makes 1 more call

Chain: n → n-1 → n-2 → ...

Complexity
>Time = O(n)
>Space = O(n)

#### Binary Recursion
```java
int fib(int n){
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```
Understanding

Each call splits into 2:

         f(n)
       /      \
    f(n-1)   f(n-2)

Complexity
> Time = O(2ⁿ) & Space = O(n)


#### Divide & Conquer Recursion

Binary Search
```java
binarySearch(arr, low, high)
```
Understanding : Problem size reduces by half each time

Complexity
>Time = O(log n) & Space = O(log n)

#### Tree Recursion (Multiple Branches)
``` java
fun(n){
    fun(n-1);
    fun(n-1);
    fun(n-1);
}
```
Understanding : 3 calls per level

Complexity
>Time = O(3ⁿ) & Space = O(n)

#### Tail Recursion
```java
int fun(int n){
    if(n == 0) return 0;
    return fun(n-1);
}
```
Understanding : Last operation is recursive call

Complexity
> Time = O(n) & Space = O(n) (Java doesn’t optimize)
