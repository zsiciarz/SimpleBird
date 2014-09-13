var config = new Object;

config.run = function() {
    console.log("--- Accuracy research ---");

    console.log("\n\n***Initializing...");
    var dict = new Dictionary();
    dict.sendMessage.connect(console.log);
    var recognizer = new Recognizer();
    recognizer.sendMessage.connect(console.log);
    var analyzer = new Analyzer();
    recognizer.sendMessage.connect(analyzer, "findAccuracy");

    console.log("\n\n***Starting measurements...");

    var windows = ["Rectangular", "Hamming", "Hann", "Blackman", "Barlett", "Flat-top"];
    for (frameLength = 19; frameLength <= 20; frameLength++)
    {
        for (w in windows)
        {
            settings.frameLength = frameLength;
            settings.windowType = windows[w];
            settings.save();
            measureAccuracy(dict, recognizer, analyzer);
        }
    }

    console.log("\n\n***Measurements finished, creating report...");
    console.log(analyzer.getReport());

    restoreSettings();
    dict.rebuild();
}

function Analyzer()
{
    this.data = new Array;

    this.currentKey = -1;

    this.setKey = function(key) {
        this.currentKey++;
        this.data[this.currentKey] = new Object;
        this.data[this.currentKey]["settings"] = key;
    };

    this.setDuration = function(duration) {
        this.data[this.currentKey]["duration"] = duration;
    };

    this.findAccuracy = function(message) {
        if (message.match(/>>>/))
        {
            this.data[this.currentKey]["accuracy"] = parseFloat(message.substr(3));
        }
    };

    this.getReport = function() {
        var report = "\n---Settings---------------Accuracy---Duration---\n";
        for (i in this.data)
        {
            report += this.data[i].settings + "     |  " +
                      this.data[i].accuracy +
                      "     |  " + (this.data[i].duration / 1000.0);
        report += "\n------------------------------------------------\n";
        }

        return report;
    };
}

function settingsAsKey()
{
    return "FL" + settings.frameLength + "_WIN" + settings.windowType;
}

function restoreSettings()
{
    settings.frameLength = 20;
    settings.windowType = "Hamming";
    settings.save();
}

function measureAccuracy(dict, recognizer, analyzer)
{
    start = new Date();
    analyzer.setKey(settingsAsKey());
    dict.rebuild();
    recognizer.recognizeFiles("L:\\_ptaki\\ziemba\\zbior_testowy", "zięba");
    stop = new Date();
    analyzer.setDuration(stop - start);
}
