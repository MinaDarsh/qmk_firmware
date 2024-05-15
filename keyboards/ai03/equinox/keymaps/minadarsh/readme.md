# Mina's Equinox keymap

A personal keymap for the ION x Ai03 Equinox WKL, using split Shifts, full Spacebar, and ISO Enter.

## Persistent layers

There are three main layers, or Persistent Layers, these stay selected even if reconnecting the board:
* Colemak-DHk layer, this one is the default.
* Qwerty, only changes the layout of the Alpha keys, Backspace still on Caps Lock.
* Gaming, same as Qwerty, but Caps Lock restored (some games need this) and Tap Dance Tab is different. (More further on.)

Colemak-DHk:

![Colemak](https://i.imgur.com/Hp4YR4y.png)

_Colemak-DHk, Backspace is where Capslock normally is._


#### Tap Dance Keys on the Main Layer

I chose not to layer some of the more commonly used keys, dash and colon. These can be accessed by double-tapping the keys that you see in the keymap that have their Tap Dance key in parenthesis. Holding Shift will send their shifted variant. So for example, if you want to type a underscore or colon, hold Shift, and double-tap quote or comma fast enough. (Tapping Term can be set in `config.h`)

#### Custom Tap Dance Tap/Escape

Tab is a special kind of Tap Dance key, as it will send Tab on a short press, Escape on a long one. If hitting the key multiple times rapidly, it'll just send Tab, even if holding the last tap. (Which will be like holding Tab down for the duration of the key press.) This is so that it can still be used to quickly insert Tabs when scripting without having the delay that the Tapping Term would impose.


Qwerty:

![Qwerty](https://i.imgur.com/tPjsHYp.png)

_Qwerty, same as Colemak-DH, but with your good ol' typewriter optimized layout._


Gaming:

![G4MUR!](https://i.imgur.com/BrRTvgk.png)

_Qwerty, but for gaming, left Backspace is now Caps Lock once more as some games use this._


_* With the gaming layer, the Tap Dance key for Tab/Escape is a normal Double Tap Dance again, so you don't get Escape by holding it, but by tapping it twice. This way you can still hold Tab as that is more finnicky with the special Tap Dance Tab/Escape described prior in games._

## Additional non-persistent layers for numbers, symbols, numpad and other functions

You may have noticed one key labeled `MO/LT` in the keymap overviews above, but four extra layers (the fourth being accessed differently, though), just holding the `MO/LT` key will switch to the _symbols_ layer, tapping it once followed by a hold will switch to the _shifted symbols_ layer, lastly, tapping trice holding on the last tap will enter the _adjust_ layer. If you omit holding on the last press, the keyboard will toggle these layers rather than waiting for you to let go of the key in order to go back to the main layer. (Hence the `MO/LT` name.) So for example, tapping twice brings you to the _shifted symbols_ layer, and stays there (until idle timeout), tap twice again to go back to the main layer. You can also hop between layers, so from _shifted symbols_ you can also go to _symbols_ by tapping once or _adjust_ by tapping trice from there. When you want to get back to main, there are three ways:

* If you know which layer you're on, tap the amount you used to get on that layer again.
* If you don't know it, you can either hold the button longer than Tapping Term and let go. (250ms for this key specifically.)
* Or tap four times in a row or more, this will leave all extra layers.
* Last but not least, if you do nothing for a while the keyboard will switch back to the main layer by itself. (See Additional Notes.)

![Symbols and Media](https://i.imgur.com/90yvQdA.png)

_Symbols layer, numbers, symbols and media keys are housed here._

![Shifted Symbols and Function Keys](https://i.imgur.com/22XjjQ2.png)

_Shifted Symbols Layer, for when two taps is easier than holding Shift as well._
_Function keys are here as well._

![Keyboard Settings](https://i.imgur.com/KOQUmdD.png)

_Adjust layer, controlling keyboard settings like layout, NKRO and enabling DFU Mode._
_Keys labeled N/A here are disabled, they don't do anything when pressed._


To clarify:

* Qwerty, Colemak and Game switch layouts that stay even when the board loses power.
* Numpad switches over to the Numpad layer, or TenKey. (Hence I put it on the T-key, assuming Qwerty.(May move in the future.))
* NKRO toggles N-key Rollover, you may need to disable it if using this keyboard in your computer's BIOS.

![Numpad Layer](https://i.imgur.com/7llBeae.png)

_Numpad layer, note that the Function key is used for Numpad 0._
_Switching back is done by hitting Leave Num. (Numpad.)_
_or by waiting for Layer Idle Timeout to trigger._


## Additional notes

- Make sure when making your own version based on my keymap to have `TAP_DANCE = yes` in your `rules.mk` file and `#define TAPPING_TERM 175` and `#define TAPPING_TERM_PER_KEY` in your `config.h`, else the double-tap keys on the persistent layers won't work. The number after Tapping Term can be changed to whatever you want and is in milliseconds. Each key in the keymap can also get their own Tapping Term in the `get_tapping_term()` Function in your keymap.
- In `config.h`, `#define LAYER_IDLE_TIMEOUT 3` is used to set a timeout variable for when to automatically switch back to the main layer if you toggled to one of the non-persistent layers. The number is the amount of seconds which you can change to your liking.
- `config.h` undefines `PRODUCT` and then redefines it with my own, this is so that when you look up the device in (Windows) Devices on your computer, it'll have a nice personalized name. You can change this in your own map to make your board also have a unique name. `\x0027` is used to type an apostrophe.
