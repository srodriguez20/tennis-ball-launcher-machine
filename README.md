# tennis-ball-launcher-machine

Este es el repositorio de código que podemos usar para compartirnos los archivos del proyecto.

## Diagrama de Circuitos:

Encontre este aplicación web que podemos usar para dibujar y planear como va a quedar el ciruito del Robot:

https://app.cirkitdesigner.com/project/5e583946-ec0f-4e64-9766-b30a853e2492

## Codigo:

Cree por ahora un archivo main.ino que contiene todo el codigo esqueleto del robot.
Trate de hacerlo por ahora lo mas simple y entendible para que partamos de esa base.

Vas a ver que en el código cree una clase por separado de lanzador de bolas para que cuando lo usemos sea mas entendible que la intención es lanzar una bola mas allá de solo ajustar la velocidad de los motores.

También le agregue un buzzer para que haga un ruidito antes de lanzar la bola jaja.

Por ahora solo hay un archivo main.ino que contiene todo el código pero mas adelante podemos organizar el proyecto así:


```
src/
  main.cpp
  ball_launcher/
    BallLauncher.h
    BallLauncher.cpp
  buzzer/
    Buzzer.h
    Buzzer.cpp
include/
lib/
```

## Notas:

En el diagrama puse un modulo `motor driver` que no es exactamente el mismo que tu tienes pero sirve para el ejemplo.

Creo que el modulo que tu tienes es parecido al DBH-1A y creo que nos puede servir pero caí en cuanta de que habías cambiado por adaptadores de 24V. Ese modulo creo que solo funciona hasta 12V.

Encontré que podemos usar un modulo bts7960 que ese si aguanta hasta 27V. Nos tocaría buscar donde los podemos comprar pero vi que es muy común.
