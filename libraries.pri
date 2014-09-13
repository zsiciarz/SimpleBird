# BOOST
win32 {
    INCLUDEPATH += F:\boost_1_41_0
}

# QWT
win32 {
    INCLUDEPATH += F:\Qwt\include
    DEFINES += QWT_DLL
    LIBS += -LF:\Qwt\lib
    CONFIG(debug, debug|release):LIBS += -lqwtd5
    CONFIG(release, debug|release):LIBS += -lqwt5
}
unix {
    INCLUDEPATH += /usr/include/qwt-qt4
    LIBS += -lqwt-qt4
}

# AQUILA
win32 {
    INCLUDEPATH += F:\aquila\include
    DEFINES += AQUILA_DLL
    LIBS += -LF:\aquila\lib
    CONFIG(debug, debug|release):LIBS += -laquilad2
    CONFIG(release, debug|release):LIBS += -laquila2
}
unix {
    INCLUDEPATH += /usr/include/aquila
    LIBS += -L/usr/lib/aquila
    LIBS += -laquila
}
