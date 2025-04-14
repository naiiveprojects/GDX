## Added

- Core
  - New `PACK_HEADER` ( prevent decompilation with ( unmodified ) tools like Gdsdecomp )
  - Add Support to open original pck `PACK_HEADER`
- Module
  - [MiniZip](https://github.com/godotengine/godot/pull/34444)
- Node
  - `Node` [Backprot 4.x Pause Mode](https://github.com/godotengine/godot/pull/58519)
  - `ProgressBar` [Fill Direction](https://github.com/godotengine/godot/pull/36593)
  - `AudioStreamPlayer` [Control Left and Right Volume](https://github.com/godotengine/godot/pull/51666)
  - `TextEdit` [Code completion filter](https://github.com/godotengine/godot/pull/38449)
- Editor
  - borderless mode switch ( This Also Fix known Nvidia Jitter/Clipping Issue )
  - bottom panel visibility switch
  - Dock Icons
  - `SceneTree` [NodePath export hint](https://github.com/godotengine/godot/pull/39155)
  - `FileSystem` Bottom Dock
  - `CanvasItemEditor` ( 2D ) collapse tool menu into the viewport
  - `ScriptEditor`
    - Script Panel Dock
    - open valid URI
- OS Windows
  - dark mode in window title bar ( non-client area )
  - collapse client area to non client area
  - resizable borderless window ( Call `OS.window_borderless = true` in Script )
- OS Android
  - proguard ( reduce android build size )
- Misc
  - custom build script ( custom.py )

## Changed

- Update Assets
- main
  - Set `boot_splash_bg_color` to `Color(0, 0, 0)`.
- Editor
  - use project icon on project menu button
  - revamp layout
    - Simplify Window Title
    - centered `BottomDock`
    - move `UpdateSpinner` to `BottomDock`
    - hide `VideoDriver` Quick Switch
    - remove `VersionInfo` Button
    - *`& More`*
  - editor log
    - remove init message
    - change Output Text to `VERSION_FULL_BUILD`
  - default editor settings
    - Update Default theme
    - `color_picker_mode` HSV
    - `convert_text_resources_to_binary_on_export` `true`
    - `interface/theme/relationship_line_opacity` 0.15
    - `interface/theme/border_size` 0
    - `rendering/environment/default_clear_color` `Color(0.2, 0.2, 0.2)`
    - `editors/2d/grid_color` `Color(0.5, 0.5, 0.5, 0.07)`
    - `editors/2d/constrain_editor_view` `false`
    - `text_editor/navigation/stay_in_script_editor_on_node_selected` `false`
    - `text_editor/completion/add_type_hints` `true`
    - `text_editor/appearance/word_wrap` `true`
    - `text_editor/cursor/scroll_past_end_of_file` `true`
    - `run/output/always_open_output_on_play` `true`
    - `run/output/always_close_output_on_stop` `true`
    - `debugger/auto_switch_to_remote_scene_tree` `true`
- Project Manager
  - not include default icon & environment when creating project
  - revamp
    - Simplify Window Title
    - Move all option to top section
    - Project List: change `HBoxContainer` to `FlowContainer`
    - `Favorite Button` inside project icon
    - *`& More`*
  - default project manager
    - `sorting_order` Last modified
- Github Actions
  - Add Manual run
  - Create release using artifact (manual)
  - Add server build
  - android: editor, armv7
  - MacOS: universal
  - Rename javascript to web
  - Web: Compiling `Thread`
  - Change prefix and suffix

## Removed

- `VisualScript`

## Fixed

- [Resolve performance issues with create dialog](https://github.com/godotengine/godot/pull/39797)