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

You can currently test this program as is, using the example views "index.c" or "help.c". Simply cd to your document root and run these commands:

    git clone https://github.com/ODyckhoff/constitution.git
    cd constitution/
    make

Yes, that is really it. Then navigate to the folder in a web browser and you will be greeted with some placeholder text letting you know that the correct function was dispatched. If you visit the index page, it'll give you an error until you put the correct database details in src/dbopts.h.

Remember to run `make` every time you alter any C code.

Thanks!
*Owen R. Dyckhoff*
