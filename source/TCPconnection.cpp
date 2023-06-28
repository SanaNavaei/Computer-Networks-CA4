#include "../include/TCPconnection.hpp"
#include "../include/Reno.hpp"
#include "../include/NewReno.hpp"
#include "../include/BBR.hpp"

TCPconnection::TCPconnection();

void TCPconnection::run()
{
    Reno reno_connnection(/*attributes*/);
    NewReno newReno_connection(/*attributes*/);
    BBR bbr_connection(/*attributes*/);
}
