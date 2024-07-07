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



pub fn tokenize(str: &str) {
    //buffer vector
    let mut buffer = vec![];

    for (_i,c) in str.chars().enumerate(){
        if c.is_alphabetic(){
            buffer.push(c);
        }
    }
    //printing buffer
    for ch in &buffer{
        print!("{}", ch);
    }
}
