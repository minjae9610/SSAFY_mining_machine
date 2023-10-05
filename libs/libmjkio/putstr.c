#include <stdbool.h>
#include <unistd.h>

#define WRITE_SIZE_MAX 1048576

bool putstr_fd(int fd, const char *s)
{
    size_t write_size;
    ssize_t write_result;

    if (fd < 0 || !s)
        return false;
    write_size = 0;
    while (s[write_size])
    {
        ++write_size;
        if (WRITE_SIZE_MAX == write_size)
        {
            write_result = write(fd, s, write_size);
            if (write_result != WRITE_SIZE_MAX)
                return false;
            write_size = 0;
            s += write_result;
        }
    }
    write_result = write(fd, s, write_size);
    return true;
}