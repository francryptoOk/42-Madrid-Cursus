#include <unistd.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    int     i;
    char    c;
    int     flag;

    i = 0;
    flag = 0;
    if (argc == 2)
    {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while (argv[1][i])
        {
            if (argv[1][i] == ' ' || argv[1][i] == '\t')
                flag = 1;
            if (argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                if (flag == 1)
                    write (1, " ", 1);
                flag = 0;
                c = argv[1][i];
                write (1, &c, 1);
            }
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}
