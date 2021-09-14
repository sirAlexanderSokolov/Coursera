//=======================================================================
//=========coursera task tracker - TeamTasks class definition============
//=======================================================================

#include "c_task_tracker.h"

// TasksInfo = map<TaskStatus, int>;
// map <string, TasksInfo> Team;
//-----------------------------------------------------------------------
// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
void TeamTasks::AddNewTask(const string& person)
{
Team[person][TaskStatus::NEW]++;
}
//=======================================================================
// Получить статистику по статусам задач конкретного разработчика
const TasksInfo& TeamTasks::GetPersonTasksInfo(const string& person) const
{
return Team.at(person);
}
//-----------------------------------------------------------------------
// Обновить статусы по данному количеству задач конкретного разработчика
tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(
      const string& person, int task_count)
{
TasksInfo result1;
TasksInfo result2(Team[person]);

for (int ii=0; ii<task_count; ++ii)
{  
for (size_t i = 0; i < 3; ++i) //find task ID and advance it
{
    if (Team[person].find(static_cast<TaskStatus>(i))!=Team[person].end()) 
    {
     ++Team[person][static_cast<TaskStatus>(i)];
     ++Team[person][static_cast<TaskStatus>(i+1)];
     if (Team[person][static_cast<TaskStatus>(i)]<=0) Team[person].erase(static_cast<TaskStatus>(i));
     
     ++result1[static_cast<TaskStatus>(i+1)];
     --result2[static_cast<TaskStatus>(i)];
     if (result2[static_cast<TaskStatus>(i)]<=0) result2.erase(static_cast<TaskStatus>(i));

     break;
    }
}
}
return {result1, result2}; 
}
//-----------------------------------------------------------------------