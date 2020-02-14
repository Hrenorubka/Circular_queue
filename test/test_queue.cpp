#include "Queue.h"
#include <gtest.h>

TEST(Queue, can_create_Queue)
{
  ASSERT_NO_THROW(Stack<int> s());
}

TEST(Queue, can_create_stack_with_pozitive_length)
{
	ASSERT_NO_THROW(Stack<int> s(15));
}

TEST(Queue, can_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> s(-15));
}

TEST(Queue, can_create_copied_stack)
{
	Stack<int> s(5);
	s.push(1);
	ASSERT_NO_THROW(Stack<int> s_c(s));
}

TEST(Queue, empty_stack_is_empty)
{
	Stack<int> s;
	EXPECT_EQ(true, s.empty());
}

TEST(Queue, not_empty_stack_is_not_empty)
{
	Stack<int> s(10);
	s.push(1);
	EXPECT_EQ(false, s.empty());
}

TEST(Queue, full_stack_is_full)
{
	Stack<int> s(1);
	s.push(1);
	EXPECT_EQ(true, s.full());
}

TEST(Queue, not_full_stack_is_full)
{
	Stack<int> s(3);
	s.push(1);
	EXPECT_EQ(false, s.full());
}

TEST(Queue, can_get_size)
{
	Stack<int> s(3);
	s.push(1);
	EXPECT_EQ(1, s.size());
}

TEST(Queue, can_allocate_mem_for_biger_stack)
{
	Stack<int> s(9);
	for (int i = 0; i < 9; i++)
		s.push(1);
	s.push(1);
	std::cout << s.size() << "\n";
	EXPECT_EQ(10, s.size());
}

TEST(Queue, can_get_top_elem)
{
	Stack<int> s(5);
	s.push(3);
	EXPECT_EQ(3, s.top());
}

TEST(Queue, can_not_get_top_elem_from_stack_with_no_elem)
{
	Stack<int> s(2);
	ASSERT_ANY_THROW(s.top());
}

TEST(Queue, can_pop_elem)
{
	Stack<int> s(2);
	s.push(3);
	s.push(1);
	s.pop();
	EXPECT_EQ(3, s.top());
}

TEST(Queue, can_not_pop_elem_from_empty_stack)
{
	Stack<int> s(10);
	ASSERT_ANY_THROW(s.pop());
}

TEST(Queue, can_push_elem)
{
	Stack<int> s(10);
	ASSERT_NO_THROW(s.push(14));
}
