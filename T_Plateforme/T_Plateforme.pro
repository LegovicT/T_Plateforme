TEMPLATE += app
QT+= core gui sensors qml widgets network quick gamepad opengl    #3dcore 3drender 3dinput 3dlogic 3dextras 3danimation 3dquick 3dquickextras 3dextras
# declarative
CONFIG += c++11 mobility resources_big
LIBS   += -lopengl32
LIBS   += -lglu32
#LIBS   += -lglut32
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = T_Plateforme

target.path = $$[QT_INSTALL_EXAMPLES]/qt3d/$$TARGET
INSTALLS += target
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    RftG/TiGameWindow.cpp \
    RftG/TiPlayer.cpp \
    main.cpp \
    communication.cpp \
    #LWG
    LWG/LWGmainwindow.cpp \
    LWG/AbstractModul.cpp \
    LWG/TechnomanAbstractWheel.cpp \
    LWG/TechnomanAppendage.cpp \
    LWG/TechnomanBody.cpp \
    LWG/TechnomanCore.cpp \
    LWG/TechnomanFoot.cpp \
    LWG/TechnomanShield.cpp \
    #RftG
    RftG/RftGmainwindow.cpp \
    RftG/RftGSelectionMenu.cpp \
    RftG/TiArena.cpp \
    RftG/TiCharacter.cpp \
    RftG/TiDoodad.cpp \
    RftG/TiEffects.cpp \
    #RftG/TiAnimations.cpp \
    #RftG/TiSprite.cpp
    #MTD
    MTD/MTDMainWindow.cpp \
    MTD/TiAmelioration.cpp \
    MTD/TiAngel.cpp \
    MTD/TiBattleField.cpp \
    MTD/TiBiochemist.cpp \
    MTD/TiBuilder.cpp \
    MTD/TiBuilding.cpp \
    MTD/TiCharacterMTD.cpp \
    MTD/TiCraftman.cpp \
    MTD/TiCurator.cpp \
    MTD/TiDecoration.cpp \
    MTD/TiDestructor.cpp \
    MTD/TiDruid.cpp \
    MTD/TiElement.cpp \
    MTD/TiElementary.cpp \
    MTD/TiField.cpp \
    MTD/TiGunner.cpp \
    MTD/TiHealer.cpp \
    MTD/TiInquisitor.cpp \
    MTD/TiItem.cpp \
    MTD/TiJagger.cpp \
    MTD/TiKnight.cpp \
    MTD/TiMachinist.cpp \
    MTD/TiMainField.cpp \
    MTD/TiMonk.cpp \
    MTD/TiPlayerMTD.cpp \
    MTD/TiPriest.cpp \
    MTD/TiRepairer.cpp \
    MTD/TiShaman.cpp \
    MTD/TiSorcerer.cpp \
    MTD/TiSpecialist.cpp \
    MTD/TiSummoner.cpp \
    MTD/TiTank.cpp \
    MTD/TiTechnic.cpp \
    MTD/TiTitan.cpp \
    MTD/TiUltimate.cpp \
    MTD/TiUnit.cpp

HEADERS += \
    RftG/TiGameWindow.h \
    RftG/TiPlayer.h \
    communication.h \
    #LWG
    LWG/LWGmainwindow.h \
    LWG/AbstractModul.h \
    LWG/TechnomanAbstractWheel.h \
    LWG/TechnomanAppendage.h \
    LWG/TechnomanBody.h \
    LWG/TechnomanCore.h \
    LWG/TechnomanFoot.h \
    LWG/TechnomanShield.h \
    #RftG
    RftG/RftGmainwindow.h \
    RftG/RftGSelectionMenu.h \
    RftG/TiArena.h \
    RftG/TiCharacter.h \
    RftG/TiDoodad.h \
    RftG/TiEffects.h \
    #RftG/TiAnimations.h \
    #RftG/TiSprite.h
    #MTD
    MTD/MTDMainWindow.h \
    MTD/TiAmerlioration.h \
    MTD/TiAngel.h \
    MTD/TiBattleField.h \
    MTD/TiBiochemist.h \
    MTD/TiBuilder.h \
    MTD/TiBuilding.h \
    MTD/TiCharacterMTD.h \
    MTD/TiCraftman.h \
    MTD/TiCurator.h \
    MTD/TiDecoration.h \
    MTD/TiDestructor.h \
    MTD/TiDruid.h \
    MTD/TiElement.h \
    MTD/TiElementary.h \
    MTD/TiField.h \
    MTD/TiGunner.h \
    MTD/TiHealer.h \
    MTD/TiInquisitor.h \
    MTD/TiItem.h \
    MTD/TiJagger.h \
    MTD/TiKnight.h \
    MTD/TiMachinist.h \
    MTD/TiMainField.h \
    MTD/TiMonk.h \
    MTD/TiPlayerMTD.h \
    MTD/TiPriest.h \
    MTD/TiRepairer.h \
    MTD/TiShaman.h \
    MTD/TiSorcerer.h \
    MTD/TiSpecialist.h \
    MTD/TiSummoner.h \
    MTD/TiTank.h \
    MTD/TiTechnic.h \
    MTD/TiTitan.h \
    MTD/TiUltimate.h \
    MTD/TiUnit.h

TRANSLATIONS += \
    T_Plateforme_fr_FR.ts

DISTFILES += \
    #gamepadQml
    SRC/qml/Authentifier.qml \
    SRC/qml/Browser.qml \
    SRC/qml/ButtonImage.qml \
    SRC/qml/DPad.qml \
    SRC/qml/JoystickViewer.qml \
    SRC/qml/LeftThumbstick.qml \
    SRC/qml/RightThumbstick.qml \
    SRC/qml/main.qml \
    #quick3D
#    SRC/OBJ/main.qml \
#    SRC/OBJ/QuadViewportFrameGraph.qml \
#    SRC/OBJ/SimpleCamera.qml \
#    SRC/OBJ/test_scene.dae \
#    SRC/OBJ/Gear_scene.dae

RESOURCES += \
