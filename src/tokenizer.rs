//lexter (turns text into tokens)

pub enum TokenTypes{
    Return_,
    IntLit_,
    Semi_,
}

pub struct Token{
    pub token_type: TokenTypes,
    pub value: Option<char>,
}


pub fn tokenize(str: &str) -> Vec<Token>{
    //buffer vectors
    let mut buffer: Vec<char> = vec![];
    let mut tokenbuffer: Vec<Token> = vec![];


    //iterate over file
    for (_i,c) in str.chars().enumerate(){
        if c.is_whitespace(){
        }
        //every alphbetic char is pushed to buffer
        else if c.is_alphabetic(){
            buffer.push(c);
        }
        //pushes single numbers into buffers
        else if c.is_numeric(){
            buffer.push(c);
            tokenbuffer.push(Token{token_type: TokenTypes::IntLit_, value:Some(c)});
            buffer.clear();
        }
        else if c == ';'{
        tokenbuffer.push(Token{token_type: TokenTypes::Semi_, value:None});
        }
        let buffercontent: String = buffer.iter().collect();

        //push return token to token vector
        if  buffercontent.contains("return"){
            tokenbuffer.push(Token{token_type: TokenTypes::Return_, value:None});
            buffer.clear();
        }
    }
    return tokenbuffer;
}
