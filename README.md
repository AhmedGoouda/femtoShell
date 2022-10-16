# femtoShell

### Linux Shell Imitation 

An ongoing project to imitate Linux Shell.

The femtoShell commands are starting with the letter ' f ', corresponding to the main shell command without ' f '. For example, femtoShell command 'fecho' imitates the Linux Shell command 'echo'.

**Currently supported commands:**

1. fexit
1. fecho
1. fpwd
1. fcp
1. fmv

### Compilation commands

```bash
gcc -o fecho echo.c
gcc -o fpwd pwd.c
gcc -o fcp file_open_close.c file_read_write.c cp.c
gcc -o fmv file_open_close.c file_read_write.c mv.c
gcc -o femtoShell input_getter.c tokenizer.c femtoShell.c
```