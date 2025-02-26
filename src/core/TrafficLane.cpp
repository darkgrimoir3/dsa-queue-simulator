// src/core/TrafficLane.cpp
#include "core/TrafficLane.h"
#include <filesystem>

TrafficLane::TrafficLane(LaneId id, bool isPriority)
    : id(id), isPriority(isPriority) {
    // Set up data file path based on lane ID
    std::string lanePrefix;
    switch(id) {
        case LaneId::AL1_INCOMING: lanePrefix = "a1"; break;
        case LaneId::AL2_PRIORITY: lanePrefix = "a2"; break;
        case LaneId::AL3_FREELANE: lanePrefix = "a3"; break;
        // ... add other cases
        default: lanePrefix = "unknown";
    }
    dataFile = "data/lanes/lane_" + lanePrefix + ".txt";
}


Direction TrafficLane::getVehicleDirection(size_t index) const {
    if (index >= vehicleQueue.getSize()) {
        return Direction::STRAIGHT;  // Default direction
    }

    // This assumes you maintain the vehicles in order in your queue
    // You might need to adjust this based on your Queue implementation
    auto vehicle = vehicleQueue.peek(index);
    return vehicle ? vehicle->getDirection() : Direction::STRAIGHT;
}

void TrafficLane::addVehicle(std::shared_ptr<Vehicle> vehicle) {
    vehicleQueue.enqueue(vehicle);
}

std::shared_ptr<Vehicle> TrafficLane::removeVehicle() {
    if (vehicleQueue.isEmpty()) return nullptr;
    return vehicleQueue.dequeue();
}

size_t TrafficLane::getQueueSize() const {
    return vehicleQueue.getSize();
}

bool TrafficLane::isPriorityLane() const {
    return isPriority;
}

LaneId TrafficLane::getId() const {
    return id;
}

const std::string& TrafficLane::getDataFile() const {
    return dataFile;
}

void TrafficLane::update() {
    // Update logic for free lanes
    if (id == LaneId::AL3_FREELANE ||
        id == LaneId::BL3_FREELANE ||
        id == LaneId::CL3_FREELANE ||
        id == LaneId::DL3_FREELANE) {
        // Free lanes process vehicles immediately
        while (!vehicleQueue.isEmpty()) {
            removeVehicle();
        }
    }
}