#ifndef _HAND_TREE_INFO_H_
#define _HAND_TREE_INFO_H_

#include "GenBDTree.h"
#include "Common.h"

class TypicalCards;

class HandTreeInfo
{
public:
  HandTreeInfo(int root_st, int root_bd, int final_st);
  ~HandTreeInfo(void);
  const TypicalCards *Hands(int st, int gbd) const
  {
    int lbd = LocalBoardIndex(st, gbd);
    return hands_[st][lbd];
  }
  int FinalSt(void) const { return final_st_; }
  int RootSt(void) const { return root_st_; }
  int RootBd(void) const { return root_bd_; }
  int LocalBoardIndex(int st, int gbd) const
  {
    return GenBDTree::LocalIndex(root_st_, root_bd_, st, gbd);
  }

private:
  int root_st_;
  int root_bd_;
  int final_st_;
  TypicalCards ***hands_;
};

int HCPIndex(int st, const Card *cards);
int HCPIndex(int st, const Card *board, const Card *hole_cards);

#endif
