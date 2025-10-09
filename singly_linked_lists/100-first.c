#include"lists.h"
/**
 * _construct - before main executed
 * Description: a function prints befor main executed
 */
__attribute__((constructor))
void _construct(void)
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
