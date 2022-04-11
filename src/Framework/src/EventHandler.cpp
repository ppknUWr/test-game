#include <iostream>

#include "EventHandler.hpp"

std::unique_ptr<EventHandler> EventHandler::s_instance = nullptr;

EventHandler::EventHandler()
{
  std::cout << "[EventHandler] Created new instance of EventHandler.\n";
}

EventHandler::~EventHandler()
{
  std::cout << "[EventHandler] Deleted instance of EventHandler.\n";
}

EventHandler &EventHandler::GetInstance()
{
  if (EventHandler::s_instance == nullptr)
  {
    EventHandler::s_instance = std::unique_ptr<EventHandler>(new EventHandler);
  }

  return *s_instance;
}

KeyboardInput &EventHandler::GetKeyboardInput()
{
  return m_keyboardInput;
}

MouseInput &EventHandler::GetMouseInput()
{
  return m_mouseInput;
}

void EventHandler::ProcessEvent(const sf::Event &event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    m_keyboardInput.UpdateKeyPressed(event.key.code);
  }
  
  if (event.type == sf::Event::KeyReleased)
  {
    m_keyboardInput.UpdateKeyReleased(event.key.code);
  }

  if (event.type == sf::Event::MouseButtonPressed)
  {
    m_mouseInput.UpdateKeyPressed(event.mouseButton.button);
  }

  if (event.type == sf::Event::MouseButtonReleased)
  {
    m_mouseInput.UpdateKeyReleased(event.mouseButton.button);
  }

  if (event.type == sf::Event::LostFocus)
  {
    std::cout << "[EventHandler] Reporting that Window has lost focus.\n";

    /*
    TODO: Implement a game freeze, and show of the pause menu when it will be implemented.
    */

  }

  if (event.type == sf::Event::GainedFocus)
  {
    std::cout << "[EventHandler] Reporting that Window has gained focus.\n";

    /*
    TODO: Unfreeze the game.
    */

  }

  /*
  TODO: Add support for joysticks.
  */

}