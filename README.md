# Silk CEF

A flattened/patched CEF tree.  Not useful for upstream CEF development.

## Usage

```sh
$ source setup
$ gn gen out/Debug_GN_arm
$ ninja -C out/Debug_GN_arm cefsimple
```

## Updating to a new Chromium version

First modify the `CEF_BRANCH` variable in `./update` to the desired new version,
then run `./update`.

