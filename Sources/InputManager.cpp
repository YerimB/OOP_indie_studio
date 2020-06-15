#include <InputManager/InputManager.hpp>

using namespace irr;

InputManager::InputManager(IrrlichtDevice* device)
{
    m_Device = device;
    m_KeyDown = std::vector<bool>(KEY_KEY_CODES_COUNT);

    std::fill(m_KeyDown.begin(), m_KeyDown.end(), false);

    m_Buttons.emplace(Button::PLAY, false);
    m_Buttons.emplace(Button::QUIT, false);
    m_Buttons.emplace(Button::CHANGE_P_AI_1, false);
    m_Buttons.emplace(Button::CHANGE_P_AI_2, false);
    m_Buttons.emplace(Button::CHANGE_P_AI_3, false);
    m_Buttons.emplace(Button::CHANGE_P_AI_4, false);
    m_Buttons.emplace(Button::BUTTON_CHANGE_1, false);
    m_Buttons.emplace(Button::BUTTON_CHANGE_2, false);
    m_Buttons.emplace(Button::BUTTON_CHANGE_3, false);
    m_Buttons.emplace(Button::BUTTON_CHANGE_4, false);
    m_Buttons.emplace(Button::LOWERMUSIC, false);
    m_Buttons.emplace(Button::UPPERMUSIC, false);
    m_Buttons.emplace(Button::LOWERFX, false);
    m_Buttons.emplace(Button::UPPERFX, false);
    m_Buttons.emplace(Button::LOWERSIZEMAP, false);
    m_Buttons.emplace(Button::UPPERSIZEMAP, false);
    m_Buttons.emplace(Button::CHANGE_MUSIC, false);
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
                case Button::CHANGE_P_AI_1:
                    m_Buttons[Button::CHANGE_P_AI_1] = true; break;
                case Button::CHANGE_P_AI_2:
                    m_Buttons[Button::CHANGE_P_AI_2] = true; break;
                case Button::CHANGE_P_AI_3:
                    m_Buttons[Button::CHANGE_P_AI_3] = true; break;
                case Button::CHANGE_P_AI_4:
                    m_Buttons[Button::CHANGE_P_AI_4] = true; break;
                case Button::BUTTON_CHANGE_1:
                    m_Buttons[Button::BUTTON_CHANGE_1] = true; break;
                case Button::BUTTON_CHANGE_2:
                    m_Buttons[Button::BUTTON_CHANGE_2] = true; break;
                case Button::BUTTON_CHANGE_3:
                    m_Buttons[Button::BUTTON_CHANGE_3] = true; break;
                case Button::BUTTON_CHANGE_4:
                    m_Buttons[Button::BUTTON_CHANGE_4] = true; break;
                case Button::LOWERMUSIC:
                    m_Buttons[Button::LOWERMUSIC] = true; break;
                case Button::UPPERMUSIC:
                    m_Buttons[Button::UPPERMUSIC] = true; break;
                case Button::LOWERFX:
                    m_Buttons[Button::LOWERFX] = true; break;
                case Button::UPPERFX:
                    m_Buttons[Button::UPPERFX] = true; break;
                case Button::LOWERSIZEMAP:
                    m_Buttons[Button::LOWERSIZEMAP] = true; break;
                case Button::UPPERSIZEMAP:
                    m_Buttons[Button::UPPERSIZEMAP] = true; break;
                case Button::CHANGE_MUSIC:
                    m_Buttons[Button::CHANGE_MUSIC] = true; break;
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

JoystickEvent& InputManager::GetJoystickEvent()
{
    return m_JoystickState;
}

bool InputManager::IsControllerButtonDown(const ControllerButton& button)
{
    return m_JoystickState.IsButtonPressed(static_cast<irr::u32>(button));
}

int InputManager::GetAxisValue(const JoystickAxis& axis)
{
    if (m_JoystickState.Axis[static_cast<irr::s16>(axis)] < -m_DeadZone)
        return -1;
    else if (m_JoystickState.Axis[static_cast<irr::s16>(axis)] > m_DeadZone)
        return 1;
    return 0;
}
