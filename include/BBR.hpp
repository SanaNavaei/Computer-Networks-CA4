#ifndef __BBR_HPP__
#define __BBR_HPP__

#include <iostream>

#define Slow_Start 0
#define Congestion_Avoidence 1
#define Fast_Recovery 2
#define Fast_Retransmit 3

class BBR
{
private:
  std::vector<std::string> Mechanism;

public:
  BBR(Mechanism_/*attributes*/);
}

#endif
