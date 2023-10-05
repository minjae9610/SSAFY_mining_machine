#ifndef LIBMJKSTD_H
#define LIBMJKSTD_H

#include <stdbool.h>

int convert_alpha_case(int c);
int isupper(int c);
void tolower_str(char *str, int len);
int tolower(int c);
bool isdigit_str(const char *str);
bool ishex_str(const char *str);

#endif
