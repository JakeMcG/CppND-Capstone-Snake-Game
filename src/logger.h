#pragma once

#include <filesystem>
#include <fstream>
#include <mutex>

class Logger {
 public:
  Logger();
  ~Logger();
  void UpdateHighScore(int score);

  static const std::filesystem::path file;

 private:
  int readHighScore();
  void writeHighScore(int score);
  
  std::mutex mtx;
  std::fstream stream;
  bool newfile;
};
