/*************************************************************************
	> File Name: tabtenn.h
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Mar 2017 11:55:24 AM CST
 ************************************************************************/

#ifndef _TABTENN_H
#define _TABTENN_H
class TableTennisPlayer{
private:
    enum {LIM = 20};
    char firstname[LIM];
    char lastname[LIM];
    bool hasTable;
public:
    int i;
    TableTennisPlayer ( const char *fn = "none", const char *ln = "none", bool ht = false );
    void Name() const;
    bool HasTable() const{ return hasTable; };
    void RestTable(bool v) {hasTable = v;};
};

class RatedPlayer: public TableTennisPlayer
{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r = 0, const char * fn = "none", const char *ln = "none", bool hasTable = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
    unsigned int Rating() {return rating;}
    void ResetRating(unsigned int r) { rating = r; }
};
#endif
