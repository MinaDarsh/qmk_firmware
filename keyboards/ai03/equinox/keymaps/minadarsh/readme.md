# Mina's Equinox keymap

A personal keymap for the ION x Ai03 Equinox WKL, using split Shifts, full Spacebar, and ISO Enter.

## Persistent layers

It features Persistent layers for Colemak-DHk (default) and two Qwerty layouts, one normal, and one more optimized for gaming. These layers remain set even after un-plugging your keyboard. Due to my preference and to keep the keys somewhat consistent on the physical board, the Angle Mod is also applied to the Qwerty layouts.

```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│  Tab   │  Q  │  W  │  F  │  P  │  B  │  J  │  L  │  U  │  Y  │ '(;)│ BkSp │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│Backspace│  A  │  R  │  S  │  T  │  G  │  K  │  N  │  E  │  I  │  O  ┋Enter│
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋  Z  │  X  │  C  │  D  │  V  │  /  │  M  │  H  │ ,(-)│  .  ┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │    Space     ┋Space┋     Space    │  Fn  │     │ Win  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Colemak-DHk, Backspace is where Capslock normally is, but if using_
_a 1.25U Enter and 1.5U Backspace, it can be in the top-right too._
_If using split Space, all will be space, so change that too for your own map._

Note: I chose not to layer some of the more commonly used keys, dash and colon. These can be accessed by double-tapping the keys that you see in the keymap that have their Tap Dance key in parenthesis. Holding Shift will send their shifted key. So for example, if you want to type a underscore or colon, hold Shift, and double-tap quote or comma fast enough. (Tapping Term can be set in `config.h`)


```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│  Tab   │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ BkSp │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│Backspace│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │ '(;)┋Enter│
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋  Z  │  X  │  C  │  V  │  B  │  /  │  N  │  M  │ ,(-)│  .  ┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │    Space     ┋Space┋     Space    │  Fn  │     │ Win  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Qwerty, same as Colemak-DH, but with your good ol' typewriter optimized layout._

```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│  Tab   │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ BkSp │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│Caps Lock│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │ '(;)┋Enter│
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋  Z  │  X  │  C  │  V  │  B  │  /  │  N  │  M  │ ,(-)│  .  ┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │    Space     ┋Space┋     Space    │  Fn  │     │ N/A  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Qwerty, but for gaming, left Backspace is now Caps Lock once more as some games use this,_
_and Windows key is disabled, just in case._

## Additional layers for numbers, symbols and other functions

You may have noticed one Function key in the keymap overviews above, but three extra layers, just holding the Function key will switch to the _symbols_ layer, tapping it once followed by a hold will switch to the _shifted symbols_ layer, lastly, tapping trice holding on the last tap will enter the _adjust_ layer. If you omit holding on the last press, they keyboard will toggle these layers rather than waiting for you to let go of the key in order to go back to the main layer. So for example, tapping twice brings you to the _shifted symbols_ layer, and stays there. tap twice to go back to the main layer. You can also hop between layers, so from _shift symbols_ you can also go to _symbols_ by tapping once or _adjust_ by tapping trice from there. When you want to get back to main, there are three ways:

* If you know which layer you're on, tap the amount you used to get on that layer again.
* If you don't know it, you can either hold the button longer than Tapping Term. (250ms for this key specifically.)
* Or tap four times in a row or more, this will enter the final possibility which is set to leave all extra layers.

```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│ Escape │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │ BkSp │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│  Grave  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │  \  │  =  │  [  │  ]  ┋Enter│
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ Ins │ Del │Pg Up│Pg Dn┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │              ┋Space┋              │  Fn  │     │ Win  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Symbols layer, though it mostly offers numbers and F-row keys, etc._

```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│  Esc   │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  (  │  )  │ BkSp │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│  Tilde  │Left │ Up  │Down │Right│ N/A │ N/A │  |  │  +  │  {  │  }  ┋Play │
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋Prev │Vol -│Vol +│Next │ N/A │ N/A │PScrn│Pause│Home │ End ┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │              ┋Space┋              │  Fn  │     │ Win  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Shifted Symbols Layer, for when two taps is easier than holding Shift as well._
_Also the remainder of the Navigation keys can be found here as well as Media keys._

```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│ Reset  │Qwrty│     │     │     │     │     │     │     │     │     │      │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│         │     │     │     │     │Game │     │     │     │     │     ┋     │
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│      ┋     │     │Colmk│BlBth│BlStp│     │     │     │     │     ┋        │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│      │     │      │              ┋     ┋              │  Fn  │     │      │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Adjust layer, controlling keyboard settings like layout and backlighting, as well as enabling DFU Mode._
_Blank keys on just this layer are not transparent here but disabled, they don't do anything when pressed._

To clarify:

* Qwrty, Colmk and Game switch to Qwerty, Colemak-DHk and Gaming layout respectively.
* BlBth toggles Backlight Breathing mode and BlStp cycles through backlight brightness levels. (off, level 1 to 5 in brightness.)

## Additional notes

- Make sure when making your own version based on my keymap to have `TAP_DANCE = yes` in your `rules.mk` file and `#define TAPPING_TERM 175` and `#define TAPPING_TERM_PER_KEY` in your `config.h`, else the double-tap keys on the persistent layers won't work. The number after Tapping Term can be changed to whatever you want and is in milliseconds. Each key in the keymap can also get their own Tapping Term in the `get_tapping_term()` Function.
- `config.h` undefines `PRODUCT` and then redefines it with my own, this is so that when you look up the device in (Windows) Devices on your computer, it'll have a nice personalized name. You can change this in your own map to make your board also have a unique name. `\x0027` is used to type an apostrophe.
