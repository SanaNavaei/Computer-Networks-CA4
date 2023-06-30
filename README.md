# CN_CHomeworks_4  
**Maryam Jafarabadi Ashtiani : 810199549**  
**Sana Sari Navaei : 810199435**  

- [Introduction](#introduction)
- [Algorithms](#algorithms)
    - [Reno](#reno)
    - [NewReno](#new-reno)
    - [BBR](#bbr)
- [Code Description](#code-description)
- [Results](#results)
- [Questions](#questions)
    - [Q1](#q1)
    - [Q2](#q2)
    - [Q3](#q3)
    - [Q4](#q4)
    - [Q5](#q5)
    - [Q6](#q6)

# Introduction  
This project focuses on studying TCP congestion control algorithms, specifically BBR, Reno, and New Reno. The goal is to understand how these algorithms manage data flow over a network and prevent congestion.  

# Algorithms  

## Reno  
The `Reno algorithm` is a widely used variant of TCP congestion control that incorporates slow start, congestion avoidance, and fast recovery mechanisms to regulate the sending rate of TCP traffic. It follows a multi-phase approach to optimize network utilization and ensure fairness among competing connections.  
The algorithm begins with a slow start phase, where the sender gradually increases the congestion window (cwnd) size to explore the network's capacity. As the cwnd grows, the sender can transmit more packets, effectively probing the available bandwidth.  
Once the cwnd reaches a certain threshold, the algorithm transitions to the congestion avoidance phase. In this phase, the cwnd is incremented by a smaller value for each acknowledgment (ACK) received. This helps maintain a steady sending rate while avoiding congestion.  
If a packet loss is detected, the algorithm enters the fast recovery phase. Instead of reducing the cwnd to 1 and restarting the slow start phase, as in the original TCP algorithm, Reno's fast recovery allows the sender to recover more quickly. It reduces the cwnd to half of its current value and increments it by one for each duplicate ACK received. This allows the sender to continue sending packets without a significant decrease in throughput.  
Overall, the Reno algorithm aims to achieve high network utilization while ensuring fairness among connections by dynamically adjusting the cwnd based on network conditions and responding efficiently to packet loss events.  

## New Reno  
TCP `New Reno algorithm` is the extension of TCP Reno. It overcomes the limitations of Reno.  
### Limitation Of Reno:  
- It takes a lot of time to detect multiple packet losses in the same congestion window.  
- It reduces the congestion window multiple times for multiple packet loss in the same window, where one reduction was sufficient.  

NewReno utilizes partial acknowledgements to handle packet loss within a congestion window. Unlike TCP Reno, when the sender receives the ACK of the first retransmitted packet, it does not consider it a **New ACK.** Instead, NewReno checks if all previously transmitted packets within that window have been acknowledged. If multiple packets are lost within the same congestion window, the receiver will continue sending duplicate ACKs even after receiving the retransmitted packet. This informs the sender that not all packets have reached the receiver, and the ACK is considered partial because only a portion of the window is acknowledged. Unlike Reno, NewReno does not exit the fast recovery phase upon receiving a partial ACK. It intelligently waits until it receives a cumulative ACK for the entire congestion window before ending the fast recovery phase. This allows NewReno to promptly detect multiple packet loss without prematurely exiting the fast recovery phase, distinguishing it from Reno's behavior.  

## BBR
`BBR` is a congestion control algorithm developed by Google to optimize network performance. It dynamically adjusts the sending rate based on the available bandwidth and round-trip time (RTT) of the network.  
The BBR algorithm has two main phases: startup and congestion avoidance. During the startup phase, BBR rapidly increases the sending rate to probe the available bandwidth. It measures the delivery rate and the minimum RTT to estimate the bottleneck bandwidth.  
Once the bottleneck bandwidth is determined, BBR enters the congestion avoidance phase. It aims to maintain a stable sending rate that does not exceed the estimated bottleneck bandwidth. BBR achieves this by using a model-based approach that adjusts the sending rate based on the observed RTT and the estimated bandwidth.  
One of the key advantages of BBR is its ability to react quickly to changing network conditions. It responds more efficiently to congestion signals compared to traditional algorithms like TCP Reno or Cubic. BBR achieves high throughput, low latency, and improved network utilization, making it well-suited for modern high-speed networks.  
BBR also considers the presence of competing flows in the network. It uses a mechanism called "proportional share" to allocate bandwidth fairly among different flows, ensuring that each flow receives its fair share of the available capacity.

# Code Description  

# Results  

# Questions  

## Q1  
Congestion control and flow control are two important mechanisms in computer networks that work together to ensure efficient and reliable data transmission.  
Congestion control is primarily concerned with managing and preventing network congestion. Network congestion occurs when the demand for network resources exceeds the available capacity, leading to degraded performance, increased packet loss, and delays. The goal of congestion control is to regulate the rate at which data is sent into the network to prevent congestion from occurring or to alleviate it if it does occur.  
On the other hand, flow control operates at the transport layer and focuses on regulating the flow of data between the sender and receiver. It ensures that the receiver can handle the incoming data at a pace it can process without overwhelming its buffer capacity. Flow control prevents the sender from transmitting data faster than the receiver can handle, avoiding data loss or buffer overflow situations.  
In summary, congestion control manages and prevents network congestion to optimize overall network performance, while flow control regulates the flow of data between sender and receiver to ensure a smooth and efficient data transfer process. Both mechanisms work together to ensure reliable and efficient communication in computer networks. 

## Q2  
TCP New Reno is an enhanced congestion control algorithm that improves upon the original TCP Reno algorithm. It effectively handles packet loss and congestion by implementing a fast recovery phase. When packet loss is detected, instead of reverting to slow start, the sender enters fast recovery. During this phase, the sender continues to send new packets, known as "partial acknowledgments," to maintain a higher sending rate and expedite congestion recovery.  
Once all lost packets are successfully retransmitted and acknowledged, the sender exits fast recovery and transitions to the congestion avoidance phase. In this phase, the sender gradually increases the congestion window size to prevent triggering congestion again.  
TCP New Reno optimizes TCP congestion control by reducing the time required to recover from packet loss and congestion, resulting in improved throughput and responsiveness.  

## Q3  
TCP BBR (Bottleneck Bandwidth and Round-trip propagation time) is a congestion control algorithm developed by Google.  
It aims to achieve higher bandwidth and lower latencies for internet traffic. BBR differs from traditional loss-based congestion control algorithms by using measurements of the network's available bandwidth and round-trip time to adjust the sending rate. It operates at the point just before the onset of queuing, optimizing the flow's ability to utilize network resources without causing excessive delays or packet loss.  

## Q4  
- BBR and Reno:  
    - improved throughput: BBR is designed to maximize network throughput by dynamically estimating the available bandwidth and adjusting the sending rate accordingly. This can result in higher throughput compared to Reno.  
    - Complexity: BBR is more complex than Reno and requires more sophisticated algorithms to estimate the available bandwidth and adjust the sending rate.  
    - Reduced latency: BBR aims to minimize queuing delay and round-trip time (RTT) by probing the network to find the optimal sending rate. This can lead to lower latency and improved responsiveness for interactive applications.  
- Reno and NewReno:  
    - The main difference is that TCP Reno can't distinguish between full ACK and partial ACK while new Reno can. Therefore multiple packet loss is detected by new Reno. In context of protocol, TCP new Reno remains in the fast recovery until all the outstanding packets are acknowledged.  

## Q5  

## Q6  
- TCP Vegas: TCP Vegas uses round trip time for the increase or decrease of the congestion window. Expected and current throughput is measured whose difference is compared with some min and max threshold values. On the basis of the comparison we increase, decrease, or don’t change the congestion window.  
- TCP cubic: TCP CUBIC is a congestion control algorithm that arises with the idea of taking advantage of the fact that today’s communications links tend to have increasingly higher bandwidth levels.  
In a network composed of wide bandwidth links, a congestion control algorithm that slowly increases the transmission rate may end up wasting the capacity of the links.  
The intention is to have an algorithm that works with congestion windows whose incremental processes are more aggressive, but are restricted from overloading the network.  
- Proportional Rate Reduction: This algorithm determines the amount of data sent by TCP during loss recovery. PRR minimizes excess window adjustments, and the actual window size at the end of recovery will be as close as possible to the ssthresh, as determined by the congestion control algorithm.  

TCP Vegas has several advantages over TCP Reno and TCP New Reno. One of them is that it can achieve high throughput and low delay, as it avoids congestion and packet losses by maintaining a small buffer at the bottleneck link. Another one is that it can be fair to other TCP Vegas flows, as it allocates the bandwidth proportionally to the RTT of each flow.  
