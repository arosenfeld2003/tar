# Welcome to My Tar
***

## Task
Build a replica of the Linux method `tar` in C.
-c Create a new archive containing the specified items.
-r Like -c, but new entries are appended to the archive. The -f option is required.
-t List archive contents to stdout.
-u Like -r, but new entries are added only if they have a modification date newer 
than the corresponding entry in the archive. The -f option is required.
-x Extract to disk from the archive. 
If a file with the same name appears more than once in the archive, 
each copy will be extracted, with later copies overwriting (replacing) earlier copies.
In -c, -r, or -u mode, 
each specified file or directory is added to the archive 
in the order specified on the command line. 
By default, the contents of each directory are also archived.

## Description
-- WHAT IS IN A TAR ARCHIVE?
- TAR archives concatenate files and their metadata (permissions, ownership, timestamps, etc.)
into a single stream of bytes, which makes them suitable for sequential access.

## Installation
TODO - How to install your project? npm install? make? make re?

## Usage
TODO - How does it work?
```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
