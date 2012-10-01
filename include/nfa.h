#ifndef NFA_H
#define NFA_H

/*
 *  include/nfa.c
 *  
 *  This file contains the interface of my nfa, it contains:
 *
 *    NState:         the interface of nfa state
 *    NStateFrag      the interface of nfa state fragment (nfa frag)
 *    NFA:            the interface of nfa
 *
 */  

#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

class DFA;

struct NState {
  NState();
  NState(vector<NState*>& v, int c=0, NState* out1=NULL, NState* out2=NULL);

  enum StateTag {LAMBDA=-1, END=0};

  int c;         // char to enter this state
  int flag;      // travel flag
  NState*  out1; // out1
  NState* out2;  // out2
  int index;     // index of the state vector
  int out_num;
};

struct NStateFrag {
  NStateFrag();
  NStateFrag(NState* start, NState** out1, NState** out2=NULL);

  NState* start;   // point to the Start
  NState** out1;   // point to the State's out addrees
  NState** out2;   // point to the State's out address

  void connect_state(NState* state);
};

struct DState {
  DState(){}
  DState(set<int> i):identifier(i), is_end(false){}

  set<int> identifier;
  map<int, set<int> > next_states;
  bool is_end;
};

class NFA {
  public:
    typedef void (* travel_func)(NState * state);

    // create nfa from postfix expression
    static NFA* post2nfa(string postfix);
    static set<int> get_lambda(NState* state);
    set<int> get_lambda(set<int> states);
    
    virtual ~NFA();
    // traval states in the NFA
    void nfa_travel(travel_func func);
    void print_all();
    DFA* construct_DFA();
  private:
    NState _start;
    vector<NState*> _states;

    void _nfa_travel(NState* state, travel_func func); 
    //set<int> _get_lambda(NState* state);

};


#endif
