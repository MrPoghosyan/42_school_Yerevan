#include <unistd.h>
#include <stdlib.h>

void rot_13(char *str, int n)
{
    if (!str)
        return;

    while (*str)
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            char base = (*str >= 'a') ? 'a' : 'A';
            
            char shifted = (*str - base + n) % 26 + base; 
            write(1, &shifted, 1);
        }
        else
        {
            write(1, str, 1);
        }
        str++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1 || argc > 3){
        write (1, "\n", 1);
        return 1;
    } 
    
    rot_13(argv[1], atoi(argv[2]));
    write (1, "\n", 1);

    return 0;
}
