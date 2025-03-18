# 3XC0

mostly refine / reimplement 3XB branch to get rid some issue it has.

## Added

- Module
  - [MiniZip](https://github.com/godotengine/godot/pull/34444) [`1c26a14`](https://github.com/naiiveprojects/GDX/commit/1c26a14a90cf0a9346d286e5fce243953c024cc9)
- Node
  - `ProgressBar` [Fill Direction](https://github.com/godotengine/godot/pull/36593) [`7a553a1`](https://github.com/naiiveprojects/GDX/commit/7a553a1cccd52f976e224784487db2f842e5f89b)
  - `AudioStreamPlayer` [Control Left and Right Volume](https://github.com/godotengine/godot/pull/51666) [`c355830`](https://github.com/naiiveprojects/GDX/commit/c35583051e7d9afc5b2969038eeeda870795bd61)
- Editor
  - borderless mode switch ( This Also Fix known Nvidia Jitter/Clipping Issue )
  - bottom panel visibility switch
  - `ScriptEditor` Script List Dock [`384d464`](https://github.com/naiiveprojects/GDX/commit/384d464dd646ea8aa754406de1bcec90fdb4bd8a)  [`3dac6fb`](https://github.com/naiiveprojects/GDX/commit/3dac6fbee5f74aaac58eada7d09a2303339e800c)
  - `FileSystem` Bottom Dock [`465df9c`](https://github.com/naiiveprojects/GDX/commit/465df9c05869558beb5bfb7b25d1adc992057e46)  [`0f136d1`](https://github.com/naiiveprojects/GDX/commit/0f136d18eee9dcb557a5d1597e0cafa1e89c5566)
  - `CanvasItemEditor` ( 2D ) colapse tool menu into the viewport [`02e44a9`](https://github.com/naiiveprojects/GDX/commit/02e44a95a9d3017e73427ab5c27a741f28d8a15e)
  - Dock Icons [`c8fd9bd`](https://github.com/naiiveprojects/GDX/commit/c8fd9bd4556fc5bfef208fd261f47e718ab50404)
- OS Windows
  - dark mode in window title bar ( non-client area ) [`d0d0fcc`
](https://github.com/naiiveprojects/GDX/commit/d0d0fcc22fccc8804085c142d365dd768ac08fc3)
  - colapse client area to non client area [`d0d0fcc`
](https://github.com/naiiveprojects/GDX/commit/d0d0fcc22fccc8804085c142d365dd768ac08fc3)
  - resizable borderless window ( Call `OS.window_borderless = true` in Script ) [`56d8204`](https://github.com/naiiveprojects/GDX/commit/50d2cc5ade8bf6fe3f5d607532b263f32bcca588)
- OS Android
  - proguard ( reduce android build size ) [`60594e4`](https://github.com/naiiveprojects/GDX/commit/60594e4e2e1aa3c7501ffa62d2ec91fa718b621c)
- Misc
  - custom build script ( custom.py ) [`868bd17`](https://github.com/naiiveprojects/GDX/commit/868bd17d97ba37efdecfc81534585ba2d31f5349)

## Changed
- Update Assets [`2ff2237`](https://github.com/naiiveprojects/GDX/commit/2ff22373e77d6ef6645eb167f8ca5e0c0a29d04c)
- main
  - boot_splash_bg_color = Color(0, 0, 0)
- Editor
  - use project icon on project menu button
  - revamp layout
    - Simplify Window Title
    - centered `BottomDock`
    - move `UpdateSpinner` to `BottomDock`
    - hide `VideoDriver` Quick Switch
    - remove `VersionInfo` Button
    - *`& More`* [`eaaef03`](https://github.com/naiiveprojects/GDX/commit/eaaef03cef40c246b4d2b053be1ab258aa778dea) [`c8fd9bd`](https://github.com/naiiveprojects/GDX/commit/c8fd9bd4556fc5bfef208fd261f47e718ab50404)
  - editor log [`449d8e1`](https://github.com/naiiveprojects/GDX/commit/449d8e18ec01c341b0b65a44eee7782351e18359)
    - remove init message
    - change Output Text to `VERSION_FULL_BUILD`
  - default editor settings [`449d8e1`](https://github.com/naiiveprojects/GDX/commit/449d8e18ec01c341b0b65a44eee7782351e18359)  [`8cda548`](https://github.com/naiiveprojects/GDX/commit/8cda548eb0636a2bcc3f7431fb7c9ad76e4a20e5)
    - Update Default theme [`7dafa67`](https://github.com/naiiveprojects/GDX/commit/7dafa67b9485a6e0dff5950dbfcebe826594de3f)
    - corner radius: 8
    - Color Picker mode: HSV
    - convert_text_resources_to_binary_on_export: true
    - interface/theme/relationship_line_opacity: 0.15
    - interface/theme/border_size: 0
    - rendering/environment/default_clear_color: Color(0.2, 0.2, 0.2)
    - editors/2d/grid_color: Color(0.5, 0.5, 0.5, 0.07)
    - editors/2d/constrain_editor_view: false
    - text_editor/navigation/stay_in_script_editor_on_node_selected: false
    - text_editor/completion/add_type_hints: true
    - text_editor/appearance/word_wrap: true
    - text_editor/cursor/scroll_past_end_of_file: true
    - run/output/always_open_output_on_play: true
    - run/output/always_close_output_on_stop: true
    - debugger/auto_switch_to_remote_scene_tree: true
- Project Manager
  - not include default icon & environment when creating project [`bf620d9`](https://github.com/naiiveprojects/GDX/commit/bf620d9ed6237fc57d91ca7fa734583e8dd1c1dd)
  - revamp
    - Simplify Window Title
    - Move all option to top section
    - Project List : change `HBoxContainer` to `FlowContainer`
    - `Favorite Button` inside project icon
    - *`& More`*  [`13d592f`](https://github.com/naiiveprojects/GDX/commit/13d592f7bda839f4f041eb3ce6611837c85e8741) [`d25314c`](https://github.com/naiiveprojects/GDX/commit/d25314ca6ce7df9dea2d82b7c55ff53c5a5f3284)
  - default project manager
    - `sorting_order` Last modified [`449d8e1`](https://github.com/naiiveprojects/GDX/commit/449d8e18ec01c341b0b65a44eee7782351e18359)
- Github Actions [`3694fc2`](https://github.com/naiiveprojects/GDX/commit/3694fc26b28c787758fd7253d8c9742335307074)
  - Add Manual Trigger
  - Remove Static checks
  - Android: remove arm64v8
  - JavaScript : Compiling `Thread`
  - Linux: Compiling Template & Editor, remove minimal template

## Removed

- `VisualScript` [`d46d00c`](https://github.com/naiiveprojects/GDX/commit/d46d00c6eefb8655ab7ba23d7d882b369814937f)

## Fixed

- `ScriptEditor` Fix Crash When calling `Show In FileSystem`

## Known Issue

- Editor
  - Top Bar Panel container theme doesn't update when changing color in setting ( require restart the editor )
