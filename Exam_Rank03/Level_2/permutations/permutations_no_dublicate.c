#include <unistd.h>

unsigned int my_strlen(const char *s) {
    unsigned int len = 0;
    while (s[len]) len++;
    return len;
}

void my_swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int should_swap(char *str, int start, int i) {
    for (int j = start; j < i; j++) {
        if (str[j] == str[i]) return 0;
    }
    return 1;
}

void generate_permutations(char *str, int start, int end) {
    if (start == end) {
        write(1, str, end + 1);
        write(1, "\n", 1);
    } else {
        for (int i = start; i <= end; i++) {
            if (should_swap(str, start, i)) {
                my_swap(&str[start], &str[i]);
                generate_permutations(str, start + 1, end);
                my_swap(&str[start], &str[i]);
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        write(1, "Usage: ./a.out <string>\n", 24);
        return 1;
    }

    char *input = argv[1];
    unsigned int len = my_strlen(input);

    generate_permutations(input, 0, len - 1);

    return 0;
}
