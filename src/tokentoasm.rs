use crate::tokenizer::Token;
use crate::tokenizer::TokenTypes;

use std::fs::File;
use std::io::Write;


pub fn token_to_asm(tokenvec: Vec<Token>) -> String{

    //initing asm file
    let mut asmfile = File::create("volare.asm").expect("error in creating file");
    asmfile.write_all("section      .text\n".as_bytes()).expect("error in writing data");
    asmfile.write_all("global       _start\n".as_bytes()).expect("error in writing data");
    asmfile.write_all("_start:\n".as_bytes()).expect("error in writing data");
    //for later
    let mut output:String = "    mov rdi, ".to_string();
    //acc going through tokens
    for givetoken in tokenvec{
        //pushing any numeric values to temp string
        if givetoken.value != Option::None{
            let holdvalue:String = givetoken.value.expect("ERROR IN VALUE").to_string();
            output.push_str(&holdvalue);
            output.push_str(" \n");
        }
        match givetoken.token_type{
        TokenTypes::Return_ =>
            asmfile.write_all("    mov rax, 60\n".as_bytes()).expect("error in writing data"),
        TokenTypes::IntLit_ =>
            asmfile.write_all(output.as_bytes()).expect("error in writing data"),
        TokenTypes::Semi_ =>
           asmfile.write_all("    syscall\n".as_bytes()).expect("error in writing data"),
        _ => println!("error, how did this happen @v@"),
        }
    }



    return output;
}
