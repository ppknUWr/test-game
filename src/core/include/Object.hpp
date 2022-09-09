#pragma once

#include <vector>
#include <memory>

#include "Window.hpp"
#include "Component.hpp"
#include "Log.hpp"

class Object
{

public:

  Object();
  ~Object();

  void Awake(); // Called when object created. Use to ensure required components are present.
  void Start(); // Called after Awake method. Use to initialise variables.

  void Update(float deltaTime);
  void LateUpdate(float deltaTime);
  void Draw(Window &window);

  bool QueuedForRemoval() const;
  void QueueForRemoval();

  void SetDrawable(bool drawable);
  void SetCollidable(bool collidable);

  bool Drawable() const;
  bool Collidable() const;

  template <typename T>
  std::shared_ptr<T> AddComponent()
  {
    static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

    // Check that we don't already have a component of this type.
    for (auto& exisitingComponent : m_components)
    {
      if (std::dynamic_pointer_cast<T>(exisitingComponent))
      {
        return std::dynamic_pointer_cast<T>(exisitingComponent);
      }
    }

    std::shared_ptr<T> newComponent = std::make_shared<T>(this);
    m_components.push_back(newComponent);

    return newComponent;
  };

  template <typename T>
  std::shared_ptr<T> GetComponent()
  {
    // Check that we don't already have a component of this type.
    for (auto& exisitingComponent : m_components)
    {
      if (std::dynamic_pointer_cast<T>(exisitingComponent))
      {
        return std::dynamic_pointer_cast<T>(exisitingComponent);
      }
    }

    LOG_WARNING("[Object][GetComponent] Returned nullptr.");

    return nullptr;
  };

  template <typename T>
  bool HasComponent() const
  {
    // Check that we don't already have a component of this type.
    for (auto& exisitingComponent : m_components)
    {
      if (std::dynamic_pointer_cast<T>(exisitingComponent))
      {
        return true;
      }
    }

    return false;
  };

private:

  std::vector<std::shared_ptr<Component>> m_components;
  bool m_queuedForRemoval;

  bool m_drawable;
  bool m_collidable;

};
