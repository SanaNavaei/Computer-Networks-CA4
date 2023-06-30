#include "../include/TCPconnection.hpp"

TCPconnection::TCPconnection()
{};

void TCPconnection::run()
{
    // Reno reno_connnection1(1, 1000);
    // reno_connnection1.run();

    // NewReno newReno_connection(1, 1000);
    // newReno_connection.run();
    
    BBR bbr_connection(1);
    bbr_connection.run();
}

