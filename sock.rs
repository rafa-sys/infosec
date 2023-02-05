use std::io::{self, Read, Write};
use std::net::TcpStream;

fn main() {
    let mut stream = TcpStream::connect("example.com:80").unwrap();

    // Send a GET request to the server
    let request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    stream.write(request.as_bytes()).unwrap();

    // Read the response from the server
    let mut response = String::new();
    stream.read_to_string(&mut response).unwrap();

    println!("Response: {}", response);
}
