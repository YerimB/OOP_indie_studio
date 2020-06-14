#include <InputManager/InputManager.hpp>

using namespace irr;

InputManager::InputManager(IrrlichtDevice* device)
{
    m_Device = device;
    m_KeyDown = std::vector<bool>(KEY_KEY_CODES_COUNT);

    std::fill(m_KeyDown.begin(), m_KeyDown.end(), false);

    m_Buttons.emplace(Button::PLAY, false);
    m_Buttons.emplace(Button::QUIT, false);
    m_Buttons.emplace(Button::CHANGECLR, false);
    m_Buttons.emplace(Button::BUTTON_CHANGE_1, false);
}

bool InputManager::OnEvent(const SEvent& event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        m_KeyDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

    if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT)
        this->m_JoystickState = event.JoystickEvent;

    if (event.EventType == irr::EET_GUI_EVENT)
    {
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
        {
            s32 id = event.GUIEvent.Caller->getID();
            switch (id)
            {
                case Button::PLAY:
                    m_Buttons[Button::PLAY] = true; break;
                case Button::QUIT:
                    m_Buttons[Button::QUIT] = true; break;
                case Button::CHANGECLR:
                    m_Buttons[Button::CHANGECLR] = true; break;
                case Button::CHANGEPLAYER1:
                    m_Buttons[Button::CHANGEPLAYER1] = true; break;
                case Button::CHANGEPLAYER2:
                    m_Buttons[Button::CHANGEPLAYER2] = true; break;
                case Button::CHANGEPLAYER3:
                    m_Buttons[Button::CHANGEPLAYER3] = true; break;
                case Button::CHANGEPLAYER4:
                    m_Buttons[Button::CHANGEPLAYER4] = true; break;
                case Button::BUTTON_CHANGE_1:
                    m_Buttons[Button::BUTTON_CHANGE_1] = true; break;
                default: break;
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

JoystickEvent& InputManager::GetJoystickEvent()
{
    return m_JoystickState;
}
