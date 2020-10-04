#include "NBA.h"
#include "NBA_db.h"
#include "result.h"
#include<fstream>

//Construtor
NBA::NBA(): WestChampion(""),EastChampion(""),mvpName(""),mvpTeam(""){}
NBA::NBA(std::string w_Champ,std::string e_Champ,std::string m_Name,std::string m_Team):
 WestChampion(w_Champ),
 EastChampion(e_Champ),
 mvpName(m_Name),
 mvpTeam(m_Team){}


 // Getters
    std::string NBA::getWestChampion(){
        return WestChampion;
    }
    std::string NBA::getEastChampion(){
        return EastChampion;
    }
    std::string NBA::getmvpName(){
        return mvpName;
    }
    std::string NBA::getmvpTeam(){
        return mvpTeam;
    }
/*    int main()
    {
         std::list<Result> stats;
         ifstream nba("NBA Finals and MVP.csv");

         if(!nba.is_open()) std::cout << "ERROR: File Open" << '\n';

         std::string WestChampion;
         std::string EastChampion;
         std::string mvpName;
         std::string mvpTeam;
         std::string year;
         std::string WScore;
         std::string EScore;
         int Year;
         int WestScore;
         int EastScore;

         while(nba.good()){

            getline(nba,WestChampion,',');
            getline(nba,EastChampion,',');
            getline(nba,mvpName,',');
            getline(nba,mvpTeam,',');
            getline(nba,year,',');
            getline(nba,WScore,',');
            getline(nba,EScore,',');
            Year=stoi(year);
            WestScore=stoi(WScore);
            EastScore=stoi(EScore);

            if(WestChampion!="")
                stats.addStats(WestChampion,EastChampion,mvpName,mvpTeam,Year,WestScore,EastScore);
        }

            nba.close();
        return 0;
    }
*/

