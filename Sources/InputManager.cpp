#include <InputManager/InputManager.h>

using namespace irr;

InputManager::InputManager(IrrlichtDevice* device)
{
    m_Device = std::unique_ptr<IrrlichtDevice>(device);
    m_KeyDown = std::vector<bool>(KEY_KEY_CODES_COUNT);

    std::fill(m_KeyDown.begin(), m_KeyDown.end(), false);
}

bool InputManager::OnEvent(const SEvent& event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
        m_KeyDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }

    return false;
}

bool InputManager::IsKeyDown(EKEY_CODE keyCode) const
{
    return m_KeyDown[keyCode];
}

void InputManager::AddBindable(IBindable* bindable)
{
    m_Bindables.emplace_back(std::unique_ptr<IBindable>(bindable));

    m_Bindables[0]->SetValue(10.0f);
}

void InputManager::AddBindable(std::unique_ptr<IBindable>& bindable)
{
    m_Bindables.emplace_back(std::move(bindable));

    m_Bindables[0]->SetValue(10.0f);
}

void InputManager::RunKeyboardManager()
{

    while (this->m_Device->run())
    {
        // Handle keys
    }
}