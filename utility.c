#include "utility.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operations.h"

void ask_for_operation(char* destination)
{
	printf("Input operation: ");
	scanf("%s", destination);
}

struct args ask_for_args()
{
	struct args res;
	printf("Input arguments: ");
	scanf("%lf %lf", &res.first, &res.second);
	return res;
}


bool find_operation(const char* key, operation_func* res)
{

	for (int i = 0; i < SIZE; ++i)
	{
		if(strcmp(key, operation_map[i].key) == 0)
		{
			if(res != NULL)
				*res = operation_map[i].value;
			return true;
		}
	}
	return false;
}

bool is_valid_operation(const char* key)
{
	return find_operation(key, NULL);
}

double perform_operation(const char* operation_str, double arg_first, double arg_second)
{
	operation_func required_operation;
	if(find_operation(operation_str, &required_operation))
	{
		return required_operation(arg_first, arg_second);
	}
	abort();
}




struct key_value_operation_pair operation_map[SIZE] = {
	{"+",&addition },
	{"-",&subtraction},
	{"*",&multiplication},
	{"**",&power},
	{"/",&division}
};