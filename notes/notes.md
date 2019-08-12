# Notes

**Please Note:** I don't at all know anything that I am talking about. Don't read this.

## Redirect `cin` and `cout` to files

```c++
ifstream cin("input.txt");
ofstream cout("output.txt");
```

**Reference(s):** https://stackoverflow.com/a/38504880/7345209

## Fast I/O for `cout` and `cin`

```c++
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

**Reference(s):** https://www.geeksforgeeks.org/fast-io-for-competitive-programming/

## Sorting STL

Uses [**Introsort**](https://en.wikipedia.org/wiki/Introsort) (combination of [**Quicksort**](https://en.wikipedia.org/wiki/Quicksort) and [**Heapsort**](https://en.wikipedia.org/wiki/Heapsort)), followed by an [**Insertion Sort**](https://en.wikipedia.org/wiki/Insertion_sort) on the result.

Works in **O(N log N)**.

```c++
// Sorts A[] uptil n'th index
sort(A, A + n);

// Sorts in reverse
sort(A, A + n, greater<int>());

// Sorts vector<int> A
sort(A.begin(), A.end());
```

**Reference(s):**

- https://en.wikipedia.org/wiki/Sort_(C++)
- https://www.geeksforgeeks.org/sort-c-stl/
- https://stackoverflow.com/a/23985906/7345209

## Type Conversion

### Explicit

##### Type Casting

```c++
double x = 2.5;

// (type) expression
int sum1 = int(x) + 1.5; // Same as (int)x + 1.5 (C-type Casting)
int sum2 = int(x + 1.5); // Same as (int)(x + 1.5) (C-type Casting)
int sum3 = x + 1.5;
cout << sum1 << " " << sum2 << " " << sum3;

// Output: 3 4 4
```

### Implicit

Also known as coercion, is an automatic type conversion by the compiler during comparisons or assignments.

**Reference(s):**

- https://www.geeksforgeeks.org/type-conversion-in-c/
- http://www.cplusplus.com/doc/tutorial/typecasting/ (See also [Type Casting](http://www.cplusplus.com/doc/tutorial/typecasting/#type_casting))
- https://en.wikibooks.org/wiki/Computer_Programming/Type_conversion

## Ternary Operator

```c++
// (expression) ? ifTrue : ifFalse

int max = (a > b) ? a : b;
```

If either `ifTrue` or `ifFalse` have side effects, only one of them will be evaluated.

**Reference(s):**

- https://www.geeksforgeeks.org/ cc-ternary-operator-some-interesting-observations/
- http://www.cplusplus.com/articles/1AUq5Di1/
