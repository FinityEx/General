#include <iostream>
#include <string>
#include <boost/asio.hpp>


using namespace boost::asio;
using std::cout;
using std::cin;
using std::endl;
using std::string;


int main(){
    string msg;
    boost::asio::io_context io;
    ip::tcp::socket socket(io);
    boost::system::error_code error;
    boost::asio::streambuf receive_buffer;

    //connect on port 13
    socket.connect(ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 13));


    do {
        cout << "Your message: ";
        std::getline(cin, msg);
        //write message to socket
        boost::asio::write(socket, boost::asio::buffer(msg + "\n"), error);
        //read from socket
        boost::asio::read_until(socket, receive_buffer, '\n'); 
        if (error && error != boost::asio::error::eof) {
            cout << "receive failed: " << error.message() << endl;
        }
        else {
            //convert streambuf to char type and print its content
            const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
            cout << "Server's response: " << data << endl;
            //then reset to avoid streambuf overflow
            receive_buffer.consume(1024);
            
        }

    } while (msg != "exit"); 

    cout << "See your around!\n";

    return 0;
}