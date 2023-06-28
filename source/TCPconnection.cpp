#include "../include/TCPconnection.hpp"

TCPconnection::TCPconnection()
{
    cwnd = 1;
    ssthresh = 65535;
    rtt = 0;
}
