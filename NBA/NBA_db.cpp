#include "NBA_db.h"
#include "result.h"

#include <fstream>
#include <list>
#include <iterator>

bool NBADatabase::addStats(std::string w_Champ,std::string e_Champ,std::string m_Name,std::string m_Team,int y,int w,int e)
{
	stats.push_back(Result(w_Champ,e_Champ,m_Name,m_Team,y,w,e));
	return true;
}


bool NBADatabase::removeStats(int y)
{
	std::list<Result> :: iterator iter;

   	for(iter=stats.begin();iter!=stats.end();iter++)
    	{
        	if(iter->getYear()== y)
        	{
                stats.erase(iter);
                return true;
        	}
    	}
    	return false;

}

Result* NBADatabase::findStatsByYear(int y)
{
	std::list<Result> :: iterator iter;

   	for(iter=stats.begin();iter!=stats.end();iter++)
    	{
        	if(iter->getYear()== y)
        	{
           		return &(*iter);
        	}
    	}
    	return NULL;
}

int NBADatabase::countMvpbyTeams(std::string m_Team)
{
	std::list<Result> :: iterator iter;
	int countMVPs=0;

   	for(iter=stats.begin();iter!=stats.end();iter++)
    	{
        	if(iter->getmvpTeam()== m_Team)
        	{
           		++countMVPs;
        	}
    	}
    	return countMVPs;
}

int NBADatabase::countWestChampionshipsForTeam(std::string w_Champ)
{
	std::list<Result> :: iterator iter;
	int countWins=0;

   	for(iter=stats.begin();iter!=stats.end();iter++)
    	{
        	if(iter->getWestChampion()== w_Champ)
        	{
           		++countWins;
        	}
    	}
    	return countWins;
}

int NBADatabase::countEastChampionshipsForTeam(std::string e_Champ)
{
	std::list<Result> :: iterator iter;
	int countWins=0;

   	for(iter=stats.begin();iter!=stats.end();iter++)
    	{
        	if(iter->getEastChampion()== e_Champ)
        	{
           		++countWins;
        	}
    	}
    	return countWins;
}

int NBADatabase::countAll()
{
	return stats.size();
}

int main()
    {
         //std::list<Result> stats;
         std::ifstream nba("NBA Finals and MVP.csv");

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
                bool addStats(std::string, std::string, std::string, std::string, int, int, int);
        }

            nba.close();
        return 0;
    }
