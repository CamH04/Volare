use std::fs;
mod tokenizer;
mod tokentoasm;

use std::process::Command;;

fn main() {
//tokenize code
    let readfile = fs::read_to_string("test.volare").expect("Didnt read");
    let returntokens = tokenizer::tokenize(&readfile);
    //println!("tokenize finished:");
    //println!("{:#?}", returntokens);

    //turn tokens into assembly
    tokentoasm::token_to_asm(returntokens);


    //Command::new()

    //nasm -f elf64 volare.asm
    //ld -s -o volare volare.o
    //./volare

}





