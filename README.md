# Filler
This project at UNIT Factory (School 42) is about creating a bot player that plays with another bots.

Game managed by Virtual Machine that gives random tokens to players and takes answers from players (coordinates where bot want to put token).

Game stops for bot who cannot allocate given token.

When both players cannot allocate given token, game stops, VM counts total score and it's game over.

![alt text](https://github.com/oleksiirude/Filler/blob/master/img/map02.png)

Usage example without visualization: ./filler_vm -p1 ./[bot_name] -p2 ./[bot_name] -f ./[map]

![alt text](https://github.com/oleksiirude/Filler/blob/master/img/map00.png)

Usage example with visualization: ./filler_vm -p1 ./[bot_name] -p2 ./[bot_name] -f ./[map] | ./vizo

![alt text](https://github.com/oleksiirude/Filler/blob/master/img/map01.png)

For detailed info and task requirement you can check Subject pdf.

Project is done in accordance with school norms (you can see them in Norme pdf).

Have fun!
