# How to Run External Programs from Viola

> **Added in: ViolaWWW 4.0**  
> The TTY class existed in the original ViolaWWW but was non-functional. It was restored to working condition in version 4.0 (2025).

This guide shows how to write a Viola application that launches an external program and communicates with it via a pseudo-terminal.

## What We'll Build

We'll create a simple application that:
1. Launches an external program (e.g., `cat`, `bc`, or your own binary)
2. Sends commands to it
3. Receives and displays responses

## Step 1: Application Structure

A typical TTY application consists of several objects:

```
\class {vpane}
\name {myApp}
\children {myApp.tty myApp.output myApp.input}
\width {500}
\height {400}
\
```

- `myApp` — main container (vpane arranges children vertically)
- `myApp.tty` — TTY class object, manages the external process
- `myApp.output` — field to display program output
- `myApp.input` — input field for commands

## Step 2: Create the TTY Object

The TTY object is a "bridge" between Viola and the external program:

```
\class {TTY}
\name {myApp.tty}
\parent {myApp}
\height {1}
\maxHeight {1}
\script {
    switch (arg[0]) {
    case "init":
        usual();
        
        /* 1. Set the path to the program */
        set("path", "/bin/cat");
        
        /* 2. Configure delimiters */
        set("inDelimStr1", "\n");    /* read until newline */
        set("outDelimStr", "\n");    /* append newline to output */
        
        /* 3. Start it! */
        startClient();
        
        print("Process started, PID: ", get("pid"), "\n");
        return;
    break;
    }
    usual();
}
\
```

**Important:** Set `height` and `maxHeight` to 1 because the TTY object is invisible — it only manages the process.

## Step 3: Send Data to the Program

Add a `send` command handler:

```
\script {
    switch (arg[0]) {
    case "init":
        /* ... initialization ... */
    break;
    
    case "send":
        /* Send data to external program */
        output(arg[1]);
        return;
    break;
    }
    usual();
}
```

The `output()` function sends a string and automatically appends `outDelimStr` at the end.

## Step 4: Receive Data from the Program

When the program outputs something, Viola calls the `input` handler:

```
    case "input":
        /* Read data from program */
        data = input(0);    /* 0 = wait without timeout */
        
        print("Received: ", data, "\n");
        
        /* Send to output field */
        send(nthSibling(1), "show", data);
        return;
    break;
```

## Step 5: Output Field

A simple text field to display responses:

```
\class {txtDisp}
\name {myApp.output}
\parent {myApp}
\content {}
\script {
    switch (arg[0]) {
    case "show":
        /* Append text to content */
        oldContent = get("content");
        set("content", concat(oldContent, arg[1], "\n"));
        return;
    break;
    }
    usual();
}
\
```

## Step 6: Input Field

A field where the user enters commands:

```
\class {txtEdit}
\name {myApp.input}
\parent {myApp}
\maxHeight {24}
\script {
    switch (arg[0]) {
    case "keyPress":
        c = key();
        if (c == '\r') {
            /* Enter pressed — send command */
            cmd = currentLine();
            
            /* Find TTY and send to it */
            ttyObj = nthSibling(-2);   /* TTY is 2 positions earlier */
            send(ttyObj, "send", cmd);
            
            /* Move to new line */
            insert('\n');
        } else {
            insert(c);
        }
        return;
    break;
    }
    usual();
}
\
```

## Complete Example: bc Calculator

Here's a complete working example — an interface to `bc` (calculator):

