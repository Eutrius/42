#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

void	test_return_values(int org, int ft, int test_number)
{
	if (org == ft)
		printf("\033[0;32mTest %d: OK - Return values match: %d\033[0m\n",
			test_number, org);
	else
		printf("\033[0;31mTest %d: KO - Expected: %d, Got: %d\033[0m\n",
			test_number, org, ft);
}

int	test(void)
{
	int		org;
	int		ft;
	int		test_num;
	int		num;
	void	*ptr;
	void	*null_ptr;

	test_num = 1;
	printf("\n=== TESTING %%c ===\n");
	// %c only works with width and minus flag
	printf("\nTest %d: Basic char\n", test_num);
	org = printf("Printf:    |%c|\n", 'a');
	ft = ft_printf("ft_printf: |%c|\n", 'a');
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Width\n", test_num);
	org = printf("Printf:    |%5c|\n", 'a');
	ft = ft_printf("ft_printf: |%5c|\n", 'a');
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Left-aligned width\n", test_num);
	org = printf("Printf:    |%-5c|\n", 'a');
	ft = ft_printf("ft_printf: |%-5c|\n", 'a');
	test_return_values(org, ft, test_num++);
	// Edge cases
	printf("\nTest %d: Null character\n", test_num);
	org = printf("Printf:    |%c|\n", '\0');
	ft = ft_printf("ft_printf: |%c|\n", '\0');
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Null character with width\n", test_num);
	org = printf("Printf:    |%5c|\n", '\0');
	ft = ft_printf("ft_printf: |%5c|\n", '\0');
	test_return_values(org, ft, test_num++);
	printf("\n=== TESTING %%s ===\n");
	// %s works with width, precision, and minus flag
	printf("\nTest %d: Basic string\n", test_num);
	org = printf("Printf:    |%s|\n", "hello");
	ft = ft_printf("ft_printf: |%s|\n", "hello");
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Width\n", test_num);
	org = printf("Printf:    |%10s|\n", "hello");
	ft = ft_printf("ft_printf: |%10s|\n", "hello");
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Left-aligned width\n", test_num);
	org = printf("Printf:    |%-10s|\n", "hello");
	ft = ft_printf("ft_printf: |%-10s|\n", "hello");
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Precision\n", test_num);
	org = printf("Printf:    |%.3s|\n", "hello");
	ft = ft_printf("ft_printf: |%.3s|\n", "hello");
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Width and precision\n", test_num);
	org = printf("Printf:    |%10.3s|\n", "hello");
	ft = ft_printf("ft_printf: |%10.3s|\n", "hello");
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Left-aligned width and precision\n", test_num);
	org = printf("Printf:    |%-10.3s|\n", "hello");
	ft = ft_printf("ft_printf: |%-10.3s|\n", "hello");
	test_return_values(org, ft, test_num++);
	// Edge cases
	printf("\nTest %d: NULL string\n", test_num);
	org = printf("Printf:    |%s|\n", NULL);
	ft = ft_printf("ft_printf: |%s|\n", NULL);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Empty string\n", test_num);
	org = printf("Printf:    |%s|\n", "");
	ft = ft_printf("ft_printf: |%s|\n", "");
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Zero precision\n", test_num);
	org = printf("Printf:    |%.0s|\n", "hello");
	ft = ft_printf("ft_printf: |%.0s|\n", "hello");
	test_return_values(org, ft, test_num++);
	printf("\n=== TESTING %%p ===\n");
	// %p works with width and minus flag
	num = 42;
	ptr = &num;
	null_ptr = NULL;
	printf("\nTest %d: Basic pointer\n", test_num);
	org = printf("Printf:    |%p|\n", ptr);
	ft = ft_printf("ft_printf: |%p|\n", ptr);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Width\n", test_num);
	org = printf("Printf:    |%20p|\n", ptr);
	ft = ft_printf("ft_printf: |%20p|\n", ptr);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Left-aligned width\n", test_num);
	org = printf("Printf:    |%-20p|\n", ptr);
	ft = ft_printf("ft_printf: |%-20p|\n", ptr);
	test_return_values(org, ft, test_num++);
	// Edge cases
	printf("\nTest %d: NULL pointer\n", test_num);
	org = printf("Printf:    |%p|\n", null_ptr);
	ft = ft_printf("ft_printf: |%p|\n", null_ptr);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: NULL pointer with width\n", test_num);
	org = printf("Printf:    |%20p|\n", null_ptr);
	ft = ft_printf("ft_printf: |%20p|\n", null_ptr);
	test_return_values(org, ft, test_num++);
	printf("\n=== TESTING %%d WITH ALL VALID FLAG COMBINATIONS ===\n");
	// Basic tests without flags
	printf("\nTest %d: Basic integer without flags\n", test_num);
	org = printf("Printf:    |%d|\n", 42);
	ft = ft_printf("ft_printf: |%d|\n", 42);
	test_return_values(org, ft, test_num++);
	// Width tests
	printf("\nTest %d: Width only\n", test_num);
	org = printf("Printf:    |%10d|\n", 42);
	ft = ft_printf("ft_printf: |%10d|\n", 42);
	test_return_values(org, ft, test_num++);
	// Precision tests
	printf("\nTest %d: Precision only\n", test_num);
	org = printf("Printf:    |%.5d|\n", 42);
	ft = ft_printf("ft_printf: |%.5d|\n", 42);
	test_return_values(org, ft, test_num++);
	// Width + Precision combinations
	printf("\nTest %d: Width and precision\n", test_num);
	org = printf("Printf:    |%10.5d|\n", 42);
	ft = ft_printf("ft_printf: |%10.5d|\n", 42);
	test_return_values(org, ft, test_num++);
	// Minus flag combinations
	printf("\nTest %d: Minus flag with width\n", test_num);
	org = printf("Printf:    |%-10d|\n", 42);
	ft = ft_printf("ft_printf: |%-10d|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Minus flag with width and precision\n", test_num);
	org = printf("Printf:    |%-10.5d|\n", 42);
	ft = ft_printf("ft_printf: |%-10.5d|\n", 42);
	test_return_values(org, ft, test_num++);
	// Plus flag combinations
	printf("\nTest %d: Plus flag only\n", test_num);
	org = printf("Printf:    |%+d|\n", 42);
	ft = ft_printf("ft_printf: |%+d|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Plus flag with width\n", test_num);
	org = printf("Printf:    |%+10d|\n", 42);
	ft = ft_printf("ft_printf: |%+10d|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Plus flag with precision\n", test_num);
	org = printf("Printf:    |%+.5d|\n", 42);
	ft = ft_printf("ft_printf: |%+.5d|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Plus and minus flags with width\n", test_num);
	org = printf("Printf:    |%+-10d|\n", 42);
	ft = ft_printf("ft_printf: |%+-10d|\n", 42);
	test_return_values(org, ft, test_num++);
	// Space flag combinations (space is ignored when plus is present)
	printf("\nTest %d: Space flag only\n", test_num);
	org = printf("Printf:    |% d|\n", 42);
	ft = ft_printf("ft_printf: |% d|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Space flag with width\n", test_num);
	org = printf("Printf:    |% 10d|\n", 42);
	ft = ft_printf("ft_printf: |% 10d|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Space flag with precision\n", test_num);
	org = printf("Printf:    |% .5d|\n", 42);
	ft = ft_printf("ft_printf: |% .5d|\n", 42);
	test_return_values(org, ft, test_num++);
	// Zero flag combinations (zero is ignored with precision or minus)
	printf("\nTest %d: Zero flag with width\n", test_num);
	org = printf("Printf:    |%010d|\n", 42);
	ft = ft_printf("ft_printf: |%010d|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Zero and plus flags with width\n", test_num);
	org = printf("Printf:    |%+010d|\n", 42);
	ft = ft_printf("ft_printf: |%+010d|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Zero and space flags with width\n", test_num);
	org = printf("Printf:    |% 010d|\n", 42);
	ft = ft_printf("ft_printf: |% 010d|\n", 42);
	test_return_values(org, ft, test_num++);
	// Zero flag ignored cases
	printf("\nTest %d: Zero flag with precision (zero should be ignored)\n",
		test_num);
	org = printf("Printf:    |%010.5d|\n", 42);
	ft = ft_printf("ft_printf: |%010.5d|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Zero flag with minus (zero should be ignored)\n",
		test_num);
	org = printf("Printf:    |%-010d|\n", 42);
	ft = ft_printf("ft_printf: |%-010d|\n", 42);
	test_return_values(org, ft, test_num++);
	// Complex combinations
	printf("\nTest %d: All valid flags together\n", test_num);
	org = printf("Printf:    |%+-10.5d|\n", 42);
	ft = ft_printf("ft_printf: |%+-10.5d|\n", 42);
	test_return_values(org, ft, test_num++);
	// Edge cases with various flag combinations
	printf("\nTest %d: Zero value with precision zero\n", test_num);
	org = printf("Printf:    |%.0d|\n", 0);
	ft = ft_printf("ft_printf: |%.0d|\n", 0);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: INT_MAX with all valid flags\n", test_num);
	org = printf("Printf:    |%+-10.5d|\n", INT_MAX);
	ft = ft_printf("ft_printf: |%+-10.5d|\n", INT_MAX);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: INT_MIN with all valid flags\n", test_num);
	org = printf("Printf:    |%+-10.5d|\n", INT_MIN);
	ft = ft_printf("ft_printf: |%+-10.5d|\n", INT_MIN);
	test_return_values(org, ft, test_num++);
	// Negative numbers with various flag combinations
	printf("\nTest %d: Negative number with plus (plus is ignored)\n",
		test_num);
	org = printf("Printf:    |%+d|\n", -42);
	ft = ft_printf("ft_printf: |%+d|\n", -42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Negative number with space (space is ignored)\n",
		test_num);
	org = printf("Printf:    |% d|\n", -42);
	ft = ft_printf("ft_printf: |% d|\n", -42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Negative number with zero padding\n", test_num);
	org = printf("Printf:    |%010d|\n", -42);
	ft = ft_printf("ft_printf: |%010d|\n", -42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Negative number with all valid flags\n", test_num);
	org = printf("Printf:    |%+-10.5d|\n", -42);
	ft = ft_printf("ft_printf: |%+-10.5d|\n", -42);
	test_return_values(org, ft, test_num++);
	printf("\n=== TESTING %%u ===\n");
	// %u works with width, precision, minus flag, and zero flag
	printf("\nTest %d: Basic unsigned\n", test_num);
	org = printf("Printf:    |%u|\n", 42);
	ft = ft_printf("ft_printf: |%u|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Width\n", test_num);
	org = printf("Printf:    |%10u|\n", 42);
	ft = ft_printf("ft_printf: |%10u|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Left-aligned width\n", test_num);
	org = printf("Printf:    |%-10u|\n", 42);
	ft = ft_printf("ft_printf: |%-10u|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Precision\n", test_num);
	org = printf("Printf:    |%.5u|\n", 42);
	ft = ft_printf("ft_printf: |%.5u|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Zero padding\n", test_num);
	org = printf("Printf:    |%010u|\n", 42);
	ft = ft_printf("ft_printf: |%010u|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Width and precision\n", test_num);
	org = printf("Printf:    |%10.5u|\n", 42);
	ft = ft_printf("ft_printf: |%10.5u|\n", 42);
	test_return_values(org, ft, test_num++);
	// Edge cases
	printf("\nTest %d: Zero value\n", test_num);
	org = printf("Printf:    |%u|\n", 0);
	ft = ft_printf("ft_printf: |%u|\n", 0);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: UINT_MAX\n", test_num);
	org = printf("Printf:    |%u|\n", UINT_MAX);
	ft = ft_printf("ft_printf: |%u|\n", UINT_MAX);
	test_return_values(org, ft, test_num++);
	printf("\n=== TESTING %%x and %%X ===\n");
	// %x/%X work with width, precision, minus flag, zero flag, and hash flag
	printf("\nTest %d: Basic hex lower\n", test_num);
	org = printf("Printf:    |%x|\n", 42);
	ft = ft_printf("ft_printf: |%x|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Basic hex upper\n", test_num);
	org = printf("Printf:    |%X|\n", 42);
	ft = ft_printf("ft_printf: |%X|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Width\n", test_num);
	org = printf("Printf:    |%10x|\n", 42);
	ft = ft_printf("ft_printf: |%10x|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Left-aligned width\n", test_num);
	org = printf("Printf:    |%-10x|\n", 42);
	ft = ft_printf("ft_printf: |%-10x|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Precision\n", test_num);
	org = printf("Printf:    |%.5x|\n", 42);
	ft = ft_printf("ft_printf: |%.5x|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Zero padding\n", test_num);
	org = printf("Printf:    |%010x|\n", 42);
	ft = ft_printf("ft_printf: |%010x|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Hash flag lower\n", test_num);
	org = printf("Printf:    |%#x|\n", 42);
	ft = ft_printf("ft_printf: |%#x|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Hash flag upper\n", test_num);
	org = printf("Printf:    |%#X|\n", 42);
	ft = ft_printf("ft_printf: |%#X|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: All flags combined lower\n", test_num);
	org = printf("Printf:    |%#-10.5x|\n", 42);
	ft = ft_printf("ft_printf: |%#-10.5x|\n", 42);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: All flags combined upper\n", test_num);
	org = printf("Printf:    |%#-10.5X|\n", 42);
	ft = ft_printf("ft_printf: |%#-10.5X|\n", 42);
	test_return_values(org, ft, test_num++);
	// Edge cases
	printf("\nTest %d: Zero value (hash flag should be ignored)\n", test_num);
	org = printf("Printf:    |%#x|\n", 0);
	ft = ft_printf("ft_printf: |%#x|\n", 0);
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: UINT_MAX\n", test_num);
	org = printf("Printf:    |%#x|\n", UINT_MAX);
	ft = ft_printf("ft_printf: |%#x|\n", UINT_MAX);
	test_return_values(org, ft, test_num++);
	printf("\n=== TESTING %% ===\n");
	// %% works with width, minus flag, and zero flag
	printf("\nTest %d: Basic percent\n", test_num);
	org = printf("Printf:    |%%|\n");
	ft = ft_printf("ft_printf: |%%|\n");
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Width\n", test_num);
	org = printf("Printf:    |%5%|\n");
	ft = ft_printf("ft_printf: |%5%|\n");
	test_return_values(org, ft, test_num++);
	printf("\nTest %d: Left-aligned width\n", test_num);
	org = printf("Printf:    |%-5%|\n");
	ft = ft_printf("ft_printf: |%-5%|\n");
	test_return_values(org, ft, test_num++);
	org = printf("Printf:    |%05%|\n");
	ft = ft_printf("ft_printf: |%05%|\n");
	test_return_values(org, ft, test_num++);
	return (0);
	printf("\nTest %d: Zero padding\n", test_num);
}

int	main(void)
{
	char	*format;
	int		count;
	int		count2;
	int		uint;

	test();
	format = "|%5%|\n";
	uint = 0;
	count = printf(format, uint);
	count2 = ft_printf(format, uint);
	test_return_values(count, count2, 0);
}
