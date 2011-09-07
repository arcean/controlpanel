import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: rootWindow

    initialPage: ListPage { }

    Component.onCompleted: {
        theme.inverted = true;
        screen.allowedOrientations = Screen.Portrait;
    }

    rotation: 90
}

