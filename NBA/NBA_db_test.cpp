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
            int Year=stoi(year);
            int WestScore=stoi(WScore);
            int EastScore=stoi(EScore);

            if(WestChampion!="")
            n1.addStats(WestChampion, EastChampion, mvpName, mvpTeam, Year, WestScore, EastScore);
        }
  }
  void TearDown() {}
  NBADatabase n1;
};

TEST_F(NBAListDbTest, AddStats) {
  n1.addStats("GSW","Cleveland","Steph","GSW",2019,4,0);
  EXPECT_NE((Result*)NULL, n1.findStatsByYear(2019));
  EXPECT_EQ(70, n1.countAll());
}


/*TEST_F(PassengerListDbTest, RemovePassengerTest) {

  L1.removeTripByPNR(1050);
  EXPECT_EQ(NULL, L1.findPassengerByPNR(1050));
  EXPECT_EQ(50, L1.countNumberOfPassengers());
}

TEST_F(PassengerListDbTest, TotalPassengersFromSource) {


  EXPECT_EQ(6, L1.totalPassengersFromSource("Mumbai"));
  EXPECT_EQ(16, L1.totalPassengersFromSource("Chennai"));

}

TEST_F(PassengerListDbTest, TotalPassengersToADestination) {


  EXPECT_EQ(19, L1.totalPassengersToADestination("Mumbai"));
  EXPECT_EQ(3, L1.totalPassengersToADestination("Chennai"));

}

TEST_F(PassengerListDbTest, totalPassengersFromSourcetoDestination) {


  EXPECT_EQ(3, L1.totalPassengersFromSourcetoDestination("Mumbai","Delhi"));
  EXPECT_EQ(4, L1.totalPassengersFromSourcetoDestination("Chennai","Mumbai"));

}*/
