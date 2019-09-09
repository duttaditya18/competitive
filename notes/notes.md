# Notes

**Please Note:** I don't at all know anything that I am talking about. Don't read this.

## Redirect `cin` and `cout` to files (C/C++)

```c++
ifstream cin("input.txt");
ofstream cout("output.txt");
```

**Reference(s):**

- https://stackoverflow.com/a/38504880/7345209

## Fast I/O for `cout` and `cin`

```c++
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

**Reference(s):**

- https://www.geeksforgeeks.org/fast-io-for-competitive-programming/

## Sorting STL (C/C++)

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

## Type Conversion (C/C++)

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

## Ternary Operator (C/C++)

```c++
// (expression) ? ifTrue : ifFalse

int max = (a > b) ? a : b;
```

If either `ifTrue` or `ifFalse` have side effects, only one of them will be evaluated.

**Reference(s):**

- https://www.geeksforgeeks.org/ cc-ternary-operator-some-interesting-observations/
- http://www.cplusplus.com/articles/1AUq5Di1/

## GCD STL (C/C++)

```c++
cout << __gcd(6, 12);
```

Only `int` values are allowed to be passed in and functions which might return non-`int` values are not allowed to be nested.

**Reference(s):**

- https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/
- https://en.cppreference.com/w/cpp/numeric/gcd

## Stack Smashing (C/C++)

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

## Input with Spaces (C/C++)

```c++
string s;
getline(cin, s);
```

**Reference(s):**

- https://www.geeksforgeeks.org/getline-string-c/

## Format Specifiers (C/C++)

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

## Operator Predence (C/C++)

**Reference(s):**

- http://www.cplusplus.com/doc/tutorial/operators/
- http://www.cplusplus.com/doc/tutorial/operators/

## Vectors STL (C/C++)

**Reference(s):**

- https://www.geeksforgeeks.org/vector-in-cpp-stl/
- https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/
- https://www.geeksforgeeks.org/ways-copy-vector-c/
- https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/
- http://www.cplusplus.com/reference/vector/vector/

## Map STL (C/C++)

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

## Min and Max Element (C/C++)

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

## Data Structures

- https://www.hackerearth.com/practice/notes/c-stls-when-to-use-which-stl/

## Dynamic Programming

- https://www.topcoder.com/community/competitive-programming/tutorials/dynamic-programming-from-novice-to-advanced/
- https://www.geeksforgeeks.org/tabulation-vs-memoization/
