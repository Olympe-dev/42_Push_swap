# 42_Push_swap

## We had to write a sorting algorithm using only another stack and specific moves chosen by 42 and make it as optimal as possible (use as fewer moves as possible).

1. Compile with make.
2. Pass a series of int (up to 500) as arguments to the executable called push_swap. *(Ex. ./push_swap 2147483647 0 32498 126 -75456 -7619 321654)* There can be **no duplicate, no letters or other characters and no number that do not fit in an int**.
3. It will print all the moves that need to be done to sort the list of int you passed as arguments.
  * **pb** : pushes the int on top of stack A (the original series of int you gave the executable) to the top of stack B
  * **pa** : the other way around
  * **sa** : switches the first two elements of stack A
  * **sb** : same but on stack B
  * **ss** : both at the same time
  * **ra** : the first element of stack A goes at the bottom. As a result, everything moves up one step as well
  * **rb** : same but with stack B
  * **rr** : both at the same time
  * **rra** : the last element of stack A goes at the top. As a result, everything moves down one step as well
  * **rrb** : same but with stack B
  * **rrr** : both at the same time

### How I decided to go about it

1. I check args : at least two of them, only figures (no letters or other characters, apart from - or +)
2. I create the array of long (stack A) with the numbers received and then I check if none of them are < -2147483648 or > 2147483647, if there is no duplicate.
3. I create the second array of long (stack B) that I fill with -2147483649.
4. I check if the array is not simply all the way upside down so I put it back up.
5. I finally take action according to the length of the array (so the number of int you passed as arguments)
  * It can be 2 and if its not sorted, I simply do a sa
  * It can be 3 in which case I brute force solve the five possibilities
  * It can be 4 or 5 so I push on stack B the first or first two elements (pb), apply the algorithm for 3 on stack A and push back what is on stack B at the right place in stack A and finally the smallest number on top in stack A
  * It can be up to a 100 or even 500.
    * I get the value of the smallest int
    * I get the value of the biggest int
    * I get the difference between them
    * I divide that difference by 5 if you typed between 6 and 100 numbers, by 12.5 if you typed between 101 and 500 numbers. *(Ex. You typed all the numbers between 1 and 100, inclusive, in an unsorted fashion of course. That will create a difference of 99 and, divided by 5 (because 100 numbers), that will give me chunks of 20.)*
    * I find the first int that belongs to the first chunk and the last int that belongs to the first chunk.
    * I determine which one can be the quickest brought on top of stack A. *(Ex. If the first int is at index 10 and the last int is at index 98. It will be easiest to bring the index 98 to 0 with two rra, than to bring index 10 with nine ra.)* I do bring it on top.
    * I make sure stack B is ready to receive the int by adjusting it with rb and rrb so that I do not insert that new int anywhere in stack B. I then push it on B with pb.
    * I repeat until there is no int left from that first chunk going from 0 to 19.
    * I repeat for the second chunk: 20 to 39. And so on.
    * In the end, I have my list upside down on stack B.
    * I simply push it all on stack A one by one.

### How many moves is that?

You can simply add | wc -l so it counts the number of instructions were actually needed to sort the int you gave.
In order to have 5/5 for 100 numbers, you had to have less than 700 moves and I usually had a little bit more.
And in order to have 5/5 for 500 numbers, you had to have less than 5500 moves. To have 4/5, less than 7000. And again, I was often around that number.
To test my code, I used a random numbers generator: https://numbergenerator.org/randomnumbergenerator/1-100#!numbers=100&low=-2147483648&high=2147483647&unique=true&csv=&oddeven=&oddqty=0&sorted=false&addfilters=

## Bonus

### We could write a checker for that program.

1. When you compiled push_swap with make, it also compiled the bonus part and created the executable checker.
2. It kind of completes push_swap as it works the other way around. You pass the executable checker a series of int (between 1 and 500 again) and checker will do the same tests to make sure the list is okay (ac >= 2, just figures or - or +, no duplicate).
3. It will prompt you to write an instruction: one of the pb, pa, sa, sb, ss, ra, rb, rr, rra, rrb or rrr followed by Enter. And again: as much instructions as you want.
4. Hit Ctrl + C when you are done giving checker instructions.
5. Checker will apply those instructions to the ints you first passed as arguments.
6. It will tell you if the list is sorted ("OK") or not ("KO").
