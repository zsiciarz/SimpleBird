var config = new Object;

config.run = function() {
    console.log("--- Dictionary information ---");

    var dict = new Dictionary();
    dict.sendMessage.connect(console.log);

    console.log("Entries count: " + dict.entriesCount);
    var files = dict.getFiles();
    for (var f in files)
    {
        var file = files[f];
        console.log("File: " + file + ", label: " + dict.findLabel(file));
    }

    console.log("\n***REBUILDING - SINGLE-THREADED***\n");
    dict.rebuild();

    console.log("\n***REBUILDING - MULTI-THREADED***\n");
    dict.rebuild(true);
};
