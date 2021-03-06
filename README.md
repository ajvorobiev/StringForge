# StringForge
A tool to work with Arma game series stringtables which are used for translations.

[![GitHub issues](https://img.shields.io/github/issues/ajvorobiev/StringForge.svg?style=plastic)](https://github.com/ajvorobiev/StringForge/issues)
[![GitHub forks](https://img.shields.io/github/forks/ajvorobiev/StringForge.svg?style=plastic)](https://github.com/ajvorobiev/StringForge/network)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg?style=plastic)](https://raw.githubusercontent.com/ajvorobiev/StringForge/master/LICENSE)
[![Build Status](http://jenkins.rhsmods.org/job/StringForge/badge/icon)](http://jenkins.rhsmods.org/job/StringForge/)

# Background
The program is written as a part of advanced tools utilized by Red Hammer Studios (http://www.rhsmods.org).

# About the Tool
The program has all the necessary tools to deal with translation stringtables for the game Arma 3. It can load in `Stringtable.xml` files, add, edit, reorganise and delete entries, convert whole projects consisting out of multiple `Stringtable.csv` into single fragmented xml files. It was made with handling large projects in mind.

The software is built in C#, .NET (Framework 4.5) and WPF. The MVVM architectural pattern is utilized where possible but without the use of any perticular MVVM framework. Some advanced 3rd party libraries are used, such as ReactiveUI and Extended WPF Toolkit (CE) and GongSolutions dragndrop.

The tool is built and maintained by Alex Vorobiev.

# Accreditation

Icons used from: https://www.iconfinder.com/

# Changelog

v1.3
- Added search and replace
- Added config scanner
- Some fixes related to transliteration

v1.1
- Key ID templates added
- Model objects are now reactive, better reflecting updates
- Improved Drag and Drop for the tree
- Duplication of keys imporved
- Some bug fixes

v1.0
- Basing stringtable handling and conversion