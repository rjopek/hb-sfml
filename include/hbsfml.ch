
#ifndef HBSFML_CH_
#define HBSFML_CH_

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Audio/SoundStatus */
#define sfStopped                        0   ///< Sound / music is not playing
#define sfPaused                         1   ///< Sound / music is paused
#define sfPlaying                        2   ///< Sound / music is playing

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Graphics/BlendMode */
#define sfBlendFactorZero                0   ///< (0, 0, 0, 0)
#define sfBlendFactorOne                 1   ///< (1, 1, 1, 1)
#define sfBlendFactorSrcColor            2   ///< (src.r, src.g, src.b, src.a)
#define sfBlendFactorOneMinusSrcColor    3   ///< (1, 1, 1, 1) - (src.r, src.g, src.b, src.a)
#define sfBlendFactorDstColor            4   ///< (dst.r, dst.g, dst.b, dst.a)
#define sfBlendFactorOneMinusDstColor    5   ///< (1, 1, 1, 1) - (dst.r, dst.g, dst.b, dst.a)
#define sfBlendFactorSrcAlpha            6   ///< (src.a, src.a, src.a, src.a)
#define sfBlendFactorOneMinusSrcAlpha    7   ///< (1, 1, 1, 1) - (src.a, src.a, src.a, src.a)
#define sfBlendFactorDstAlpha            8   ///< (dst.a, dst.a, dst.a, dst.a)
#define sfBlendFactorOneMinusDstAlpha    9   ///< (1, 1, 1, 1) - (dst.a, dst.a, dst.a, dst.a)

#define sfBlendEquationAdd               0   ///< Pixel = Src * SrcFactor + Dst * DstFactor
#define sfBlendEquationSubtract          1   ///< Pixel = Src * SrcFactor - Dst * DstFactor
#define sfBlendEquationReverseSubtract   2   ///< Pixel = Dst * DstFactor - Src * SrcFactor

/* Graphics/Text */
#define sfTextRegular                    0   ///< Regular characters no style
#define sfTextBold                       1   ///< Bold characters
#define sfTextItalic                     2   ///< Italic characters
#define sfTextUnderlined                 4   ///< Underlined characters
#define sfTextStrikeThrough              8   ///< Strike through characters

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Network/sfFtpListingResponse */
#define sfFtpBinary                      0   ///< Binary mode (file is transfered as a sequence of bytes)
#define sfFtpAscii                       1   ///< Text mode using ASCII encoding
#define sfFtpEbcdic                      2   ///< Text mode using EBCDIC encoding

   // 1xx: the requested action is being initiated,
   // expect another reply before proceeding with a new command
#define sfFtpRestartMarkerReply          110   ///< Restart marker reply
#define sfFtpServiceReadySoon            120   ///< Service ready in N minutes
#define sfFtpDataConnectionAlreadyOpened 125   ///< Data connection already opened, transfer starting
#define sfFtpOpeningDataConnection       150   ///< File status ok, about to open data connection

   // 2xx: the requested action has been successfully completed
#define sfFtpOk                          200   ///< Command ok
#define sfFtpPointlessCommand            202   ///< Command not implemented
#define sfFtpSystemStatus                211   ///< System status, or system help reply
#define sfFtpDirectoryStatus             212   ///< Directory status
#define sfFtpFileStatus                  213   ///< File status
#define sfFtpHelpMessage                 214   ///< Help message
#define sfFtpSystemType                  215   ///< NAME system type, where NAME is an official system name from the list in the Assigned Numbers document
#define sfFtpServiceReady                220   ///< Service ready for new user
#define sfFtpClosingConnection           221   ///< Service closing control connection
#define sfFtpDataConnectionOpened        225   ///< Data connection open, no transfer in progress
#define sfFtpClosingDataConnection       226   ///< Closing data connection, requested file action successful
#define sfFtpEnteringPassiveMode         227   ///< Entering passive mode
#define sfFtpLoggedIn                    230   ///< User logged in, proceed. Logged out if appropriate
#define sfFtpFileActionOk                250   ///< Requested file action ok
#define sfFtpDirectoryOk                 257   ///< PATHNAME created

   // 3xx: the command has been accepted, but the requested action
   // is dormant, pending receipt of further information
#define sfFtpNeedPassword                331   ///< User name ok, need password
#define sfFtpNeedAccountToLogIn          332   ///< Need account for login
#define sfFtpNeedInformation             350   ///< Requested file action pending further information

   // 4xx: the command was not accepted and the requested action did not take place,
   // but the error condition is temporary and the action may be requested again
