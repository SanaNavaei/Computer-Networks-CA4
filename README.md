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
The Reno algorithm is a TCP congestion control variant that enhances the performance and fairness of TCP connections in congested networks. It introduces a modified fast recovery mechanism to expedite recovery from packet loss.  
During fast recovery, the sender retransmits the lost packet and continues sending new packets at a reduced rate. It monitors for duplicate acknowledgments (ACKs) from the receiver, indicating successful receipt of subsequent packets.  
Upon receiving three duplicate ACKs, the sender performs a fast retransmit, retransmitting the missing packet without waiting for a timeout. It then enters a phase called "fast recovery" where it incrementally increases the congestion window, allowing for faster recovery and higher sending rates.  
Compared to the original Reno algorithm, the New Reno algorithm minimizes unnecessary timeouts and retransmissions. This results in quicker recovery from packet loss and improved network performance and fairness.  

## Q3  

## Q4  

## Q5  

## Q6  
