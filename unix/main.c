// Volare (stack based language)


//-----------instruction set-------------
//PUSH (int)                            - push to stack
//POP                                   - pop stack
//ADD                                   - pops 2 ints from stack and adds, pushes result to stack
//SUB                                   - pops 2 ints from stack and subtracts, pushes result to stack
//PRINT(string)                         - prints string to terminal
//READ                                  - reads int from I/O, pushes result to stack
//JEQ(label)                            - jumps to label if top of stack is = 0
//JGT(label)                            - jumps to label if top of stack is > 0
//JLT(label)                            - jumps to label if top of stack is < 0
//HALT                                  - stops program

//eg program , checking if 2 numbers are equal / the same
//READ
//READ
//SUB
//JEQ L1
//PRINT "not the same"
//HALT

//L1:
//PRINT "the same"
//HALT

//----------------------------------------------------------------------------------------------------------------------------------------------
//TODO

// read from file with extention .vpw (for windows) or .vpl for linux
//-----------------------------------------------------------------------
//tokanise each line:
//      read every line: each line will be a label or instruction
//      if opcode is empty go next line
//      we add opcode to token array
//          if opcode takes args add to token array (eg PRINT)
//-----------------------------------------------------------------------
//convert tokens to asm:
//      read from token array
//      convert token and args to an asm eqiuvilent
//      output to a .asm file of the same name as volare file


int main(){
    return 0;
}