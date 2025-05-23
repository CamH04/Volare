# Volare : A stack based asm like language

## Instruction Set

+ PUSH (int)                            - push to stack
+ POP                                   - pop stack
+ ADD                                   - pops 2 ints from stack and adds, pushes result to stack
+ SUB                                   - pops 2 ints from stack and subtracts, pushes result to stack
+ PRINT(string)                         - prints string to terminal
+ READ                                  - reads int from I/O, pushes result to stack
+ JEQ(label)                            - jumps to label if top of stack is = 0
+ JGT(label)                            - jumps to label if top of stack is > 0
+ JLT(label)                            - jumps to label if top of stack is < 0
+ HALT                                  - stops program

## File Extensions
.vpw (for windows) or .vpu for linux

## Example Program
Checking if 2 numbers are the same
```
READ
READ
SUB
JEQ L1
PRINT "not the same"
HALT

L1:
PRINT "the same"
HALT
```


## Progress

### Unix
+ can read .vpu files

### Win
