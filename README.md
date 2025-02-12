# Minitalk

Minitalk is a simple project that demonstrates interprocess 
communication (IPC) using UNIX signals. It consists of a 
server and a client that communicate by sending signals.
_______________________________________________________________
### How It Works

Client Side:

Converts each character of the message into binary.
Sends each bit to the server using signals:

* SIGUSR1 for binary 1.

* SIGUSR2 for binary 0.

In the normal version, the client waits a fixed amount of 
time (using usleep(300)) after sending each bit.

In the bonus version, the client waits for an 
acknowledgment from the server before sending the next bit.

Server Side:

Receives signals and reconstructs the message bit by bit.
Prints the complete message when the transmission ends.
In the bonus version, the server manages multiple clients by 
processing one message at a time.
_______________________________________________________________
### Usage

Start the Server:

./server

The server will display its PID.

Send a Message from the Client:

./client <server_pid> "Your message here"
_______________________________________________________________
Notes
Normal Version: Uses a fixed delay (usleep(300)) after each bit.
Bonus Version: Uses a handshake mechanism for more reliable 
communication, especially when multiple clients are sending 
messages at the same time.
Feel free to customize this README as needed!
