function fireEvent(event) {
    return function() {
        window.location = 'event://' + event;
        return true;
    }
}

function pageReady() {
    // Called at the end of <body>
    var links = document.getElementsByTagName('a');
    for (var i=0; i<links.length; i++) {
        var link = links[i];
        link.href = "event://linkTouchStart/" + link.href.split("://")[1];
    }
}
