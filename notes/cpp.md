## C++ Notes

**Please Note:** I don't at all know anything that I am talking about. Don't read this.

### Redirect `cin` and `cout` to files

```c++
// works throughout the file (recommnded)
freopen("input.txt", "w", stdin);
freopen("output.txt", "w", stdout);

// only works in the function it is initialized in
ifstream cin("input.txt");
ofstream cout("output.txt");
```

```Shell
$ a.out < input.txt > output.txt
```

**Reference(s):**

- https://stackoverflow.com/a/38504880/7345209

### Fast I/O for `cout` and `cin`

```c++
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

**Reference(s):**

- https://www.geeksforgeeks.org/fast-io-for-competitive-programming/

### Sorting

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

### Type Conversion

#### Explicit

```c++
double x = 2.5;

// (type) expression
int sum1 = int(x) + 1.5; // Same as (int)x + 1.5 (C-type Casting)
int sum2 = int(x + 1.5); // Same as (int)(x + 1.5) (C-type Casting)
int sum3 = x + 1.5;
cout << sum1 << " " << sum2 << " " << sum3;

// Output: 3 4 4
```

#### Implicit

Also known as coercion, is an automatic type conversion by the compiler during comparisons or assignments.

**Reference(s):**

- https://www.geeksforgeeks.org/type-conversion-in-c/
- http://www.cplusplus.com/doc/tutorial/typecasting/ (See also [Type Casting](http://www.cplusplus.com/doc/tutorial/typecasting/#type_casting))
- https://en.wikibooks.org/wiki/Computer_Programming/Type_conversion

### Ternary Operator

```c++
// (expression) ? ifTrue : ifFalse

int max = (a > b) ? a : b;
```

If either `ifTrue` or `ifFalse` have side effects, only one of them will be evaluated.

**Reference(s):**

- https://www.geeksforgeeks.org/ cc-ternary-operator-some-interesting-observations/
- http://www.cplusplus.com/articles/1AUq5Di1/

### GCD STL

```c++
cout << __gcd(6, 12);
```

Only `int` values are allowed to be passed in and functions which might return non-`int` values are not allowed to be nested.

**Reference(s):**

- https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/
- https://en.cppreference.com/w/cpp/numeric/gcd

### Stack Smashing

Occurs when we try to copy information copy information into a variable or buffer.

Certain protection mechanisms are put in place to prevent this kind of tampering which can potentially result in buffer exploits.

This results in a Runtime Error with the following message: `*** stack smashing detected ***: ./a.exe terminated`

```c++
char message[10];
strcpy(message, "Hello, world!");
// "Hello, world!' is 14 characters long (including the NULL Character) and we only have 10
```

`-fno-stack-protector` switch doesn't show the Stack Smashing error. The program will probably crash and will be vulnerable to buffer overflow exploits.

**Reference(s):**

- https://www.thegeekstuff.com/2013/02/stack-smashing-attacks-gcc

### Input with Spaces

```c++
string s;
getline(cin, s);
```

**Reference(s):**

- https://www.geeksforgeeks.org/getline-string-c/

### Format Specifiers

| Specifier |                       Are                       |
| :-------: | :---------------------------------------------: |
|   d, i    |                   Dec or Int                    |
|     u     |                  Unsigned Int                   |
|     o     |                      Octal                      |
|    x,X    |        Hexadecimal (lower and uppercase)        |
|   `.d`f   | Floating Point (`d = number of decimal places`) |
|   `.d`e   |   Scientific (`d = number of decimal places`)   |
|     g     |                     Double                      |
|     c     |                    Character                    |
|     s     |                     String                      |
|     n     |                 Pointer to Int                  |
|     p     |                     Pointer                     |

```c++
printf("%d\n", -5); //-5
printf("%u\n", 5); //5
printf("%e\n", 5.5); //5.500000e+00
printf("%.2f\n", 1.0/3.0); // 0.33
printf("%.3f\n", 1.0/3.0); // 0.333
printf("%.2e\n", 1.0/3.0); // 3.33e-001
printf("%.3e\n", 1.0/3.0); // 3.333e-001
printf("%c",'a'); // a
printf("%s","string"); // string
```

**Reference(s):**

- https://www.geeksforgeeks.org/format-specifiers-in-c/
- https://www.geeksforgeeks.org/difference-d-format-specifier-c-language/
- http://www.cplusplus.com/reference/cstdio/printf/
- http://docwiki.embarcadero.com/RADStudio/Rio/en/Format_Specifiers_in_C/C++

### Copy Array

```c++
#include <iterator>
#include <algorithm>

