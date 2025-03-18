# 3XC0

mostly refine / reimplement 3XB branch to get rid some issue it has.

## Added

- Module
  - [MiniZip Module](https://github.com/godotengine/godot/pull/34444) 
- Node
  - `ProgressBar` [Fill Direction](https://github.com/godotengine/godot/pull/36593)
  - `AudioStreamPlayer` [Control Left and Right Volume](https://github.com/godotengine/godot/pull/51666)
- Editor
  - borderless mode switch ( Windows ) ( This Also Fix known Nvidia Jitter/Clipping Issue )
  - bottom panel visibility switch
  - `ScriptEditor` Script List Dock
  - `FileSystem` Bottom Dock
  - `CanvasItemEditor` ( 2D ) colapse tool menu into the viewport
  - Dock Icons
- OS Windows
  - dark mode in window title bar ( non-client area ) https://github.com/naiiveprojects/GDX/commit/d0d0fcc22fccc8804085c142d365dd768ac08fc3
  - colapse client area to non client area https://github.com/naiiveprojects/GDX/commit/d0d0fcc22fccc8804085c142d365dd768ac08fc3
  - resizable borderless window ( Call `OS.window_borderless = true` in Script )
- OS Android
  - proguard ( reduce android build size )
- Misc
  - custom build script ( custom.py )

## Changed

- change default icons, logo, & splash
- Editor
  - use project icon on project menu button
  - revamp layout
    - Simplify Window Title
    - centered `BottomDock`
    - move `UpdateSpinner` to `BottomDock`
    - hide `VideoDriver` Quick Switch
    - remove `VersionInfo` Button
  - editor log
    - remove init message
    - change Output Text to `VERSION_FULL_BUILD`
  - default editor setting
    - Update Default theme
    - corner radius : 8
    - Color Picker mode : HSV
    - convert_text_resources_to_binary_on_export : true
    - interface/theme/relationship_line_opacity : 0.15
- Project Manager
  - not include default icon & environment when creating project
  - revamp layout
    - Simplify Window Title
    - Move all option to top section
    - Project List : change `GridContainer` to `FlowContainer`
    - `Favorite Button` inside project icon
  - default project manager
    - sorting_order : Last modified
  
## Removed

- `VisualScript`

## Fixed

- `ScriptEditor` Fix Crash When calling `Show In FileSystem`

## Known Issue

- Editor
  - Top Bar Panel container theme doesn't update when changing color in setting ( require restart the editor )