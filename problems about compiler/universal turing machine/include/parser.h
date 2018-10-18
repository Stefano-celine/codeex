#ifndef PARSER_H
#define PARSER_H


struct Parser
{
    static set<string> gen_set(vector<Token>);
    
    static tuple<tuple<string, char>, tuple<string, char, char>> gen_4delta(vector<Token>);

    static string gen_input(string);
};


#endif // PARSER_H