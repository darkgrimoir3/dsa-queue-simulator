
#include "core/TrafficLane.h"
#include "Headers/Constants.h"
#include <filesystem>
#include <algorithm>

TrafficLane::TrafficLane(LaneId id, bool isPriority)
    : id(id), isPriority(isPriority), waitTime(0.0f)
{
    // Determine if this is a free lane (lane 3 of each road)
    isFreeLane = (
        id == LaneId::AL3_FREELANE ||
        id == LaneId::BL3_FREELANE ||
        id == LaneId::CL3_FREELANE ||
        id == LaneId::DL3_FREELANE
    );
    // Set up data file path based on lane ID
    std::string lanePrefix;
    switch(id) {
        case LaneId::AL1_INCOMING: lanePrefix = "a1"; break;
        case LaneId::AL2_PRIORITY: lanePrefix = "a2"; break;
        case LaneId::AL3_FREELANE: lanePrefix = "a3"; break;
        case LaneId::BL1_INCOMING: lanePrefix = "b1"; break;
        case LaneId::BL2_NORMAL: lanePrefix = "b2"; break;
        case LaneId::BL3_FREELANE: lanePrefix = "b3"; break;
        case LaneId::CL1_INCOMING: lanePrefix = "c1"; break;
        case LaneId::CL2_NORMAL: lanePrefix = "c2"; break;
        case LaneId::CL3_FREELANE: lanePrefix = "c3"; break;
        case LaneId::DL1_INCOMING: lanePrefix = "d1"; break;
        case LaneId::DL2_NORMAL: lanePrefix = "d2"; break;
        case LaneId::DL3_FREELANE: lanePrefix = "d3"; break;
        default: lanePrefix = "unknown";
    }
    dataFile = "data/lanes/lane_" + lanePrefix + ".txt";
}

Direction TrafficLane::getVehicleDirection(size_t index) const {
    if (index >= vehicleQueue.getSize()) {
        return Direction::STRAIGHT;  // Default direction
    }
    return vehicleQueue.peek(index)->getDirection();
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

bool TrafficLane::isFreeLaneType() const {
    return isFreeLane;
}

void TrafficLane::update(float deltaTime) {
    // Update wait times for vehicles
    updateVehicleWaitTimes(deltaTime);
    // Free lanes (3rd lane of each road) process vehicles immediately
    if (isFreeLane) {
        while (!vehicleQueue.isEmpty()) {
            removeVehicle();
        }
    }
}

void TrafficLane::updateVehicleWaitTimes(float deltaTime) {
    size_t count = vehicleQueue.getSize();
    if (count == 0) return;
    float totalWaitTime = 0.0f;
    for (size_t i = 0; i < count; i++) {
        auto vehicle = vehicleQueue.peek(i);
        vehicle->updateWaitTime(deltaTime);
        totalWaitTime += vehicle->getWaitTime();
    }
    // Update average wait time
    waitTime = totalWaitTime / static_cast<float>(count);
}

float TrafficLane::getAverageWaitTime() const {
    return waitTime;
}

bool TrafficLane::exceedsPriorityThreshold() const {
    return isPriority && vehicleQueue.getSize() > SimConstants::PRIORITY_THRESHOLD;
}

bool TrafficLane::isBelowNormalThreshold() const {
    return isPriority && vehicleQueue.getSize() < SimConstants::NORMAL_THRESHOLD;
}