#define sfFtpServiceUnavailable          421   ///< Service not available, closing control connection
#define sfFtpDataConnectionUnavailable   425   ///< Can't open data connection
#define sfFtpTransferAborted             426   ///< Connection closed, transfer aborted
#define sfFtpFileActionAborted           450   ///< Requested file action not taken
#define sfFtpLocalError                  451   ///< Requested action aborted, local error in processing
#define sfFtpInsufficientStorageSpace    452   ///< Requested action not taken; insufficient storage space in system, file unavailable

   // 5xx: the command was not accepted and
   // the requested action did not take place
#define sfFtpCommandUnknown              500   ///< Syntax error, command unrecognized
#define sfFtpParametersUnknown           501   ///< Syntax error in parameters or arguments
#define sfFtpCommandNotImplemented       502   ///< Command not implemented
#define sfFtpBadCommandSequence          503   ///< Bad sequence of commands
#define sfFtpParameterNotImplemented     504   ///< Command not implemented for that parameter
#define sfFtpNotLoggedIn                 530   ///< Not logged in
#define sfFtpNeedAccountToStore          532   ///< Need account for storing files
#define sfFtpFileUnavailable             550   ///< Requested action not taken, file unavailable
#define sfFtpPageTypeUnknown             551   ///< Requested action aborted, page type unknown
#define sfFtpNotEnoughMemory             552   ///< Requested file action aborted, exceeded storage allocation
#define sfFtpFilenameNotAllowed          553   ///< Requested action not taken, file name not allowed

   // 10xx: SFML custom codes
#define sfFtpInvalidResponse             1000  ///< Response is not a valid FTP one
#define sfFtpConnectionFailed            1001  ///< Connection with server failed
#define sfFtpConnectionClosed            1002  ///< Connection with server closed
#define sfFtpInvalidFile                 1003  ///< Invalid file to upload / download

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Window/Cursor */
#define sfCursorArrow                    0    ///< Arrow cursor (default)
#define sfCursorArrowWait                1    ///< Busy arrow cursor
#define sfCursorWait                     2    ///< Busy cursor
#define sfCursorText                     3    ///< I-beam cursor when hovering over a field allowing text entry
#define sfCursorHand                     4    ///< Pointing hand cursor
#define sfCursorSizeHorizontal           5    ///< Horizontal double arrow cursor
#define sfCursorSizeVertical             6    ///< Vertical double arrow cursor
#define sfCursorSizeTopLeftBottomRight   7    ///< Double arrow cursor going from top-left to bottom-right
#define sfCursorSizeBottomLeftTopRight   8    ///< Double arrow cursor going from bottom-left to top-right
#define sfCursorSizeAll                  9    ///< Combination of SizeHorizontal and SizeVertical
#define sfCursorCross                    10   ///< Crosshair cursor
#define sfCursorHelp                     11   ///< Help cursor
#define sfCursorNotAllowed               12   ///< Action not allowed cursor

/* Window/Event */
#define sfEvtClosed                      0    ///< The window requested to be closed (no data)
#define sfEvtResized                     1    ///< The window was resized (data in event.size)
#define sfEvtLostFocus                   2    ///< The window lost the focus (no data)
#define sfEvtGainedFocus                 3    ///< The window gained the focus (no data)
#define sfEvtTextEntered                 4    ///< A character was entered (data in event.text)
#define sfEvtKeyPressed                  5    ///< A key was pressed (data in event.key)
#define sfEvtKeyReleased                 6    ///< A key was released (data in event.key)
#define sfEvtMouseWheelMoved             7    ///< The mouse wheel was scrolled (data in event.mouseWheel) (deprecated)
#define sfEvtMouseWheelScrolled          8    ///< The mouse wheel was scrolled (data in event.mouseWheelScroll)
#define sfEvtMouseButtonPressed          9    ///< A mouse button was pressed (data in event.mouseButton)
#define sfEvtMouseButtonReleased         10   ///< A mouse button was released (data in event.mouseButton)
#define sfEvtMouseMoved                  11   ///< The mouse cursor moved (data in event.mouseMove)
#define sfEvtMouseEntered                12   ///< The mouse cursor entered the area of the window (no data)
#define sfEvtMouseLeft                   13   ///< The mouse cursor left the area of the window (no data)
#define sfEvtJoystickButtonPressed       14   ///< A joystick button was pressed (data in event.joystickButton)
#define sfEvtJoystickButtonReleased      15   ///< A joystick button was released (data in event.joystickButton)
#define sfEvtJoystickMoved               16   ///< The joystick moved along an axis (data in event.joystickMove)
#define sfEvtJoystickConnected           17   ///< A joystick was connected (data in event.joystickConnect)
#define sfEvtJoystickDisconnected        18   ///< A joystick was disconnected (data in event.joystickConnect)
#define sfEvtTouchBegan                  19   ///< A touch event began (data in event.touch)
#define sfEvtTouchMoved                  20   ///< A touch moved (data in event.touch)
#define sfEvtTouchEnded                  21   ///< A touch event ended (data in event.touch)
#define sfEvtSensorChanged               22   ///< A sensor value changed (data in event.sensor)
#define sfEvtCount                       23   ///< Keep last -- the total number of event types