memcpy(b, a, sizeof(a)); // Copy a[] to b[]
std::copy(std::begin(a), std::end(a), std::begin(a)); // Copy a[] to b[]
```

**Reference(s):**

- https://social.msdn.microsoft.com/Forums/en-US/73a633d1-9787-4973-a741-054a7b4032a2/
- https://stackoverflow.com/q/16137953/7345209
- https://www.geeksforgeeks.org/different-methods-copy-c-stl-stdcopy-copy_n-copy_if-copy_backwards/

### Operator Predence (TODO)

**Reference(s):**

- http://www.cplusplus.com/doc/tutorial/operators/
- http://www.cplusplus.com/doc/tutorial/operators/

### Integer Literal (TODO)

**Reference(s):**

- https://www.geeksforgeeks.org/integer-literal-in-c-cpp-prefixes-suffixes/
- https://en.wikipedia.org/wiki/Integer_literal

### Vectors (TODO)

**Reference(s):**

- https://www.geeksforgeeks.org/vector-in-cpp-stl/
- https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/
- https://www.geeksforgeeks.org/ways-copy-vector-c/
- https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/
- http://www.cplusplus.com/reference/vector/vector/

### Map

```c++
map <char, int> mp;

mp.insert(pair<char, int>('a', 2)); // 'a' is key and 2 is value
mp['x'] = 3; // 'x' is key and 2 is value

map <char,int>::iterator it; // Iterator for map;

it = mp.find('x');
cout << it->first << " " << it->second; // Output: x 3

// Loop through Map using Iterator
for(it = mp.begin(); it != mp.end(); it++)
{
  cout << it->first << " " << it->second << endl;
}

mp.erase('x'); // Erase element mapped at x

cout << mp.count('a') // Output: 1

mp.erase(mp.begin(),mp.end()); // Erase all elements

cout << (mp.empty() ? "YES" : "NO"); // Output: YES
```

**Reference(s):**

- https://www.hackerearth.com/practice/notes/standard-template-library/
- https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
- https://www.hackerrank.com/challenges/cpp-maps/problem

### Unordered Map

**Reference(s):**

```c++
unordered_map<string, int> umap;

// Add ELements
umap["pi"] = 3;
umap.insert(make_pair("e", 2));

// If key not found in map iterator to end is returned
cout << (umap.find("pi") == umap.end()); // Output: 1

// Count returns the number of occurences of a key (1 or 0)
cout << umap.count("phi"); // Output: 0

// itr works as a pointer to pair <string, double>
unordered_map<string, int>::iterator itr;
for (itr = umap.begin(); itr != umap.end(); itr++)
{
  cout << itr->first << "  " << itr->second << endl;
}
```

- https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
- https://www.geeksforgeeks.org/map-vs-unordered_map-c/
- https://www.techiedelight.com/check-given-key-exists-map-cpp/

### Min and Max Element

```c++
// For Array
int max_el = *max_element(a, a + n);

// For Vectors
int max_el = *max_element(a.begin(), a.end());

// For Array
int min_el = *min_element(a, a + n);

// For Vectors
int min_el = *min_element(a.begin(), a.end());
```

**Reference(s):**

- https://www.geeksforgeeks.org/how-to-find-the-minimum-and-maximum-element-of-a-vector-using-stl-in-c/

### Upper and Lower Bound (TODO)

**Reference(s):**

- https://www.geeksforgeeks.org/set-upper_bound-function-in-c-stl/
- https://www.geeksforgeeks.org/lower_bound-in-cpp/
- https://www.geeksforgeeks.org/upper_bound-and-lower_bound-for-vector-in-cpp-stl/

### C++ Memory Layout

Stacks have fixed amount of memory. Heap has several parts and has a large memory. So, we should declare large arrays in the heap.

This will allocate in the BSS segment, which is a part of the heap:

```c++
static int c[1000000];
int main()
{
   cout << "done\n";
   return 0;
}
```

This will allocate in the DATA segment, which is a part of the heap too:

```c++
int c[1000000] = {};
int main()
{
   cout << "done\n";
   return 0;
}
```

This will allocate at some unspecified location in the heap:

```c++
int main()
{
  int\* c = new int[1000000];
  cout << "done\n";
  return 0;
}
```

**Reference(s):**

- https://www.geeksforgeeks.org/memory-layout-of-c-program/
- https://stackoverflow.com/q/1847789/7345209

### Check if using Code Judge

```c++
#ifdef ONLINE_JUDGE
// If code IS running on judge
#else
// If code is NOT running on judge
#endif


#ifndef ONLINE_JUDGE
// If code is NOT running on judge
#else
// If code IS running on judge
#endif
```

**Reference(s):**

- https://codeforces.com/blog/entry/14118

### Stringstream

```c++
string str;
cin >> str;

stringstream ss(str);

int x, y;
ss >> x >> y;
```

**Reference(s):**

- https://www.geeksforgeeks.org/stringstream-c-applications/
- http://www.cplusplus.com/reference/sstream/stringstream/stringstream/
