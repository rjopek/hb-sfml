
#ifndef HBSFML_CH_
#define HBSFML_CH_

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Window/Event */
#define sfEvtClosed                   0    ///< The window requested to be closed (no data)
#define sfEvtResized                  1    ///< The window was resized (data in event.size)
#define sfEvtLostFocus                2    ///< The window lost the focus (no data)
#define sfEvtGainedFocus              3    ///< The window gained the focus (no data)
#define sfEvtTextEntered              4    ///< A character was entered (data in event.text)
#define sfEvtKeyPressed               5    ///< A key was pressed (data in event.key)
#define sfEvtKeyReleased              6    ///< A key was released (data in event.key)
#define sfEvtMouseWheelMoved          7    ///< The mouse wheel was scrolled (data in event.mouseWheel) (deprecated)
#define sfEvtMouseWheelScrolled       8    ///< The mouse wheel was scrolled (data in event.mouseWheelScroll)
#define sfEvtMouseButtonPressed       9    ///< A mouse button was pressed (data in event.mouseButton)
#define sfEvtMouseButtonReleased      10   ///< A mouse button was released (data in event.mouseButton)
#define sfEvtMouseMoved               11   ///< The mouse cursor moved (data in event.mouseMove)
#define sfEvtMouseEntered             12   ///< The mouse cursor entered the area of the window (no data)
#define sfEvtMouseLeft                13   ///< The mouse cursor left the area of the window (no data)
#define sfEvtJoystickButtonPressed    14   ///< A joystick button was pressed (data in event.joystickButton)
#define sfEvtJoystickButtonReleased   15   ///< A joystick button was released (data in event.joystickButton)
#define sfEvtJoystickMoved            16   ///< The joystick moved along an axis (data in event.joystickMove)
#define sfEvtJoystickConnected        17   ///< A joystick was connected (data in event.joystickConnect)
#define sfEvtJoystickDisconnected     18   ///< A joystick was disconnected (data in event.joystickConnect)
#define sfEvtTouchBegan               19   ///< A touch event began (data in event.touch)
#define sfEvtTouchMoved               20   ///< A touch moved (data in event.touch)
#define sfEvtTouchEnded               21   ///< A touch event ended (data in event.touch)
#define sfEvtSensorChanged            22   ///< A sensor value changed (data in event.sensor)
#define sfEvtCount                    23   ///< Keep last -- the total number of event types

/* Window/sfWindow */
#define sfNone         0
#define sfTitlebar     1
#define sfResize       2
#define sfClose        4
#define sfFullscreen   8
#define sfDefaultStyle ( sfTitlebar + sfResize + sfClose )

#define sfContextDefault   0
#define sfContextCore      1
#define sfContextDebug     2

#endif /* HBSFML_CH_ */