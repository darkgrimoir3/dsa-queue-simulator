
#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "/traffic_management/vehicle.h"
#include <filesystem>
#include <string>
#include <vector>

class FileHandler {
public:
  FileHandler(const std::string &directory);
  ~FileHandler();

  // Write vehicle data to lane file
  void writeVehicleData(const Vehicle &vehicle);

  // Read vehicle data from lane files
  std::vector<Vehicle *> readVehicleData(SDL_Renderer *renderer);

  LaneId getLaneFromFileName(const std::filesystem::path &filename) const;

private:
  std::string m_directory;
  std::string getLaneFileName(LaneId lane) const;
  void initializeDirectory();
  void cleanup();
};

#endif 