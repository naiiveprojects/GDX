# GDX

GDX is a custom [**Godot Engine 3.x branch**](https://github.com/godotengine/godot/tree/3.x). For detailed changes, refer to the [**changelog**](thirdparty/gdx/CHANGELOG.md). This fork continuously tracks the latest development of the 3.x branch.

<center>
<img src="thirdparty/gdx/ss_editor.png" width="100%">  
<img src="thirdparty/gdx/ss_pm.png" width="100%">  
</center>

## Binaries

The [releases](https://github.com/naiiveprojects/GDX/releases/latest) utilize [Github Actions](https://github.com/naiiveprojects/GDX/actions) artifacts, with the following flags applied for all builds: `debug_symbols=no lto=full production=yes optimize=size deprecated=no`

Additionally, builds compiled with the following encryption key:

```hex
FEE1ADDC0FFEEDEC0DEDEFDEADC0DEDECADEDEC0DEC0FFEEC0DEC0FFEEC0FFEE
```
> [!NOTE]
> This encryption key is publicly accessible. If you prefer to use a more secure key for encryption, refer to the [compiling with script encryption key](https://docs.godotengine.org/en/3.6/development/compiling/compiling_with_script_encryption_key.html).

To minimize compilation time and binary size, builds are provided only for the following architectures:

| Platform  | Editor  | Template  |
|-----------|---------|-----------|
| Android   | armv7   | armv7     |
| iOS       | -       | arm64v8   |
| Linux     | x64     | x64       |
| macOS     | universal (x64, arm64) | universal |
| Windows   | x64     | x64       |
| Web       | -       | Default, Threads |
| Server    | Linux Headless x64 | Linux Server x64 |

To add more platform / architectures, follow the [Godot Engine compilation guide](https://docs.godotengine.org/en/3.6/development/compiling/index.html).

### Download

- **Precompiled Binaries:** Available on the [Releases](https://github.com/naiiveprojects/GDX/releases/latest) page.  
- **Latest Builds:** Check [Artifacts](https://github.com/naiiveprojects/GDX/actions) in GitHub Actions.
- **Manual Compilation:** download this repository and Follow the [Godot Engine compilation guide](https://docs.godotengine.org/en/3.6/development/compiling/index.html). 

> [!CAUTION]
> These builds are considered bleeding-edge. It is strongly recommended to back up your projects or use version control systems like Git.


GDX use **custom templates** for exporting the projects.

precompiled Binaries utilize `BUILD_NAME` for versioning using format YYMMDDHH, ex: `25033000`.

---  

<p align="center">  
    <img src="thirdparty/gdx/project_icon.svg" width="32">  
</p>
