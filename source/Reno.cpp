#include "../include/Reno.hpp"

Reno::Reno(Mechanism_/*attributes*/)
{
  Mechanism = Mechanism_;
  //etc...
}

void Reno::change_mech(std::string newMech)
{
  mechanism = newMech;
}

void Reno::Mult_cwnd(int num)
{
  cwnd = cwnd * num;
}

void Reno::decrement_size(int num)
{
  data_size -= num;
}

void Reno::increment_cwnd(int num)
{
  cwnd += num;
}

void Reno::SendData()
{
  if(mechanism == Mechanism[Fast_Retransmit])
  {
    should_sent_again = cwnd - 1;
    if(should_sent_again > 0)
      return;
    change_mech(Mechanism[Congestion_Avoidence]); 
    not_ACKed_yet -= 1;
  }
  else
  {
    decrement_size(1);
    if(mechanism == Mechansim[Slow_Start])
    {
      if(cwnd > ssthresh || cwnd == ssthresh)
      {
        change_mech(Mechanism[Congestion_Avoindence]);  
      }
      else
      {
        Mult_cwnd(2);
      }
    }
    else if(mechanism == Mechanism[Congestion_Avoidence])
    {
      increment_cwnd(1);
    }
    else if(mechanism == Mechanism[Fast_Reconvery])
    {
      div_cwnd_by(2);
      ssthresh = cwnd;
      change_mech(Mechansim[Fast_Retransmit]);
    }
  }
}




