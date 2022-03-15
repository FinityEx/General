#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>



using namespace boost::asio;
using std::cout;
using std::cin;
using std::endl;
using namespace std::placeholders;

class connection : public boost::enable_shared_from_this<connection> {
private:
	ip::tcp::socket socket_;
	boost::asio::streambuf streambuf_;


	void read()
	{
		boost::asio::async_read(socket_, streambuf_, boost::asio::transfer_at_least(1), std::bind(&connection::on_read, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
	}

	void on_read(boost::system::error_code error, std::size_t bytes_transferred)
	{
		if (!error)
		{
			//server received a buffer, write it back
			write();
		}
		else {
			cout << "Error: " << error.what();
		}
	}

	void write()
	{
		boost::asio::async_write(socket_, streambuf_, std::bind(&connection::on_write, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
	}

	void on_write(boost::system::error_code error, std::size_t bytes_transferred)
	{
		if (!error)
		{
			//server sent , read new one
			read();
		}
		else {
			cout << "Error: " << error.what();
		}
	}

public:
	typedef boost::shared_ptr<connection> ptr;
	connection(io_context& io) : socket_(io) {
	}

	static ptr create(boost::asio::io_context& io) {
		return ptr(new connection(io));
	}

	ip::tcp::socket& socket() {
		return socket_;
	}

	void start() {
		//read on start
		read();
	}


	
};



class server {
private:
	void start_accept() {
		connection::ptr new_connection = connection::create(io_);

		acceptor_.async_accept(new_connection->socket(),
			boost::bind(&server::handle_accept, this, new_connection,
				placeholders::error));
	}

	void handle_accept(connection::ptr new_connection, const boost::system::error_code& e) {
		if (!e) {
			new_connection->start();
		}

		start_accept();
	}

	io_context& io_;
	ip::tcp::acceptor acceptor_;

public:
	//start listening in port 13
	server(io_context& io) : io_(io), acceptor_(io, ip::tcp::endpoint(ip::tcp::v4(), 13))
	{
		start_accept();
	}
};



int main() {
	try {
		boost::asio::io_context io;
		server server(io);
		io.run();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << endl;
	}
	return 0;
}