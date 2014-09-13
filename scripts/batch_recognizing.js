var config = new Object;

config.run = function() {
    console.log("--- Batch recognizing ---");

    var recognizer = new Recognizer();
    recognizer.sendMessage.connect(console.log);

    recognizer.recognizeFiles("L:\\_ptaki\\ziemba\\zbior_testowy", "zięba");
}
