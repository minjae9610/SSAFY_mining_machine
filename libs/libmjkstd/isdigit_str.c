#include <stdbool.h>

bool isdigit_str(const char *str)
{
    if (!str)
        return false;
    while (*str)
    {
        if (*str < '0' || '9' < *str)
            return false;
        ++str;
    }
    return true;
}

bool ishex_str(const char *str)
{
    if (!str)
        return false;
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
        str += 2;
    while (*str)
    {
        if (!((*str >= '0' && '9' >= *str) || (*str >= 'a' && 'f' >= *str) || (*str >= 'A' && 'F' >= *str)))
            return false;
        ++str;
    }
    return true;
}
