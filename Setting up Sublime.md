(☞ﾟ∀ﾟ)☞ Credit to Muzaffar Ahmed for the all that follows

𝐒𝐞𝐭𝐭𝐢𝐧𝐠 𝐮𝐩 𝐒𝐮𝐛𝐥𝐢𝐦𝐞 𝐓𝐞𝐱𝐭 𝟑 𝐚𝐧𝐝 𝐂++ 𝐜𝐨𝐦𝐩𝐢𝐥𝐞𝐫 𝐟𝐨𝐫 𝐖𝐢𝐧𝐝𝐨𝐰𝐬

Hello!
Before we begin with Competitive Programming tutorials, I felt like I should write this since many face problems with setting up the environment or end up setting poor environment which affects their speed.
I use and recommend Sublime Text over other editors/IDEs because it is light and extremely fast. IDEs in general are heavy and slow, which waste precious time during contests. Sublime has many shortcuts and features which will save you a lot of time while coding.

𝗦𝘂𝗯𝗹𝗶𝗺𝗲 𝗧𝗲𝘅𝘁 𝟯𝟭𝟳𝟲 𝗳𝗼𝗿 𝗪𝗶𝗻𝗱𝗼𝘄𝘀 𝟲𝟰-𝗯𝗶𝘁 (because crack for later versions isn't out yet and the recurring unregistered dialog box is quite annoying):
https://drive.google.com/open…
License key:
Open Sublime Text, click on Help → Enter License and paste the following license: http://p.ip.fi/BNXS
Package Control:
Follow these instructions to install Package Control, needed for easy installation of packages: https://packagecontrol.io/installation

𝗠𝗶𝗻𝗚𝗪 𝟳.𝟯.𝟬 (GNU C/C++ compiler collection for Windows 64-bit):
https://drive.google.com/open…
I use 7.3 because later versions have many bugs.
To check if you have g++ installed, execute 𝚐++ --𝚟𝚎𝚛𝚜𝚒𝚘𝚗 from the command prompt. If you have an older version, uninstall it and install this. If you have a later version, I recommend rolling back, but it's not necessary if you aren't facing issues.
Installation instructions:
1. Extract the .zip to wherever you wish, preferably Program Files.
2. Add <𝚎𝚡𝚝𝚛𝚊𝚌𝚝𝚎𝚍_𝚝𝚘_𝚏𝚘𝚕𝚍𝚎𝚛>/𝚖𝚒𝚗𝚐𝚠𝟼𝟺/𝚋𝚒𝚗 to path. To add to path:
i. Click on Start, search for "environment variables".
ii. Click on "Environment Variables..." at the bottom of the window.
iii. Under User variables (or System variables), double click on the value of Path, and paste the above path in a new line (if you were unable to follow the above, refer to this video: https://www.youtube.com/watch?v=ozoO0e7hg48).
3. Start a new command prompt and execute 𝚐++ --𝚟𝚎𝚛𝚜𝚒𝚘𝚗 to check if installation was successful.

𝗖𝗽𝗽𝗙𝗮𝘀𝘁𝗢𝗹𝘆𝗺𝗽𝗶𝗰𝗖𝗼𝗱𝗶𝗻𝗴:
My favorite tool (and the only one I use right now) for competitive programming. It's a Sublime plugin for managing test cases and linting(error checking on the fly) C++ and is pretty neat. There are other useful features too, like stress testing, check it out yourself: https://packagecontrol.io/packages/CppFastOlympicCoding
Installation:
In Sublime Text, go to Preferences → Package Control → Install Package, wait until the packages load, search for CppFastOlympicCoding and hit enter to install.
Alternative:
If you don't want to use a package, you can use 𝚏𝚛𝚎𝚘𝚙𝚎𝚗 to redirect input and output to files. Have an 𝚒𝚗𝚙𝚞𝚝.𝚝𝚡𝚝 and an 𝚘𝚞𝚝𝚙𝚞𝚝.𝚝𝚡𝚝 in the same folder as your source code file, use 𝚏𝚛𝚎𝚘𝚙𝚎𝚗 in an 𝚒𝚏𝚗𝚍𝚎𝚏 (or better, 𝚒𝚏𝚍𝚎𝚏) directive (refer http://p.ip.fi/psMk) and change the layout of Sublime by clicking View → Groups → New Group twice.

We're almost through. Following are just tips and guidelines which you may find helpful.

𝗦𝘂𝗯𝗹𝗶𝗺𝗲 𝘀𝗵𝗼𝗿𝘁𝗰𝘂𝘁𝘀 𝗜 𝗳𝗿𝗲𝗾𝘂𝗲𝗻𝘁𝗹𝘆 𝘂𝘀𝗲:
1. Delete word - ctrl+backspace
2. Delete line - ctrl+shift+backspace
3. Select line(s) - ctrl+L
4. Move line up/down - ctrl+shift+up/down (very useful)
5. Cut/copy entire line - ctrl+X/C without selection
6. Select occurrence of a word - ctrl+D (probably the most useful, check out how it works)
7. Switch to panel # - ctrl+# (number)
8. Switch to tab # - alt+# (number)

𝗦𝘂𝗯𝗹𝗶𝗺𝗲 𝘀𝗻𝗶𝗽𝗽𝗲𝘁𝘀:
Ah, snippets. Most useful for competitive programmers, it's one hell of a feature. They're templates which are triggered by a keyword/phrase. In Sublime Text, go to Tools → Developer → New Snippet... to create a new snippet. You can use this for your CC template or commonly used functions (Please, don't make your CC template ugly by adding every function and macro ever. Keep it clean and use snippets instead.).
Snippet I use for my template: pastebin.com/jp79zQM1
Another example for a snippet (RNG): pastebin.com/cwYhUvw1
Read more on this feature here: http://docs.sublimetext.info/…/…/extensibility/snippets.html

𝗖𝗽𝗽𝗙𝗮𝘀𝘁𝗢𝗹𝘆𝗺𝗽𝗶𝗰𝗖𝗼𝗱𝗶𝗻𝗴 𝘀𝗲𝘁𝘁𝗶𝗻𝗴𝘀:
1. Key bindings:
Hitting ctrl+alt+b every single time to run is too much work, ain't it? You can change the package's key bindings by going to Preferences → Browse Packages... → FastOlympicCoding and open "Default (Windows).sublime-keymap" with Sublime Text. Search for ctrl+alt+b and replace it with whatever you like, but make sure it isn't already used by Sublime. Mine is ctrl+' (single quote). While you're at it, explore other key bindings as well.
2. C++17 and other compilation flags:
CppFastOlympicCoding uses C++11 by default. To change the compile command, go to Tools → FastOlympicCoding → settings and make your changes in the right pane. Change -𝚜𝚝𝚍=𝚐𝚗𝚞++𝟷𝟷 to -𝚜𝚝𝚍=𝚌++𝟷𝟽 and add any flags you wish to. My settings file: pastebin.com/biNXA2Cg
(I will explain what each flag does and why it's needed in another article later)

𝗢𝘁𝗵𝗲𝗿 𝗦𝘂𝗯𝗹𝗶𝗺𝗲 𝘀𝗲𝘁𝘁𝗶𝗻𝗴𝘀:
Go to Preferences → Settings and explore. Whatever changes you want to make, add that change in the right panel. I suggest these settings: pastebin.com/peJ8tVyE
(yes, spaces are better than tabs)

𝗖𝗼𝗺𝗺𝗮𝗻𝗱 𝗽𝗿𝗼𝗺𝗽𝘁 𝘀𝗵𝗼𝗿𝘁𝗰𝘂𝘁:
Right click on taskbar → Taskbar settings → Disable "Replace Command prompt... ...Windows key+X".
Now you can use Win+X followed by C to quickly open command prompt.
This isn't necessary, but it is important to know because if your editor fails to work for some reason during a contest, you should be able to write, compile and run your code. Your workspace should be easily navigable from the user folder.

That's it for now.
Feel free to PM if you have any doubts.
Happy coding! 😄

UPD: Sublime Text 3176 crack does not work anymore, so you should preferably install the latest version from their website.

&lt /Direct-copy-pasta-from-the-FB-group-for-those-who-may-not-be-able-to-access &rt

## Source
[Link](https://facebook.com/groups/BPHCCompetitiveCoding/permalink/2365719330329693/)
