use std::fs;
mod tokenizer;


//58:05
//TODO : turen tokens into assembly now

fn main() {
//tokenize code
    let readfile = fs::read_to_string("test.volare").expect("Didnt read");
    let returntokens = tokenizer::tokenize(&readfile);
    println!("tokenize finished:");
    println!("{:#?}", returntokens);

}





