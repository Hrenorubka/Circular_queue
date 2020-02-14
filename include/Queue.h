#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
#include <memory>

using std::unique_ptr;

template <class ValType>
class Queue
{
private:
	ValType *begin_queue;
	ValType *end_queue;
	unique_ptr<ValType> container;
	int size;
	void resize()
	{
		int new_size = size + 5 + size / 3;
		ValType *obl = new ValType[new_size];
		int i = 0;
		ValType *step = end_queue;
		if (step == NULL)
		{
			container.reset(obl);
			begin_queue = container.get();
			size = new_size;
			return;
		}
		while (step != begin_queue)
		{
			obl[i] = *step;
			i++;
			if (step == container.get() + size - 1)
				step = container.get();
			else
				step++;
		}
		obl[i] = *step;
		container.reset(obl);
		end_queue = container.get();
		begin_queue = end_queue + i;
		size = new_size;
	}
public:
	Queue()
	{
		size = 15;
		ValType *obl = new ValType[size];
		container.reset(obl);
		begin_queue = container.get();
		end_queue = NULL;
	}
	Queue(int size_queue)
	{
		if (size_queue < 0)
			throw 1;
		size = size_queue;
		ValType *obl = new ValType[size];
		container.reset(obl);
		begin_queue = container.get();
		end_queue = NULL;
	}
	Queue(const Queue &cop)
	{
		size = cop.size;
		ValType *obl = new ValType[size];
		ValType *step = cop.end_queue;
		int i = 0;
		while (step != cop.begin_queue)
		{

			obl[i] = *step;
			if (step == cop.container.get() + size - 1)
				step = cop.container.get();
			else
				step++;
			i++;
		}
		obl[i] = *step;
		container.reset(obl);
		end_queue = container.get();
		begin_queue = container.get() + i;
	}
	ValType get()
	{
		if (end_queue == NULL)
			throw 1;
		return *end_queue;
	}
	void pop()
	{
		if (end_queue == NULL)
			throw 1;
		if (end_queue == begin_queue)
		{
			end_queue = NULL;
			return;
		}
		if (end_queue == container.get() + size - 1)
			end_queue = container.get();
		else
			end_queue++;
	}
	void push(ValType elem)
	{
		if (end_queue == NULL)
		{
			if (size == 0)
			{
				resize();
			}
			*begin_queue = elem;
			end_queue = begin_queue;
			return;
		}
		ValType *obl = begin_queue;
		if (obl == container.get() + size - 1)
			obl = container.get();
		else
			obl++;
		if (obl == end_queue)
		{
			resize();
			obl = begin_queue + 1;
		}
		begin_queue = obl;
		*begin_queue = elem;

	}
	int get_size()
	{
		if (end_queue == NULL)
			return 0;
		if (begin_queue >= end_queue)
			return begin_queue - end_queue + 1;
		return (container.get() + size - begin_queue) + (end_queue - container.get() + 1);
	}
	bool empty()
	{
		if (end_queue == NULL)
			return true;
		return false;
	}
	bool full()
	{
		if (get_size() == size)
			return true;
		return false;
	}

};
#endif
