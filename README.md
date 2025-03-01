# 🚦 Traffic Light Management System
<div align="center">
  <hr style="width: 75%">
  <h3>COMP202 Data Structures and Algorithms Project</h3>
  <hr style="width: 75%">
</div>

Hey there! Welcome to my traffic light simulator project. This is my solution for the COMP202 Data Structures and Algorithms assignment where I've built a queue-based system to manage traffic at a busy intersection.

![final GIF](gif/final.gif)

<hr style="width: 40%"><h3>🚗 What's This All About?</h3><hr style="width: 40%">

Imagine a busy intersection where four major roads meet. Cars are coming from all directions, and we need a smart system to control the traffic lights. That's exactly what this project does!

The system handles two main scenarios:

Regular traffic flow: Where we try to serve vehicles equally from all lanes
Rush hour situations: When one road gets backed up with more than 10 vehicles, it gets priority until the traffic eases

<hr style="width: 40%"><h3>✨ Key Features</h3><hr style="width: 40%">

Uses queues to model real-world traffic (putting those DSA lessons to work!)
Visual simulation of vehicles moving through the junction
Smart handling of priority lanes when traffic builds up
Traffic light coordination to prevent gridlock

<hr style="width: 40%"><h3>🛣️ The Road Layout</h3><hr style="width: 40%">

Each of the four roads (A, B, C, D) has three lanes:

An incoming lane (like AL1)
An outgoing lane that follows traffic light rules
A free-turn left lane

The lane labeled AL2 is our special priority lane that gets preferential treatment when it gets congested.



<hr style="width: 40%"><h3>📁 Project Organization</h3><hr style="width: 40%">

├── data/                         # Where all the traffic data lives
├── base/                      # Header files
│   ├── SDL3/                     # Graphics library headers
│   ├── visualisation.h, trafficlane.h, etc. # Various component headers
├── core/                          # Where the magic happens
│   ├── trafficgenerator/                # Creates vehicles for our simulation
│   ├── trafficlane/                     # Manages lane operations
│   ├── simulator/                # Runs the actual simulation
│   └── vehicle/                  # Defines vehicle behavior
├── main.c                        # The entry point
└── README.md                     # You are here! 👋



<hr style="width: 40%"><h3>🧠 How It Works</h3><hr style="width: 40%">
The system uses queues (a perfect application for FIFO structures!) to manage vehicles at the intersection:

1. Vehicle Generation: The generator creates vehicles and assigns them to lanes
2. Traffic Rules:

Normal mode: Serve vehicles from all lanes fairly
Priority mode: When AL2 has >10 vehicles, it gets priority service until it drops below 5


3. Traffic Lights: Coordinate red/green states to keep traffic flowing and prevent deadlocks

<hr style="width: 40%"><h3>🚀 Getting Started</h3><hr style="width: 40%">

1.Clone this repo:

git clone https://github.com/yourusername/dsa-queue-simulator.git
cd dsa-queue-simulator

2.Build the project:
gcc main.c src/generator/generator.c src/lane/lane.c src/vehicle/vehicle.c -Iinclude -o simulator

3.Run it:
./simulator

4.Watch the traffic flow and see how the queue-based system handles different scenarios!

<hr style="width: 40%"><h3>🙏 Acknowledgments</h3><hr style="width: 40%">

My DSA professor for the challenging assignment
The SDL library for making visualization possible
Coffee ☕ - the true hero behind all coding projects