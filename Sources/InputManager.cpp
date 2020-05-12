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

UniqueBindable& InputManager::GetBindableByName(const std::string& name)
{
    for (auto& bindable : m_Bindables)
    {
        if (bindable.first == name)
            return bindable.second;
    }

    throw;
}

void InputManager::RunKeyboardManager()
{

    while (m_Device->run())
    {
        if (IsKeyDown(irr::KEY_KEY_Z)) {
            GetBindableByName("UpKey")->SetValue(core::vector2df(0.53f, 0.53f));
        }
    }
}