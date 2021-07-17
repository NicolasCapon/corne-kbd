# Corne keyboard layout

## QMK

Install (QMK)[https://beta.docs.qmk.fm/tutorial/newbs_getting_started]
```
sudo pacman -S qmk
```

## Download layout
```
cd qmk-firmware/crkbd/keymaps
git clone https://github.com/NicolasCapon/corne-kbd.git NicolasCapon
```

## Compile and flash
```
qmk compile -kb crkbd/rev1 -km NicolasCapon
qmk flash -kb crkbd/rev1 -km NicolasCapon
```

