#include <stdio.h>
#include <ncurses.h>

int main() {
    initscr();
    raw();
    keypad(stdscr, TRUE);

    int voto, win = 0, unixVotos = 0, linuxVotos = 0, netVotos = 0, macVotos = 0, outroVotos = 0, contVotos = 0, contWin, contUnix, contLinux, contNet, contMac, contOut, restart = 0;

    do {
        clear();
        refresh();
        voto = 7;
        curs_set(1);
        mvprintw(1, 3, "===Bem vindo à nossa votação===");
        mvprintw(3, 0, "Por favor insira apenas valores entre 0 e 6, sendo 0 para encerrar a votação e de 1 a 6 para votar");
        mvprintw(4, 0, "Deseja votar em qual sistema?\n1-Windows\n2-Unix\n3-Linux\n4-Netware\n5-Mac Os\n6-Outros\n0-Encerrar Votação\n\n");
        scanw("%d", &voto);

        switch (voto) {
            case 1:
                win = win + 1;
                contVotos = contVotos + 1;
                break;
            case 2:
                unixVotos = unixVotos + 1;
                contVotos = contVotos + 1;
                break;
            case 3:
                linuxVotos = linuxVotos + 1;
                contVotos = contVotos + 1;
                break;
            case 4:
                netVotos = netVotos + 1;
                contVotos = contVotos + 1;
                break;
            case 5:
                macVotos = macVotos + 1;
                contVotos = contVotos + 1;
                break;
            case 6:
                outroVotos = outroVotos + 1;
                contVotos = contVotos + 1;
                break;
            case 0:
                clear();
                refresh();

                contWin = win * 100 / contVotos;
                contUnix = unixVotos * 100 / contVotos;
                contLinux = linuxVotos * 100 / contVotos;
                contNet = netVotos * 100 / contVotos;
                contMac = macVotos * 100 / contVotos;
                contOut = outroVotos * 100 / contVotos;

                mvprintw(1, 0, "===Votação encerrada===");                
                mvprintw(3, 0, "O resultado das votações são:");
                mvprintw(5,0, "Ao todo foram %d votos", contVotos);
                mvprintw(7, 0, "Windows teve %d%% dos votos", contWin);
                mvprintw(8, 0, "Unix teve %d%% dos votos", contUnix);
                mvprintw(9, 0, "Linux teve %d%% dos votos", contLinux);
                mvprintw(10, 0, "Netware teve %d%% dos votos", contNet);
                mvprintw(11, 0, "Mac Os teve %d%% dos votos", contMac);
                mvprintw(12, 0, "Outros sistemas tiveram %d%% dos votos", contOut);

                mvprintw(14, 0, "Para sair pressione qualquer tecla...");
                refresh();
                getch();
                endwin();
                return 0;

            default:
                clear();
                refresh();
                mvprintw(1, 0, "Valor incorreto por favor insira um valor válido.");
                mvprintw(2,0, "Pressione qualquer tecla para voltar a tela de votação.");
                getch();
                break;
        }
    } while (restart == 0);
}
