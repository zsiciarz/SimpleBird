WaveFile.prototype.showProperties = function() {
    console.log("Loaded file: " + this.filename);
    console.log("Length: " + this.audioLength + " ms");
    console.log("Channels: " + (this.channels == 1 ? "mono" : "stereo"));
    console.log("Sample frequency: " + this.sampleFrequency);
    console.log("Frames count: " + this.framesCount);
    console.log("Samples per frame: " + this.samplesPerFrame);
};

var config = new Object;
config.run = function() {
    settings.frameLength = 15;
    settings.save();
    var wav = new WaveFile();
    wav.load("L:\\ptaki\\bak2.wav");
    wav.showProperties();

    settings.frameLength = 20;
    settings.save();
    console.log("***Frame length changed to " + settings.frameLength + " ms");

    wav.recalculate();
    wav.showProperties();
};
