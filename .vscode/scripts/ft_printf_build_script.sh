make
clang printf_test.c libftprintf.a -g
echo "prtf_test compiled"
./a.out | cat -e