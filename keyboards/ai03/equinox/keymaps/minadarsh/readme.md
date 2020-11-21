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
_Colemak-DH, Backspace is where Capslock normally is, but if using_
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
│Capslock │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │ '(;)┋Enter│
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋  Z  │  X  │  C  │  V  │  B  │  /  │  N  │  M  │ ,(-)│  .  ┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │    Space     ┋Space┋     Space    │  Fn  │     │ N/A  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Qwerty, but for gaming, left Backspace is now Capslock once more as some games use this,_
_and Windows key is disabled, just in case._

## Additional layers for numbers, symbols and other functions

You may have noticed one Function key in the keymap overviews above, but two extra layers, just holding the Function key will switch to the _symbols_ layer, tapping it once followed by a hold will switch to the _adjust_ layer.


```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│ Escape │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │ BkSp │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│  Grave  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │  \  │  =  │  [  │  ]  ┋Enter│
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ Ins │ Del │Pg Up│Pg Dn┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │              ┋     ┋              │Adjust│     │ Win  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Symbols layer, though it mostly offers numbers and F-row keys, etc._
_Blank keys are transparent thus using keys on the previous layer._

```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│  N/A   │ Qwt │     │     │Reset│     │     │Next │Vol -│Vol +│Prev │ BkSp │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│Capslock │     │     │     │     │Game │     │Left │Down │ Up  │Right┋Play │
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋     │     │ Col │     │     │     │     │     │Home │ End ┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │     N/A      ┋ N/A ┋      N/A     │      │     │ Win  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Adjust layer, the rest of the features are here, including media controls and arrows._
_Blank Alpha keys and keys market N/A are not transparent here, they don't do anything when pressed._

## Additional notes

- Make sure when making your own version based on my keymap to have `TAP_DANCE = yes` in your `rules.mk` file and `#define TAPPING_TERM 175` in your `config.h` (the number `175` can be changed to anything you want and is in milliseconds), else the double-tap keys on the persistent layers won't work, or to remove the Tap Dance buttons entirely.
- `config.h` undefines `PRODUCT` and then redefines it with my own, this is so that when you look up the device in (Windows) Devices on your computer, it'll have a nice personalized name. You can change this in your own map to make your board also have a unique name. `\x0027` is used to type an apostrophe.
