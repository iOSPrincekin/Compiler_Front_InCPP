//
// Created by LEE on 4/12/20.
//

#include <iostream>

#include "Lexer.h"
#include "../symbols/Type.h"
#include "Num.h"
#include "Real.h"


Lexer::Lexer(){
    setup();
}

void Lexer::setup() {

    reserve(  new Word("if",    Tag::IF)    );
    reserve(  new Word("else",  Tag::ELSE)  );
    reserve(  new Word("while", Tag::WHILE) );
    reserve(  new Word("do",    Tag::DO)    );
    reserve(  new Word("break", Tag::BREAK) );

    reserve( Word::_True );  reserve( Word::_False );

    reserve( Type::Int  );  reserve( Type::Char  );
    reserve( Type::Bool );  reserve( Type::Float );


}

Lexer::Lexer(string file_path) {
    setup();
    file_in = fstream(file_path.c_str());

    if(file_in.fail())
    {
        cerr << "Could not open \""<< file_path << "\""
             << ":reason " << strerror(errno)
             << endl;
        exit(1);
    }
    else
    {
        cout << "File opened successfully." << endl;

    }

}
void Lexer::reserve(Word* w) {
    words.put(w->lexeme,w);
}




void Lexer::readch() {
    file_in >> noskipws >> peek;
   // peek = file_in.peek();
    if (true == file_in.eof()) {
   //     cout << "==--==" << endl;
    }else {
     //   cout << peek << endl;
    }
}

bool Lexer::readch(char c) {
    readch();
    if (peek != c) return false;
    peek = ' ';
    return true;
}
Token* Lexer::scan() {
    for (; ;readch()) {
        if(true == file_in.eof()) break;
        else if (peek == ' ' || peek == '\t') continue;
        else if (peek == '\n') line = line + 1;
        else break;
    }

    switch (peek)
    {
        case '&':
            if (readch('&')) return Word::_and; else return new Token('&');
        case '|':
            if (readch('|')) return Word::_or;  else return new Token('|');
        case '=':
            if (readch('=')) return Word::_eq; else return new Token('=');
        case '!':
            if (readch('=')) return Word::_ne; else return new Token('!');
        case '<':
            if (readch('=')) return Word::_le; else return new Token('<');
        case '>':
            if (readch('=')) return Word::_ge; else return new Token('>');
    }

    if (isdigit(peek))
    {
        int v = 0;
        do{
            v = 10*v + peek - '0'; readch();

        }while (isdigit(peek));
        if (peek != '.') return new Num(v);
        float x = v; float d = 10;
        for(;;)
        {
            readch();
            if (!isdigit(peek))break;
            x = x + (peek-'0') / d ; d = d* 10;
        }
        return new Real(x);
    }

    if(isalpha(peek)){
        string b;
        do{
            b += peek; readch();
        }while (isalnum(peek));

        if(words.get(b) != NULL) {
            return static_cast<Word *>(words.get(b));

        }
        Word *w = new Word(b,Tag::ID);
        words.put(b,w);
        return w;
    }
    Token *tok = new Token(peek); peek = ' ';
    return tok;
}
