Liturgy of the Hours for iOS
============================

This project contains the iOS app for
[Liturgia-hodin-online](https://github.com/breviar-sk/Liturgia-hodin-online)
created by [Juraj Vidéky](https://github.com/breviar-sk/).

The application is available for the following languages:

- [Slovak](https://itunes.apple.com/us/app/breviar/id818787573?mt=8) (web version: [http://breviar.sk](http://breviar.sk))
- [Czech](https://itunes.apple.com/us/app/breviar/id818790371?mt=8) (web version: [http://ebreviar.cz](http://ebreviar.cz))
- [Hungarian](https://itunes.apple.com/us/app/zsolozsma/id818769806?mt=8) (web version: [http://zsolozsma.katolikus.hu](http://zsolozsma.katolikus.hu))

Getting started
===============

This repository contains only the iOS sources, so in order to get started you
have to fetch the rest of the files from various places.

First, clone this repository:

    git clone https://github.com/gyim/breviar-ios.git

This project uses the sources of the web version as a submodule. However, this
repository is not public, only some parts of it (unless you join the core
team). To obtain the public sources you have to do the following:

    # Fetch the public sources
    cd breviar-ios
    git clone https://github.com/breviar-sk/Liturgia-hodin-online.git breviar-cgi
    
    # Fetch the text from the websites:
    cd breviar-cgi
    wget -r http://breviar.sk/include -nd -P include
    wget -r http://breviar.sk/include_cz -nd -P include_cz
    wget -r http://breviar.sk/include_hu -nd -P include_hu

