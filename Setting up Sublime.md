# Setting up Sublime Text 3 and C++ for Windows
Before we begin with Competitive Programming tutorials, I felt like I should write this since many face problems with setting up the environment or end up setting poor environment which affects their speed.

I use and recommend Sublime Text over other editors/IDEs because it is light and extremely fast. IDEs in general are heavy and slow, which waste precious time during contests. Sublime has many shortcuts and features which will save you a lot of time while coding.

### Application
Download Sublime Text 3 from [here](https://www.sublimetext.com/3).

### Package Control
Follow [these](https://packagecontrol.io/installation) instructions to install Package Control, needed for easy installation of packages.

## MinGW (GNU C/C++ compiler collection for Windows 64-bit)
[Link](https://sourceforge.net/projects/mingw-w64/files/latest/download) (Latest)\
[Aternate Drive link](https://drive.google.com/file/d/1NISQqx2x0Ss5AveZy3AV4V41zL7HdIOo/) (MinGW 7.3.0)

To check if you have g++ installed, execute `𝚐++ --𝚟𝚎𝚛𝚜𝚒𝚘𝚗` from the command prompt.

### Installation
* Extract the .zip to wherever you wish, preferably Program Files.
* Add `<𝚎𝚡𝚝𝚛𝚊𝚌𝚝𝚎𝚍_𝚝𝚘_𝚏𝚘𝚕𝚍𝚎𝚛>/𝚖𝚒𝚗𝚐𝚠𝟼𝟺/𝚋𝚒𝚗` to path. To add to path:
  * Click on Start, search for "environment variables".
  * Click on "Environment Variables..." at the bottom of the window.
  * Under User variables (or System variables), double click on the value of Path, and paste the above path in a new line (if you were       unable to follow the above, refer to [this](https://www.youtube.com/watch?v=ozoO0e7hg48) video.
* Start a new command prompt and execute `𝚐++ --𝚟𝚎𝚛𝚜𝚒𝚘𝚗` to check if installation was successful.

## CppFastOlympicCoding
My favorite tool (and the only one I use right now) for competitive programming. It's a Sublime plugin for managing test cases and linting(error checking on the fly) C++ and is pretty neat. There are other useful features too, like stress testing, [check it out](https://packagecontrol.io/packages/CppFastOlympicCoding) yourself.

### Installation
In Sublime Text, go to `Preferences → Package Control → Install Package`, wait until the packages load, search for CppFastOlympicCoding and hit enter to install.

#### Alternative
If you don't want to use a package, you can use 𝚏𝚛𝚎𝚘𝚙𝚎𝚗 to redirect input and output to files. Have an 𝚒𝚗𝚙𝚞𝚝.𝚝𝚡𝚝 and an 𝚘𝚞𝚝𝚙𝚞𝚝.𝚝𝚡𝚝 in the same folder as your source code file, use [𝚏𝚛𝚎𝚘𝚙𝚎𝚗](https://en.cppreference.com/w/cpp/io/c/freopen) in an 𝚒𝚏𝚗𝚍𝚎𝚏 (or better, 𝚒𝚏𝚍𝚎𝚏) directive and change the layout of Sublime by clicking `View → Groups → New Group twice`.

<details>
  <summary>Code</summary>
 
 ```c++
// Relies on the online judge using -DONLINE_JUDGE flag during compilation.
// Most judges (like Codefoces, UVa) do use it, but not all.
int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
 
    /* your code */
}
```
```c++
// Requires you to compile with -DMY_FLAG_6969 flag during compilation. Always works.
int main() {
    #ifdef MY_FLAG_6969
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
 
    /* your code */
}
 ```
</details>

# Some tips and shortcuts
We're almost through. Following are just tips and guidelines which you may find helpful.

## Sublime shortcuts I frequently use
1. Delete word - `ctrl + backspace`
2. Delete line - `ctrl + shift + backspace`
3. Select line(s) - `ctrl + L`
4. Move line up/down - `ctrl + shift + up/down` (very useful)
5. Cut/copy entire line - `ctrl + X/C` without selection
6. Select occurrence of a word - `ctrl + D` (probably the most useful, check out how it works)
7. Switch to panel # - `ctrl + #` (number)
8. Switch to tab # - `alt + #` (number)

## Sublime snippets 
Ah, snippets. Most useful for competitive programmers, it's one hell of a feature. They're templates which are triggered by a keyword/phrase. In Sublime Text, go to `Tools → Developer → New Snippet...` to create a new snippet. You can use this for your CC template or commonly used functions (Please, don't make your CC template ugly by adding every function and macro ever; Keep it clean and use snippets instead).

<details>
  <summary>Example of a starting snippet</summary>
 
 ```xml
<snippet>
    <content><![CDATA[
// Author: πα
#include <bits/stdc++.h>
using namespace std;
#define long int64_t
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
<details>
  <summary>Rng snippet</summary>
 
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

## CppFastOlympicCoding settings

### Key bindings
Hitting ctrl+alt+b every single time to run is too much work, ain't it? You can change the package's key bindings by going to `Preferences → Browse Packages... → FastOlympicCoding` and open "Default (Windows).sublime-keymap" with Sublime Text. Search for ctrl+alt+b and replace it with whatever you like, but make sure it isn't already used by Sublime. Mine is ctrl+' (single quote). While you're at it, explore other key bindings as well.

### C++17 and other compilation flags
CppFastOlympicCoding uses C++11 by default. To change the compile command, go to Tools → FastOlympicCoding → settings and make your changes in the right pane. Change `-𝚜𝚝𝚍=𝚐𝚗𝚞++𝟷𝟷` to `-𝚜𝚝𝚍=𝚌++𝟷𝟽` and add any flags you wish to. 

<details>
  <summary>My settings</summary>
 
 ```json
{
    "cpp_complete_enabled": false,
    "run_settings": [
        {
            "name": "C++",
            "extensions": ["cpp"],
            "compile_cmd": "g++ -fmessage-length=38 -Warray-bounds -Wmisleading-indentation -Wformat=2 -Wmaybe-uninitialized -Wsign-compare -Wconversion -Wshift-overflow=2 -Wstrict-overflow=5 -Wshadow -Wdangling-else -D_GLIBCXX_DEBUG \"{source_file}\" -Wl,--stack=268435456 -O2 -std=c++17 -o \"{file_name}\"",
            "run_cmd": "\"{source_file_dir}\\{file_name}.exe\" {args} -debug",
            "lint_compile_cmd": "g++ -Warray-bounds -Wmisleading-indentation -Wformat=2 -Wmaybe-uninitialized -Wsign-compare -Wconversion -Wshift-overflow=2 -Wstrict-overflow=5 -Wshadow -Wdangling-else -std=c++17 \"{source_file}\" -I \"{source_file_dir}\""
        },
 
        {
            "name": "Python",
            "extensions": ["py"],
            "compile_cmd": null,
            "run_cmd": "python \"{source_file}\""
        },
 
        {
            "name": "C",
            "extensions": ["c"],
            "compile_cmd": "gcc \"{source_file}\" -std=c99 -o \"{file_name}\"",
            "run_cmd": "\"{source_file_dir}\\{file_name}.exe\"",
        }
    ]
}
 ```
</details>

## Other Sublime settings
Go to `Preferences → Settings` and explore. Any changes you want to make can be added to right panel.

<details>
  <summary>My settings</summary>
 
 ```json
{
    "color_scheme": "Packages/Color Scheme - Default/Monokai.sublime-color-scheme",
    "font_size": 13,
    "ignored_packages":
    [
        "Vintage"
    ],
    "indent_guide_options":
    [
        "draw_active"
    ],
    "save_on_focus_lost": true,
    "scroll_past_end": false,
    "theme": "Adaptive.sublime-theme",
    "translate_tabs_to_spaces": true
}
 ```
</details>

## Command prompt shortcut
Right click on `taskbar → Taskbar settings → Disable "Replace Command prompt... ...Windows key+X"`.

Now you can use Win+X followed by C to quickly open command prompt.

This isn't necessary, but it is important to know because if your editor fails to work for some reason during a contest, you should be able to write, compile and run your code. Your workspace should be easily navigable from the user folder.

## Sauce
(☞ﾟ∀ﾟ)☞ Muzaffar Ahmed\
[Link](https://facebook.com/groups/BPHCCompetitiveCoding/permalink/2365719330329693/)
