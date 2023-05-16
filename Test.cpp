#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/OldNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/point.hpp"
using namespace ariel;


TEST_CASE("Testing Point class") {
    SUBCASE("Testing constructor and getter methods") {
        ariel::Point point(2.5, 3.8);
        CHECK(point.getX() == 2.5);
        CHECK(point.getY() == 3.8);
    }

    SUBCASE("Testing distance() method") {
        ariel::Point point1(1.0, 2.0);
        ariel::Point point2(4.0, 6.0);
        CHECK(point1.distance(point2) == doctest::Approx(5.0).epsilon(0.001));
    }

    // SUBCASE("Testing print() method") {
    //     ariel::Point point(2.5, 3.8);
    //     std::ostringstream oss;
    //     oss << "Point: (" << point.getX() << ", " << point.getY() << ")";
    //     CHECK(point.print() == oss.str());
    // }

    SUBCASE("Testing moveTowards() method") {
        ariel::Point source(2.0, 2.0);
        ariel::Point dest(5.0, 6.0);
        double distance = 4.0;
        ariel::Point result = source.moveTowards(source, dest, distance);
        CHECK(result.getX() == doctest::Approx(3.6).epsilon(0.001));
        CHECK(result.getY() == doctest::Approx(4.8).epsilon(0.001));
    }
}

TEST_CASE("Testing Ninja class") {
    ariel::Ninja ninja("Naruto", ariel::Point(0, 0));

    SUBCASE("Testing move() function") {
        ariel::Cowboy enemy("Enemy", ariel::Point(3, 3));
        ninja.move(&enemy);
        CHECK(ninja.getLocation().getX() == 3);
        CHECK(ninja.getLocation().getY() == 3);
    }

    SUBCASE("Testing slash() function") {
        ariel::Cowboy enemy("Enemy", ariel::Point(3, 3));
        ninja.slash(&enemy);
        CHECK(enemy.isAlive() == false);
    }

    SUBCASE("Testing print() function") {
        std::string expected = "Name: Naruto\nLocation: (0, 0)\nHit Points: 100\n";
        CHECK(ninja.print() == expected);
    }
}

TEST_CASE("Testing Cowboy class") {
    ariel::Cowboy cowboy("John", ariel::Point(0, 0));

    SUBCASE("Testing move() function") {
        ariel::Cowboy enemy("Enemy", ariel::Point(3, 3));
        cowboy.shoot(&enemy);
        CHECK(cowboy.getLocation().getX() == 3);
        CHECK(cowboy.getLocation().getY() == 3);
    }

    SUBCASE("Testing shoot() function") {
        ariel::Cowboy enemy("Enemy", ariel::Point(3, 3));
        cowboy.shoot(&enemy);
        CHECK(enemy.isAlive() == false);
    }

    SUBCASE("Testing hasboolets() function") {
        CHECK(cowboy.hasboolets() == true);
        cowboy.shoot(nullptr); // Shoot all bullets
        CHECK(cowboy.hasboolets() == false);
    }

    SUBCASE("Testing reload() function") {
        cowboy.reload();
        CHECK(cowboy.hasboolets() == true);
    }

    SUBCASE("Testing print() function") {
        std::string expected = "Name: John\nLocation: (0, 0)\nHit Points: 100\n";
        CHECK(cowboy.print() == expected);
    }
}
    TEST_CASE("Testing Team class") {
    ariel::Character* leader = new ariel::Cowboy("John", ariel::Point(0, 0));
    ariel::Team team(leader);

    SUBCASE("Testing add() function") {
        ariel::Character* ninja = new ariel::OldNinja("Naruto", ariel::Point(1, 1));
        team.add(ninja);
        CHECK(team.stillAlive() == 2);
    }

    SUBCASE("Testing attack() function") {
        ariel::Team enemyTeam;
        ariel::Character* cowboy = new ariel::Cowboy("Enemy Cowboy", ariel::Point(1, 1));
        enemyTeam.add(cowboy);

        team.attack(&enemyTeam);
        CHECK(enemyTeam.stillAlive() == 0);
    }

    SUBCASE("Testing stillAlive() function") {
        CHECK(team.stillAlive() == 1);
        ariel::Character* ninja = new ariel::YoungNinja("Sasuke", ariel::Point(2, 2));
        team.add(ninja);
        CHECK(team.stillAlive() == 2);
        ariel::Character* anotherNinja = new ariel::TrainedNinja("Kakashi", ariel::Point(3, 3));
        team.add(anotherNinja);
        CHECK(team.stillAlive() == 3);
    }

    // SUBCASE("Testing print() function") {
    //     std::ostringstream oss;
    //     oss << "Team Leader:\n";
    //     oss << "Name: John\nLocation: (0, 0)\nHit Points: 100\n";
    //     oss << "Team Members:\n";
    //     oss << "Name: Naruto\nLocation: (1, 1)\nHit Points: 100\n";
    //     oss << "Name: Sasuke\nLocation: (2, 2)\nHit Points: 100\n";
    //     oss << "Name: Kakashi\nLocation: (3, 3)\nHit Points: 100\n";
    //     CHECK(team.print() == oss.str());
    // }

    SUBCASE("Testing destructor") {
        ariel::Team* newTeam = new ariel::Team();
        ariel::Character* character = new ariel::Cowboy("Character", ariel::Point(0, 0));
        newTeam->add(character);
        delete newTeam; // Should delete the added character as well
    }
}

