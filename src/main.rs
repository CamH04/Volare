//44:10 ep 1
use std::fs;

// lexer stuff
enum TokenTypes{
    Return_,
    IntLit_,
    Semi_,
}

struct Token{
    t_type: TokenTypes,
    value: String,
}

fn tokenize(str: &str) {

    for (i,c) in str.chars().enumerate(){
        if c.is_alphabetic(){
            print!("{}", c);
        }

    }
}


fn main() {
    let readfile = fs::read_to_string("test.v").expect("Didnt read");
    //println!("{readfile}");

    //iterating over file content

    tokenize(&readfile);

    println!(" ");
}





