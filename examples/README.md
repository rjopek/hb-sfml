# Getting started

* [Harbour programming language](https://en.wikipedia.org/wiki/Harbour_(programming_language))
* [Homepage](https://harbour.github.io)
* Select your Harbour:
   - [hb30](https://sourceforge.net/projects/harbour-project/files/)
   - [hb32](https://github.com/harbour/core)
   - [hb34](https://github.com/vszakats/harbour-core)

# Installing on Windows

### Install SFML

Download [CSFML](https://github.com/SFML/CSFML/releases/tag/2.5) binary archive from this page and unpack in the directory:

```
c:\SFML\bin *.dll
c:\SFML\include *.h
c:\SFML\lib *.a
```

### install hb-sfml

Environment Variables

```
set HB_WITH_SFML=c:\SFML\include
set PATH=c:\SFML\bin;%path%
```

Clone an existing repository only fetching the 10 most recent commits on the default branch (useful to save time):

```
git clone --depth 10 https://github.com/rjopek/hb-sfml
cd hb-sfml
hb-sfml>hbmk2 hbsfml.hbp
```

To test it, type:

```
hb-sfml\examples\harbour\tutorial>hbmk2 tutorial_01.prg
```

---

[Edit me](https://github.com/rjopek/hb-sfml/edit/main/examples/README.md)
