#pragma once
#include <stdbool.h>

typedef double (*operation_func)(double, double);
struct key_value_operation_pair
{
	const char* key;
	operation_func value;
};
struct args
{
	double first;
	double second;
};

void ask_for_operation(char* destination);

struct args ask_for_args(void);

bool is_valid_operation(const char* res);

double perform_operation(const char* operation_str, double arg_first, double arg_second);

#define SIZE 5

extern struct key_value_operation_pair operation_map[SIZE];
