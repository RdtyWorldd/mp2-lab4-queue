#include "gtest.h"
#include "../TQue/TQueue.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> q(10));
}

TEST(TQueue, throws_when_create_queue_with_negative_length)
{
  ASSERT_ANY_THROW(TQueue<int> q(-10));
}

TEST(TQueue, can_create_copied_queue)
{
  TQueue<int> q1(10);
  ASSERT_NO_THROW(TQueue<int> q2(q1));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
  TQueue<int> q1(10);
  for (int i = 0; i < 10; i++)
	q1.push(i);
  TQueue<int> q2(q1);
  EXPECT_EQ(q1, q2);
}

TEST(TQueue, copied_queue_has_its_own_memory)
{
  TQueue<int> q1(10);
  for (int i = 0; i < 9; i++)
	q1.push(i);
  TQueue<int> q2(q1);
  q2.push(0);
  EXPECT_NE(q1, q2);
}

TEST(TQueue, isFull_return_true_when_queue_full)
{
  TQueue<int> q(3);
  for (int i = 0; i < 3; i++)
	q.push(i);
  EXPECT_EQ(q.isFull(), true);
}

TEST(TQueue, isFull_return_false_when_queue_isnt_full)
{
  TQueue<int> q(3);
  q.push(1);
  EXPECT_EQ(q.isFull(), false);
}

TEST(TQueue, isFull_return_true_when_queue_empty)
{
  TQueue<int> q(3);
  EXPECT_EQ(q.isEmpty(), true);
}

TEST(TQueue, isEmpty_return_false_when_queue_isnt_full)
{
  TQueue<int> q(3);
  q.push(1);
  EXPECT_EQ(q.isEmpty(), false);
}

TEST(TQueue, throw_when_push_to_full_queue)
{
  TQueue<int> q(3);
  for (int i = 0; i < 3; i++)
	q.push(i);
  ASSERT_ANY_THROW(q.push(4));
}

TEST(TQueue, throw_when_pop_from_empty_queue)
{
  TQueue<int> q(3);
  ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, cleared_queue_isEmpty)
{
  TQueue<int> q(3);
  for (int i = 0; i < 3; i++)
	q.push(i);
  q.clear();
  EXPECT_EQ(q.isEmpty(), true);
}

TEST(TQueue, can_assign_queue_to_itself)
{
  TQueue<int> q1(3), q2(3);
  for (int i = 0; i < 3; i++) {
	q1.push(i);
	q2.push(i);
  }
  q1 = q1;
  EXPECT_EQ(q1, q2);
}

TEST(TQueue, can_assign_queues_of_equal_size)
{
  TQueue<int> q1(3), q2(3), res(3);
  for (int i = 0; i < 3; i++) {
	q1.push(i);
	q2.push(3);
	res.push(3);
  }
  q1 = q2;
  EXPECT_EQ(q1, res);
}

TEST(TQueue, can_assign_queues_with_of_different_size)
{
  TQueue<int> q1(3), q2(4), res(4);
  for (int i = 0; i < 3; i++) {
	q1.push(i);
  }
  for (int i = 0; i < 4; i++) {
	q2.push(i);
	res.push(i);
  }
  q1 = q2;
  EXPECT_EQ(q1, res);
}

TEST(TQueue, compare_queue_with_itself_return_true)
{
  TQueue<int> q1(3);
  for (int i = 0; i < 3; i++) {
	q1.push(i);
  }
  EXPECT_EQ(q1, q1);
}

TEST(TQueue, compare_equal_queues_return_true)
{
  TQueue<int> q1(4), q2(4);
  for (int i = 0; i < 3; i++) {
	q1.push(i);
  }
  for (int i = 0; i < 3; i++) {
	q2.push(i);
  }
  for (int i = 0; i < 3; i++) {
	q2.pop();
  }
  for (int i = 0; i < 3; i++) {
	q2.push(i);
  }
  EXPECT_EQ(q1, q2);
}

TEST(TQueue, queues_with_different_size_are_not_equal)
{
  TQueue<int> q1(3), q2(4);
  for (int i = 0; i < 3; i++) {
	q1.push(i);
  }
  for (int i = 0; i < 4; i++) {
	q2.push(i);
  }
  EXPECT_NE(q1, q2);
}
