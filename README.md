# Project 02: 42_printf


## Replicating the printf function
</br>

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/opacaud/ft_printf)](https://github.com/JaeSeoKim/badge42)
</br>

</br>
Handling c, s, d, i, u, x, X, p and % specifiers and -, 0, . and * flags.
</br>
</br>

### Description:
</br>
What I did implement:
</br>

* **specifiers**: d, i, u, x, X, p, c, s and %
* **flags**: number, -, ., 0 and *

I also implemented it so that it returns what the real printf returns which is the number of characters it printed.
</br>
</br>

#### <ins>Specifiers</ins> :capital_abcd:
</br>

If you are not familiar with these -I was not at first- let me try to explain them to you.

Specifier | For printing... |
--- | --- |
**d or i** | an int |
**u** | an unsigned int |
**x** | an unsigned int written in its hexadecimal form, using lowercase letters, so 0123456789abcdef |
**X** | an unsigned int written in its hexadecimal form, using uppercase letters, so 0123456789abcdef |
**p** | a pointer (so an address) |
**c** | one character |
**s** | a string of characters |
**%** | an actual % |

    Examples:

    int min = -2147483648;  <--- int
    printf("%d\n", min);    <--- d specifier

    char *str = "bonjour";  <--- string
    printf("%s\n", str);    <--- s specifier


</br>
</br>

#### <ins>Flags</ins> :rainbow_flag::white_flag:
</br>

The flags are used to present information a certain way.
- you can just indicate **a number** which will be the **width** of the output.

        Examples:

        %10d --->          4 if you want to print the number 4: 9 spaces and the number.

        %10d --->         42 if you want to print the number 42: 8 spaces and the number.

    *Please note that if the width is lower than the number of digits, it will not truncate the number or the string you wish to print.*

        Examples:

        %5d ---> 2147483647 if you wish to print 2147483647

        %5s ---> bonjour if you wish to print bonjour
</br>

- **- followed by a number (width)** will **print your variable on the left of said width**:

        Examples:

        %-10d ---> 4          if you want to print the number 4: the number and 9 spaces.

        %-10d ---> 42         if you want to print the number 42: the number and 8 spaces.

    *Please note that if the width is lower than the number of digits, it will not truncate the number or the string you wish to print.*

        Examples:

        %-5d ---> 2147483647 if you wish to print 2147483647

        %-5s ---> bonjour if you wish to print bonjour
</br>

- **. followed by a number** indicating the **precision** you want to see

        Examples:

        %.10d ---> 0000000004 if you want to print the number 4: 9 zeroes and the number.

        %.10d ---> 0000000042 if you want to print the number 42: 8 zeroes and the number.

    *Please note that if the precision is lower than the number of digits, it will not truncate the number you wish to print but it will truncate the string you wish to print.*

        Examples:

        %5d ---> 2147483647 if you wish to print 2147483647

        %5s ---> bonjo if you wish to print bonjour
</br>

- **0 followed by a number (precision) and add zeroes** to get to the precision you indicated.

        Examples:

        %010d ---> 0000000004 if you want to print the number 4: 9 zeroes and the number.

        %010d ---> 0000000042 if you want to print the number 42: 8 zeroes and the number.

    *Please note that it does not work with strings and if the width is lower than the number of digits, it will not truncate the number you wish to print.*

        Examples:

        %05d ---> 2147483647 if you wish to print 2147483647
</br>
</br>

What's the difference between 0 and . you might ask? Well it is more obvious if you try to print a negative number.

    Examples:

    %015d ---> -00002147483647
    %.15d ---> -000002147483647

The zeroes will fill in so that the precision 15 is achieved. So when you wish to print a ten-digit number such as 2147483647, it will print the minus, follow by 4 zeroes and the 10 digits. It is called zero padding.
While the point is aiming at precision. So it will print the minus, then the 15 digits that you asked so in this case, 5 zeros and the 10 digits so that you print indeed 15 digits. It is pure precision.

- **\* allows you to specify width or precision as an argument** and not embedded in the string itself.

        Examples:

        int min = -2147483648;

            ft_printf("%10d\n", min);
        can become
            ft_printf("%*d\n", 10, min);

        and

            ft_printf("%.10d\n", min);
        can become
            ft_printf("%.*d\n", 10, min);

        and even

            ft_printf("%20.15d\n", min);
        can become
            ft_printf("%*.*d\n", 20, 15, min);
</br>
</br>

#### <ins>How to test my code?</ins> :raised_eyebrow: :question: :heavy_check_mark:
</br>

You can use "make" to generate an executable called ft_printf.
It compiles my code using gcc -Wall -Wextra -Werror.
So you can right away run these two commands, one after the other:

```make```

```./ft_printf```

You will see a list of calls to "my" printf and the real printf so that you can compare. (As well as the value of the int my function and the real printf returned.)

If you open ft_printf.c, you will see that, at the bottom, in the main function, I commented a lot of lines (a lot, a lot).
They are tests, ordered by specifiers, then by flags. All you have to do is uncomment the portion you wish to test.

You are welcome to run your own tests though. To do so, just change the content of the main function as you wish.
I know it is not easy to understand what I did take into account and what I did not. That is why I took the liberty to write all these tests. And I tried to include all the possibilities.
But feel free to try yourself if you think of a possibility I seem to have forgotten!
If in doubt, do not hesitate to contact me and I will in all honesty tell you if I made a mistake (as I intended to take care of the case you saw fail) or if it is "normal".

You should know that for instance, the flags - and 0 cannot work at the same time. Same goes for . and 0.
Moreover, p and c specifiers do not work with . and 0 flags and s specifier does not work with the 0 flag.
Keep in mind that I initially implemented my version of printf on iOS and I realized some behaviors, especially when empty or null strings are passed to printf, may differ under Windows for instance.
</br>
</br>

#### <ins>How did I implement all that?</ins> :shrug:
</br>

I started by studying printf. Through the man page or articles like [this one](https://www.cypress.com/file/54441/download).
I especially had to get to know more about va\_start, va\_arg, va\_end to handle an unknown number of parameters.
Then I took a piece of paper and a pen to organize my thoughts and determine how to go about it, as I always do.
I decided to resort to some kind of referral system.
- I am given a string. As long as I don't come across a '%' I simply print.
- When I do come across a '%', if it is not followed immediately by another '%', I analysed what is between the '%' and the specifier (d, i, u, x, X, p, c, s or %).
  If I see a point, I go one way. If I don't I go another.
- No matter which way I am going down, at this point, I have three options (three on one way and the same three on the other) as there are three flags : 0, - or no flag.
- Again, no matter which way I have to take, I will now have as many possibilities as I have specifiers, so 8 (since d and i are the same).
- I am finally in the right function since I know if I have a precision to take into account (. or no .), another flag like - or 0 and finally, the type of conversion that is asked (specifier).
  So I can just go ahead and treat that particular case by getting the width, the precision if applicable, the value that needs to be printed and print the right amount of zeroes or spaces, the variable, etc.
I cannot say that my way is the smartest and certainly not the quickest or lightest but I think it is working and quite clear.
As long as you did not get lost along the way you are supposed to take depending on the factors I described before.
</br>

#### <ins>SUMMARY</ins> :grinning:
</br>

So if you correctly followed my train of thought...
- My code starts in the ft\_printf.c file.
- Then, depending on if there is a point or not in the string to be interpreted, you'll either want to go in the ft\_printf\_no\_point... files or ft\_printf\_point... ones.
- Then, I check for flags so I either go in the "simple file" that goes (no_)point_... or in the (no_)point_d_... file (d for "dash") or the (no_)point_z_... file (z for "zero").
- Finally, I use the other files to print things how they should be at the end of each road.
</br>
</br>

Hope you enjoyed discovering my work as much as I enjoyed implementing it! :grinning: :see\_no_evil:
</br>
</br>
See you soon! :wave:
