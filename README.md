## mruby-platform
A small mruby gem to check what platform you've compiled for.

```Ruby
conf.gem :github => 'captainjet/mruby-platform', :branch => 'main'
```

## Usage

```Ruby
Platform.get_symbol #=> :windows_32, :windows_64, :ios, :macos, :apple, :android, :web, :linux, :unix, :posix, :unknown

# Convenience checkers for all platforms and generalizations:
Platform.windows? #=> true if :windows_32 or :windows_64
Platform.mobile? #=> true if :android or :ios
Platform.apple? #=> true if :ios, :macos, :apple

# And ones for individual symbols equivalent to get_symbol return values.
Platform.mac?
Platform.ios?
Platform.web? #=> Note: Only works when compiling with Emscripten.
Platform.android?
Platform.linux?
Platform.unix?
Platform.posix?
Platform.unknown?

PlatformError # Defined for user functions when calling a platform specific function on the wrong platform.
```

## License

MIT