---
layout: default
title: Window
permalink: window
---

#**Function Documentation Window**

# sfWindow_close()

```c

void sfWindow_close( sfWindow* window )

```

Close a window and destroy all the attached resources.

After calling this function, the sfWindow object remains valid, you must call sfWindow_destroy to actually delete it. All other functions such as sfWindow_pollEvent or sfWindow_display will still work (i.e. you don't have to test sfWindow_isOpen every time), and will have no effect on closed windows.

**Parameters**

- `window` Window object

# sfWindow_create()

```c

sfWindow* sfWindow_create( sfVideoMode mode, const char* title, sfUint32 style, const sfContextSettings* settings )

```

Construct a new window.

This function creates the window with the size and pixel depth defined in mode. An optional style can be passed to customize the look and behaviour of the window (borders, title bar, resizable, closable, ...). If style contains sfFullscreen, then mode must be a valid video mode.

The fourth parameter is a pointer to a structure specifying advanced OpenGL context settings such as antialiasing, depth-buffer bits, etc.

**Parameters**

- `mode` Video mode to use (defines the width, height and depth of the rendering area of the window)
- `title` Title of the window
- `style` Window style
- `settings` Additional settings for the underlying OpenGL context

**Returns**

A new sfWindow object

# sfWindow_createFromHandle()

```c

sfWindow* sfWindow_createFromHandle( sfWindowHandle handle, const sfContextSettings* settings )

```

Construct a window from an existing control.

Use this constructor if you want to create an OpenGL rendering area into an already existing control.

The second parameter is a pointer to a structure specifying advanced OpenGL context settings such as antialiasing, depth-buffer bits, etc.

**Parameters**

- `handle` Platform-specific handle of the control
- `settings` Additional settings for the underlying OpenGL context

**Returns**

A new sfWindow object

# sfWindow_createUnicode()

```c

sfWindow* sfWindow_createUnicode( sfVideoMode mode, const sfUint32* title, sfUint32 style, const sfContextSettings* settings )

```

Construct a new window (with a UTF-32 title)

This function creates the window with the size and pixel depth defined in mode. An optional style can be passed to customize the look and behaviour of the window (borders, title bar, resizable, closable, ...). If style contains sfFullscreen, then mode must be a valid video mode.

The fourth parameter is a pointer to a structure specifying advanced OpenGL context settings such as antialiasing, depth-buffer bits, etc.

**Parameters**

- `mode` Video mode to use (defines the width, height and depth of the rendering area of the window)
- `title` Title of the window (UTF-32)
- `style` Window style
- `settings` Additional settings for the underlying OpenGL context

**Returns**

A new sfWindow object

# sfWindow_destroy()

```c

void sfWindow_destroy( sfWindow* window )

```

Destroy a window.

**Parameters**

- `window` Window to destroy

# sfWindow_display()

```c

void sfWindow_display( sfWindow* window )

```

Display on screen what has been rendered to the window so far.

This function is typically called after all OpenGL rendering has been done for the current frame, in order to show it on screen.

**Parameters**

- `window` Window object

# sfWindow_getPosition()

```c

sfVector2i sfWindow_getPosition(	const sfWindow* window	)

```

Get the position of a window.

**Parameters**

- `window` Window object

**Returns**
Position in pixels

# sfWindow_getSettings()

sfContextSettings sfWindow_getSettings( const sfWindow* window )

Get the settings of the OpenGL context of a window.

Note that these settings may be different from what was passed to the sfWindow_create function, if one or more settings were not supported. In this case, SFML chose the closest match.

**Parameters**

- `window` Window object

**Returns**

Structure containing the OpenGL context settings

# sfWindow_getSize()

```c

sfVector2u sfWindow_getSize( const sfWindow* window )

```

Get the size of the rendering region of a window.

The size doesn't include the titlebar and borders of the window.

**Parameters**

- `window` Window object

**Returns**

Size in pixels

# sfWindow_getSystemHandle()

```c

sfWindowHandle sfWindow_getSystemHandle( const sfWindow* window )

```

Get the OS-specific handle of the window.

The type of the returned handle is sfWindowHandle, which is a typedef to the handle type defined by the OS. You shouldn't need to use this function, unless you have very specific stuff to implement that SFML doesn't support, or implement a temporary workaround until a bug is fixed.

**Parameters**

- `window` Window object

**Returns**

System handle of the window

# sfWindow_hasFocus()

```c

sfBool sfWindow_hasFocus( const sfWindow* window )

```

Check whether the window has the input focus.

At any given time, only one window may have the input focus to receive input events such as keystrokes or most mouse events.

**Returns**

True if window has focus, false otherwise

# sfWindow_isOpen()

```c

sfBool sfWindow_isOpen(	const sfWindow* window	)

```

Tell whether or not a window is opened.

This function**Returns** whether or not the window exists. Note that a hidden window (sfWindow_setVisible(sfFalse)) will return sfTrue.

**Parameters**

- `window` Window object

**Returns**

sfTrue if the window is opened, sfFalse if it has been closed

# sfWindow_pollEvent()

```c

sfBool sfWindow_pollEvent(	sfWindow* window, sfEvent* event )

```

Pop the event on top of event queue, if any, and return it.

This function is not blocking: if there's no pending event then it will return false and leave event unmodified. Note that more than one event may be present in the event queue, thus you should always call this function in a loop to make sure that you process every pending event.

**Parameters**

- `window` Window object
- `event` Event to be returned

**Returns**

sfTrue if an event was returned, or sfFalse if the event queue was empty

# sfWindow_requestFocus()

```c

void sfWindow_requestFocus( sfWindow* window )

```

Request the current window to be made the active foreground window.

At any given time, only one window may have the input focus to receive input events such as keystrokes or mouse events. If a window requests focus, it only hints to the operating system, that it would like to be focused. The operating system is free to deny the request. This is not to be confused with sfWindow_setActive().

# sfWindow_setActive()

```c

sfBool sfWindow_setActive(	sfWindow* window, sfBool active )

```

Activate or deactivate a window as the current target for OpenGL rendering.

A window is active only on the current thread, if you want to make it active on another thread you have to deactivate it on the previous thread first if it was active. Only one window can be active on a thread at a time, thus the window previously active (if any) automatically gets deactivated. This is not to be confused with sfWindow_requestFocus().

**Parameters**

- `window` Window object
- `active` sfTrue to activate, sfFalse to deactivate

**Returns**

sfTrue if operation was successful, sfFalse otherwise

# sfWindow_setFramerateLimit()

```c

void sfWindow_setFramerateLimit( sfWindow* window, unsigned int limit )

```

Limit the framerate to a maximum fixed frequency.

If a limit is set, the window will use a small delay after each call to sfWindow_display to ensure that the current frame lasted long enough to match the framerate limit.

**Parameters**

- `window` Window object

limit Framerate limit, in frames per seconds (use 0 to disable limit)

# sfWindow_setIcon()

```c

void sfWindow_setIcon( sfWindow* window, unsigned int width, unsigned int height, const sfUint8* pixels )

```

Change a window's icon.

pixels must be an array of width x height pixels in 32-bits RGBA format.

**Parameters**

- `window` Window object
- `width` Icon's width, in pixels
- `height` Icon's height, in pixels
- `pixels` Pointer to the array of pixels in memory

# sfWindow_setJoystickThreshold()

```c

void sfWindow_setJoystickThreshold( sfWindow* window, float threshold )

```

Change the joystick threshold.

The joystick threshold is the value below which no JoyMoved event will be generated.

**Parameters**

- `window` Window object
- `threshold` New threshold, in the range [0, 100]

# sfWindow_setKeyRepeatEnabled()

void sfWindow_setKeyRepeatEnabled( sfWindow* window, sfBool enabled )

Enable or disable automatic key-repeat.

If key repeat is enabled, you will receive repeated KeyPress events while keeping a key pressed. If it is disabled, you will only get a single event when the key is pressed.

Key repeat is enabled by default.

**Parameters**

- `window` Window object
- `enabled` sfTrue to enable, sfFalse to disable

# sfWindow_setMouseCursorGrabbed()

void sfWindow_setMouseCursorGrabbed( sfWindow* window, sfBool grabbed )

Grab or release the mouse cursor.

If set, grabs the mouse cursor inside this window's client area so it may no longer be moved outside its bounds. Note that grabbing is only active while the window has focus and calling this function for fullscreen windows won't have any effect (fullscreen windows always grab the cursor).

**Parameters**

- `grabbed` sfTrue to enable, sfFalse to disable

# sfWindow_setMouseCursorVisible()

```c

void sfWindow_setMouseCursorVisible( sfWindow* window, sfBool visible )

```

Show or hide the mouse cursor.

**Parameters**

- `window` Window object
- `visible` sfTrue to show, sfFalse to hide

# sfWindow_setPosition()

```c

void sfWindow_setPosition( sfWindow* window, sfVector2i position )

```

Change the position of a window on screen.

This function only works for top-level windows (i.e. it will be ignored for windows created from the handle of a child window/control).

**Parameters**

- `window` Window object
- `position` New position of the window, in pixels

# sfWindow_setSize()

```c

void sfWindow_setSize( sfWindow* window, sfVector2u size )

```

Change the size of the rendering region of a window.

**Parameters**

- `window` Window object
- `size` New size, in pixels

# sfWindow_setTitle()

```c

void sfWindow_setTitle(	sfWindow* window, const char* title )

```

Change the title of a window.

**Parameters**

- `window` Window object
- `title` New title

# sfWindow_setUnicodeTitle()

```c

void sfWindow_setUnicodeTitle( sfWindow _ window, const sfUint32 _ title )

```

Change the title of a window (with a UTF-32 string)

**Parameters**

- `window` Window object
- `title` New title

# sfWindow_setVerticalSyncEnabled()

```c

void sfWindow_setVerticalSyncEnabled( sfWindow* window, sfBool enabled )

```

Enable or disable vertical synchronization.

Activating vertical synchronization will limit the number of frames displayed to the refresh rate of the monitor. This can avoid some visual artifacts, and limit the framerate to a good value (but not constant across different computers).

**Parameters**

- `window` Window object
- `enabled` sfTrue to enable v-sync, sfFalse to deactivate

# sfWindow_setVisible()

```c

void sfWindow_setVisible( sfWindow* window, sfBool visible )

```

Show or hide a window.

**Parameters**

- `window` Window object
- `visible` sfTrue to show the window, sfFalse to hide it

# sfWindow_waitEvent()

```c

sfBool sfWindow_waitEvent(	sfWindow* window, sfEvent* event )

```

Wait for an event and return it.

This function is blocking: if there's no pending event then it will wait until an event is received. After this function**Returns** (and no error occured), the event object is always valid and filled properly. This function is typically used when you have a thread that is dedicated to events handling: you want to make this thread sleep as long as no new event is received.

**Parameters**

- `window` Window object
- `event` Event to be returned

**Returns**

sfFalse if any error occured
