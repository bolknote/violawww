# Sound Reference

> **ViolaWWW 4.0 Additions:**  
> - macOS Audio Queue Services implementation for `bell()` function (pure C, no ObjC)
> - Audio file playback using `afplay` on macOS

This document describes sound capabilities in ViolaWWW.

## Contents

- [Viola Script Functions](#viola-script-functions)
- [Playing Audio Files in HTML](#playing-audio-files-in-html)
- [Supported Audio Formats](#supported-audio-formats)

---

## Viola Script Functions

### bell()

Plays a system alert sound.

**Returns:** (int) 1

**Example:**
```c
bell();
```

**macOS Implementation:** Uses Audio Queue Services (AudioToolbox framework) to play the system sound "Tink.aiff". This is a pure C implementation without Objective-C dependencies. Supports volume control via `bellVolume()`.

**Other platforms:** Falls back to X11 `XBell()`.

---

### bellVolume([percent])

Gets or sets the bell volume.

**Parameters:**
- `percent` (int, optional) - volume from 0 to 100

**Returns:** (int) current volume

**Example:**
```c
bellVolume(50);   /* Set volume to 50% */
bell();           /* Play at 50% volume */

vol = bellVolume();  /* Get current volume */
```

---

## Playing Audio Files in HTML

### Method 1: Hyperlink

Create a hyperlink to an audio file. When clicked, the browser downloads and plays the file:

```html
<A HREF="sound.au">Play sound</A>
```

### Method 2: Auto-play with INSERT

Use the `<INSERT>` tag to automatically play a sound when the page loads:

```html
<INSERT HREF="sound.au"></INSERT>
```

### Method 3: Looping with AFTER

Add the `AFTER` attribute to repeat playback at a specified interval (in milliseconds):

```html
<INSERT HREF="sound.au" AFTER="1000"></INSERT>
```

This plays `sound.au` immediately, then repeats every 1000ms (1 second).

**Note:** The `AFTER` interval is measured from the start of each playback, not from when the previous playback ends.

---

## Supported Audio Formats

On macOS, audio playback uses the built-in `afplay` utility, which supports all formats handled by Core Audio:

| Format | Extensions | Description |
|--------|------------|-------------|
| AIFF | `.aiff`, `.aif` | Audio Interchange File Format |
| AIFC | `.aifc`, `.aiff`, `.aif` | AIFF Compressed |
| WAV | `.wav` | Waveform Audio |
| MP3 | `.mp3` | MPEG Layer 3 |
| AAC | `.aac`, `.m4a` | Advanced Audio Coding |
| ALAC | `.m4a` | Apple Lossless |
| FLAC | `.flac` | Free Lossless Audio Codec |
| CAF | `.caf` | Core Audio Format |
| AU | `.au` | Sun/NeXT audio |
| AC3 | `.ac3` | Dolby Digital |
| 3GP | `.3gp`, `.3gpp` | 3GPP audio |
| AMR | `.amr` | Adaptive Multi-Rate |

**Note:** While ViolaWWW historically recognized `.au` files by extension, the `afplay` backend can play any format listed above. The browser uses format detection based on file extension, so `.au` is the most reliably supported extension for embedded audio.

### Testing Audio Playback

To verify `afplay` works on your system:

```bash
afplay /System/Library/Sounds/Tink.aiff
```

To check supported formats:

```bash
afconvert -hf
```

---

## Examples

### Simple Bell Button

Create a file `bell_button.v`:

```
\class {txtButton}
\name {bell_button}
\label {Ring Bell!}
\width {120}
\height {30}
\script {
  switch (arg[0]) {
  case "buttonRelease":
    bell();
  break;
  case "init":
    usual();
  break;
  }
  usual();
}
\
```

Then embed it in HTML using `<VOBJF>`:

```html
<html>
<body>
<p>Click the button:</p>
<VOBJF HREF="bell_button.v"></VOBJF>
</body>
</html>
```

### Volume Control Example

Create a file `volume_button.v`:

```
\class {txtButton}
\name {volume_button}
\label {Click Me!}
\width {150}
\height {30}
\script {
  switch (arg[0]) {
  case "buttonRelease":
    count = count + 10;
    if (count > 100) count = 10;
    set("label", concat("Volume: ", count, "%"));
    bellVolume(count);
    bell();
    render();
  break;
  case "init":
    count = 0;
    usual();
  break;
  }
  usual();
}
\
```

Each click increases volume by 10% and plays the bell.

### HTML Page with Background Sound

```html
<html>
<head><title>Welcome</title></head>
<body>
<h1>Welcome!</h1>

<!-- Play welcome sound once on page load -->
<INSERT HREF="welcome.au"></INSERT>

<p>Click below to play again:</p>
<a href="welcome.au">Play welcome sound</a>

</body>
</html>
```

### Looping Background Music

```html
<html>
<head><title>Game</title></head>
<body>

<!-- Loop background music every 30 seconds -->
<INSERT HREF="music.au" AFTER="30000"></INSERT>

<h1>Game Page</h1>

</body>
</html>
```

---

## Technical Notes

1. **macOS Sound Implementation:** The `bell()` function uses Audio Queue Services from AudioToolbox framework, providing reliable audio playback without depending on X11 or Objective-C runtime.

2. **File Playback:** Audio files are first downloaded via HTTP to a temporary file, then played using `afplay` in the background.

3. **Limitations:**
   - `sleep()` and `delay()` only accept whole seconds, making precise rhythm timing difficult in Viola scripts
   - The `AFTER` attribute uses milliseconds for more precise timing
   - Audio playback is asynchronous - the script continues while sound plays

