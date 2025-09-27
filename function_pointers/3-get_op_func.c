#include "3-calc.h"
#include <string.h>

/**
 * get_op_func - select corrects function
 * @s: operator passed as argument
 *
 * Return: pointer to the right function
 */

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}
    };
    int i;

    while (i < 5)
    {
    	if (s && s[0] == ops[i].op[0] && !s[1])
		return (ops[i].f);
	i++;
    }
    return (NULL);
}
