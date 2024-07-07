use std::fs;
mod tokenizer;


fn main() {
    let readfile = fs::read_to_string("test.v").expect("Didnt read");
    tokenizer::tokenize(&readfile);
    println!(" ");
}





