//!Notes on the subject
/*
There will be a spaghetti on the middle of the table. 
Each Philosopher (thread) has to eat the spaghetti. 
Each Philosopher has a fork to themselves but to eat the spaghetti it requires two forks.
Number of forks is equal to number of philosophers.
Philo's activities: sleep, think and eat.
When a philo is performing one task, they are not performing another task.
Every philo is required to eat and should never starve.
The simulation stops when one of the philo dies of stravation.
When a philo finished eating, they would put back the fork on the table.

Program arguments input in order: 
number_of_philosophers - The number of philosophers and also the number of forks.

time_to_dies (in miliseconds) - If a philosopher has not started ating within time_to_die miliseconds
since the start of thier last meal or the start of the simulation, they die.

time_to_eat (in miliseconds) - The time it takes for a philosopher to eat.

time_to_sleep (in miliseconds) - The time a philosopher will spend sleeping.

number_of_times_each_philosopher_must_eat (optional argument) - If all philosophes have eaten
at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified,
the simulation stops when a philosopher dies.
*/ 