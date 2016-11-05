// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "gtest/gtest.h"

#include <sstream>

#include "Darwin.h"

using namespace std;

// -------
// Darwin
// -------

TEST(DarwinFixture, d_test_1) {
    Darwin x = Darwin(1,1);
}

TEST(DarwinFixture, d_test_2) {
    Darwin x = Darwin(3,9);
}

TEST(DarwinFixture, d_test_3) {
    Darwin x = Darwin(9,3);
}

TEST(DarwinFixture, d_test_4) {
    Darwin x = Darwin(72,72);
}

TEST(DarwinFixture, d_test_5){
	Darwin d = Darwin(3,3);
	Species s('t');
	s.addInstruction(HOP);
	Creature x(s, SOUTH);
	d.addCreature(x, 0, 0);
}

//--------------------
// Species
//--------------------
 
TEST(SpeciesFixture, s_test_1) {
    Species x('t');
    ostringstream o;
    x.printProg(o);
    ASSERT_EQ("" , o.str()); 
}

TEST(SpeciesFixture, s_test_2) {
    Species x('t');
    x.addInstruction(HOP);
    x.addInstruction(GO, 0);
    ostringstream o;
    x.printProg(o);
    ASSERT_EQ("0. hop\n1. go 0\n", o.str()); 
}

TEST(SpeciesFixture, s_test_3){
 	Species x('t');
 	ostringstream o;
 	x.print(o);
 	ASSERT_EQ("t", o.str());
}

TEST(SpeciesFixture, s_test_4){
	Species x('t');
	for(int i = 0; i < 1000; i++){
		x.addInstruction(LEFT);
	}
	ASSERT_EQ(x.size(), 1000);
}

TEST(SpeciesFixture, s_test_5){
	Species x('s');
	Species y('t');
	ASSERT_EQ(!(x == y), true);
}

TEST(SpeciesFixture, s_test_6){
	Species x('s');
	Species y('s');
	ASSERT_EQ(x == y, true);
}

TEST(SpeciesFixture, s_test_7){
	Species x('s');
	Species y('t');
	ASSERT_EQ(x != y, true);
}

//--------------
// Instruction
//--------------

TEST(InstructionFixture, i_test_1){
	Instruction i = Instruction(0);
	ASSERT_EQ(i.isControl(), false);
}

TEST(InstructionFixture, i_test_2){
	Instruction i = Instruction(6, 2);
	ASSERT_EQ(i.isControl(), true);
}

TEST(InstructionFixture, i_test_3){
	Instruction i = Instruction(0);
	ostringstream o;
	i.print(o);
	ASSERT_EQ("hop\n", o.str());
}

TEST(InstructionFixture, i_test_4){
	Instruction i = Instruction(4, 2);
	ostringstream o;
	i.print(o);
	ASSERT_EQ("if empty 2\n", o.str());
}

//----------
//Creature
//---------

TEST(CreatureFixture, c_test_1){
	Species x('t');
	Creature c(x, SOUTH);
	ostringstream o;
	x.print(o);
	ASSERT_EQ("t", o.str());
}

TEST(CreatureFixture, c_test_2){
	Species x('t');
	Species y('s');
	Creature c(x, SOUTH);
	Creature b(y, SOUTH);

	ASSERT_EQ(c.compare(b), false);
}

TEST(CreatureFixture, c_test_3){
	Species x('t');
	Creature c(x, SOUTH);
	Creature b(x, SOUTH);

	ASSERT_EQ(c.compare(b), true);
}

TEST(CreatureFixture, c_test_4){
	Species x('t');
	Species y('s');
	Creature c(x, SOUTH);
	Creature b(y, SOUTH);
	c.infect(b);

	ASSERT_EQ(c.compare(b), true);
}

