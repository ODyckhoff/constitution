Constitution
============

*A web framework written in C*

Why?
----

Because:
 * Fast as blazes.
 * Minimalistic.
 * Fine grained control over memory management.
 * Bindings for **all** the things!
 * Why not?

Status
------

This project currently only has this README file. Keep an eye out for the codebase expanding, and please report any issues (potential or real) that you spot.

Testing so far
--------------

You can currently test this program as is, using the example views "index.c" or "help.c". Simply cd to the directory you dumped this lot in, and run this command: `make`

and it will take care of compiling all the necessary bits to make the dispatcher work. Now run either:
    `export QUERY_STRING=index`

or:
    `export QUERY_STRING=help`

to set the query string, then type `./cnstn_exec` and you will be greeted with some placeholder text letting you know that the correct function was dispatched.

Thanks!
*Owen R. Dyckhoff*
