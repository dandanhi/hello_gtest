#include <malloc.h>
#include <string.h>
#include "hex.h"

int16_t *hex2int16(char *string)
{
  if (string == NULL)
    return NULL;

  size_t slength = strlen(string);
  if ((slength % 4) != 0) // must be even
    return NULL;

  size_t dlength = slength / 4;
  int16_t *data = (int16_t *)malloc(dlength*2);
  memset(data, 0, dlength*2);

  size_t index = 0;
  while (index < slength)
  {
    char c = string[index];
    int value = 0;
    if (c >= '0' && c <= '9')
      value = (c - '0');
    else if (c >= 'A' && c <= 'F')
      value = (10 + (c - 'A'));
    else if (c >= 'a' && c <= 'f')
      value = (10 + (c - 'a'));
    else
    {
      free(data);
      return NULL;
    }
    int shift = 0;
    shift = 16 - (index + 1) % 4 * 4;
    shift = (shift == 16) ? 0 : shift;
    data[(index / 4)] += value << shift;
    index++;
  }
  return data;
}