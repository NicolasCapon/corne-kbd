# Corne keyboard layout
Personnal corne layout with [french keycodes](https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_french.h) based on default layout.

## QMK

Install [QMK](https://beta.docs.qmk.fm/tutorial/newbs_getting_started)
```
sudo pacman -S qmk
```

## Download layout
```
cd qmk-firmware/crkbd/keymaps
git clone https://github.com/NicolasCapon/corne-kbd.git NicolasCapon
```

## Customization
### Logo
Use canvas size to 128x32 pixels and load the logo using [image2cpp](https://javl.github.io/image2cpp/)
```
Code output format: plain bytes
Draw mode: Vertical, 1 bite per pixel
```

## Compile
```
qmk compile -kb crkbd/rev1 -km NicolasCapon
```

## Flash
Perform this task for each half keyboard.
```
qmk flash -kb crkbd/rev1 -km NicolasCapon
```

## TODO
-  Implement Raw HID
