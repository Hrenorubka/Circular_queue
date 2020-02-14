#include "Queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue)
{
  ASSERT_NO_THROW(Queue<int> q());
}

TEST(Queue, can_create_queue_with_pozitive_length)
{
	ASSERT_NO_THROW(Queue<int> q(15));
}

TEST(Queue, can_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> q(-15));
}

TEST(Queue, can_create_copied_queue)
{
	Queue<int> q(5);
	q.push(1);
	ASSERT_NO_THROW(Queue<int> q_c(q));
}

TEST(Queue, empty_queue_is_empty)
{
	Queue<int> q;
	EXPECT_EQ(true, q.empty());
}

TEST(Queue, not_empty_queue_is_not_empty)
{
	Queue<int> q(10);
	q.push(1);
	EXPECT_EQ(false, q.empty());
}

TEST(Queue, full_queue_is_full)
{
	Queue<int> q(1);
	q.push(1);
	EXPECT_EQ(true, q.full());
}

TEST(Queue, not_full_queue_is_full)
{
	Queue<int> q(3);
	q.push(1);
	EXPECT_EQ(false, q.full());
}

TEST(Queue, can_get_size)
{
	Queue<int> q(3);
	q.push(1);
	EXPECT_EQ(1, q.get_size());
}

TEST(Queue, can_allocate_mem_for_biger_queue)
{
	Queue<int> q(9);
	for (int i = 0; i < 9; i++)
		q.push(1);
	q.push(1);
	EXPECT_EQ(10, q.get_size());
}

TEST(Queue, can_get_first_elem)
{
	Queue<int> q(5);
	q.push(3);
	EXPECT_EQ(3, q.get());
}

TEST(Queue, can_not_get_top_elem_from_queue_with_no_elem)
{
	Queue<int> q(2);
	ASSERT_ANY_THROW(q.get());
}

TEST(Queue, can_pop_elem)
{
	Queue<int> q(2);
	q.push(3);
	q.push(1);
	q.pop();
	EXPECT_EQ(1, q.get());
}

TEST(Queue, can_not_pop_elem_from_empty_queue)
{
	Queue<int> q(10);
	ASSERT_ANY_THROW(q.pop());
}

TEST(Queue, can_push_elem)
{
	Queue<int> q(10);
	ASSERT_NO_THROW(q.push(14));
}
