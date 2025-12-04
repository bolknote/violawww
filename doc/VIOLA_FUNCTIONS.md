# Viola Functions Reference

This document describes functions available in the Viola language. All functions are defined in the `generic` class and are available from any Viola object.

## Contents

- [Core Functions](#core-functions)
- [HTTP Functions](#http-functions)
- [SGML/HTML Functions](#sgmlhtml-functions)
- [STG Functions](#stg-functions)
- [String Functions](#string-functions)
- [Object Functions](#object-functions)
- [Mathematical Functions](#mathematical-functions)
- [System Functions](#system-functions)
- [Input/Output Functions](#inputoutput-functions)
- [Time Functions](#time-functions)
- [Graphics Functions](#graphics-functions)
- [Drawing Functions](#drawing-functions)
- [Miscellaneous Functions](#miscellaneous-functions)
- [Client/TTY Class Methods](#clienttty-class-methods)

---

## Core Functions

These functions are fundamental to Viola's message-passing object model.

### send(target, message, args...)
Sends a message to another object.

**Parameters:**
- `target` (object/string) - target object or object name
- `message` (string) - message to send
- `args...` (any, optional) - additional arguments

**Returns:** (any) result from the target object's message handler

**Example:**
```c
send(parent(), "redraw");
send("res.font", "useHelveticaMediumFonts");
result = send(self(), "calculate", x, y);
```

---

### usual()
Calls the class script (inherited behavior) for the current message. This is similar to calling the superclass method in traditional OOP.

**Returns:** (any) result from the class script

**Example:**
```c
switch (arg[0]) {
case "init":
    /* custom initialization */
    count = 0;
    usual();  /* call inherited init behavior */
break;
}
```

---

### interpret(code)
Dynamically executes Viola script code.

**Parameters:**
- `code` (string) - Viola script code to execute

**Returns:** (any) result of the executed code

**Example:**
```c
interpret("x = 10; y = 20;");
result = interpret("return " + varName + ";");
```

**Note:** Requires security clearance.

---

### exit(code)
Terminates the application with an exit code.

**Parameters:**
- `code` (int) - exit status code

**Note:** Requires security clearance.

---

### quit()
Gracefully quits the application, decrementing the application count.

**Note:** Typically called via `send("res", "quit")`.

---

### exist(obj)
Checks whether an object exists (is currently loaded).

**Parameters:**
- `obj` (object/string) - object or object name to check

**Returns:** (int) 1 if exists, 0 if not

---

### object(name)
Returns an object reference by name.

**Parameters:**
- `name` (string) - object name

**Returns:** (object) object reference, or NULL if not found

---

### loadObjFile(filename)
Loads objects from a `.v` file.

**Parameters:**
- `filename` (string) - path to the object file

**Returns:** (int) number of objects loaded, -1 on error

---

## HTTP Functions

### HTTPCanonicalURL(url)
Canonicalizes a URL.

**Parameters:**
- `url` (string) - URL to canonicalize

**Returns:** (string) canonicalized URL

---

### HTTPCurrentDocAddr()
Returns the current document address.

**Returns:** (string) document address

---

### HTTPCurrentDocAddrParsed([addr] [, relative])
Parses a document address and returns its components.

**Parameters:**
- `addr` (string, optional) - address to parse
- `relative` (string, optional) - relative address

**Returns:** (list) list with components:
- [0] access scheme
- [1] host
- [2] path (without filename)
- [3] file
- [4] anchor

---

### HTTPCurrentDocAddrSet(addr)
Sets the current document address.

**Parameters:**
- `addr` (string) - new address

**Returns:** (int) 1 on success

---

### HTTPDecodeURL(url)
Decodes a URL.

**Parameters:**
- `url` (string) - encoded URL

**Returns:** (string) decoded URL

---

### HTTPEncodeURL(url)
Encodes a URL.

**Parameters:**
- `url` (string) - URL to encode

**Returns:** (string) encoded URL

---

### HTTPGet(url)
Loads a document from URL and saves it to a temporary file.

**Parameters:**
- `url` (string) - document URL

**Returns:** (string) path to temporary file

**Note:** The user must delete the temporary file after use.

---

### HTTPGetNParse(url, parentForBuiltObjs, width)
Loads and parses an HTML document.

**Parameters:**
- `url` (string) - document URL
- `parentForBuiltObjs` (object) - parent object for created objects
- `width` (int) - width

**Returns:** (object) document object

---

### HTTPPost(url, parentForBuiltObjs, width, postData)
Sends a POST request.

**Parameters:**
- `url` (string) - URL
- `parentForBuiltObjs` (object) - parent object
- `width` (int) - width
- `postData` (string) - data to send

**Returns:** (object) document object

---

### HTTPSubmit(url, parentForBuiltObjs, width, submitData)
Sends a SUBMIT request.

**Parameters:**
- `url` (string) - URL
- `parentForBuiltObjs` (object) - parent object
- `width` (int) - width
- `submitData` (string) - data to send

**Returns:** (object) document object

---

### HTTPHotListAdd(url, comment, date)
Adds an item to the hotlist.

**Parameters:**
- `url` (string) - URL
- `comment` (string) - comment
- `date` (string) - date

**Returns:** (int) 1 on success

---

### HTTPHotListDelete(n)
Deletes the n-th item from the hotlist.

**Parameters:**
- `n` (int) - item number

**Returns:** (int) 1 on success

---

### HTTPHotListChange(type, n, newData)
Changes an item in the hotlist.

**Parameters:**
- `type` (int) - type: 0 for URL, 1 for comment
- `n` (int) - item number
- `newData` (string) - new data

**Returns:** (int) 1 on success

---

### HTTPHotListGet(type, n)
Gets data from the hotlist.

**Parameters:**
- `type` (int) - type: 0 for URL, 1 for comment, 2 for all URLs, 3 for all comments
- `n` (int) - item number (if type is 0 or 1)

**Returns:** (string) data

---

### HTTPHotListLoad()
Loads the hotlist.

**Returns:** (int) 1 on success

---

### HTTPHotListSave()
Saves the hotlist.

**Returns:** (int) 1 on success

---

## SGML/HTML Functions

### SGMLBuildDoc(source, url, parent, name, width, anchor)
Builds an SGML document.

**Parameters:**
- `source` (string) - source text
- `url` (string) - document URL
- `parent` (object) - parent object
- `name` (string) - object name
- `width` (int) - width
- `anchor` (string) - anchor

**Returns:** (object) document object

---

### SGMLBuildDocB(source, url, parent, name, width, anchor)
Builds an SGML document (variant B).

**Parameters:**
- `source` (string) - source text
- `url` (string) - document URL
- `parent` (object) - parent object
- `name` (string) - object name
- `width` (int) - width
- `anchor` (string) - anchor

**Returns:** (object) document object

---

### SGMLBuildDoc_flush()
Flushes the document building buffer.

**Returns:** (int) 1

---

### SGMLBuildDoc_insertObj(obj [, position])
Inserts an object into the document.

**Parameters:**
- `obj` (object) - object to insert
- `position` (int, optional) - insertion position

**Returns:** (int) 1

---

### SGMLBuildDoc_setBuff(bufferID)
Sets the buffer for document building.

**Parameters:**
- `bufferID` (int) - buffer identifier

**Returns:** (int) 1

---

### SGMLBuildDoc_setColors()
Sets document colors from resources.

**Returns:** (int) 1

---

### SGMLBuildDoc_span()
Returns the current span of document building.

**Returns:** (int) span

---

### SGMLFindAnchorOffset(anchorName)
Finds the anchor offset.

**Parameters:**
- `anchorName` (string) - anchor name

**Returns:** (int) vertical offset

---

### SGMLMathFormater(obj1, obj2, mode)
Formats a mathematical expression.

**Parameters:**
- `obj1` (object) - first object
- `obj2` (object) - second object
- `mode` (int) - formatting mode

**Returns:** (int) 1 on success

---

### HTMLMathUpdateWindow()
Updates the mathematical expression window.

**Returns:** (int) 1

---

### SGMLTileDoc(width, height)
Tiles the document in the window.

**Parameters:**
- `width` (int) - width
- `height` (int) - height

**Returns:** (int) vertical span

---

### SGMLReBuildDoc(source, url, parent, name, width, anchor)
Rebuilds an SGML document.

**Parameters:**
- `source` (string) - source text
- `url` (string) - document URL
- `parent` (object) - parent object
- `name` (string) - object name
- `width` (int) - width
- `anchor` (string) - anchor

**Returns:** (object) document object

---

### SGMLGetStyle(dtd, tagName [, attrName])
Gets the style of an SGML tag.

**Parameters:**
- `dtd` (string) - DTD name
- `tagName` (string) - tag name
- `attrName` (string, optional) - attribute name

**Returns:** (string/list) attribute value or list of values

---

### SGMLSetStyle(dtd, tagName, attrName, value)
Sets the style of an SGML tag.

**Parameters:**
- `dtd` (string) - DTD name
- `tagName` (string) - tag name
- `attrName` (string) - attribute name
- `value` (string) - value

**Returns:** (int) 1 on success

---

### SGMLTableFormater(tableObj [, width])
Formats a table.

**Parameters:**
- `tableObj` (object) - table object
- `width` (int, optional) - width

**Returns:** (int) 1 on success

---

## STG Functions

### STGInfo(stgFile, tagName)
Gets information about an STG tag.

**Parameters:**
- `stgFile` (string) - path to STG file
- `tagName` (string) - tag name

**Returns:** (list) tag information

---

### STG_tagPtr(tagName [, superTagName] [, styleAttr])
Gets a pointer to an STG tag.

**Parameters:**
- `tagName` (string) - tag name
- `superTagName` (string, optional) - parent tag name
- `styleAttr` (string, optional) - style attribute

**Returns:** (int) tag pointer

---

### STG_attr(tagPtr, attrName)
Gets an STG tag attribute.

**Parameters:**
- `tagPtr` (int) - tag pointer
- `attrName` (string) - attribute name

**Returns:** (string) attribute value

---

### STG_attrEx(tagPtr, attrName)
Gets an STG tag attribute (extended version).

**Parameters:**
- `tagPtr` (int) - tag pointer (from STG_tagPtr with styleAttr)
- `attrName` (string) - attribute name

**Returns:** (string) attribute value

---

### STG_clean(tagPtr)
Cleans an STG tag.

**Parameters:**
- `tagPtr` (int) - tag pointer

**Returns:** (int) 1

---

## String Functions

### concatenate(arg1, arg2, ...)
Concatenates arguments into a string.

**Parameters:**
- `arg1, arg2, ...` (any) - arguments to concatenate

**Returns:** (string) resulting string

**Alias:** `concat`

---

### concatList(argList)
Concatenates list items into a string.

**Parameters:**
- `argList` (list) - list of items

**Returns:** (string) resulting string

---

### nthChar(str, n [, n2])
Returns the n-th character of a string or substring from n to n2.

**Parameters:**
- `str` (string) - string
- `n` (int) - character position
- `n2` (int, optional) - end position

**Returns:** (char) character or (string) substring

---

### nthWord(str, n1 [, n2])
Returns the n1-th word or words from n1 to n2.

**Parameters:**
- `str` (string) - string
- `n1` (int) - starting word
- `n2` (int, optional) - ending word

**Returns:** (string) word or words

---

### nthLine(str, n1 [, n2])
Returns the n1-th line or lines from n1 to n2.

**Parameters:**
- `str` (string) - string
- `n1` (int) - starting line
- `n2` (int, optional) - ending line

**Returns:** (string) line or lines

---

### strlen(str)
Returns the length of a string.

**Parameters:**
- `str` (string) - string

**Returns:** (int) string length

**Alias:** `countChars`

---

### countLines(str)
Counts the number of lines (number of '\n' characters).

**Parameters:**
- `str` (string) - string

**Returns:** (int) number of lines

---

### countWords(str)
Counts the number of words.

**Parameters:**
- `str` (string) - string

**Returns:** (int) number of words

---

### countItems(str)
Counts the number of comma-separated items.

**Parameters:**
- `str` (string) - string

**Returns:** (int) number of items

---

### replaceChar(originalStr, charToReplace, newChar)
Replaces characters in a string.

**Parameters:**
- `originalStr` (string) - original string
- `charToReplace` (char) - character to replace
- `newChar` (char) - new character

**Returns:** (string) string with replaced characters

---

### replaceCharQ(originalStr, charToReplace, newChar)
Replaces characters in a string (without copying).

**Parameters:**
- `originalStr` (string) - original string
- `charToReplace` (char) - character to replace
- `newChar` (char) - new character

**Returns:** (string) string with replaced characters

---

### replaceStr(originalStr, pattern, patternReplaceStr)
Replaces substrings in a string.

**Parameters:**
- `originalStr` (string) - original string
- `pattern` (string) - pattern to search for
- `patternReplaceStr` (string) - replacement string

**Returns:** (string) string with replaced substrings

---

### replaceStrQ(originalStr, pattern, patternReplaceStr)
Replaces substrings in a string (Q version).

**Parameters:**
- `originalStr` (string) - original string
- `pattern` (string) - pattern to search for
- `patternReplaceStr` (string) - replacement string

**Returns:** (string) string with replaced substrings

---

### deleteSubStr(str, start, end)
Deletes a substring.

**Parameters:**
- `str` (string) - original string
- `start` (int) - start position
- `end` (int) - end position

**Returns:** (string) string without substring

---

### deleteSubStrQ(str, start, end)
Deletes a substring (without copying).

**Parameters:**
- `str` (string) - original string
- `start` (int) - start position
- `end` (int) - end position

**Returns:** (string) string without substring

---

### compressSpaces(str)
Compresses multiple spaces into one.

**Parameters:**
- `str` (string) - original string

**Returns:** (string) string with compressed spaces

---

### trimEdge(str)
Removes spaces from the beginning and end of a string.

**Parameters:**
- `str` (string) - original string

**Returns:** (string) trimmed string

---

### trimEdgeQ(str)
Removes spaces from the beginning and end of a string (without copying).

**Parameters:**
- `str` (string) - original string

**Returns:** (string) trimmed string

---

### findPattern(text, pattern)
Finds the position of the end of a pattern match.

**Parameters:**
- `text` (string) - text to search
- `pattern` (string) - pattern

**Returns:** (int) position of match end, -1 if not found

---

### filter(text)
Converts escape codes into escape characters.

**Parameters:**
- `text` (string) - text with escape codes

**Returns:** (string) text with converted escape characters

---

### isBlank(str)
Checks if a string is empty or contains only spaces.

**Parameters:**
- `str` (string) - string

**Returns:** (int) 1 if empty, 0 if not

---

### str(arg1, arg2, ...)
Converts arguments to a string.

**Parameters:**
- `arg1, arg2, ...` (any) - arguments

**Returns:** (string) string representation

---

## Object Functions

### get(attrName)
Gets the value of an object attribute.

**Parameters:**
- `attrName` (string) - attribute name

**Returns:** (any) attribute value

**Alias:** `geta`

---

### set(attrName, value)
Sets the value of an object attribute.

**Parameters:**
- `attrName` (string) - attribute name
- `value` (any) - value

**Returns:** (int) 1 on success

**Alias:** `seta`

---

### parent()
Returns the parent object.

**Returns:** (object) parent object

---

### nthChild(n)
Returns the n-th child object.

**Parameters:**
- `n` (int) - child object number

**Returns:** (object) child object

---

### nthSibling(n)
Returns the n-th sibling object.

**Parameters:**
- `n` (int) - sibling object number

**Returns:** (object) sibling object

---

### countChildren()
Counts the number of child objects.

**Returns:** (int) number of child objects

---

### self()
Returns the current object.

**Returns:** (object) current object

---

### clone([suffix])
Creates a clone of an object.

**Parameters:**
- `suffix` (string, optional) - suffix for clone name

**Returns:** (object) cloned object

---

### clone2([suffix])
Creates a clone of an object (version 2).

**Parameters:**
- `suffix` (string, optional) - suffix for clone name

**Returns:** (object) cloned object

---

### freeSelf()
Frees an object and its attributes.

**Returns:** (int) 1

---

### objectListAppend(listName, obj)
Appends an object to a named object list.

**Parameters:**
- `listName` (string) - list name
- `obj` (object) - object to append

**Returns:** (object) appended object

---

### objectListAppend_children(obj)
Appends an object to the children list.

**Parameters:**
- `obj` (object) - object to append

**Returns:** (object) appended object

---

### objectListPrepend(listName, obj)
Prepends an object to a named object list.

**Parameters:**
- `listName` (string) - list name
- `obj` (object) - object to prepend

**Returns:** (object) prepended object

---

### objectListPrepend_children(obj)
Prepends an object to the children list.

**Parameters:**
- `obj` (object) - object to prepend

**Returns:** (object) prepended object

---

### objectListDelete(listName, obj)
Deletes an object from a named object list.

**Parameters:**
- `listName` (string) - list name
- `obj` (object) - object to delete

**Returns:** (int) 1 on success

---

### objectListDelete_children(obj)
Deletes an object from the children list.

**Parameters:**
- `obj` (object) - object to delete

**Returns:** (int) 1 on success

---

### objectListCount(listName)
Counts the number of objects in a named list.

**Parameters:**
- `listName` (string) - list name

**Returns:** (int) number of objects, -1 if list not found

---

### objectListCount_children()
Counts the number of child objects.

**Returns:** (int) number of child objects

---

### objectListSend(listName, arg1, arg2, ...)
Sends messages to all objects in a named list.

**Parameters:**
- `listName` (string) - list name
- `arg1, arg2, ...` (any) - message arguments

**Returns:** (int) 1

---

### objectListSend_children(arg1, arg2, ...)
Sends messages to all child objects.

**Parameters:**
- `arg1, arg2, ...` (any) - message arguments

**Returns:** (int) 1

---

### deepObjectListSend(listName, arg1, arg2, ...)
Recursively sends messages to all objects in a list.

**Parameters:**
- `listName` (string) - list name
- `arg1, arg2, ...` (any) - message arguments

**Returns:** (int) 1

---

### objectPosition(obj, listName)
Returns the position of an object in a named list.

**Parameters:**
- `obj` (object) - object
- `listName` (string) - list name

**Returns:** (int) position (starting from 0), -1 if not found

---

### nthObjectInList(listName, n)
Returns the n-th object from a named list.

**Parameters:**
- `listName` (string) - list name
- `n` (int) - object number

**Returns:** (object) object

---

### listAllObjects()
Returns a list of all objects.

**Returns:** (list) list of objects

---

### initialize()
Initializes an object.

**Returns:** (int) 1

---

## Mathematical Functions

### cos(degree)
Calculates the cosine of an angle in degrees.

**Parameters:**
- `degree` (float) - angle in degrees

**Returns:** (float) cosine

---

### sin(degree)
Calculates the sine of an angle in degrees.

**Parameters:**
- `degree` (float) - angle in degrees

**Returns:** (float) sine

---

### random([seed])
Generates a random number.

**Parameters:**
- `seed` (int, optional) - seed value for the generator

**Returns:** (int) random number

---

## System Functions

### system(cmdline1 [, cmdline2, ...])
Executes a system command.

**Parameters:**
- `cmdline1, cmdline2, ...` (string) - commands to execute

**Returns:** (int) return value from system()

---

### pipe(cmdline)
Creates a pipe for command execution.

**Parameters:**
- `cmdline` (string) - command

**Returns:** (int) pipe descriptor

---

### environVar(name)
Gets the value of an environment variable.

**Parameters:**
- `name` (string) - variable name

**Returns:** (string) variable value

---

### violaPath([path])
Gets or sets the Viola file search path.

**Parameters:**
- `path` (string, optional) - new path

**Returns:** (string) current path or (int) 1 when setting

---

### version()
Returns the Viola version string.

**Returns:** (string) version

---

### argument()
Returns the argument string passed via the -ar option.

**Returns:** (string) argument

---

### securityMode([mode])
Gets or sets the security mode.

**Parameters:**
- `mode` (int, optional) - new security mode

**Returns:** (int) current security mode

---

## Input/Output Functions

### print(arg1, arg2, ...)
Prints arguments to standard output.

**Parameters:**
- `arg1, arg2, ...` (any) - arguments to print

**Returns:** (int) 1

**Alias:** `write`

---

### printf(arg1, arg2, ...)
Prints arguments to standard output (formatted).

**Parameters:**
- `arg1, arg2, ...` (any) - arguments to print

**Returns:** (int) 1

---

### writeln(arg1, arg2, ...)
Prints arguments to standard output with newline.

**Parameters:**
- `arg1, arg2, ...` (any) - arguments to print

**Returns:** (int) 1

---

### sprintf(format, arg1, arg2, ...)
Formats a string.

**Parameters:**
- `format` (string) - format
- `arg1, arg2, ...` (any) - arguments

**Returns:** (string) formatted string

---

### scanf(format, arg1, arg2, ...)
Scans input according to a format.

**Parameters:**
- `format` (string) - format
- `arg1, arg2, ...` (any) - arguments

**Returns:** (int) 1

---

### loadFile(fileName)
Loads file contents.

**Parameters:**
- `fileName` (string) - file path

**Returns:** (string) file contents

---

### saveFile(fileName, data)
Saves data to a file.

**Parameters:**
- `fileName` (string) - file path
- `data` (string) - data to save

**Returns:** (int) 1 on success, 0 on error

---

### deleteFile(fileName)
Deletes a file.

**Parameters:**
- `fileName` (string) - file path

**Returns:** (int) 0 on success

---

### makeTempFile([prefix])
Creates a temporary file.

**Parameters:**
- `prefix` (string, optional) - file name prefix

**Returns:** (string) path to temporary file

---

### accessible(filePath)
Checks file accessibility.

**Parameters:**
- `filePath` (string) - file path

**Returns:** (string) full path on success, "" on error

---

### loadSTG(stgFile)
Loads an STG file.

**Parameters:**
- `stgFile` (string) - path to STG file

**Returns:** (int) 1 on success

---

## Time Functions

### time()
Returns the number of seconds since 00:00:00 GMT, January 1, 1970.

**Returns:** (int) number of seconds

---

### date()
Returns a string with the current date and time.

**Returns:** (string) date in format "Sat Feb 16 19:59:04 1991"

---

### delay(seconds)
Delays execution for the specified number of seconds.

**Parameters:**
- `seconds` (int) - number of seconds

**Returns:** (int) number of seconds delayed

---

### sleep(seconds)
Delays execution for the specified number of seconds.

**Parameters:**
- `seconds` (int) - number of seconds

**Returns:** (int) number of seconds delayed

---

### alarm([seconds])
Sets an alarm.

**Parameters:**
- `seconds` (int, optional) - number of seconds

**Returns:** (int) 1

---

### after(milliseconds, object, [message1, message2, ...])
Schedules sending messages to an object after a specified time.

**Parameters:**
- `milliseconds` (int) - time in milliseconds
- `object` (object) - target object
- `message1, message2, ...` (any, optional) - messages

**Returns:** (int) 1 on success

---

## Graphics Functions

### x()
Returns the x-coordinate of an object.

**Returns:** (int) x-coordinate

---

### y()
Returns the y-coordinate of an object.

**Returns:** (int) y-coordinate

---

### width()
Returns the width of an object.

**Returns:** (int) width

---

### height()
Returns the height of an object.

**Returns:** (int) height

---

### textWidth(fontID, text)
Calculates text width.

**Parameters:**
- `fontID` (int) - font identifier
- `text` (string) - text

**Returns:** (int) text width in pixels

---

### charHeight(fontID)
Returns the maximum height of a font.

**Parameters:**
- `fontID` (int) - font identifier (0=fixed, 1=normal, 2=bold, etc.)

**Returns:** (int) font height in pixels

**Example:**
```c
/* Center text vertically in a button */
labelH = charHeight(1);
textY = buttonY + ((buttonH - labelH) / 2);
```

**See also:** `textWidth`

---

### cursorShape([shape])
Changes the cursor shape.

**Parameters:**
- `shape` (string, optional) - shape: "busy" or "idle"

**Returns:** (string) current cursor shape

---

### setMouse(x, y)
Sets the mouse position.

**Parameters:**
- `x` (int) - x-coordinate
- `y` (int) - y-coordinate

**Returns:** (int) 1

---

### getSelection()
Gets the selected text.

**Returns:** (string) selected text

---

### setSelection(text)
Sets the selected text.

**Parameters:**
- `text` (string) - text to select

**Returns:** (int) 1

---

### selectionInfo()
Returns selection information.

**Returns:** (list) selection information, [0] - object

---

### bell()
Sounds a bell.

**Returns:** (int) 1

---

### bellVolume([volume])
Gets or sets the bell volume.

**Parameters:**
- `volume` (int, optional) - volume from 0 to 100

**Returns:** (int) current volume

---

### clear()
Clears the window.

**Returns:** (int) 1

---

### clearWindow()
Clears the object window.

**Returns:** (int) 1

**Note:** Available in `field` class and subclasses.

---

## Drawing Functions

These functions are available in the `field` class and its subclasses for custom drawing.

### drawLine(x0, y0, x1, y1)
Draws a line from (x0, y0) to (x1, y1).

**Parameters:**
- `x0` (int) - starting x-coordinate
- `y0` (int) - starting y-coordinate
- `x1` (int) - ending x-coordinate
- `y1` (int) - ending y-coordinate

**Returns:** (int) 1 on success, 0 on failure

---

### drawRect(x0, y0, x1, y1)
Draws a rectangle outline.

**Parameters:**
- `x0` (int) - left x-coordinate
- `y0` (int) - top y-coordinate
- `x1` (int) - right x-coordinate
- `y1` (int) - bottom y-coordinate

**Returns:** (int) 1 on success

---

### drawFillRect(x0, y0, x1, y1)
Draws a filled rectangle.

**Parameters:**
- `x0` (int) - left x-coordinate
- `y0` (int) - top y-coordinate
- `x1` (int) - right x-coordinate
- `y1` (int) - bottom y-coordinate

**Returns:** (int) 1 on success

---

### drawOval(x0, y0, x1, y1)
Draws an oval outline within the bounding box.

**Parameters:**
- `x0` (int) - left x-coordinate
- `y0` (int) - top y-coordinate
- `x1` (int) - right x-coordinate
- `y1` (int) - bottom y-coordinate

**Returns:** (int) 1 on success

---

### drawFillOval(x0, y0, x1, y1)
Draws a filled oval within the bounding box.

**Parameters:**
- `x0` (int) - left x-coordinate
- `y0` (int) - top y-coordinate
- `x1` (int) - right x-coordinate
- `y1` (int) - bottom y-coordinate

**Returns:** (int) 1 on success

---

### drawFillPolygon(x0, y0, x1, y1, x2, y2, x3, y3)
Draws a filled quadrilateral (4-point polygon). Useful for drawing rotated rectangles.

**Parameters:**
- `x0` (int) - first point x-coordinate
- `y0` (int) - first point y-coordinate
- `x1` (int) - second point x-coordinate
- `y1` (int) - second point y-coordinate
- `x2` (int) - third point x-coordinate
- `y2` (int) - third point y-coordinate
- `x3` (int) - fourth point x-coordinate
- `y3` (int) - fourth point y-coordinate

**Returns:** (int) 1 on success

**Example:**
```c
/* Draw a rotated rectangle */
drawFillPolygon(cx[0], cy[0], cx[1], cy[1], cx[2], cy[2], cx[3], cy[3]);
```

---

### drawText(x, y, fontID, text)
Draws text at the specified position.

**Parameters:**
- `x` (int) - x-coordinate
- `y` (int) - y-coordinate
- `fontID` (int) - font identifier
- `text` (string) - text to draw

**Returns:** (int) 1 on success

---

### clearArea(x0, y0, x1, y1)
Clears a rectangular area (fills with background color).

**Parameters:**
- `x0` (int) - left x-coordinate
- `y0` (int) - top y-coordinate
- `x1` (int) - right x-coordinate
- `y1` (int) - bottom y-coordinate

**Returns:** (int) 1 on success

---

### copyArea(srcX, srcY, width, height, destX, destY)
Copies a rectangular area to another location.

**Parameters:**
- `srcX` (int) - source x-coordinate
- `srcY` (int) - source y-coordinate
- `width` (int) - width to copy
- `height` (int) - height to copy
- `destX` (int) - destination x-coordinate
- `destY` (int) - destination y-coordinate

**Returns:** (int) 1 on success

---

### mouseX()
Returns the current mouse x-coordinate within the widget.

**Returns:** (int) x-coordinate

---

### mouseY()
Returns the current mouse y-coordinate within the widget.

**Returns:** (int) y-coordinate

---

### eraseFillRect(x0, y0, x1, y1)
Erases a filled rectangle (fills with background color).

**Parameters:**
- `x0` (int) - left x-coordinate
- `y0` (int) - top y-coordinate
- `x1` (int) - right x-coordinate
- `y1` (int) - bottom y-coordinate

**Returns:** (int) 1 on success

---

### eraseFillOval(x0, y0, x1, y1)
Erases a filled oval (fills with background color).

**Parameters:**
- `x0` (int) - left x-coordinate
- `y0` (int) - top y-coordinate
- `x1` (int) - right x-coordinate
- `y1` (int) - bottom y-coordinate

**Returns:** (int) 1 on success

---

### render()
Forces the widget to re-render itself.

**Returns:** (int) 1

---

### smudge()
Marks the widget as needing redraw.

**Returns:** (int) 1

---

## Miscellaneous Functions

### int(value)
Converts a value to an integer.

**Parameters:**
- `value` (any) - value

**Returns:** (int) integer

---

### float(value)
Converts a value to a floating point number.

**Parameters:**
- `value` (any) - value

**Returns:** (float) floating point number

---

### char(value)
Converts a value to a character.

**Parameters:**
- `value` (any) - value

**Returns:** (char) character

---

### ascii(code)
Converts an ASCII code to a character.

**Parameters:**
- `code` (int) - ASCII code

**Returns:** (char) character

---

### asciiVal(char)
Converts a character to an ASCII code.

**Parameters:**
- `char` (char) - character

**Returns:** (int) ASCII code

---

### not(value)
Logical negation.

**Parameters:**
- `value` (any) - value

**Returns:** (int) 1 if false, 0 if true

---

### key()
Returns the last pressed key.

**Returns:** (char) key character

---

### ctrlKeyP()
Checks if the Control key is pressed.

**Returns:** (int) 1 if pressed, 0 if not

---

### shiftKeyP()
Checks if the Shift key is pressed.

**Returns:** (int) 1 if pressed, 0 if not

---

### getVariable(name)
Gets the value of an object variable.

**Parameters:**
- `name` (string) - variable name

**Returns:** (any) variable value

---

### setVariable(name, value)
Sets the value of an object variable.

**Parameters:**
- `name` (string) - variable name
- `value` (any) - value

**Returns:** (int) 1 on success

---

### destroyVariable(name)
Deletes an object variable.

**Parameters:**
- `name` (string) - variable name

**Returns:** (int) 1

---

### getResource(name)
Gets the value of a resource.

**Parameters:**
- `name` (string) - resource name

**Returns:** (string) resource value

---

### setResource(name, value)
Sets the value of a resource.

**Parameters:**
- `name` (string) - resource name
- `value` (string) - value

**Returns:** (int) 1 on success

---

### target([objName])
Gets or sets the target object.

**Parameters:**
- `objName` (string, optional) - target object name

**Returns:** (object) target object

---

### tool([toolName])
Gets or sets the current tool.

**Parameters:**
- `toolName` (string, optional) - tool name: "action", "move", "reparent", "resize", "target"

**Returns:** (string) current tool name

---

### hash(str)
Converts a string to a hash (token).

**Parameters:**
- `str` (string) - string

**Returns:** (token) hash

---

### unhash(token)
Converts a hash back to a string.

**Parameters:**
- `token` (int) - hash

**Returns:** (string) string

---

### prepend(list, id, value)
Prepends an item to a list.

**Parameters:**
- `list` (list) - list
- `id` (int) - identifier
- `value` (any) - value

**Returns:** (int) 1

---

### append(list, id, value)
Appends an item to a list.

**Parameters:**
- `list` (list) - list
- `id` (int) - identifier
- `value` (any) - value

**Returns:** (int) 1

---

### item(str, n1 [, n2])
Extracts item(s) from a comma-separated string.

**Parameters:**
- `str` (string) - string
- `n1` (int) - starting item
- `n2` (int, optional) - ending item

**Returns:** (string) item(s)

---

### nthItem(str, n)
Returns the n-th item from a string.

**Parameters:**
- `str` (string) - string
- `n` (int) - item number

**Returns:** (string) item

---

### format(text, style [, styleInfo])
Formats text.

**Parameters:**
- `text` (string) - text
- `style` (string) - style
- `styleInfo` (any, optional) - style information

**Returns:** (string) formatted text

---

### defineNewFont(fontID, fontName, XFontName)
Defines a new font.

**Parameters:**
- `fontID` (int) - font identifier
- `fontName` (string) - font name
- `XFontName` (string) - X font name

**Returns:** (int) 1 on success

---

### depth()
Returns the depth of an object.

**Returns:** (int) depth

---

### gravity()
Returns the gravity of an object.

**Returns:** (int) gravity

---

### cli()
Starts the Viola interpreter command line interface.

**Returns:** (int) 1

---

### sendToInterface(arg1, arg2, ...)
Sends a message to the program interface.

**Parameters:**
- `arg1, arg2, ...` (any) - message arguments

**Returns:** (int) 1

---

### isURLVisited(url)
Checks if a URL has been visited (is in the browsing history).

This function is used internally for `traversedForegroundColor` support in STG stylesheets, but can also be called directly from Viola scripts.

**Parameters:**
- `url` (string) - the URL to check

**Returns:** (int) 1 if visited, 0 if not visited

**Example:**
```
if (isURLVisited("http://www.example.com/page.html")) {
    /* User has visited this page before */
    set("FGColor", "purple");
} else {
    /* Unvisited link */
    set("FGColor", "blue");
}
```

**Note:** In standalone Viola (without the VW Motif interface), this function checks `~/.viola_history` for visited URLs. Use `addURLToHistory()` to add URLs to the persistent history.

**See also:** `addURLToHistory`, `traversedForegroundColor` in STG_REFERENCE.md

---

### setLinkColor(colorname)
Sets the color for unvisited links.

This function is typically called automatically when processing STG stylesheets with `FGColor` attribute on `A` tags. It can also be called directly from Viola scripts.

**Parameters:**
- `colorname` (string) - X11 color name (e.g., "red", "blue", "navy")

**Returns:** (int) 1 on success, 0 on failure

**Example:**
```
setLinkColor("red");  /* Unvisited links will be red */
```

**See also:** `setLinkVisitedColor`, `resetLinkColors`, `FGColor` in STG_REFERENCE.md

---

### setLinkVisitedColor(colorname)
Sets the color for visited links.

This function is typically called automatically when processing STG stylesheets with `traversedForegroundColor` attribute on `A` tags. It can also be called directly from Viola scripts.

**Parameters:**
- `colorname` (string) - X11 color name (e.g., "purple", "blue", "maroon")

**Returns:** (int) 1 on success, 0 on failure

**Example:**
```
setLinkVisitedColor("purple");  /* Visited links will be purple */
```

**See also:** `setLinkColor`, `resetLinkColors`, `traversedForegroundColor` in STG_REFERENCE.md

---

### resetLinkColors()
Resets link colors to the default (black).

This function is called automatically when loading a new STG stylesheet to ensure that link colors are reset before applying new styles. Without this, colors from a previous stylesheet would persist.

**Parameters:** None

**Returns:** (int) 1

**Example:**
```
resetLinkColors();  /* Both visited and unvisited links are now black */
setLinkColor("blue");  /* Now unvisited links are blue, visited remain black */
```

**See also:** `setLinkColor`, `setLinkVisitedColor`

---

### addURLToHistory(url)
Adds a URL to the browsing history.

In VW mode (with the Motif GUI), this is a no-op because history is managed through the VW message handler system. In standalone viola, this persists the URL to `~/.viola_history` file, enabling visited link detection across sessions.

**Parameters:**
- `url` (string) - the URL to add to history

**Returns:** (int) 1 on success, 0 on failure

**Example:**
```
addURLToHistory("http://www.example.com/page.html");
```

**Note:** In standalone viola, URLs are stored in `~/.viola_history` (one URL per line, max 4096 entries). This enables `isURLVisited()` to detect previously visited links.

**See also:** `isURLVisited`

---

### activeHelp([message])
Displays a message in the active help field.

**Parameters:**
- `message` (string, optional) - message

**Returns:** (int) 1

---

### accessible(filePath)
Checks file accessibility.

**Parameters:**
- `filePath` (string) - file path

**Returns:** (string) full path on success, "" on error

---

### addPicFromFile(obj, filePath)
Adds an image from a file.

**Parameters:**
- `obj` (object) - object
- `filePath` (string) - image file path

**Returns:** (int) image identifier

---

### watch(flag)
Sets variable tracking flags.

**Parameters:**
- `flag` (int) - flag

**Returns:** (int) 1

---

## Special HTML Functions

### code_HTML_txt(...)
Internal function for HTML text processing.

---

### code_HTML_txtAnchor(...)
Internal function for HTML anchor processing.

---

### code_HTML_header_large(...)
Internal function for large HTML header processing.

---

### code_HTML_header_medium(...)
Internal function for medium HTML header processing.

---

### code_HTML_header_small(...)
Internal function for small HTML header processing.

---

## Client/TTY Class Methods

The `client` class (and its subclass `TTY`) provides methods for inter-process communication via pseudo-terminals.

### Class Hierarchy

```
field → client → TTY
```

### Client Class Attributes

| Attribute | Type | Description |
|-----------|------|-------------|
| `inDelimStr1` | string | First input delimiter string |
| `inDelimStr2` | string | Second input delimiter string |
| `outDelimStr` | string | Output delimiter string |
| `clientFD` | int | Client file descriptor |

### TTY Class Attributes

| Attribute | Type | Description |
|-----------|------|-------------|
| `path` | string | Path to executable file |
| `args` | string | Command line arguments |
| `pid` | int | Process ID of the running client |

---

### startClient()
Starts the client process. For TTY class, this forks a new process and connects it via pseudo-terminal.

**Returns:** (int) file descriptor on success, -1 on error

**Note:** The `path` attribute must be set before calling this method.

---

### endClient()
Terminates the client process.

**Returns:** (int) 1 on success

---

### initialize()
Initializes the client object.

**Returns:** (int) 1

---

### input([timeout])
Reads input from the client process. Blocks until data is available or delimiter is matched.

**Parameters:**
- `timeout` (int, optional) - timeout in some units (0 = no timeout)

**Returns:** (string) data received from client

---

### inputn(n)
Reads exactly n bytes from the client process.

**Parameters:**
- `n` (int) - number of bytes to read

**Returns:** (string) data received

---

### output(data)
Sends data to the client process. The `outDelimStr` is automatically appended.

**Parameters:**
- `data` (string) - data to send

**Returns:** (int) 1 on success

---

### Example Usage

```c
\class {TTY}
\name {myProcess}
\script {
    switch (arg[0]) {
    case "init":
        usual();
        set("path", "/usr/bin/myprogram");
        set("args", "-v -o output.txt");
        set("inDelimStr1", "\n");
        set("outDelimStr", "\n");
        startClient();
        return;
    break;
    case "sendCommand":
        output(arg[1]);
        return;
    break;
    case "input":
        data = input(0);
        print("Received: ", data, "\n");
        return;
    break;
    }
    usual();
}
```

---

## Notes

- Functions with suffix `Q` (e.g., `replaceCharQ`, `trimEdgeQ`) work without copying data and may modify original strings.
- Functions that work with files may require security checks (`notSecure`).
- Some functions are marked as "NOT IMPLEMENTED" in the source code.
- Function aliases: `concat` for `concatenate`, `write` for `print`, `countChars` for `strlen`, `geta` for `get`, `seta` for `set`.
