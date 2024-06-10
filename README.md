# Song Lyric Search Engine

An interactive C++ application where users can search for specific lyrics in a playlist.


## Before You Build

Before you can build the project, here are some prerequisites you need to define yourself.

### CMake
This project uses CMake to build the application. Please make sure CMake is installed on your system before following the steps below.

### `config.json`

One file I have omitted from this repository is `config.json`. This is the file where I define my sensitive API keys. You must define `config.json` at the project root directory with the following keys:

```
// config.json Contents

{
    "GENIUS_CLIENT_ID": "Your Developer Client ID for Genius API"
    "GENIUS_CLIENT_SECRET": "Your Developer Client Secret for Genius API"
    "SPOTIFY_CLIENT_ID": "Your Developer Client ID for Spotify API"
    "SPOTIFY_CLIENT_SECRET": "Your Developer Client Secret for Spotify API"
}
```

### `build/` Directory

I utilize a subdirectory called `build/` to contain CMake's build of my application. This directory is used by my scripts to run the application or tests.

If you do not have a `build/` directory inside the project, you can create one with the following series of commands:

```
$ cd Song-Lyric-Search-Engine  # Go to project root directory

$ mkdir build  # Make a directory called build in the current directory
```
<br>

## How to Build

Here are the steps I use to build the application

```
$ cd Song-Lyric-Search-Engine  # Go to project root directory

$ cmake -S . -B build  # Generate build system files

$ cmake --build build  # Build app inside build/ directory
```

<br>

## How to Run

After building the application, I run the application by doing the following:

```
$ cd Song-Lyric-Search-Engine  # Go to project root directory

$ bash run-app.sh  # Run application script
```
<br>

## Testing
I utilize GoogleTest to write my unit tests for this application. GoogleTest integration with CMake allows me to build both the application and test suites at the same time, which is pretty neat :)

### Running Tests

To run the tests built with the application, run the following commands:

```
$ cd Song-Lyric-Search-Engine  # Go to project root directory

$ bash run-tests.sh  # Run test scripts
```

