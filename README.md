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



</h2>📁 Project Organization</h2>

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



</h2>🧠 How It Works</h2>
The system uses queues (a perfect application for FIFO structures!) to manage vehicles at the intersection:

1. Vehicle Generation: The generator creates vehicles and assigns them to lanes
2. Traffic Rules:

Normal mode: Serve vehicles from all lanes fairly
Priority mode: When AL2 has >10 vehicles, it gets priority service until it drops below 5


3. Traffic Lights: Coordinate red/green states to keep traffic flowing and prevent deadlocks

</h2>🚀 Getting Started</h2>

1.Clone this repo:

git clone https://github.com/yourusername/dsa-queue-simulator.git
cd dsa-queue-simulator

2.Build the project:
gcc main.c src/generator/generator.c src/lane/lane.c src/vehicle/vehicle.c -Iinclude -o simulator

3.Run it:
./simulator

4.Watch the traffic flow and see how the queue-based system handles different scenarios!

</h2>🙏 Acknowledgments</h2>

My DSA professor for the challenging assignment
The SDL library for making visualization possible
Coffee ☕ - the true hero behind all coding projects