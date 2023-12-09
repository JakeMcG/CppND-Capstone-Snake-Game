#include "logger.h"
#include <fstream>
#include <iostream>

const std::filesystem::path Logger::file = std::filesystem::path("high_score.txt");

Logger::Logger() {
  // check if the file exists before constructing the file
  // if it doesn't exist we can skip the reading step in UpdateHighScore
  newfile = !std::filesystem::exists(file);
  stream = std::fstream{file, std::fstream::trunc};
  // trunc overwrites everything https://cplusplus.com/reference/fstream/ofstream/ofstream/
};

Logger::~Logger() {
  stream.close(); // close the stream upon destruction
}

void Logger::UpdateHighScore(int score) {
  if (!newfile) {
    int highScore = readHighScore(); 
    if (highScore >= score) return; // not new high score
  }
  writeHighScore(score);
}

int Logger::readHighScore() {
  std::lock_guard<std::mutex> lock(mtx);
  std::string line;
  std::getline(stream, line);
  return stoi(line);
}

void Logger::writeHighScore(int score) {
  std::lock_guard<std::mutex> lock(mtx);
  stream << std::to_string(score);
  std::cout << "New high score of " << score << " saved to file!" << std::endl;
}