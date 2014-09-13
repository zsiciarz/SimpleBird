var config = new Object;

config.run = function() {
    console.log("--- Recognizing test ---");

    var recognizer = new Recognizer();
    recognizer.sendMessage.connect(console.log);

    recognizer.recognizeFile("L:\\_ptaki\\ziemba\\zbior_testowy\\L_ZT_z_3min_43410_344120ms.wav");
}
