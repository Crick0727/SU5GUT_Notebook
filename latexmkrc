#!/usr/bin/env perl
@default_files = ("main.tex");
$latex          = 'platex -synctex=1 -halt-on-error';
$latex_silent   = 'platex -synctex=1 -halt-on-error -interaction=batchmode';
$dvipdf         = 'dvipdfmx %O -o %D %S';
$bibtex         = 'bibtex';

