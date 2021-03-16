This repository is the home of Rachel and I's hand made printf program.

Our program will have the same functionality of <stdio.h>'s printf.

You are able to print whatever you want with it, but as of now we only have the following specifiers
accounted for:

	%c for chars,	 	 %s for strings,	 %% for printing a %,
	%d for integers,	 %i for integers also,	 %u for unsigned ints,
	%b for binary,		 %R for rot13,		 %o for unsigned octal,
	%x for lowercase hexidecimal,		         %X for uppercase hexidecimal,
	%r for reversing a string

Our return will always be count, with count being how many characters are passed.
