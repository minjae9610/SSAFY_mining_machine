#include "libmjkstd.h"

int tolower(int c)
{
    if (isupper(c))
        c = convert_alpha_case(c);
    return c;
}