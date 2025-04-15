# <img src="thirdparty/gdx/icon.svg" width="32"> GDX

[![release](https://badges.ws/github/release/naiiveprojects/gdx?color=green)](https://github.com/naiiveprojects/GDX/releases/latest)
[![GitHub commits since latest release](https://img.shields.io/github/commits-since/naiiveprojects/GDX/latest?style=flat&logo=2c2c2e&label=commit%20since%20release&labelColor=2c2c2e&color=e6653d)](https://github.com/naiiveprojects/GDX/commits/3.x)
[![repo](https://badges.ws/github/repo-size/naiiveprojects/gdx)](https://github.com/naiiveprojects/GDX/pulse/monthly)
[![lang](https://badges.ws/github/lang-size/naiiveprojects/gdx)](https://github.com/naiiveprojects/GDX/pulse/monthly)

GDX is a custom [**Godot Engine 3.x branch**](https://github.com/godotengine/godot/tree/3.x). it aims to incorporate changes, additions, or merged features that may not be merged into the official `3.x` branch.

<img src="thirdparty/gdx/ss_editor.png" width="100%">

> [!NOTE]
> refer to [**this Changelog**](thirdparty/gdx/CHANGELOG.md) for list of changes.

## Binaries

The [Releases](https://github.com/naiiveprojects/GDX/releases/latest) utilize [GitHub Actions](https://github.com/naiiveprojects/GDX/actions) artifacts, with the following flags applied for all builds:

`debug_symbols=no lto=full production=yes optimize=size deprecated=no`.

Additionally, it compiled with the following encryption key:

```hex
FEE1ADDC0FFEEDEC0DEDEFDEADC0DEDECADEDEC0DEC0FFEEC0DEC0FFEEC0FFEE
```

> [!IMPORTANT]
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

To add more platforms/architectures, follow the [compilation guide](https://docs.godotengine.org/en/3.6/development/compiling/index.html).

### Download

- **Precompiled Binaries:** Available on the [Releases](https://github.com/naiiveprojects/GDX/releases/latest) page.
- **Latest Builds:** Check [Artifacts](https://github.com/naiiveprojects/GDX/actions) in GitHub Actions.
- **Manual Compilation:** Get the source code [Here](https://github.com/naiiveprojects/GDX/archive/refs/heads/3.x.zip) then follow this [compilation guide](https://docs.godotengine.org/en/3.6/development/compiling/index.html).

GDX uses **custom templates** for exporting projects.

**Precompiled Binaries** utilize `BUILD_NAME` for versioning using the format YYMMDDHH, e.g., `25033000`.

> [!CAUTION]
> These builds are considered *bleeding-edge*. It is strongly recommended to back up your projects or use version control systems like Git.

## Contributing

We appreciate contributions!

- If you encounter any **bugs** or specific **issues**, please open an [Issue](https://github.com/naiiveprojects/GDX/issues).
- For **questions**, **ideas**, or general **suggestions**, feel free to start a [Discussion](https://github.com/naiiveprojects/GDX/discussions).
- For substantial changes or new features, its recommended to include relevant documentation directly within the PR description.

<img src="thirdparty/gdx/icon.svg" width="32">
