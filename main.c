
#include <stdio.h>
#include <stdlib.h>

#include "utility.h"

void run_calculator(void)
{
	char operation[255];
	ask_for_operation(operation);

	while (!is_valid_operation(operation))
	{
		printf("Invalid operation!\n");
		ask_for_operation(operation); 
	}


	const struct args arguments = ask_for_args();
	const double result = perform_operation(operation, arguments.first, arguments.second);

	printf("%lf\n", result);
}

int main()
{
	run_calculator();
	return EXIT_SUCCESS;
}