/* Window/Joystick */
#define sfJoystickCount                  8    ///< Maximum number of supported joysticks
#define sfJoystickButtonCount            32   ///< Maximum number of supported buttons
#define sfJoystickAxisCount              8    ///< Maximum number of supported axes

#define sfJoystickX                      0   ///< The X axis
#define sfJoystickY                      1   ///< The Y axis
#define sfJoystickZ                      2   ///< The Z axis
#define sfJoystickR                      3   ///< The R axis
#define sfJoystickU                      4   ///< The U axis
#define sfJoystickV                      5   ///< The V axis
#define sfJoystickPovX                   6   ///< The X axis of the point-of-view hat
#define sfJoystickPovY                   7   ///< The Y axis of the point-of-view hat

/* Window/Keyboard /**/

#define sfKeyUnknown                    -1   ///< Unhandled key
#define sfKeyA                           0   ///< The A key
#define sfKeyB                           1   ///< The B key
#define sfKeyC                           2   ///< The C key
#define sfKeyD                           3   ///< The D key
#define sfKeyE                           4   ///< The E key
#define sfKeyF                           5   ///< The F key
#define sfKeyG                           6   ///< The G key
#define sfKeyH                           7   ///< The H key
#define sfKeyI                           8   ///< The I key
#define sfKeyJ                           9   ///< The J key
#define sfKeyK                           10  ///< The K key
#define sfKeyL                           11  ///< The L key
#define sfKeyM                           12  ///< The M key
#define sfKeyN                           13  ///< The N key
#define sfKeyO                           14  ///< The O key
#define sfKeyP                           15  ///< The P key
#define sfKeyQ                           16  ///< The Q key
#define sfKeyR                           17  ///< The R key
#define sfKeyS                           18  ///< The S key
#define sfKeyT                           19  ///< The T key
#define sfKeyU                           20  ///< The U key
#define sfKeyV                           21  ///< The V key
#define sfKeyW                           22  ///< The W key
#define sfKeyX                           23  ///< The X key
#define sfKeyY                           24  ///< The Y key
#define sfKeyZ                           25  ///< The Z key
#define sfKeyNum0                        26  ///< The 0 key
#define sfKeyNum1                        27  ///< The 1 key
#define sfKeyNum2                        28  ///< The 2 key
#define sfKeyNum3                        29  ///< The 3 key
#define sfKeyNum4                        30  ///< The 4 key
#define sfKeyNum5                        31  ///< The 5 key
#define sfKeyNum6                        32  ///< The 6 key
#define sfKeyNum7                        33  ///< The 7 key
#define sfKeyNum8                        34  ///< The 8 key
#define sfKeyNum9                        35  ///< The 9 key
#define sfKeyEscape                      36  ///< The Escape key
#define sfKeyLControl                    37  ///< The left Control key
#define sfKeyLShift                      38  ///< The left Shift key
#define sfKeyLAlt                        39  ///< The left Alt key
#define sfKeyLSystem                     40  ///< The left OS specific key: window (Windows and Linux) apple (MacOS X) ...
#define sfKeyRControl                    41  ///< The right Control key
#define sfKeyRShift                      42  ///< The right Shift key
#define sfKeyRAlt                        43  ///< The right Alt key
#define sfKeyRSystem                     44  ///< The right OS specific key: window (Windows and Linux) apple (MacOS X) ...
#define sfKeyMenu                        45  ///< The Menu key
#define sfKeyLBracket                    46  ///< The [ key
#define sfKeyRBracket                    47  ///< The ] key
#define sfKeySemicolon                   48  ///< The ; key
#define sfKeyComma                       49  ///< The  key
#define sfKeyPeriod                      50  ///< The . key
#define sfKeyQuote                       51  ///< The ' key
#define sfKeySlash                       52  ///< The / key
#define sfKeyBackslash                   53  ///< The \ key
#define sfKeyTilde                       54  ///< The ~ key
#define sfKeyEqual                       55  ///< The = key
#define sfKeyHyphen                      56  ///< The - key (hyphen)
#define sfKeySpace                       57  ///< The Space key
#define sfKeyEnter                       58  ///< The Enter/Return key
#define sfKeyBackspace                   59  ///< The Backspace key
#define sfKeyTab                         60  ///< The Tabulation key
#define sfKeyPageUp                      61  ///< The Page up key
#define sfKeyPageDown                    62  ///< The Page down key
#define sfKeyEnd                         63  ///< The End key
#define sfKeyHome                        64  ///< The Home key
#define sfKeyInsert                      65  ///< The Insert key
#define sfKeyDelete                      66  ///< The Delete key
#define sfKeyAdd                         67  ///< The + key
#define sfKeySubtract                    68  ///< The - key (minus usually from numpad)
#define sfKeyMultiply                    69  ///< The * key
#define sfKeyDivide                      70  ///< The / key
#define sfKeyLeft                        71  ///< Left arrow
#define sfKeyRight                       72  ///< Right arrow
#define sfKeyUp                          73  ///< Up arrow
#define sfKeyDown                        74  ///< Down arrow
#define sfKeyNumpad0                     75  ///< The numpad 0 key
#define sfKeyNumpad1                     76  ///< The numpad 1 key
#define sfKeyNumpad2                     77  ///< The numpad 2 key
#define sfKeyNumpad3                     78  ///< The numpad 3 key
#define sfKeyNumpad4                     79  ///< The numpad 4 key
#define sfKeyNumpad5                     80  ///< The numpad 5 key
#define sfKeyNumpad6                     81  ///< The numpad 6 key
#define sfKeyNumpad7                     82  ///< The numpad 7 key
#define sfKeyNumpad8                     83  ///< The numpad 8 key
#define sfKeyNumpad9                     84  ///< The numpad 9 key
#define sfKeyF1                          85  ///< The F1 key
#define sfKeyF2                          86  ///< The F2 key
#define sfKeyF3                          87  ///< The F3 key
#define sfKeyF4                          88  ///< The F4 key
#define sfKeyF5                          89  ///< The F5 key
#define sfKeyF6                          90  ///< The F6 key
#define sfKeyF7                          91  ///< The F7 key
#define sfKeyF8                          92  ///< The F8 key
#define sfKeyF9                          93  ///< The F8 key
#define sfKeyF10                         94  ///< The F10 key
#define sfKeyF11                         95  ///< The F11 key
#define sfKeyF12                         96  ///< The F12 key
#define sfKeyF13                         97  ///< The F13 key
#define sfKeyF14                         98  ///< The F14 key
#define sfKeyF15                         99  ///< The F15 key
#define sfKeyPause                       100 ///< The Pause key
#define sfKeyCount                       101 ///< Keep last -- the total number of keyboard keys

