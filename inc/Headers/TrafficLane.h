
#ifndef TRAFFIC_LANE_H
#define TRAFFIC_LANE_H
#include <vector>
#include <string>
#include "Headers/Vehicle.h"
#include "Headers/Queue.h"

class TrafficLane {
public:
    TrafficLane(char laneId, int laneNumber);
    ~TrafficLane();
    // Queue operations
    void enqueue(Vehicle* vehicle);
    Vehicle* dequeue();
    Vehicle* peek() const;
    bool isEmpty() const;
    int getVehicleCount() const;
    // Priority related operations
    int getPriority() const;
    void updatePriority();
    bool isPriorityLane() const;
    // Lane identification
    char getLaneId() const;
    int getLaneNumber() const;
    std::string getName() const;
    // For iteration through vehicles (for rendering)
    const std::vector<Vehicle*>& getVehicles() const;
private:
    char laneId;               // A, B, C, or D
    int laneNumber;            // 1, 2, or 3
    bool isPriority;           // Is this a priority lane (AL2)
    int priority;              // Current priority (higher means served first)
    Queue<Vehicle*> vehicleQueue; // Queue for vehicles in the lane
};
#endif // TRAFFIC_LANE_H