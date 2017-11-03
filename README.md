# Arg_parser_cpp

Arg_parser class<br>
<br>
This class is designed for parsing command-line string from user.<br>
Warning!!! This code works with solid string, not with arguments-array (argv**).<br>
<br>
You can create Arg_parser object and put string with command in it's constructor.<br>
Example:<br>
Arg_parser parser("-day 22 -month April");<br>
<br>
Syntax of arguments-line is provided not in "canonical" UNIX argument-line style, but has some features.<br>
<br>
Arg_parser supports 3 types of data:<br>
1) Unnamed arguments<br>
&nbsp;&nbsp;&nbsp;&nbsp;This is just any string without name.<br>
&nbsp;&nbsp;&nbsp;&nbsp;For example: "April" is unnamed argument.<br>
2) Named arguments<br>
&nbsp;&nbsp;&nbsp;&nbsp;This is string parameter, which has unique name.<br>
&nbsp;&nbsp;&nbsp;&nbsp;Name of argument (key) starts with single minus (-).<br>
&nbsp;&nbsp;&nbsp;&nbsp;For example: "-month April" is named argument.<br>
3) Named arrays<br>
&nbsp;&nbsp;&nbsp;&nbsp;This is sequence of strings, which has unique name.<br>
&nbsp;&nbsp;&nbsp;&nbsp;Name of array (key) starts with double minus (--)<br>
&nbsp;&nbsp;&nbsp;&nbsp;For example: "--months March April May June" is array of strings.<br>
<br>
<br>
Parser also supports escaping characters:<br>
&nbsp;&nbsp;&nbsp;&nbsp;quotes: (\') and (\")<br>
&nbsp;&nbsp;&nbsp;&nbsp;newline character: (\n)<br>
&nbsp;&nbsp;&nbsp;&nbsp;Backslash: (\\)<br>
&nbsp;&nbsp;&nbsp;&nbsp;And space: (\ )<br>
<br>
&nbsp;&nbsp;&nbsp;&nbsp;(Inside single quotes escape-characters are ignored).<br>
<br>
Arguments are separated with spaces.<br>
If you need string, which includes spaces, you can put<br>
it into double-quotes ( " - supports escaping)<br>
or in single-quotes ( ' - without escaping)<br>
<br>
You also can combine different types in one string.<br>
<br>
Example:<br>
&nbsp;&nbsp;&nbsp;&nbsp;Arguments line is:<br>
&nbsp;&nbsp;&nbsp;&nbsp;arg1 arg2 arg\ 3   -key1 'Value 1' arg4 -Key2 "Value 2" -singlequotes 'one newline1 -><br>
&nbsp;&nbsp;&nbsp;&nbsp;two, double quote """' -doublequotes "double quote \" newline2 ->\n++" --some_array oc <br>
&nbsp;&nbsp;&nbsp;&nbsp;toc perevertoc 'A B C D' -key3 value3 😄😄 😄😄😄😄<br>
<br>
<br>
&nbsp;&nbsp;Arguments line will be parsed this way:<br>
<br>
&nbsp;&nbsp;&nbsp;&nbsp;All arguments:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arg1<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arg2<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arg 3<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-key1<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Value 1<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arg4<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Key2<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Value 2<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-singlequotes<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;one newline1 -><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;two, double quote """<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-doublequotes<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double quote " newline2 -><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;++<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--some_array<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;oc<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;toc<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;perevertoc<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A B C D<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-key3<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;value3<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;😄😄<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;😄😄😄😄<br>
&nbsp;&nbsp;&nbsp;&nbsp;Unnamed arguments:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arg1<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arg2<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arg 3<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arg4<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;😄😄<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;😄😄😄😄<br>
&nbsp;&nbsp;&nbsp;&nbsp;Named arguments:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;key1 => Value 1<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Key2 => Value 2<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;doublequotes => double quote " newline2 -><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;++<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;key3 => value3<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;singlequotes => one newline1 -><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;two, double quote """<br>
&nbsp;&nbsp;&nbsp;&nbsp;Named arrays:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;some_array => <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;oc<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;toc<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;perevertoc<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A B C D<br>
<br>
