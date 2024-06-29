## Added

- [MiniZip Module](https://github.com/godotengine/godot/pull/34444)
- custom build script (custom.py)
- ProgressBar : [fill direction](https://github.com/godotengine/godot/pull/36593)
- Editor
  - borderless mode
  - show/hide bottom panel button
  - Script Editor
  - Switch between Default & Docked mode for Script List
- OS Windows
  - dark mode in window title bar (non-client area)
  - resizable borderless window (call via script: `OS.window_borderless = true`)
  - colapse client area to non client area
- OS Android
  - proguard (reduce android build size)
- `& more ...`

## Changed

- change icons, logo, & splash
- dark initial color bg
- Editor
  - centered bottom dock
  - move update spinner to bottom dock
  - use project icon on project menu button
  - re-arrage title bar (Project Name, Edited Node Path)
  - revamp layout
  - minify icon
  - Dark default theme
  - inspector :
  	- hide general option
  	- move history menu
  - editor log :
    - remove init message
    - change Output title to build version
  - colapse tool menu in canvas item editor
  - double max char/sec
- default editor setting
  - Default dark theme
  - corner radius : 8
  - Color Picker mode : HSV
  - clear color : 0.2, 0.2, 0.2
  - word_wrap : true
  - Type Hint: True
  - convert_text_resources_to_binary_on_export : true
  - text_editor/cursor/scroll_past_end_of_file : true
  - constrain_editor_view : false
  - always_open_output_on_play : false
  - auto_switch_to_remote_scene_tree : true
  - editors/2d/grid_color : Color(0.5, 0.5, 0.5, 0.07)
  - file system file sort : FILE_SORT_TYPE
  - stay_in_script_editor_on_node_selected : false
- project manager
	- revamp layout
	- change grid container to flow container
	- not include default icon & environment when creating project
	- favorite ontop project icon
	- option on top
	- black background
	- re-arrage title bar ( + version full build + hash)
- default project manager
	- sorting_order : Last modified
- Github Action
  - no static checks
  - manual trigger
  - Android : compile armv7
  - Linux : Editor & Template
- `& more ...`
  
## Removed

- visual script
- deprecated features
- Editor
  - video driver toggle
  - version info button
- `& more ...`

## Issue

- Github Action
  - Android
    - Problem:
      - /home/runner/work/_temp/*****.sh: line 2: ./gradlew: Permission denied
      - Error: Process completed with exit code 126.
    - Explanation:
      - Permission denied 😊
    - Solution:
      - terminal
        - `cd platform/android/java`
        - `git update-index --chmod=+x gradlew`
      - Commit & Push