#pragma once

#include <iostream>
#include <filesystem>

class LogFileManager
{

public:

  ~LogFileManager();

  static LogFileManager &GetInstance();

  void GenerateLogDirectory();
  void GenerateLogFile();

private:

  LogFileManager();

private:

  static std::unique_ptr<LogFileManager> s_instance;

  std::string m_pathToLogFile;

};