#pragma once

class ITask
{
	public:
		virtual ~ITask() = default;

	public:
		virtual void Run() = 0;
};