```
\class {vpane}
\name {calc}
\children {calc.tty calc.title calc.output calc.input}
\width {400}
\height {300}
\
\class {txtLabel}
\name {calc.title}
\parent {calc}
\label {Calculator (bc)}
\maxHeight {20}
\
\class {TTY}
\name {calc.tty}
\parent {calc}
\height {1}
\maxHeight {1}
\script {
    switch (arg[0]) {
    case "init":
        usual();
        set("path", "/usr/bin/bc");
        set("args", "-q");              /* quiet mode, no banner */
        set("inDelimStr1", "\n");
        set("outDelimStr", "\n");
        startClient();
        return;
    break;
    case "send":
        output(arg[1]);
        return;
    break;
    case "input":
        data = input(0);
        send(nthSibling(2), "show", data);
        return;
    break;
    case "freeSelf":
        endClient();
        return usual();
    break;
    }
    usual();
}
\
\class {txtDisp}
\name {calc.output}
\parent {calc}
\content {}
\script {
    switch (arg[0]) {
    case "show":
        old = get("content");
        set("content", concat(old, "= ", arg[1], "\n"));
        return;
    break;
    }
    usual();
}
\
\class {txtEdit}
\name {calc.input}
\parent {calc}
\maxHeight {24}
\script {
    switch (arg[0]) {
    case "keyPress":
        c = key();
        if (c == '\r') {
            cmd = currentLine();
            
            /* Show what was entered */
            send(nthSibling(-1), "show", concat("> ", cmd));
            
            /* Send to bc */
            send(nthSibling(-2), "send", cmd);
            
            insert('\n');
        } else {
            insert(c);
        }
        return;
    break;
    }
    usual();
}
\
```

Save as `calc.v` and run:
```bash
viola calc.v
```

Now you can enter expressions: `2+2`, `3*4`, `scale=2; 10/3`, etc.

## Example with Environment Variable

If the program path depends on the environment:

```
case "init":
    usual();
    
    /* Get path from environment variable */
    myPath = environVar("MY_PROGRAM_PATH");
    
    if (isBlank(myPath) == 1) {
        print("Error: set MY_PROGRAM_PATH\n");
        return;
    }
    
    set("path", concat(myPath, "/myprogram"));
    set("inDelimStr1", "\n");
    set("outDelimStr", "\n");
    startClient();
    return;
break;
```

## Example with Command-Line Arguments

Pass arguments via the `args` attribute:

```
case "init":
    usual();
    set("path", "/usr/bin/python3");
    set("args", "-u -i");    /* -u unbuffered, -i interactive */
    set("inDelimStr1", "\n");
    set("outDelimStr", "\n");
    startClient();
    return;
break;
```

## What Are Delimiters

Delimiters define how Viola knows when a message has ended:

- **`outDelimStr`** — appended to the end of each `output()` call. Usually `"\n"`.

- **`inDelimStr1`** — `input()` reads data until it encounters this delimiter. Usually `"\n"`.

- **`inDelimStr2`** — alternative delimiter (if the program can respond differently).

**Example:** if the program responds with lines ending in `\n`:
```
set("inDelimStr1", "\n");
```

If the program can respond with both `\n` and `\r`:
```
set("inDelimStr1", "\n");
set("inDelimStr2", "\r");
```

## Handling Cleanup

Don't forget to close the process when the object is destroyed:

```
case "freeSelf":
    endClient();       /* terminate child process */
    return usual();    /* call standard handler */
break;
```

## TTY Attributes

| Attribute | Type | Description |
|-----------|------|-------------|
| `path` | string | Path to executable (required) |
| `args` | string | Command-line arguments |
| `pid` | int | PID of running process (read-only) |
| `inDelimStr1` | string | Input data delimiter |
| `inDelimStr2` | string | Alternative delimiter |
| `outDelimStr` | string | Output data delimiter |

## TTY Methods

| Method | Description |
|--------|-------------|
| `startClient()` | Starts the program |
| `endClient()` | Terminates the program |
| `output(str)` | Sends a string to the program |
| `input(timeout)` | Reads response (0 = wait forever) |

## See Also

- `examples/plot.v` — working example with vplot program
- [VIOLA_FUNCTIONS.md](VIOLA_FUNCTIONS.md) — Viola function reference
- [VIOLA_LANGUAGE.md](VIOLA_LANGUAGE.md) — Viola language syntax
