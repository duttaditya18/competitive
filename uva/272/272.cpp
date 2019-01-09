#include <iostream>

using namespace std;

int main(void)
{
  char c;
  bool x = true;
  while (scanf("%c", &c) != EOF)
  {
    if (c == '"')
    {
      if (x)
        printf("``");
      else
        printf("''");
      x = !x;
    }
    else
    {
      printf("%c", c);
    }
  }
  return 0;
}