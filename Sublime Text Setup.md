# Setting up C++ in Sublime Text for Competitive Programming

I use and recommend Sublime Text over other editors/IDEs because it is light weight and fast. IDEs in general are heavy and slow. Sublime also has many shortcuts and features to explore.

### MinGW (GNU C/C++ compiler collection for Windows 64-bit)
* Download [MinGW](https://sourceforge.net/projects/mingw/). You may refer to [this](https://www.youtube.com/watch?v=sXW2VLrQ3Bs) video for instructions on installation.
* Add the bin directory to system PATH, as described [here](https://stackoverflow.com/questions/5733220/how-do-i-add-the-mingw-bin-directory-to-my-system-path).

Ensure that you have g++ installed. Execute `𝚐++ --𝚟𝚎𝚛𝚜𝚒𝚘𝚗` from the command prompt or terminal. If version information of the compiler is displayed, it was successful and you can continue with the next section.

If you get an error such as `g++ not found`, then something went wrong. In this case, verify that the PATH variable was successfully set and directs to the correct installation path. Additionally, open a new command prompt and try to execute the command again. If you try to reinstall, do not forget to restart the command prompt again (it does not update automatically).

### Sublime text
* Download Sublime Text from [here](https://www.sublimetext.com/download).
* Follow [these](https://packagecontrol.io/installation) instructions to install Package Control, for easy installation of other packages.
* [Customize](#customize-sublime-text) your settings later.

---

### CppFastOlympicCoding (Package)
[CppFastOlympicCoding](https://packagecontrol.io/packages/CppFastOlympicCoding) is my favorite tool for competitive programming. It's a Sublime plugin for managing test cases and linting (error checking on the fly) C++ and is pretty neat. There are other useful features too, like stress testing.

In Sublime Text, go to `Preferences → Package Control → Install Package`, wait until the packages load, search for CPPFastOlympicCoding and hit enter to install.

Use `ctrl + alt + b` to build and execute your code and `ctrl + enter` to add test cases.

![foc2](https://user-images.githubusercontent.com/55075129/122922045-da7f9100-d380-11eb-866d-12e70e2ee3e4.png)

##### Key bindings (optional)
You can have a look at and even customize your key bindings for FastOlympicCoding. Go to `Preferences → Browse Packages... → CppFastOlympicCoding` and open `Default (Windows).sublime-keymap` (Windows, Linux or OSX depending on your OS) with Sublime Text. Feel free to edit the key bindings as per your convenience. I use `ctrl + space` to compile and run instead of `ctrl + alt + B`.

##### Compilation flags (optional)
FastOlympicCoding uses C++11 by default. To change the compile command, go to ``Tools → FastOlympicCoding → settings`` and make your changes in the right pane. Change `-𝚜𝚝𝚍=𝚐𝚗𝚞++𝟷𝟷` to `-𝚜𝚝𝚍=𝚌++𝟷𝟽` and add any flags you wish to. It should look something like this:

```json
{
  "cpp_complete_enabled": false,
  "run_settings": [
    {
      "name": "C++",
      "extensions": [ "cpp" ],
      "compile_cmd": "g++ -std=c++17 -D_GLIBCXX_DEBUG -O2 \"{source_file}\" -o \"{file_name}\"",
      "run_cmd": "\"{source_file_dir}\\{file_name}\" {args} -debug",
      "lint_compile_cmd": "g++ -Warray-bounds -Wmisleading-indentation -Wformat=2 -Wmaybe-uninitialized -Wsign-compare -Wconversion -Wshift-overflow=2 -Wstrict-overflow=5 -Wshadow -Wdangling-else -std=c++17 \"{source_file}\" -I \"{source_file_dir}\""
    },
    {
      "name": "C",
      "extensions": [ "c" ],
      "compile_cmd": "gcc \"{source_file}\" -std=c99 -o \"{file_name}\"",
      "run_cmd": "\"{source_file_dir}\\{file_name}\""
    },
    {
      "name": "Python",
      "extensions": [ "py" ],
      "compile_cmd": null,
      "run_cmd": "python \"{source_file}\""
    }
  ]
}
```

<details>
  <summary> My Windows settings </summary>

```json
{
  "lint_enabled": false,
  "cpp_complete_enabled": false,
  "close_sidebar": false,
  "stress_time_limit_seconds": 3,

  "tests_file_suffix": "__tests",

  "run_settings": [
    {
      "name": "C++",
      "extensions": [ "cpp" ],
      "compile_cmd": "g++ -DLOCAL -DW -fmessage-length=38 -Warray-bounds -Wformat=2 -Wmaybe-uninitialized -D_GLIBCXX_DEBUG \"{source_file}\" -Wl,--stack=268435456 -O2 -std=c++17 -o \"{file_name}\"",
      "run_cmd": "\"{source_file_dir}\\{file_name}\" {args} -debug",
      "lint_compile_cmd": "g++ -Warray-bounds -Wmisleading-indentation -Wformat=2 -Wmaybe-uninitialized -Wsign-compare -Wconversion -Wshift-overflow=2 -Wstrict-overflow=5 -Wshadow -Wdangling-else -std=c++17 \"{source_file}\" -I \"{source_file_dir}\""
    },

    {
      "name": "C",
      "extensions": [ "c" ],
      "compile_cmd": "gcc \"{source_file}\" -std=c99 -o \"{file_name}\"",
      "run_cmd": "\"{source_file_dir}\\{file_name}\""
    },

    {
      "name": "Python",
      "extensions": [ "py" ],
      "compile_cmd": null,
      "run_cmd": "python \"{source_file}\""
    },

    {
      "name": "Java",
      "extensions": [ "java" ],
      "compile_cmd": "javac -J-Dfile.encoding=utf8 -d \"{source_file_dir}\" \"{source_file}\"",
      "run_cmd": "java -classpath \"{source_file_dir}\" \"{file_name}\""
    }

  ]
}
```
</details>


<details>
  <summary> My Linux settings </summary>

```json
{
  "lint_enabled": false,
  "cpp_complete_enabled": false,
  "close_sidebar": true,
  "stress_time_limit_seconds": 3,

  // "tests_file_suffix": "__tests",

  "run_settings": [
    {
      "name": "C++",
      "extensions": [ "cpp" ],
      "compile_cmd": "g++ -DLOCAL -DW -fmessage-length=38 -Warray-bounds -Wformat=2 -Wmaybe-uninitialized -D_GLIBCXX_DEBUG -g \"{source_file}\" -O2 -std=gnu++17 -o \"{file_name}\"",
      "run_cmd": "ulimit -s 1048576 && ulimit -v 2097152 && ./\"{file_name}\" {args} -debug",   // 1 GB, 2 GB
      // "run_cmd": "./\"{file_name}\" {args} -debug",
      "lint_compile_cmd": "g++ -Warray-bounds -Wmisleading-indentation -Wformat=2 -Wmaybe-uninitialized -Wsign-compare -Wconversion -Wshift-overflow=2 -Wstrict-overflow=5 -Wshadow -Wdangling-else -std=gnu++17 \"{source_file}\" -I \"{source_file_dir}\""
    },

    {
      "name": "C",
      "extensions": [ "c" ],
      "compile_cmd": "gcc \"{source_file}\" -std=c99 -o \"{file_name}\"",
      "run_cmd": "\"{source_file_dir}/{file_name}\""
    },

    {
      "name": "Python",
      "extensions": [ "py" ],
      "compile_cmd": null,
      "run_cmd": "python3 \"{source_file}\""
    }
  ]
}
```
</details>


### Alternative to FastOlympicCoding (Build system)
If you don't want to use a package, you may use a custom build system to redirect input and output to files.

Go to `Tools → Build System → New Build System`, paste the code below and save it with the `.sublime-build` extension. Note that the `-std=c++17` flag enables C++17. If you want to use a different version, you may (eg. `-std=c++14`).

```json
{
  "shell_cmd": "g++ -std=c++17 -D_GLIBCXX_DEBUG -O2 \"${file}\" -o \"${file_base_name}\" && \"${file_base_name}\"<input.txt>output.txt",
  "working_dir": "$file_path",
  "selector": "source.c++"
}
```
Create two files 𝚒𝚗𝚙𝚞𝚝.𝚝𝚡𝚝 and 𝚘𝚞𝚝𝚙𝚞𝚝.𝚝𝚡𝚝 in the same folder as your source code file. Select `View → Layout → Columns: 3`, then `View → Groups → Max Columns: 2`. Open the three files, one in each column.

Go to `Tools → Build System` and select the one you just created. Use `ctrl + b` to build and execute.

![build1](https://user-images.githubusercontent.com/55075129/122922027-d5224680-d380-11eb-8846-89edcf2913a5.png)

##### Key bindings (optional)
You can change the key bindings to build as described [here](#key-bindings).

##### Compilation flags (optional)
You can edit the build file and add more flags, similar to the previous section.

---

## Customize Sublime Text
Sublime text has a lot of cool features which you can customize to your liking. Settings can be modified by editing `json` files — while this is a little trickier than using a GUI, you're rewarded with a flexible system. The left-hand pane contains all of the default settings, sometimes with descriptions. You can override the default settings in the right-hand pane.

[Odatnurd](https://www.youtube.com/user/nurdz) has great Sublime Text tutorials. Do check out the channel if interested.

### Packages
First thing's first. Install [Package Control](https://packagecontrol.io/installation) if you haven't installed it already. Package Control is the Sublime Text package manager. It allows users to find, install and keep packages up to date.

You can discover packages using the `Package Control: Discover Packages` option in the command palette (`ctrl + shift + p`). More importantly, to install a package, go to the command palette and select `Package Control: Install Package`, then enter the package name. These are some packages I use:

* [PackageDev](https://packagecontrol.io/packages/PackageDev) (syntax highlighting and other helpful utility for Sublime Text resource files)
* [Origami](https://packagecontrol.io/packages/Origami) (layout and view control on steroids)
* [Terminus](#terminal-within-sublime) (cross platform terminal for Sublime Text)
* [CppFastOlympicCoding](#cppfastolympiccoding-package) (test case manager for competitive programming)
* [FastOlympicCodingHook](https://github.com/DrSwad/FastOlympicCodingHook) (auto fetch test cases in conjunction with CppFastOlympicCoding)
* [MarkdownEditing](https://packagecontrol.io/packages/MarkdownEditing)
* [MarkdownPreview](https://packagecontrol.io/packages/MarkdownPreview) 
* [WordCount](https://packagecontrol.io/packages/WordCount) (real time word, char, line counter)
* [FileDiffs](https://packagecontrol.io/packages/FileDiffs) (diff checker)
* [SideBarEnhancements](https://packagecontrol.io/packages/SideBarEnhancements)
* [A File Icon](https://packagecontrol.io/packages/A%20File%20Icon) (pretty icons)
* [HTML-CSS-JS Prettify](https://packagecontrol.io/packages/HTML-CSS-JS%20Prettify) (code formatter)
* [Babel](https://packagecontrol.io/packages/Babel) (syntax definitions for ES6 JavaScript with React JSX extensions)
* [Babel Snippets](https://packagecontrol.io/packages/Babel%20Snippets) (JavaScript and React snippets)


### Themes and color schemes
Sublime text has many themes and color schemes. You can look for samples online. When you find something you like, go to `Preferences → Package Control → Install Package` and install it. I use the [Gravity](https://packagecontrol.io/packages/Theme%20-%20Gravity) theme and [Afterglow](https://packagecontrol.io/packages/Theme%20-%20Afterglow) color scheme.


### Preferences and settings
To change your sublime settings go to `Preferences → settings`. You may look up the documentation and override any features you want. 

<details>
  <summary> My settings </summary>
  <b>Note</b>: Install any themes or colour schemes you use first (via Package Control).

```json
{
  "theme": "Gravity.sublime-theme",
  "color_scheme": "Packages/Theme - Afterglow/Afterglow.tmTheme",
  "font_size": 12,
  "ignored_packages": [ "Vintage" ],
  "indent_guide_options": [ "draw_active" ],
  "default_line_ending" : "unix",
  "save_on_focus_lost": true,
  "scroll_past_end": false,
  "translate_tabs_to_spaces": true,
  "trim_trailing_white_space_on_save": true,
}

```
</details>

### Key bindings
Some useful ones are by default:

* Command palette - `ctrl + shift + P`
* Console - ``ctrl + ` ``
* Delete word - `ctrl + backspace`
* Delete line - `ctrl + shift + backspace` or `ctrl + shift + delete`
* Select and unselect line(s) - `ctrl + L` and `ctrl + U`
* Move line up/down - `ctrl + shift + up/down` (very useful, also works with multiple lines if they are selected)
* Cut/copy entire line without selection - `ctrl + X/C`
* Switch to panel # - `ctrl + #` (number)
* Switch to tab # - `alt + #` (number)

Probably the most useful one among them is multi-cursor/multi-selection. You can type in multiple places simultaneously, `ctrl + click` wherever you want and start typing. You can also select multiple occurrences of text using `ctrl + D` repeatedly (or `alt + F3` / `⌃ + ⌘ + G` to select all) then start typing simultaneously.

**Note**: For Mac, use `⌘` instead of `ctrl`.

Needless to say, Sublime lets you customize and change your key bindings too. Go to `Preferences → Key Bindings` and fill in the panel on the right.

<details>
  <summary> My key bindings </summary>

```json
[

  /* Package: Terminus */

    { // Toggle Terminus panel
      "keys": ["ctrl+alt+t"],
      "command": "toggle_terminus_panel",
      "args": {
        "cwd": "${file_path:${folder}}"     // open at current working dir
      }
    },

    { // Open tab in split view using Package: Origami
      "keys": ["ctrl+`"],
      "command": "terminus_open",
      "args": {
        "post_window_hooks": [
            ["carry_file_to_pane", {"direction": "right"}]
        ]
      }
    },

    { // Close
      "keys": ["ctrl+w"],
      "command": "terminus_close",
      "context": [{ "key": "terminus_view" }]
    },


  /* Package: MarkdownPreview */

    { // Preview on browser
      "keys": ["ctrl+shift+v"],
      "command": "markdown_preview",
      "args": {
        "target": "browser",
        "parser": "github"
      },
      "context": [
        {
          "key": "selector",
          "operator": "equal",
          "operand": "text.plain, text.html.markdown"
        }
      ]

    },


  /* Custom plugins */

    { // C++ starter plugin (single test)
      "keys": [ "c", "p", "p", "enter" ],
      "command": "starter_cpp",
      "context": [
        {
          "key": "selector",
          "operator": "equal",
          "operand": "source.c++"
        }
      ]
    },

    { // C++ starter plugin (multi test)
      "keys": [ "c", "p", "p", "q", "enter" ],
      "command": "starter_cppq",
      "context": [
        {
          "key": "selector",
          "operator": "equal",
          "operand": "source.c++"
        }
      ]
    },


  /* Misc */

    { "keys": ["ctrl+t"], "command": "new_file" },
    { "keys": ["shift+escape"], "command": "show_panel", "args": {"panel": "console", "toggle": true} },

    { "keys": ["ctrl+alt+p"], "command": "prompt_select_workspace" },

    { // Toggle comments
      "keys": ["`"],                                        // because I don't like ctrl + /
      "command": "toggle_comment",
      "args": {
        "block": false
      },
      "context": [
        {
          "key": "selector",
          "operator": "equal",
          "operand": "-(text.plain, text.html.markdown)"    // everywhere except unsaved tab and .md
        }
      ]
    }

]

```
If you are curious about the custom plugins, skip to [Plugins](#plugins).
</details>


### Snippets
Snippets expedite the act of writing code by providing a quick way to insert blocks of text using trigger words or phrases. To invoke a snippet, type its trigger word and press tab. To create a snippet, go to `Tools → Developer → New Snippet...`. You may refer to [this](https://www.freecodecamp.org/news/a-guide-to-preserving-your-wrists-with-sublime-text-snippets-7541662a53f2/) link for more details. Here are some examples of snippets.

<details>
  <summary> Random integer snippet </summary>

```xml
<snippet>
    <content><![CDATA[
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int L, int R) {
    uniform_int_distribution<int> dist(L, R);
    return dist(rng);
}

]]></content>
    <tabTrigger>rng</tabTrigger>
    <description>Random number generator</description>
    <scope>source.c, source.objc, source.c++, source.objc++</scope>
</snippet>
```
</details>

<details>
  <summary> Starter cpp template </summary>

```xml
<snippet>
    <content><![CDATA[
// Author: πα
#include <bits/stdc++.h>
using namespace std;
$1
int main() {
   int n, i$2;
   cin >> n$3;
   $4
   return 0;
}

]]></content>
    <tabTrigger>cpp</tabTrigger>
    <description>PyAlpha's cpp template</description>
    <scope>source.c, source.objc, source.c++, source.objc++</scope>
</snippet>
```
</details>

You can find most of my snippets (without the snippet boilerplate code) [here](https://github.com/the-hyp0cr1t3/CC/tree/master/%E6%9C%AB%20Snippets).

### Plugins
[Plugins](https://www.sublimetext.com/docs/1/plugin-basics) trigger a set of activities. You can write your own [custom plugins](https://www.tutorialspoint.com/sublime_text/sublime_text_developing_plugin.htm). Here is my `starter cpp` plugin which clears the view and then displays author, current date-time and inserts a snippet for my starter code.

```python
import sublime
import sublime_plugin
from datetime import datetime

class StarterCppCommand(sublime_plugin.TextCommand):
    def run(self, edit):
        self.view.erase(edit, sublime.Region(0, self.view.size()))
        self.view.sel().clear()
        self.view.sel().add(sublime.Region(0, 1))

        s = '/**\n 🍪 the_hyp0cr1t3\n 🍪 ' + datetime.now().strftime("%d.%m.%Y %H:%M:%S") + '\n**/\n'

        self.view.insert(edit, self.view.sel()[0].begin(), s)
        self.view.run_command("insert_snippet", {"name": "Packages/Sublime-snippets/My snippets/my_cpp_starter.sublime-snippet"})

```

You can write your own plugins and configure key bindings for them. The class name must be in camel case, while the command in key bindings should be in snake case (omit 'command'). What you name the `.py` does not matter. Another thing to note (that wasn't mentioned in the docs) was that plugins don't work if you do not save the `.py` file in the top level, i.e `/Packages/User/starter.py` works, but `/Packages/User/.../starter.py` does not.

----

## Misc

### Terminal within Sublime
[Terminus](https://packagecontrol.io/packages/Terminus) is a cross platform terminal for Sublime Text.

* [Setting up Terminus](https://www.youtube.com/watch?v=mV0ghkMwTQc)
* [Interactve Build systems using Terminus](https://www.youtube.com/watch?v=etIJMVIvVgg)

<details>
  <summary> My C++ interactive build (integrated with terminus) </summary>

```json
{
    // open in new tab
    // "target": "terminus_open",
    // "auto_close": false,
    // "title": "Output",
    // "post_window_hooks": [
    //     [ "carry_file_to_pane", { "direction": "right" } ]
    // ],

    // open in pane (comment everything above)
    "target": "terminus_exec",

    // common to both
    "cancel": "terminus_cancel_build",
    "focus": true,
    "timeit": true,

    "shell_cmd": "g++ -DLOCAL -DW -fmessage-length=38 -Warray-bounds -Wformat=2 -Wmaybe-uninitialized -D_GLIBCXX_DEBUG \"${file}\" -Wl,--stack=268435456 -O2 -std=c++17 -o \"${file_base_name}\" && \"${file_path}/${file_base_name}\" -debug",
    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
    "working_dir": "${file_path}",
    "selector": "source.c++",

}
```
</details>

### Precompile headers
You can speed up compilation time by precompiling all header files ([see](https://codeforces.com/blog/entry/53909)). Look for the `stdc++.h` file. Its path should be similar to `C:\MinGW\lib\gcc\mingw32\6.3.0\include\c++\mingw32\bits`. Open cmd or terminal and run

```bash
cd PATH
g++ -std=c++17 -D_GLIBCXX_DEBUG -O2 stdc++.h
```

Replace `PATH` with the appropriate path of the `bits` folder which contains `stdc++.h`. Make sure that you run the `g++` command with exactly the same flags FastOlympicCoding/your build system uses.

If it was successful, `stdc++.h.gch` should appear. Refer to [link](https://codeforces.com/blog/entry/53909?#comment-729130).

## Credits
(☞ﾟ∀ﾟ)☞ Muzaffar Ahmed, for inspiring me to write this \
[Link to post](https://facebook.com/groups/BPHCCompetitiveCoding/permalink/2365719330329693/)
