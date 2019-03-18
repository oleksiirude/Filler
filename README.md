# Filler
This project at UNIT Factory (School 42) is about creating a bot player that plays with another bots.

![alt text](https://github.com/oleksiirude/Filler/blob/master/img/map02.png)

Game managed by Virtual Machine that takes answers from bot players (coordinates where bot want to put token).

Game stops for bot who gives to VM [0, 0] coordinates.

When both players give zero coordinates, game stops, VM counts total score and it's game over.

For detailed info you can check Subject pdf.

![alt text](https://github.com/oleksiirude/Filler/blob/master/img/map00.png)

Usage example without visualization: ./filler_vm -p1 ./[bot_name] -p2 ./[bot_name] -f ./[map]

![alt text](https://github.com/oleksiirude/Filler/blob/master/img/map01.png)

Usage example with visualization: ./filler_vm -p1 ./[bot_name] -p2 ./[bot_name] -f ./[map] | ./vizo