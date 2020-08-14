# Mina's Equinox keymap

A personal keymap for the ION x Ai03 Equinox WKL, using split Shifts, full Spacebar, and ISO Enter.

## Persistent layers

It features Persistent layers for Colemak-DH (default) and two Qwerty layouts, one normal, and one more optimized for gaming. These layers remain set even after un-plugging your keyboard.

```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│  Tab   │  Q  │  W  │  F  │  P  │  B  │  J  │  L  │  U  │  Y  │ ;(')│ BkSp │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│Backspace│  A  │  R  │  S  │  T  │  G  │  K  │  N  │  E  │  I  │  O  ┋Enter│
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋ Fn  │  Z  │  X  │  C  │  D  │  V  │  M  │  H  │ ,(-)│ .(/)┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │    Space     ┋Space┋     Space    │  Fn  │     │ Win  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Colemak-DH, Backspace is where Capslock normally is, but if using_
_a 1.25U Enter and 1.5U Backspace, it can be in the top-right too._
_If using split Space, all will be space, so change that too for your own map._

Note: I choose not to layer some of the more commonly used keys, dash, slash and quote. These can be accessed by double-tapping the keys that you see in the keymap that have their Tap Dance key in parenthesis. Holding Shift will send their shifted key. So for example, if you want to type a question mark, hold Shift, and double-tap dot fast enough. (Tapping Term can be set in `config.h`)

```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│  Tab   │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ BkSp │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│Backspace│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │ ;(')┋Enter│
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋ Fn  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │ ,(-)│ .(/)┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │    Space     ┋Space┋     Space    │  Fn  │     │ Win  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Qwerty, same as Colemak-DH, but with your good ol' typewriter optimized layout._

```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│  Tab   │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ BkSp │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│Capslock │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │ ;(')┋Enter│
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋ Fn  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │ ,(-)│ .(/)┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │    Space     ┋Space┋     Space    │  Fn  │     │ N/A  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Qwerty, but for gaming, left Backspace is now Capslock once more as some games use this,_
_and Windows key is disabled, just in case._

## Additional layers for numbers, symbols and other functions

You may have noticed two Function keys in the keymap overviews above, they both do the same thing on their own, pressing either of them will switch to the _symbols_ layer as long as they're held, pressing them both will switch to the _adjust_ layer as long as they're both held or at least the last key of the two pressed is held. (I just felt like adding that last detail, QMK works funny like that.) I wanted to stick to just one Function key, but haven't found out how yet.

```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│ Escape │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │ BkSp │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│  Grave  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │  \  │  =  │  [  │  ]  ┋Enter│
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋Adjst│ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ Del │Pg Up│Pg Dn┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │              ┋     ┋              │Adjust│     │ Win  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Symbols layer, though it mostly offers numbers and F-row keys, etc._
_Blank keys are transparent thus using keys on the previous layer._

```
┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
│  N/A   │ QWT │     │     │Reset│     │     │Next │Vol -│Vol +│Prev │ BkSp │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
│CAPS LOCK│     │     │     │     │     │     │Left │Down │ Up  │Right┋Play │
├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
│Shift ┋     │     │     │ COL │     │     │     │     │Home │ End ┋  Shift │
├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
│ Ctrl │     │ Alt  │     N/A      ┋ N/A ┋      N/A     │      │     │ Win  │
└──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
```
_Adjust layer, the rest of the features are here, including media controls and arrows._
_Blank Alpha keys and keys market N/A are not transparent here, they don't do anything when pressed._

## Additional notes

- Make sure when making your own version based on my keymap to have `TAP_DANCE = yes` in your `rules.mk` file, else the double-tap keys on the persistent layers won't work, or to remove the Tap Dance buttons entirely.
- `config.h` undefines `PRODUCT` and then redefines it with my own, this is so that when you look up the device in (Windows) Devices on your computer, it'll have a nice personalized name. You can change this in your own map to make your board also have a unique name. `\x0027` is used to type an apostrophe.