// Deprecated values:
#define sfKeyDash        sfKeyHyphen         ///< \deprecated Use Hyphen instead
#define sfKeyBack        sfKeyBackspace      ///< \deprecated Use Backspace instead
#define sfKeyBackSlash   sfKeyBackslash      ///< \deprecated Use Backslash instead
#define sfKeySemiColon   sfKeySemicolon      ///< \deprecated Use Semicolon instead
#define sfKeyReturn      sfKeyEnter          ///< \deprecated Use Enter instead

/* Window/Mouse */
#define sfMouseLeft                      0   ///< The left mouse button
#define sfMouseRight                     1   ///< The right mouse button
#define sfMouseMiddle                    2   ///< The middle (wheel) mouse button
#define sfMouseXButton1                  3   ///< The first extra mouse button
#define sfMouseXButton2                  4   ///< The second extra mouse button
#define sfMouseButtonCount               5   ///< Keep last -- the total number of mouse buttons

#define sfMouseVerticalWheel             0   ///< The vertical mouse wheel
#define sfMouseHorizontalWheel           1   ///< The horizontal mouse wheel

/* Window/Sensor */
#define sfSensorAccelerometer            0   ///< Measures the raw acceleration (m/s^2)
#define sfSensorGyroscope                1   ///< Measures the raw rotation rates (degrees/s)
#define sfSensorMagnetometer             2   ///< Measures the ambient magnetic field (micro-teslas)
#define sfSensorGravity                  3   ///< Measures the direction and intensity of gravity independent of device acceleration (m/s^2)
#define sfSensorUserAcceleration         4   ///< Measures the direction and intensity of device acceleration independent of the gravity (m/s^2)
#define sfSensorOrientation              5   ///< Measures the absolute 3D orientation (degrees)
#define sfSensorCount                    6   ///< Keep last -- the total number of sensor types

/* Window/Window */
#define sfNone                           0   ///< No border / title bar (this flag and all others are mutually exclusive)
#define sfTitlebar                       1   ///< Title bar + fixed border
#define sfResize                         2   ///< Titlebar + resizable border + maximize button
#define sfClose                          4   ///< Titlebar + close button
#define sfFullscreen                     8   ///< Fullscreen mode (this flag and all others are mutually exclusive)
#define sfDefaultStyle ( sfTitlebar + sfResize + sfClose )   ///< Default window style

#define sfContextDefault                 0   ///< Non-debug, compatibility context (this and the core attribute are mutually exclusive)
#define sfContextCore                    1   ///< Core attribute
#define sfContextDebug                   2   ///< Debug attribute

#endif /* HBSFML_CH_ */