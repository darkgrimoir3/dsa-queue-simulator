# 🚦 Traffic Light Management System
<div align="center">
  <hr style="width: 75%">
  <h3>COMP202 Data Structures and Algorithms Project</h3>
  <hr style="width: 75%">
</div>

Hey there! Welcome to my traffic light simulator project. This is my solution for the COMP202 Data Structures and Algorithms assignment where I've built a queue-based system to manage traffic at a busy intersection.

</h2>🚗 What's This All About?</h2>
Imagine a busy intersection where four major roads meet. Cars are coming from all directions, and we need a smart system to control the traffic lights. That's exactly what this project does!

The system handles two main scenarios:

Regular traffic flow: Where we try to serve vehicles equally from all lanes
Rush hour situations: When one road gets backed up with more than 10 vehicles, it gets priority until the traffic eases

</h2>✨ Key Features</h2>

Uses queues to model real-world traffic (putting those DSA lessons to work!)
Visual simulation of vehicles moving through the junction
Smart handling of priority lanes when traffic builds up
Traffic light coordination to prevent gridlock

</h2>🛣️ The Road Layout</h2>
Each of the four roads (A, B, C, D) has three lanes:

An incoming lane (like AL1)
An outgoing lane that follows traffic light rules
A free-turn left lane

The lane labeled AL2 is our special priority lane that gets preferential treatment when it gets congested.