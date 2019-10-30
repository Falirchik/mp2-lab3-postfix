#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix pf);
}

TEST(TPostfix, can_create_postfix_with_a_given_string){
	ASSERT_NO_THROW(TPostfix p("a+b"));
}

TEST(TPostfix, can_get_infix){
	TPostfix p("a+b");
	EXPECT_EQ("a+b", p.GetInfix());
}

//TEST(TPostfix, can_create_postfix) {
//	TPostfix p("a+b");
//	EXPECT_EQ("ab+", p.ToPostfix());
//}

TEST(TPostfix, can_get_operations){
	TPostfix p("a+b");
	string tmp;
	tmp = p.GetInfix();
	EXPECT_EQ(true, p.CheckOper(tmp[1]));
}

TEST(TPostfix, can_get_operand){
	TPostfix p("a+b");
	string tmp;
	tmp = p.GetInfix();
	EXPECT_EQ(false, p.CheckOper(tmp[0]));
}

TEST(TPostfix, can_get_priority){
	TPostfix p("a+b");
	string tmp;
	tmp = p.GetInfix();
	EXPECT_EQ(1, p.Priority(tmp[1]));
}

