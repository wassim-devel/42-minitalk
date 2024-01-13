# 42-minitalk
minitalk project at 42 School.


This project, from the common core of 42 School, aims to learn how to send and handle signals in C.

The server handle two signals, SIGUSR1 and SIGUSR2, they are respectively interpreted as binary 0 and 1. Client convert a string to binary, and the server convert the binary into a string
Using signals is the worst way of sending data between processes, they don't exist for this purpose. So depending on your computer, it may not work without increasing usleep (sending signals too fast can cause problems)

These programs (server and client) are written entirely in C.

Only some functions were authorized, you can find them in the subject: 
[Full subject](https://cdn.intra.42.fr/pdf/pdf/105639/fr.subject.pdf)

Organization of files, readability of code and/or the names of functions and variables can seem awful, because of the 42 Norm that limits the length of a line to 80, number of functions in a file to 5, and number of lines in a function to 25.
