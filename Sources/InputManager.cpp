#include <InputManager/InputManager.hpp>

using namespace irr;

InputManager::InputManager(IrrlichtDevice* device)
{
    m_Device = device;
    m_KeyDown = std::vector<bool>(KEY_KEY_CODES_COUNT);

    std::fill(m_KeyDown.begin(), m_KeyDown.end(), false);

    m_Buttons.emplace(Button::PLAY, false);
    m_Buttons.emplace(Button::QUIT, false);
}

bool InputManager::OnEvent(const SEvent& event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        m_KeyDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

    if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT)
        std::cout << "Joystick Event" << std::endl;

    if (event.EventType == irr::EET_GUI_EVENT)
    {
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
        {
            s32 id = event.GUIEvent.Caller->getID();
            switch (id)
            {
                case Button::PLAY:
                    m_Buttons[Button::PLAY] = true;
                    break;
                case Button::QUIT:
                    m_Buttons[Button::QUIT] = true;
                    break;
                default:
                    break;
            }
        }
    }
    return false;
}

bool InputManager::IsKeyDown(EKEY_CODE keyCode) const
{
    return m_KeyDown[keyCode];
}

bool InputManager::IsButtonDown(const Button::ButtonID& id)
{
    return m_Buttons[id];
}

void InputManager::ResetButton(const Button::ButtonID& id)
{
    m_Buttons[id] = false;
}
