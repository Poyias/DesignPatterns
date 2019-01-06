#include <iostream>
#include <vector>
using namespace std;
class Subject {
    vector < class Observer * > observers; 
    bool scoredPenalty;                    // trigger, event
public:
    // register observers
    void attach(Observer *obs) {
        observers.push_back(obs);
    }
   
   // This is the EVENT
   // set the if scored and notify ALL observers
   void setScored(bool scored) {
      scoredPenalty = scored;
      notify();
   }
bool getScored() {
      return scoredPenalty;
   }
   // notify implementaion is further down
   // so that the script compiles and runs
   void notify();
};

class Observer 
{
    Subject *subj;
    int excitementLevel;               // state
  public:
    Observer(Subject *mod, int excLevel) 
    {
        subj = mod;
        excitementLevel = excLevel;
        // Observers register/attach themselves with the Subject
        subj->attach(this);
    }
    virtual void update() = 0;
  protected:
    Subject *getSubject() {
       return subj;
    }
    void setExcitementLevel(int excLevel) {
       excitementLevel = excLevel;
    }
    int getExcitementLevel() {
       return excitementLevel;
    }
};

void Subject::notify() {
  for (int i = 0; i < observers.size(); i++)
    observers[i]->update();
}
class Old_ConcreteObserver: public Observer 
{
   public:
     // Calls parent constructor to register with subject
     Old_ConcreteObserver(Subject *mod, int div)
        :Observer(mod, div){}
     // For older people, if the excitement level 
     // is over 150 they run risk of heart attack
     void update() 
     {
        bool scored = getSubject()->getScored(); 
        setExcitementLevel(getExcitementLevel() + 1);
        if (scored && getExcitementLevel() > 150) 
        {
          cout << "Old Observer's team scored!!" 
               << " His excitement level is " 
               << getExcitementLevel() 
               << " watch out of heart attacks!" << endl;
        }else{
          cout << "Team didn't score. Yeeeih nothing to worry about"
               << endl;
        }
    } // end update()
};
class Young_ConcreteObserver: public Observer 
{
   public:
     // Calls parent constructor to register with subject
     Young_ConcreteObserver(Subject *mod, int div)
       : Observer(mod, div){}
     // For older people, if the excitement level 
     // is over 100 they run risk of heart attack
     void update() 
     {
        bool scored = getSubject()->getScored(); 
        setExcitementLevel(getExcitementLevel() + 1);
        if (scored && getExcitementLevel() > 100) 
        {
          cout << "Young Observer's team scored!!" 
               << " His excitement level is " 
               << getExcitementLevel() 
               << " dont't drink and drive!!" << endl;
        }else{
          cout << "Team didn't score. Yeeh nothing to worry about"
               << endl;
       }
    } // end update()
};

int main() {
   Subject subj;
   Young_ConcreteObserver youngPal1(&subj, 100); 
   Old_ConcreteObserver oldPal1(&subj, 150); 
   Young_ConcreteObserver youngPal2(&subj, 52);
   subj.setScored(true);
}
// Output
// Young Observer's team scored!! His excitement level is 101
// dont't drink and drive!! 
// Old Observer's team scored!! His excitement level is 151 watch 
// out of heart attacks! Team didn't score. 
// Yeeh nothing to worry about