// lexer stuff
#[derive(Debug)]
enum TokenTypes{
    Return_,
    IntLit_,
    Semi_,
}

#[derive(Debug)]
pub struct Token{
    token_type: TokenTypes,
    value: Option<char>,
}

pub fn tokenize(str: &str) -> Vec<Token>{
    //buffer vectors
    let mut buffer: Vec<char> = vec![];
    let mut tokenbuffer = vec![];


    //iterate over file
    for (_i,c) in str.chars().enumerate(){
        if c.is_whitespace(){
        println!("whitespace");
        }
        //every alphbetic char is pushed to buffer
        else if c.is_alphabetic(){
            buffer.push(c);
        }
        //pushes single numbers into buffers
        else if c.is_numeric(){
            println!("number");
            buffer.push(c);
            tokenbuffer.push(Token{token_type: TokenTypes::IntLit_, value:Some(c)});
            buffer.clear();
        }
        else if c == ';'{
        println!("semicolon");
        tokenbuffer.push(Token{token_type: TokenTypes::Semi_, value:None});
        }
        let buffercontent: String = buffer.iter().collect();

        //push return token to token vector
        if  buffercontent.contains("return"){
            println!("return");
            tokenbuffer.push(Token{token_type: TokenTypes::Return_, value:None});
            buffer.clear();
        }
        else{
            //println!("nothing detected");
        }
    }
    return tokenbuffer;
}
