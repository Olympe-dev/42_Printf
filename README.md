# 42_Printf


**Replicating the printf function. (Handling c, s, d, i, u, x, X, p and % specifiers and -, 0, . and * flags.)**


############################################


How did I do it?

Example:
```
int main(void)
{
  char  *name;
  int   age;
  
  name = "Olympe";
  age = 28;
  
  ft_printf("Hello world! I'm 100%% French! My name is %s, I'm %d years old.\n", name, age);

  return (0);
}
```
I go through the string passed to ft_printf, character by character. ("Hello world! I'm 100%% French! My name is %s, I'm %d years old.\n")
Then three options :
- It is not a %, I just print it. ("**Hello world! I'm 100**" for instance.)
- It is a % and immediately followed by another % so I simply print one % and keep going. ("****%**** French! My name is ")
- It is a % and followed by one of these specifiers : c, s, d, i, u, x, X, p, % (not immediately) or one of these flags : -, 0, . or \*, I send the string and the index to a function that will then send them to the relevant function depending on the specifier and the flags and so on and so forth. ("**Olympe**, I'm **28** years old.\n")

As you may have guessed, this last case is the one that took me the longest to implement. Because you see, when flags join the party, it is a whole other kind of fun. But fun, that it was. **I absolutely loved reproducing this function.** I could talk for hours about the way I decided to reproduce the third case but stay assured, I will not. Not here at least. Because if you do want to know though, I would be happy to tell you!

Thank you for reading me! Have a nice day! :grin:
