use std::fs;

fn main() {
    let readfile = fs::read_to_string("test.v").expect("Didnt read");
    println!("{readfile}");
}
