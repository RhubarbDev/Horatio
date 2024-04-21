#include <iostream>
#include <Window.h>

int main()
{
    Horatio::Hint test_hint;

    test_hint.hint = 0x00020003; // window resizable
    test_hint.value = false;

    Horatio::Window window("test", 500, 500, false, { test_hint });

    while(!window.should_close)
    {
        window.poll_events();
        window.clear_buffer();
        window.swap_buffers();
    }
}