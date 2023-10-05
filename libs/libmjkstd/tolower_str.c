#include "libmjkstd.h"

void tolower_str(char *str, int len)
{
    while (*str && len--)
    {
        *str = tolower(*str);
        ++str;
    }
}