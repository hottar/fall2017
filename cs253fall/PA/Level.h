/**
 * @file Level.h
 * @brief Keeps tracks on the number of words/letters/sentences.
 *  <br> Which then returns the reading level of a file. </br>
 */

#ifndef LEVEL_H
#define LEVEL_H

#include <string>
using std::string;

/**
 * @brief Class to compute Reading Level
 */
class Level {
public:
    /**
     * @brief Constructor of Reading Level. Parameters @p l, @p w, @p s are optional.
     */
    Level(float l = 0.0, float w = 0.0, float s = 0.0) : letter(l), word(w), sentence(s) {}
    Level(const Level& other) : letter(other.letter), word(other.word), sentence(other.sentence) {}
    ~Level() {reset();}
    inline void reset() { letter = 0.0; word = 0.0; sentence = 0.0; }
    inline void insert(const string& word_p) { ++word; letter += (word_p.front() == '+') ? word_p.size()-1 : word_p.size() ; }
    inline void newline(float s) { sentence += s; }
    /**
     * @return CL(doc) = 0.0588L(doc) – 0.296S(doc) – 15.8
     */
    inline float level() { return 0.0588*Ldoc() - 0.296*Sdoc() - 15.8 ; }
    inline float Ldoc() { return (letter/word) * 100.0; }
    inline float Sdoc() { if(sentence==0.0) throw string("ERROR: The file contains only empty sentences!"); return (sentence/word) * 100.0; }
private:
    float letter;
    float word;
    float sentence;
};

#endif
