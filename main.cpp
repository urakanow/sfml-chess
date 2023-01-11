#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const string types[7] = { "king", "queen", "bishop", "horse", "rook", "pawn" , "empty" };
class Figure {
public:
    
    int type;
    int side;//white is 0
    string position;//like e2

    Figure() {}
    void add(string type, int side, string pos) {
        this->side = side;
        this->position = pos;
        for (int i = 0; i < 6; i++) {
            if (types[i] == type) {
                this->type = i;
                break;
            }
        }

    }

    vector<string>& CalculateMoves() {//{"e3" "e4"} etc.

    }
};
class Field{
public:
    Figure board[8][8];

    Field() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
            {
                board[j * 7][abs(i * 7 - 0)].add("rook", 1 - j, (char)(97 + abs(i * 7 - 0)) + to_string((1 - j) * 7 + 1));
                board[j * 7][abs(i * 7 - 1)].add("horse", 1 - j, (char)(97 + abs(i * 7 - 1)) + to_string((1 - j) * 7 + 1));
                board[j * 7][abs(i * 7 - 2)].add("bishop", 1 - j, (char)(97 + abs(i * 7 - 2)) + to_string((1 - j) * 7 + 1));
                
            }
            board[i * 7][3].add("queen", 1 - i, (char)(100) + to_string((1 - i) * 7 + 1));
            board[i * 7][4].add("king", 1 - i, (char)(101) + to_string((1 - i) * 7 + 1));
            for (int k = 0; k < 8; k++)
            {
                board[1 + 5 * i][k].add("pawn", 1 - i, (char)(97 + k) + to_string((1 - i) * 7 + 1));
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board[2 + i][j].add("empty", -1, (char)(97 + j) + to_string((5 - i) + 1));
            }
        }
    }
};
int main() {
    RenderWindow app(VideoMode(400, 400), "chess");
    //app.setFramerateLimit(60);

    Texture t1, t2;
    t1.loadFromFile("images/board.png");

    t2.loadFromFile("images/figures.png");

    Sprite figure(t2);

    Sprite background(t1);
    background.setTextureRect(IntRect(100, 100, 900, 900));
    background.scale(0.5f, 0.5f);

    Field field;
    while (app.isOpen()) {
        //app.clear();
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();

        }
        app.draw(background);
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                Figure f = field.board[i][j];
                if (f.type != 6) {
                    figure.setTextureRect(IntRect(50 * f.type, f.side * 50, 50, 50));
                    //figure.scale(0.5f, 0.5f);
                    //figure.setColor(Color(255, 255, 255, p.alpha));
                    figure.setPosition(j * 50, i * 50);
                    //gems.move(offset.x - ts, offset.y - ts);
                    cout << i << j << endl;
                    app.draw(figure);
                }
                
            }

        app.display();
    }

        //app.display();
    
}