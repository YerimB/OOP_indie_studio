#pragma once

#include <vector>
#include <iostream>
#include <memory>

#include <Irrlicht/irrlicht.h>
#include <Bindable/Bindable.hpp>

using namespace irr;

class InputManager : public IEventReceiver
{
    public:
        InputManager(IrrlichtDevice *device);

    public:
        virtual bool OnEvent(const SEvent& event);
        virtual bool IsKeyDown(EKEY_CODE keyCode) const;
        void RunKeyboardManager();

    public:
        void AddBindable(IBindable* bindable);
        void AddBindable(std::unique_ptr<IBindable>& bindable);

    private:
        std::unique_ptr<IrrlichtDevice> m_Device;
        std::vector<bool> m_KeyDown;
        SEvent::SJoystickEvent m_JoystickState;
        std::vector<std::unique_ptr<IBindable>> m_Bindables;
};
