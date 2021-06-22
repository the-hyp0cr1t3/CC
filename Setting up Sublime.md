# Setting up C++ for competitive programming in Sublime Text
I use and recommend Sublime Text over other editors/IDEs because it is light weight and fast. IDEs in general are heavy and slow. Sublime also has many shortcuts and features to explore.

### MinGW (GNU C/C++ compiler collection for Windows 64-bit)
* Download [MinGW](https://sourceforge.net/projects/mingw/). You may refer to [this](https://www.youtube.com/watch?v=sXW2VLrQ3Bs) video for instructions on installation.
* Add to the bin directory to system PATH, as described [here](https://stackoverflow.com/questions/5733220/how-do-i-add-the-mingw-bin-directory-to-my-system-path).

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

Use `ctrl + alt + B` to build and execute your code and `ctrl + enter` to add testcases.

![foc2](https://user-images.githubusercontent.com/55075129/122922045-da7f9100-d380-11eb-866d-12e70e2ee3e4.png)

##### Key bindings (optional)
You can have a look at and even customize your key bindings for FastOlympicCoding. Go to `Preferences → Browse Packages... → CppFastOlympicCoding` and open `Default (Windows).sublime-keymap` (Windows, Linux or OSX depending on your OS) with Sublime Text. Feel free to edit the key bindings as per your convenience. I use `ctrl + space` to compile and run instead of `ctrl + alt + B`.

##### Compilation flags (optional)
FastOlympicCoding uses C++11 by default. To change the compile command, go to ``Tools → FastOlympicCoding → settings`` and make your changes in the right pane. Change `-𝚜𝚝𝚍=𝚐𝚗𝚞++𝟷𝟷` to `-𝚜𝚝𝚍=𝚌++𝟷𝟽` and add any flags you wish to. These are my settings:

```json
{
  "cpp_complete_enabled": false,
  "run_settings": [
    {
      "name": "C++",
      "extensions": [ "cpp" ],
      "compile_cmd": "g++ -DLOCAL -fmessage-length=38 -Warray-bounds -Wmisleading-indentation -Wformat=2 -Wmaybe-uninitialized -Wsign-compare -Wconversion -Wshift-overflow=2 -Wstrict-overflow=5 -Wshadow -D_GLIBCXX_DEBUG \"{source_file}\" -Wl,--stack=268435456 -O2 -std=c++17 -o \"{file_name}\"",
      "run_cmd": "\"{source_file_dir}\\{file_name}.exe\" {args} -debug",
      "lint_compile_cmd": "g++ -Warray-bounds -Wmisleading-indentation -Wformat=2 -Wmaybe-uninitialized -Wsign-compare -Wconversion -Wshift-overflow=2 -Wstrict-overflow=5 -Wshadow -Wdangling-else -std=c++17 \"{source_file}\" -I \"{source_file_dir}\""
    },
    {
      "name": "Python",
      "extensions": [ "py" ],
      "compile_cmd": null,
      "run_cmd": "python \"{source_file}\""
    },
    {
      "name": "C",
      "extensions": [ "c" ],
      "compile_cmd": "gcc \"{source_file}\" -std=c99 -o \"{file_name}\"",
      "run_cmd": "\"{source_file_dir}\\{file_name}.exe\""
    }
  ]
}
```

If you're not on windows, remove `.exe` and `--stack=268435456`.

### Alternative to FastOlympicCoding (Build system)
If you don't want to use a package, you may use a custim build system to redirect input and output to files.

Go to `Tools → Build System → New Build System`, paste the code below and save it with the `.sublime-build` extension. Note that the `-std=c++17` flag enables C++17. If you want to use a different version, you may (eg. `-std=c++14`). Remove `.exe` for Linux.

```json
{
  "cmd": [ "g++.exe", "-std=c++17", "${file}", "-o", "${file_base_name}.exe", "&&", "${file_base_name}.exe<input.txt>output.txt"],
  "shell": true,
  "working_dir": "$file_path",
  "selector": "source.cpp"
}
```
Create two files 𝚒𝚗𝚙𝚞𝚝.𝚝𝚡𝚝 and 𝚘𝚞𝚝𝚙𝚞𝚝.𝚝𝚡𝚝 in the same folder as your source code file. Select `View → Layout → Columns: 3`, then `View → Groups → Max Columns: 2`. Open the three files, one in each column.

Go to `Tools → Build System` and select the one you just created. Use `ctrl + B` to build and execute.

![build1](https://user-images.githubusercontent.com/55075129/122922027-d5224680-d380-11eb-8846-89edcf2913a5.png)

##### Key bindings (optional)
You can change the key bindings to build as described [here](#key-bindings).

##### Compilation flags (optional)
You can edit the build file and add more flags, similar to the previous section.

---

## Customize Sublime Text
Sublime text has a lot of cool features which you can customize to your liking.

### Themes and color schemes
Sublime text has many themes and color schemes. You can look for samples online. When you find something you like, go to `Preferences → Package Control → Install Package` and install it. I use the [Gravity](https://packagecontrol.io/packages/Theme%20-%20Gravity) theme and [Afterglow](https://packagecontrol.io/packages/Theme%20-%20Afterglow) color scheme.

### Sublime settings
To change your sublime settings go to `Preferences → settings`. Any changes you want to make can be added to the right panel. These are my sublime settings:

```json
{
  "theme": "Gravity.sublime-theme",
  "color_scheme": "Packages/Theme - Afterglow/Afterglow-markdown.tmTheme",
  "font_size": 13,
  "ignored_packages": [ "Vintage", ],
  "indent_guide_options": [ "draw_active" ],
  "default_line_ending" : "unix",
  "save_on_focus_lost": true,
  "scroll_past_end": false,
  "translate_tabs_to_spaces": true,
  "trim_trailing_white_space_on_save": true
}
```

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

Needless to say, Sublime lets you customize and change your key bindings too. Go to `Preferences → Key Bindings` and fill in the panel on the right. These are my mine:

```json
[
  {
    "keys": ["`"],
    "command": "toggle_comment",
    "args": {
      "block": false
    },
    "context": [
      {
        "key": "selector",
        "operator": "equal",
        "operand": "source.c++"
      }
    ]
  },

  {
    "keys": [ "c", "p", "p", "enter" ],
    "command": "starter_cpp",
    "context": [
      {
        "key": "selector",
        "operator": "equal",
        "operand": "source.c++"
      }
    ]
  }

]

```

The second one is a key binding for a custom [Sublime plugin](#sublime-plugins) I made.

### Sublime snippets
Snippets expedite the act of writing code by providing a quick way to insert blocks of text using trigger words or phrases. To invoke a snippet, type its trigger word and press tab. To create a snippet, go to `Tools → Developer → New Snippet...`. You may refer to [this](https://www.freecodecamp.org/news/a-guide-to-preserving-your-wrists-with-sublime-text-snippets-7541662a53f2/) link for more details. Here are some examples of snippets.

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

### Sublime plugins
[Plugins](https://www.sublimetext.com/docs/1/plugin-basics) trigger a set of activities. You can write your own [custom plugins](https://www.tutorialspoint.com/sublime_text/sublime_text_developing_plugin.htm). Here is my `starter cpp` plugin which displays author, current date-time and inserts a snippet for my starter code.

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

You can write your own plugins and configure key bindings for them. The class name must be in camel case, while the command in key bindings should be in snake case (omit 'command'). A weird bug I ran into was that plugins don't seem to work if you save the file deeper than one layer in, i.e `/Packages/.../starter.py` works, but `/Packages/.../.../starter.py` does not.


## Misc

### Command prompt shortcut
Right click on taskbar, go to `Taskbar settings → Disable "Replace Command prompt... ...Windows key + X"`.

Now you can use `Win + X` followed by `C` to quickly open command prompt.

This isn't necessary, but it is important to know because if your editor fails to work for some reason during a contest, you should be able to write, compile and run your code. Your workspace should be easily navigable from the user folder.

### Precompile headers
You can speed up compilation time by precompiling all header files ([see](https://codeforces.com/blog/entry/53909)). Look for the `stdc++.h` file. Its path should be similar to `C:\MinGW\lib\gcc\mingw32\6.3.0\include\c++\mingw32\bits`. Open cmd or terminal and run

```bash
cd PATH
g++ -std=c++11 stdc++.h
```

Replace `PATH` with the appropriate path of the `bits` folder which contains `stdc++.h`. Make sure that you run the `g++` command with exactly the same flags FastOlympicCoding/your build system uses.

If it was successful, `stdc++.h.gch` should appear.

## Credits
(☞ﾟ∀ﾟ)☞ Muzaffar Ahmed, for a majority of the content on this page\
[Link](https://facebook.com/groups/BPHCCompetitiveCoding/permalink/2365719330329693/)
