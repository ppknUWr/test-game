#pragma once

#include <SFML/Graphics.hpp>
#include <map>

#include "Bitmask.hpp"

class MouseInput
{

public:

  enum class MouseKey
  {
    None = 0,
    Left = 1,
    Right = 2,
    Middle = 3
  };

  MouseInput();
  ~MouseInput();

  void InitializeAssociatedKeys();

  void UpdateKeyPressed(int mouseKeyCode);
  void UpdateKeyReleased(int mouseKeyCode);

  bool IsMouseKeyPressed(MouseKey key);
  bool IsMouseKeyReleased(MouseKey key);

private:

  Bitmask m_currentFrameKeys;
  Bitmask m_lastFrameKeys;

  std::map<sf::Mouse::Button, MouseKey> m_associatedKeys;

};
