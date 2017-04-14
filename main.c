#include <printf.h>
#include "tree.h"

void test(char* match)
{
    printf("%s \n",match);
}


int main() {
    Tree* t = load_file("./words.txt");
    int x = 0;
    find_all_paritial_matches(t, "apple",  test);
}
