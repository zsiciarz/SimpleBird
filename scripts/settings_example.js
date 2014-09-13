var config = new Object;

config.run = function() {
    console.log("--- enumerating settings accessible to script ---");

    for (var s in settings)
    {
        var value = settings[s].toString();

        // print only simple properties, not methods
        if (!value.match(/function/))
            console.log(s + ": " + settings[s]);
    }
};
