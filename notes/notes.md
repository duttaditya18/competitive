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
