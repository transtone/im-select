# im-select
Switch your input method from terminal. This project is a basic support for [VSCodeVim](https://github.com/VSCodeVim/Vim). It provides the command line program for VSCodeVim's autoSwitchIM function

# Installation

## macOS

Run following command in your terminal:
```shell
curl -Ls https://raw.githubusercontent.com/daipeihust/im-select/master/install_mac.sh | sh
```
The im-select program will be downloaded to your `/usr/local/bin/` path.

### M1 Mac support

Click [here](https://github.com/daipeihust/im-select/blob/8080ad18f20218d1b6b5ef81d26cc5452d56b165/im-select-mac/out/apple/im-select) to download specific im-select program

## windows

[微软官方下载 vs2017](https://visualstudio.microsoft.com/zh-hans/vs/older-downloads/)，选择 `使用c++的桌面开发`，在`可选`里把 `windows 8.1 SDK 和 UCRT SDK` 选上，就可以调试编译了。

Download the x64 [im-select.exe](https://github.com/transtone/im-select/raw/master/im-select-win/x64/Release/im-select.exe), and move it to the proper path.(If you need the 64 bit version, you can download [this one](https://github.com/daipeihust/im-select/raw/master/im-select-win/out/x64/im-select.exe).)

## linux

You don't have to install this for linux. linux have tools to switch input methods


# Usage

## macOS
If your PATH contains `/usr/local/bin`, you can just use `im-select` instead of `/usr/local/bin/im-select`
### To get current input method key
```shell
/usr/local/bin/im-select
```
### To switch current input method
```shell
/usr/local/bin/im-select imkey
```
For example `/usr/local/bin/im-select com.apple.keylayout.US`

## linux

### ibus

[@mengbo](https://github.com/mengbo) provided this configuration for ibus

```
"vim.autoSwitchInputMethod.enable": true,
"vim.autoSwitchInputMethod.defaultIM": "xkb:us::eng",
"vim.autoSwitchInputMethod.obtainIMCmd": "/usr/bin/ibus engine",
"vim.autoSwitchInputMethod.switchIMCmd": "/usr/bin/ibus engine {im}"
```

### xkb-switch

[@VEL4EG](https://github.com/VEL4EG) provided this configuration for xkb-switch

```
"vim.autoSwitchInputMethod.enable": true,
"vim.autoSwitchInputMethod.defaultIM": "us",
"vim.autoSwitchInputMethod.obtainIMCmd": "/usr/local/bin/xkb-switch",
"vim.autoSwitchInputMethod.switchIMCmd": "/usr/local/bin/xkb-switch -s {im}"
```

### fcitx

[@yunhao94](https://github.com/yunhao94) provided this configuration for fcitx

```
"vim.autoSwitchInputMethod.enable": true,
"vim.autoSwitchInputMethod.defaultIM": "1",
"vim.autoSwitchInputMethod.obtainIMCmd": "/usr/bin/fcitx-remote",
"vim.autoSwitchInputMethod.switchIMCmd": "/usr/bin/fcitx-remote -t {im}",
```
### gdbus

[@d-r-q](https://github.com/d-r-q)

Put `gdbus call --session --dest org.gnome.Shell --object-path /org/gnome/Shell --method org.gnome.Shell.Eval "imports.ui.status.keyboard.getInputSourceManager().currentSource.index" | awk -F'[^0-9]*' '{print $2}'` into get-im.sh.

Put `gdbus call --session --dest org.gnome.Shell --object-path /org/gnome/Shell --method org.gnome.Shell.Eval "imports.ui.status.keyboard.getInputSourceManager().inputSources[$1].activate()"` into set-im.sh.

```
"vim.autoSwitchInputMethod.enable": true,
"vim.autoSwitchInputMethod.defaultIM": "0",
"vim.autoSwitchInputMethod.obtainIMCmd": "<path to get-im.sh>",
"vim.autoSwitchInputMethod.switchIMCmd": "<path to set-im.sh> {im}",
```

## windows
The im-select.exe is command line program, but it can't work in cmd or powershell. It's microsoft's fault, the keyboard API doesn't support in cmd and powershell. I recommend you git-bash.

> Note: The git-bash is not required. It's only used to get current input method key, which needed in VSCodeVim's configuration.

### To get current keyboard locale
```shell
/path/to/im-select.exe
```

### To switch current keyboard locale
```shell
/path/to/im-select.exe locale
```

> Note: The path in windows is like: C:\Users\path\to\file

# Contact & Support

<div align="left">
    <img src="contact_me.jpeg" height="300">
    <img src="support_me.jpeg" height="300">
</div>
