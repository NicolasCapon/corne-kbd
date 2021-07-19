# Corne keyboard layout
Personnal corne layout with french keycodes based on default layout.

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
-  Modify layout indicator on OLED
-  Implement Raw HID
