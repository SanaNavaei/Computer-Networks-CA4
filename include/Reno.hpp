#ifndef __RENO_HPP__
#define __RENO_HPP__

#include <iostream>

#define Slow_Start 0
#define Congestion_Avoidence 1
#define Fast_Recovery 2
#define Fast_Retransmit 3

class Reno
{
private: 
  std::vector<std::string> Mechanism;

public:
  Reno(Mechanism_/*attributes*/);
}

#endif
