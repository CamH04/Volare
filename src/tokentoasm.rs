use crate::tokenizer::Token;
use crate::tokenizer::TokenTypes;

use std::fs::File;
use std::io::Write;


pub fn token_to_asm(tokenvec: Vec<Token>) -> String{

    //initing asm file
    let mut asmfile = File::create("volare.asm").expect("error in creating file");
    asmfile.write_all("global _start\n".as_bytes()).expect("error in writing data");
    asmfile.write_all("_start:\n".as_bytes()).expect("error in writing data");
    //for later
    let output:String = "".to_string();
    //acc going through tokens
    for givetoken in tokenvec{
        match givetoken.token_type{
        TokenTypes::Return_ =>
            //output.push_str("return "),
            asmfile.write_all("    mov rax, 60\n".as_bytes()).expect("error in writing data"),
        TokenTypes::IntLit_ =>
        //TODO hardcoded for now but need to get from value
            //output.push(givetoken.value.expect("error in token int value")),
            asmfile.write_all("    mov rdi, 0\n".as_bytes()).expect("error in writing data"),

        TokenTypes::Semi_ =>
           //output.push(';'),
           asmfile.write_all("    syscall\n".as_bytes()).expect("error in writing data"),
        _ => println!("error, how did this happen @v@"),
        }
    }



    return output;
}
