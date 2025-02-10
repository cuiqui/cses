#define PRINT_ARRAY(arr, l, r) do { \
    printf("["); \
    for (int i = (l); i <= (r); i++) { \
        printf("%d%s", (arr)[i], (i < (r) ? ", " : "")); \
    } \
    printf("]\n"); \
} while (0)
