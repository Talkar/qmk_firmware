# Quantum Mechanical Keyboard Firmware

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/qmk)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the Clueboard product line.

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)
# Windows

## Prerequisites
* Install [QMK_Msys](https://msys.qmk.fm/)
* Install [QMK_Toolbox](https://qmk.fm/toolbox)
1. Start QMK_Toolbox as admin
2. Install drivers in QMK_Toolbox

# Linux

## prerequisites
1. Ensure python3-pip is installed `sudo apt install -y git python3-pip`
2. Install qmk cli `python3 -m pip install --user qmk`
3. Clone this repo
4. Execute `qmk setup`
5. If there is an error of qmk not found, execute `echo 'PATH="$HOME/.local/bin:$PATH"' >> $HOME/.bashrc && source $HOME/.bashrc`
6. Answer `y` to install dependencies

## Commands
* Compile: `qmk compile -kb keychron/q11/iso_encoder -km talkar`
* Flash: `qmk flash -kb keychron/q11/iso_encoder -km talkar`

