# Arg_parser_cpp

Arg_parser class

This class is designed for parsing command-line string from user.
Warning!!! This code works with solid string, not with arguments-array (argv**).

You can create Arg_parser object and put string with command in it's constructor.
Example:
Arg_parser parser("-day 22 -month April");

Syntax of arguments-line is provided not in "canonical" UNIX argument-line style, but has some features.

Arg_parser supports 3 types of data:
1) Unnamed arguments
    This is just any string without name.
    For example: "April" is unnamed argument.
2) Named arguments
    This is string parameter, which has unique name.
    Name of argument (key) starts with single minus (-).
    For example: "-month April" is named argument.
3) Named arrays
    This is sequence of strings, which has unique name.
    Name of array (key) starts with double minus (--)
    For example: "--months March April May June" is array of strings.


Parser also supports escaping characters:
    quotes: (\') and (\")
    newline character: (\n)
    Backslash: (\\)
    And space: (\ )
    
    (Inside single quotes escape-characters are ignored).

Arguments are separated with spaces.
If you need string, which includes spaces, you can put
it into double-quotes ( " - supports escaping)
or in single-quotes ( ' - without escaping)

You also can combine different types in one string.

Example:
    Arguments line is:
    arg1 arg2 arg\ 3   -key1 'Value 1' arg4 -Key2 "Value 2" -singlequotes 'one newline1 ->
    two, double quote """' -doublequotes "double quote \" newline2 ->\n++" --some_array oc 
    toc perevertoc 'A B C D' -key3 value3 😄😄 😄😄😄😄

  
  Arguments line will be parsed this way:
  
  All arguments:
        arg1
        arg2
        arg 3
        -key1
        Value 1
        arg4
        -Key2
        Value 2
        -singlequotes
        one newline1 ->
      two, double quote """
        -doublequotes
        double quote " newline2 ->
      ++
        --some_array
        oc
        toc
        perevertoc
        A B C D
        -key3
        value3
        😄😄
        😄😄😄😄
  Unnamed arguments:
        arg1
        arg2
        arg 3
        arg4
        😄😄
        😄😄😄😄
  Named arguments:
        key1 => Value 1
        Key2 => Value 2
        doublequotes => double quote " newline2 ->
      ++
        key3 => value3
        singlequotes => one newline1 ->
      two, double quote """
  Named arrays:
        some_array => 
                oc
                toc
                perevertoc
                A B C D
