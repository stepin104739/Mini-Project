#include <iostream>
#include <fstream>
#include"NBA.h"
#include"result.h"
#include"NBA_db.h"
#include <gtest/gtest.h>

class NBAListDbTest : public ::testing::Test {

protected:
  void SetUp() {
    std::ifstream nba("NBA1.csv");

         if(!nba.is_open()) std::cout << "ERROR: File Open" << '\n';

         std::string WestChampion;
         std::string EastChampion;
         std::string mvpName;
         std::string mvpTeam;
         std::string year;
         std::string WScore;
         std::string EScore;

         while(nba.good()){

            getline(nba,WestChampion,',');
            getline(nba,EastChampion,',');
            getline(nba,mvpName,',');
            getline(nba,mvpTeam,',');
            getline(nba,year,',');
            getline(nba,WScore,',');
            getline(nba,EScore,',');
            int Year=atoi(year.c_str());
            int WestScore=atoi(WScore.c_str());
            int EastScore=atoi(EScore.c_str());

            if(WestChampion!="")
            n1.addStats(WestChampion, EastChampion, mvpName, mvpTeam, Year, WestScore, EastScore);
        }
  }
  void TearDown() {}
  NBADatabase n1;
};

TEST_F(NBAListDbTest, AddStats)
{
  n1.addStats("GSW","Cleveland","Steph","GSW",2019,4,0);
  EXPECT_NE((Result*)NULL, n1.findStatsByYear(2019));
  EXPECT_EQ(61,n1.countAll());
}

TEST_F(NBAListDbTest, RemoveStats)
{
  n1.removeStats(2010);
  EXPECT_EQ(NULL, n1.findStatsByYear(2010));
  EXPECT_EQ(60, n1.countAll());
}

TEST_F(NBAListDbTest, CountMvpbyTeams)
{
  EXPECT_EQ(5, n1.countMvpbyTeams("Boston Celtics"));
}

TEST_F(NBAListDbTest, CountWestChampionshipsForTeam)
{
  EXPECT_EQ(0, n1.countWestChampionshipsForTeam("Utah Jazz"));
}
