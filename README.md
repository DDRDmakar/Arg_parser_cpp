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
    This is just any string without name.<br>
    For example: "April" is unnamed argument.<br>
2) Named arguments<br>
    This is string parameter, which has unique name.<br>
    Name of argument (key) starts with single minus (-).<br>
    For example: "-month April" is named argument.<br>
3) Named arrays<br>
    This is sequence of strings, which has unique name.<br>
    Name of array (key) starts with double minus (--)<br>
    For example: "--months March April May June" is array of strings.<br>
<br>
<br>
Parser also supports escaping characters:<br>
    quotes: (\') and (\")<br>
    newline character: (\n)<br>
    Backslash: (\\)<br>
    And space: (\ )<br>
    <br>
    (Inside single quotes escape-characters are ignored).<br>
<br>
Arguments are separated with spaces.<br>
If you need string, which includes spaces, you can put<br>
it into double-quotes ( " - supports escaping)<br>
or in single-quotes ( ' - without escaping)<br>
<br>
You also can combine different types in one string.<br>
<br>
Example:<br>
    Arguments line is:<br>
    arg1 arg2 arg\ 3   -key1 'Value 1' arg4 -Key2 "Value 2" -singlequotes 'one newline1 -><br>
    two, double quote """' -doublequotes "double quote \" newline2 ->\n++" --some_array oc <br>
    toc perevertoc 'A B C D' -key3 value3 😄😄 😄😄😄😄<br>
<br>
  <br>
  Arguments line will be parsed this way:<br>
  <br>
  All arguments:<br>
        arg1<br>
        arg2<br>
        arg 3<br>
        -key1<br>
        Value 1<br>
        arg4<br>
        -Key2<br>
        Value 2<br>
        -singlequotes<br>
        one newline1 -><br>
      two, double quote """<br>
        -doublequotes<br>
        double quote " newline2 -><br>
      ++<br>
        --some_array<br>
        oc<br>
        toc<br>
        perevertoc<br>
        A B C D<br>
        -key3<br>
        value3<br>
        😄😄<br>
        😄😄😄😄<br>
  Unnamed arguments:<br>
        arg1<br>
        arg2<br>
        arg 3<br>
        arg4<br>
        😄😄<br>
        😄😄😄😄<br>
  Named arguments:<br>
        key1 => Value 1<br>
        Key2 => Value 2<br>
        doublequotes => double quote " newline2 -><br>
      ++<br>
        key3 => value3<br>
        singlequotes => one newline1 -><br>
      two, double quote """<br>
  Named arrays:<br>
        some_array => <br>
                oc<br>
                toc<br>
                perevertoc<br>
                A B C D<br>
<br>
