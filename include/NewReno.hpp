#ifndef __NEWRENO_HPP__
#define __NEWRENO_HPP__

#include <iostream>

#define Slow_Start 0
#define Congestion_Avoidence 1
#define Fast_Recovery 2
#define Fast_Retransmit 3

class NewReno
{
private: 
  std::vector<std::string> Mechanism;

public:
  NewReno(Mechanism_/*attributes*/);
}

#endif
