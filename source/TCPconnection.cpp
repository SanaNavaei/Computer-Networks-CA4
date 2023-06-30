#include "../include/TCPconnection.hpp"

TCPconnection::TCPconnection();

void TCPconnection::run()
{
    Reno reno_connnection1(1, 1000);
    reno_connnection1.run();
    
    //NewReno newReno_connection(Mechanism/*attributes*/);
    //BBR bbr_connection(Mechanism/*attributes*/);
}

