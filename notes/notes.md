# Notes

**Please Note:** I don't at all know anything that I am talking about. Don't read this.

## Redirect `cin` and `cout` to files

```c++
ifstream cin("input.txt");
ofstream cout("output.txt");
```

**Reference:** https://stackoverflow.com/a/38504880/7345209

## Fast I/O for `cout` and `cin`

```c++
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

**Reference:** https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
